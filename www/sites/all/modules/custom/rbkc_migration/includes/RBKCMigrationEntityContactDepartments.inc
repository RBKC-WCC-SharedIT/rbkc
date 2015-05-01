<?php

/**
 * @file
 *
 * Migrate insights.
 */
class RBKCMigrationEntityContactDepartments extends Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    //The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns = array(
    );

    //The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('Import of Contact Department content.');
    //The Source of the import
    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/sites/all/modules/custom/rbkc_migration/data/RBKCMigrationEntityContactDepartments.csv', $columns, array('delimiter' => ',', 'header_rows' => 1, 'embedded_newlines' => TRUE));
    //The destination Entity (field_collection)
    $this->destination = new MigrateDestinationFieldCollection('field_contact_department',array('host_entity_type' => 'node'));

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'uuid' => array(
          'type' => 'int',
          'not null' => true,
        ),
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );
    $this->addFieldMapping('host_entity_id', 'uuid')->sourceMigration('RBKCMigrationNodeAnswer');
  }
}