<?php

/**
 * @file
 * Migrate the source CSV documents data to MySQL for lookup purposes.
 */

class RBKCMigrationSourceDocumentsCSV extends Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import source document data from CSV to MySQL for lookup.');

    $source = drupal_get_path('module', 'rbkc_migration') . '/data/RBKCDocuments.csv';
    $columns = array();
    $options = array(
      'delimiter' => ',',
      'header_rows' => 1,
      'embedded_newlines' => TRUE,
    );

    $this->source = new MigrateSourceCSV($source, $columns, $options);

    $table_name = 'rbkc_migration_documents';
    $this->destination = new MigrateDestinationTable($table_name);

    $this->addFieldMapping('gui', 'documentid');
    $this->addFieldMapping('filename', 'FileName');

    $source_key = array(
      'documentid' => array(
        'length' => 255,
        'type' => 'varchar',
        'not null' => TRUE,
        'default' => '',
      ),
    );

    $destination_key = MigrateDestinationTable::getKeySchema($table_name);

    $this->map = new MigrateSQLMap($this->machineName, $source_key, $destination_key);
  }
}