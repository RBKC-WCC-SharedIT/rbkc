<?php
/**
 * @file
 * feature_user.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_user_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_editor_service_hub'
  $field_instances['user-user-field_editor_service_hub'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Assign this user to the service hubs they should have access to.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'user',
    'field_name' => 'field_editor_service_hub',
    'label' => 'Service hub',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'shs',
      'settings' => array(
        'shs' => array(
          'create_new_levels' => 0,
          'create_new_terms' => 0,
          'force_deepest' => 0,
          'node_count' => 0,
        ),
      ),
      'type' => 'taxonomy_shs',
      'weight' => 41,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Assign this user to the service hubs they should have access to.');
  t('Service hub');

  return $field_instances;
}
