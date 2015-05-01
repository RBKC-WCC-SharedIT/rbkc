<?php
/**
 * @file
 * feature_field_bases.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_field_bases_taxonomy_default_vocabularies() {
  return array(
    'action' => array(
      'name' => 'Action',
      'machine_name' => 'action',
      'description' => 'Action.',
      'hierarchy' => 0,
      'module' => '',
      'weight' => 0,
    ),
    'service_hub' => array(
      'name' => 'Service Hub',
      'machine_name' => 'service_hub',
      'description' => 'Service Hub.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tag' => array(
      'name' => 'Tag',
      'machine_name' => 'tag',
      'description' => 'Tag.',
      'hierarchy' => 0,
      'module' => '',
      'weight' => 0,
    ),
    'topic' => array(
      'name' => 'Topic',
      'machine_name' => 'topic',
      'description' => 'Topic.',
      'hierarchy' => 0,
      'module' => '',
      'weight' => 0,
    ),
    'user' => array(
      'name' => 'User',
      'machine_name' => 'user',
      'description' => 'User.',
      'hierarchy' => 0,
      'module' => '',
      'weight' => 0,
    ),
  );
}
