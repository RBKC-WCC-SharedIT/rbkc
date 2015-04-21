<?php

/**
 * @file
 *
 * Migrate insights.
 */
class RBKCMigrationNodeAnswer extends RBKCBaseNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    //The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns = array(
    );

    //The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('Import of answer content.');
    //The Source of the import
    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/sites/all/modules/custom/rbkc_migration/data/RBKCMigrationNodeAnswer.csv', $columns, array('enclosure' => '*','delimiter' => ',', 'header_rows' => 1, 'embedded_newlines' => TRUE));
    //The destination CCK (bundle)
    $this->destination = new MigrateDestinationNode('answer');

    // The body and its options
    $this->addFieldMapping('body','body');
    $this->addFieldMapping('body:summary','body:summary');
    $this->addFieldMapping('body:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('body:language')
      ->defaultValue('en');
    // field_contact_button and its options
    $this->addFieldMapping('field_contact_department','field_contact_department')
      ->sourceMigration(array('RBKCMigrationEntityContactDepartments'))
      ->separator(';');
    // field_service_hub and its options
    $this->addFieldMapping('field_service_hub','field_service_hub');
    $this->addUnmigratedDestinations(array('field_service_hub:source_type'));
    $this->addFieldMapping('field_service_hub:create_term')
      ->defaultValue('field_service_hub:create_term');
    $this->addFieldMapping('field_service_hub:ignore_case')
      ->defaultValue(TRUE);
    // Short title and its options
    $this->addFieldMapping('field_short_title','field_short_title');
    $this->addFieldMapping('field_short_title:language')
      ->defaultValue('en');
  }

  public function complete($entity, stdClass $row) {
    if (!isset($redirect)) {
      $redirect = new stdClass();
    }
    $parsed_url = parse_url($row->legacypath);
    $legacyurl = ltrim($parsed_url['path'], '/');
    // Merge default values.
    redirect_object_prepare($redirect, array(
      #'source' => basename($row->legacypath),
      'source' => $legacyurl,
      'source_options' => isset($_GET['source_options']) ? drupal_get_query_array($_GET['source_options']) : array(),
      'redirect' => 'node/' . $entity->nid,
      'redirect_options' => isset($_GET['redirect_options']) ? drupal_get_query_array($_GET['redirect_options']) : array(),
      'language' => isset($_GET['language']) ? urldecode($_GET['language']) : LANGUAGE_NONE,
    ));
    redirect_save($redirect);
  }
}