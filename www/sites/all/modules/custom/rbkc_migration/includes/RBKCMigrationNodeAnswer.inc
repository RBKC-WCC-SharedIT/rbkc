<?php

/**
 * @file
 *
 * Migrate answer pages.
 */

/**
 * Class RBKCMigrationNodeAnswer
 *
 * This migration creates stubs for internal links (ILINK's) it encounters,
 * the content type of the stub is determined by looking up the Alterian
 * template and mapping that against our content types.
 */
class RBKCMigrationNodeAnswer extends RBKCBaseNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import of answer content.');

    $destination = 'answer';
    $this->destination = new MigrateDestinationNode($destination);

    $this->addFieldMapping('body', 'body_html');
    $this->addFieldMapping('body:summary', 'body:summary');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('body:language')->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('status', 'status');

    $this->addFieldMapping('field_service_hub', 'path')->callbacks(array(self, 'resolveServiceHubTerm'));

    $this->addFieldMapping('field_short_title', 'field_short_title');
    $this->addFieldMapping('field_short_title:language')->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_contact_department', 'contact_department_html')->callbacks(array($this, 'resolveContactDepartment'));

    $this->addFieldMapping('metatag_title', 'metatag_title');
    $this->addFieldMapping('metatag_description', 'metatag_description');
    $this->addFieldMapping('metatag_keywords', 'metatag_keywords');

    $this->addFieldMapping('created', 'created')->callbacks(array(self, 'transformCreatedDate'));
  }



  public function prepareRow($row) {
    $row->template = trim($row->template);
    if ('rf-answer-planning' !== $row->template && 'rf-answer-generic' !== $row->template) {
      return FALSE;
    }

    if (FALSE == parent::prepareRow($row)) {
      return FALSE;
    }

    $row->contact_department_html = $this->extractNodeFromXML($row->body, 'contactbutton');
    return TRUE;
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

  protected function createNodeStub($source_id) {
    $node_type = self::templateLookUp($source_id);

    if (is_null($node_type)) {
      syslog(LOG_WARNING, sprintf('Template lookup returned a non-string value for %d.', $source_id));
      return NULL;
    }

    $node = new stdClass();
    $node->title = t('Stub for @id', array('@id' => $source_id));
    $node->body[LANGUAGE_NONE][0]['value'] = t('Stub body');
    $node->language = LANGUAGE_NONE;
    $node->type = $node_type;
    $node->uid = 1;
    $node->status = 0;
    node_save($node);
    return $node;
  }
}
