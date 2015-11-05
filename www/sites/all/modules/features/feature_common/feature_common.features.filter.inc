<?php
/**
 * @file
 * feature_common.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function feature_common_filter_default_formats() {
  $formats = array();

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'filter_url' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => 50,
        'status' => 1,
        'settings' => array(
          'local_paths' => '',
          'protocol_style' => 'path',
          'local_paths_exploded' => array(
            0 => array(
              'path' => '/',
            ),
            1 => array(
              'path' => '/',
              'host' => 'default',
            ),
          ),
          'base_url_host' => 'default',
        ),
      ),
    ),
  );

  return $formats;
}
