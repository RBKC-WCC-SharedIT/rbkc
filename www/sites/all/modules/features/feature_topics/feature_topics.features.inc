<?php
/**
 * @file
 * feature_topics.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_topics_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_topics_node_info() {
  $items = array(
    'topic' => array(
      'name' => t('Topic page'),
      'base' => 'node_content',
      'description' => t('Use this content type to create topic pages'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
