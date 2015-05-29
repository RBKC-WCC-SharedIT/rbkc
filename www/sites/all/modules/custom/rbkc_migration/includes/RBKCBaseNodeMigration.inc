<?php

/**
 * Class RBKCBaseNodeMigration
 */
class RBKCBaseNodeMigration extends RBKCBaseMigration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'p_page_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'alias' => 'import'
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->addSimpleMappings(array(
      'title',
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

    $this->addFieldMapping('uid')->defaultValue(1);
  }

  public function complete($entity, stdClass $row) {
    if (method_exists($this, 'handleRedirect')) {
      $this->handleRedirect($entity, $row);
    }
  }

  protected static function callbackTransformCreatedDate($date) {
    return strtotime($date);
  }
}
