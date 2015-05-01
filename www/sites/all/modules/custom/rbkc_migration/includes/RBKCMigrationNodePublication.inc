<?php

/**
 * @file
 *
 * Migrate insights.
 */
class RBKCMigrationNodePublication extends RBKCBaseNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    //The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns = array(
    );

    //The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('Import of publication content.');
    //The Source of the import
    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/sites/all/modules/custom/rbkc_migration/data/RBKCMigrationNodePublication.csv', $columns, array('delimiter' => ',', 'header_rows' => 1, 'embedded_newlines' => TRUE));
    //The destination CCK (boundle)
    $this->destination = new MigrateDestinationNode('publication');

    // The body and its options
    $this->addFieldMapping('body','body');
    $this->addFieldMapping('body:summary','body:summary');
    $this->addFieldMapping('body:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('body:language','body:language')
      ->defaultValue('en');

    //The field_asset and its options
    $file_source_dir = drupal_get_path('module', 'rbkc_migration') . DIRECTORY_SEPARATOR . 'data' . DIRECTORY_SEPARATOR . 'files';
    $this->addFieldMapping('field_asset', 'field_asset');
    $this->addFieldMapping('field_asset:source_dir')->defaultValue($file_source_dir);
    $this->addFieldMapping('field_asset:file_replace')->defaultValue(FILE_EXISTS_RENAME);
    $this->addFieldMapping('field_asset:preserve_files')->defaultValue(FALSE);

    // Short title and its options
    $this->addFieldMapping('field_short_title','field_short_title');
    $this->addFieldMapping('field_short_title:language')
      ->defaultValue('en');
  }
}