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
    'service_hub' => array(
      'name' => 'Service Hub',
      'machine_name' => 'service_hub',
      'description' => 'Service Hub.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
