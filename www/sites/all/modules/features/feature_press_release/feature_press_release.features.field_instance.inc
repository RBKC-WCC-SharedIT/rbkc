<?php
/**
 * @file
 * feature_press_release.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_press_release_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-press_release-body'
  $field_instances['node-press_release-body'] = array(
    'bundle' => 'press_release',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'smart_trim',
        'settings' => array(
          'more_link' => 0,
          'more_text' => 'Read more',
          'summary_handler' => 'full',
          'trim_length' => 220,
          'trim_options' => array(
            'text' => 'text',
          ),
          'trim_suffix' => '…',
          'trim_type' => 'chars',
        ),
        'type' => 'smart_trim_format',
        'weight' => 0,
      ),
      'top_three_topics' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
      'context_default' => 'full',
      'display_summary' => 1,
      'dnd_enabled' => 1,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'mee_enabled' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_display' => 'default',
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');

  return $field_instances;
}
