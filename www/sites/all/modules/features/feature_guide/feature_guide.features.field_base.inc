<?php
/**
 * @file
 * feature_guide.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function feature_guide_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_topic'
  $field_bases['field_topic'] = array(
    'active' => 1,
    'cardinality' => 3,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_topic',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'topic',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
