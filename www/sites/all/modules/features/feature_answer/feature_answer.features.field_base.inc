<?php
/**
 * @file
 * feature_answer.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function feature_answer_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_contact_department'
  $field_bases['field_contact_department'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_contact_department',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'views',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'view' => array(
          'args' => array(),
          'display_name' => 'entityreference_1',
          'view_name' => 'contact_departments',
        ),
      ),
      'target_type' => 'contact_department',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
