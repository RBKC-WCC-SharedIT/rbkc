<?php

/**
 * @file
 *
 * Migrate insights.
 */
class RBKCBaseNodeMigration extends Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    //The defintion of the collumns. Keys are integers. values are array(field name, description).
    $columns = array(
    );

    //The Description of the import. This desription is shown on the Migrate GUI
    $this->description = t('Import of answer content.');

    //The Source of the import
    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/sites/all/modules/custom/rbkc_migration/data/RBKCMigrationNodeAnswer.csv', $columns, array('delimiter' => ',', 'header_rows' => 1, 'embedded_newlines' => TRUE));
    //The destination CCK (boundle)
    $this->destination = new MigrateDestinationNode('answer');

    //Source and destination relation for rollbacks
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'uuid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'alias' => 'import'
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    //Simple Field mappings
    $this->addSimpleMappings(array(
      'title',
      'created',
      'changed',
      'promote',
      'sticky',
      'revision',
      'log',
      'language',
      'tnid',
      'translate',
      'is_new',
      'path',
      'comment'
    ));

    // Some system defaults
    $this->addFieldMapping('uid')
      ->defaultValue(1);
    $this->addFieldMapping('status')
      ->defaultValue(1);
    $this->addUnmigratedDestinations(array('legacypath'));
  }

  public function complete($entity, stdClass $row) {
    if (!isset($redirect)) {
      $redirect = new stdClass();
    }
    if(!empty($row->legacypath)){
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
}