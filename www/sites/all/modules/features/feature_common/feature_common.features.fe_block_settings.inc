<?php
/**
 * @file
 * feature_common.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function feature_common_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-govmetric'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'govmetric',
    'module' => 'block',
    'node_types' => array(
      0 => 'answer',
      1 => 'guide',
      2 => 'publication',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'rbkc' => array(
        'region' => 'govmetric',
        'status' => 1,
        'theme' => 'rbkc',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Govmetric',
    'visibility' => 0,
  );

  return $export;
}
