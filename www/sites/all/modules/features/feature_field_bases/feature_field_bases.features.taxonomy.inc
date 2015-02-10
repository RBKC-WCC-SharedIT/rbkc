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
    'site_sections' => array(
      'name' => 'Site sections',
      'machine_name' => 'site_sections',
      'description' => 'Site sections.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
