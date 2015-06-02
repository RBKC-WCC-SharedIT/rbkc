<?php

/**
 * Class RBKCMigrateDestinationFieldCollection
 *
 * This is a one shot wonder destination class, there's no going back!
 *
 * The off the shelf field collection class only caters for a single entity per
 * row and doesn't handle multi-value field collections.
 *
 * This class extends that class and iterates over a prepared array of fields
 * that are added to a new field collection entity that is in turn added to the
 * host entity.
 */

class RBKCMigrateDestinationFieldCollection extends MigrateDestinationFieldCollection {
  public function import(stdClass $collection, stdClass $row) {
    foreach ($collection->field_collections as $index => $field_collection) {
      $entity = entity_create('field_collection_item', array('field_name' => $this->bundle));
      $host_entity = entity_load_single($this->hostEntityType, $collection->host_entity_id);
      entity_get_controller($this->hostEntityType)->resetCache();
      $entity->setHostEntity($this->hostEntityType, $host_entity);

      foreach ($field_collection as $field => $value) {
        $entity->{$field} = $value;
      }

      migrate_instrument_start('field_collection_save');
      entity_save('field_collection_item', $entity);
      migrate_instrument_stop('field_collection_save');
    }

    // Pass back the last entity, not sure what else to do in the circumstances.
    $this->complete($entity, $row);
    return array($entity->item_id);
  }

  public function complete($entity, stdClass $source_row) {
    $migration = Migration::currentMigration();
    if (method_exists($migration, 'complete')) {
      try {
        $migration->complete($entity, $source_row);
      }
      catch (Exception $e) {
        $migration->saveMessage($e->getMessage());
      }
    }
  }
}