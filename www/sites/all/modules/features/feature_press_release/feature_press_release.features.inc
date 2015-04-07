<?php
/**
 * @file
 * feature_press_release.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_press_release_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_press_release_node_info() {
  $items = array(
    'press_release' => array(
      'name' => t('Press release'),
      'base' => 'node_content',
      'description' => t('Press releases are an imported RSS feed from http://rss.vuelio.uk.com/V2/RBKC/release'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
