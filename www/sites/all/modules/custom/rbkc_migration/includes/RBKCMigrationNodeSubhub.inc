<?php

/**
 * @file
 *
 * Migrate insights.
 */
class RBKCMigrationNodeSubhub extends RBKCBaseNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    //The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns = array(
    );

    //The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('Import of subhub content.');
    //The Source of the import
    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/sites/all/modules/custom/rbkc_migration/data/RBKCMigrationNodeSubhub.csv', $columns, array('delimiter' => ',', 'header_rows' => 1, 'embedded_newlines' => TRUE));
    //The destination CCK (boundle)
    $this->destination = new MigrateDestinationNode('subhub');
    $this->addHardDependencies(array(
      'RBKCMigrationNodeTopic',
    ));

    // The body and its options
    $this->addFieldMapping('body','body');
    $this->addFieldMapping('body:summary','body:summary');
    $this->addFieldMapping('body:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('body:language','body:language')
      ->defaultValue('en');

    //The field_subhub_link_to_topic and its options
    $this->addFieldMapping('field_subhub_link_to_topic','field_subhub_link_to_topic')
      ->sourceMigration('RBKCMigrationNodeTopic')
      ->separator(';');

    // Short title and its options
    $this->addFieldMapping('field_short_title','field_short_title');
    $this->addFieldMapping('field_short_title:language')
      ->defaultValue('en');
  }
}