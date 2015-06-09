<?php

/**
 * Metatag destination handler.
 */
class MigrateRBKCHandler extends MigrateDestinationHandler {

  public function __construct() {
    $this->registerTypes(array('node'));
  }

  /**
   * Implements MigrateDestinationHandler::fields().
   */
  public function fields() {
    $fields = array();
    $fields['legacypath'] = t('The URL of the content where it can be currently found on the live site and is currently indexed by google');

    return $fields;
  }
}
