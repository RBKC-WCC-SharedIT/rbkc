<?php
/**
 * @file
 * feature_service_hub.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_service_hub_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_service_hub_node_info() {
  $items = array(
    'servicehub' => array(
      'name' => t('Service Hub'),
      'base' => 'node_content',
      'description' => t('Use this content type to create service hub pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
