<?php

/**
 * @file
 * Migrate the source CSV data to MySQL for lookup purposes.
 */

class RBKCMigrationSourceCSV extends Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import source data from CSV to MySQL for lookup.');

    $source = drupal_get_path('module', 'rbkc_migration') . '/data/RBKCFullPageTable.csv';
    $columns = array();
    $options = array(
      'enclosure' => '$',
      'delimiter' => ',',
      'header_rows' => 1,
      'embedded_newlines' => TRUE,
    );

    $this->source = new MigrateSourceCSV($source, $columns, $options);

    $table_name = 'rbkc_migration_source';
    $this->destination = new MigrateDestinationTable($table_name);

    $this->addFieldMapping('p_page_id', 'p_page_id');
    $this->addFieldMapping('p_parent_id', 'p_parent_id');
    $this->addFieldMapping('p_top_id', 'p_top_id');
    $this->addFieldMapping('template', 'template');

    $source_key = array(
      'p_page_id' => array(
        'type' => 'int',
        'not null' => TRUE,
        'default' => 0,
      ),
    );

    $destination_key = MigrateDestinationTable::getKeySchema($table_name);

    $this->map = new MigrateSQLMap($this->machineName, $source_key, $destination_key);
  }
}