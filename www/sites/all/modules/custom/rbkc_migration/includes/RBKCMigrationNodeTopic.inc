<?php

/**
 * @file
 *
 * Migrate insights.
 */
class RBKCMigrationNodeTopic extends RBKCBaseNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    //The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns = array(
    );

    //The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('Import of topic content.');
    //The Source of the import
    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/sites/all/modules/custom/rbkc_migration/data/RBKCMigrationNodeTopic.csv', $columns, array('delimiter' => ',', 'header_rows' => 1, 'embedded_newlines' => TRUE));
    //The destination CCK (boundle)
    $this->destination = new MigrateDestinationNode('topic');
    $this->addHardDependencies(array(
      'RBKCMigrationNodeAnswer',
    ));

    // The body and its options
    $this->addFieldMapping('body','body');
    $this->addFieldMapping('body:summary','body:summary');
    $this->addFieldMapping('body:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('body:language','body:language')
      ->defaultValue('en');

    //todo field_topic_link and its options

    // Short title and its options
    $this->addFieldMapping('field_short_title','field_short_title');
    $this->addFieldMapping('field_short_title:language')
      ->defaultValue('en');
  }
}