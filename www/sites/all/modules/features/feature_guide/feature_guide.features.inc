<?php
/**
 * @file
 * feature_guide.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_guide_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_guide_node_info() {
  $items = array(
    'guide' => array(
      'name' => t('Guide'),
      'base' => 'node_content',
      'description' => t('Use this content type to create a guide that consists of a collection of pages with a table of contents to help users achieve a specific aim.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
