<?php

/**
 * @file
 *
 * Migrate insights.
 */
class RBKCMigrationNodeServicehub extends RBKCBaseNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    //The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns = array(
    );

    //The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('Import of service hub content.');
    //The Source of the import
    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/sites/all/modules/custom/rbkc_migration/data/RBKCMigrationNodeServicehub.csv', $columns, array('delimiter' => ',', 'header_rows' => 1, 'embedded_newlines' => TRUE));
    //The destination CCK (boundle)
    $this->destination = new MigrateDestinationNode('servicehub');
    $this->addHardDependencies(array(
      'RBKCMigrationNodeAnswer',
      ));

    //todo field_news_stories field collection migration

    //The field_other_popular_content and its options
    $this->addFieldMapping('field_other_popular_content','field_other_popular_content')
      ->separator(';');
    $this->addFieldMapping('field_other_popular_content:title','field_other_popular_content:title')
      ->separator(';');

    //The field_popular_tasks and its options
    $this->addFieldMapping('field_popular_tasks','field_popular_tasks')
      ->separator(';');
    $this->addFieldMapping('field_popular_tasks:title','field_popular_tasks:title')
      ->separator(';');

    //todo field_popular_topics field_collection

    // Short title and its options
    $this->addFieldMapping('field_short_title','field_short_title');
    $this->addFieldMapping('field_short_title:language')
      ->defaultValue('en');
  }

  /**
   * Implements createStub method to allow referencing other nodes created in
   * this migration.
   */
  protected function createStub(Migration $migration, array $source_id) {
    $node = new stdClass();
    $node->title = t('Stub for @id', array('@id' => $source_id[0]));
    $node->body[LANGUAGE_NONE][0]['value'] = t('Stub body');
    $node->type = $this->destination->getBundle();
    $node->uid = 1;
    $node->status = 0;
    node_save($node);
    if (isset($node->nid)) {
      return array($node->nid);
    }
    else {
      return FALSE;
    }
  }
}