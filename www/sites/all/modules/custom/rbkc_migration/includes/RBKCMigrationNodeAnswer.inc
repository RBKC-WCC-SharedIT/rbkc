<?php

/**
 * @file
 *
 * Migrate insights.
 */
class RBKCMigrationNodeAnswer extends RBKCBaseNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import of answer content.');

    $source = drupal_get_path('module', 'rbkc_migration') . '/data/RBKCMigrationNodeAnswer.csv';
    $columns = array();
    $options = array(
      'enclosure' => '$',
      'delimiter' => ',',
      'header_rows' => 1,
      'embedded_newlines' => TRUE
    );

    $this->source = new MigrateSourceCSV($source, $columns, $options);

    $destination = 'answer';
    $this->destination = new MigrateDestinationNode($destination);

    $this->addFieldMapping('body', 'body_html');
    $this->addFieldMapping('body:summary', 'body:summary');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('body:language')->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('status', 'status');

    $this->addFieldMapping('field_service_hub', 'field_service_hub');
//    $this->addUnmigratedDestinations(array('field_service_hub:source_type'));
//    $this->addFieldMapping('field_service_hub:create_term')->defaultValue('field_service_hub:create_term');
//    $this->addFieldMapping('field_service_hub:ignore_case')->defaultValue(TRUE);

    $this->addFieldMapping('field_short_title', 'field_short_title');
    $this->addFieldMapping('field_short_title:language')->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_contact_department', 'contact_department_html')->callbacks(array($this, 'resolveContactDepartment'));
  }

  public function prepareRow($row) {
    if (FALSE == parent::prepareRow($row)) {
      return FALSE;
    }

    $row->field_service_hub = self::resolveServiceHubTerm($row->path);
    $row->contact_department_html = $this->extractNodeFromXML($row->body, 'contactbutton');
  }

  protected static function resolveServiceHubTerm($path) {
    if (!$path) {
      return array();
    }

    if (FALSE === strpos($path, '/')) {
      return array();
    }

    $parts = explode('/', $path);
    array_pop($parts);

    $vocabulary_name = 'service_hub';
    $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_name);
    if (FALSE === $vocabulary) {
      return array();
    }

    return self::recurseServiceHubTerms($parts, $vocabulary);
  }

  protected static function recurseServiceHubTerms(array $parts, stdClass $vocabulary, stdClass $parent = NULL) {
    $part = array_shift($parts);

    $term_name = static::resolveTermMapping($part);

    $terms = taxonomy_get_term_by_name($term_name, $vocabulary->machine_name);
    if (count($terms)) {
      $term = array_shift($terms);
    }

    if (!is_object($term)) {
      $term = new stdClass();
      $term->vid = $vocabulary->vid;
      $term->name = $term_name;
      if (!is_null($parent)) {
        $term->parent = $parent->tid;
      }
      taxonomy_term_save($term);
    }

    if (count($parts)) {
      return self::recurseServiceHubTerms($parts, $vocabulary, $term);
    }

    return $term->name;
  }

  protected function resolveContactDepartment($contact_button_html) {
    if (!$contact_button_html) {
      return NULL;
    }

    try {
      $contact_button_element = new SimpleXMLElement($contact_button_html);
    }
    catch (Exception $e) {
      syslog(LOG_ERR, 'Failed to load contact button html as SimpleXMLElement: ' . $e->getMessage());
      return NULL;
    }

    $href = (string) $contact_button_element->attributes()->href;
    $contact_department_name = (string) $contact_button_element;
    $contact_department_name = str_replace(array('Contact', 'the', 'team'), array('', '', ''), $contact_department_name);
    $contact_department_name = trim($contact_department_name);
    $contact_department_name = ucfirst($contact_department_name);

    if (!$contact_department_name) {
      return NULL;
    }

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'contact_department', '=')
      ->fieldCondition('field_contact_department_name', 'value', $contact_department_name, '=');
    $result = $query->execute();

    if ($result) {
      $contact_departments = array_shift($result);
      $contact_department = array_shift($contact_departments);
    }
    else {
      $values = array(
        'created' => time(),
        'field_contact_department_name' => array(
          LANGUAGE_NONE => array(
            0 => array(
              'value' => $contact_department_name,
            ),
          ),
        ),
        'field_contact_department_link' => array(
          LANGUAGE_NONE => array(
            0 => array(
              'url' => $href,
            ),
          ),
        ),
      );

      $contact_department = entity_create('contact_department', $values);

      if ($contact_department) {
        entity_save('contact_department', $contact_department);
      }
    }

    return (int) $contact_department->id;
  }
}
