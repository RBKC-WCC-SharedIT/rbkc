<?php
/**
 * @file
 * feature_press_release.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_press_release_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__press_release';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'top_three_topics' => array(
        'custom_settings' => TRUE,
      ),
      'teaser_small' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_large' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_medium' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '7',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '6',
        ),
        'redirect' => array(
          'weight' => '5',
        ),
        'xmlsitemap' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(
        'sharethis' => array(
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'top_three_topics' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'teaser_small' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'carousel' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_press_release';
  $strongarm->value = array();
  $export['menu_options_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_press_release';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_press_release';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_press_release';
  $strongarm->value = '0';
  $export['node_preview_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_press_release';
  $strongarm->value = 0;
  $export['node_submitted_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_press_release_pattern';
  $strongarm->value = 'press-release/[node:title]';
  $export['pathauto_node_press_release_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'short_title_enable_press_release';
  $strongarm->value = 1;
  $export['short_title_enable_press_release'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_press_release';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_press_release'] = $strongarm;

  return $export;
}
