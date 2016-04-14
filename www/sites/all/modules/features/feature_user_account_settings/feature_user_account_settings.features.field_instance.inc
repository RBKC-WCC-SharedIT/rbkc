<?php
/**
 * @file
 * feature_user_account_settings.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_user_account_settings_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_full_name'
  $field_instances['user-user-field_full_name'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'ie \'Joe Bloggs\'',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'user',
    'field_name' => 'field_full_name',
    'label' => 'User\'s full name',
    'required' => 0,
    'settings' => array(
      'context' => 'title',
      'context_default' => 'full',
      'dnd_enabled' => 0,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'mee_enabled' => 0,
      'text_processing' => 0,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('User\'s full name');
  t('ie \'Joe Bloggs\'');

  return $field_instances;
}
