<?php
/**
 * @file
 * feature_service_sub_hub.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_service_sub_hub_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_service_sub_hub_node_info() {
  $items = array(
    'subhub' => array(
      'name' => t('Service Sub-Hub'),
      'base' => 'node_content',
      'description' => t('Use this content type to create a service sub-hub page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
