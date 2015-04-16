<?php
/**
 * @file
 * feature_survey.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_survey_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_survey_node_info() {
  $items = array(
    'survey' => array(
      'name' => t('Survey'),
      'base' => 'node_content',
      'description' => t('Use this content type to create surveys. Uses the Webform module.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
