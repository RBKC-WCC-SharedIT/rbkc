<?php
/**
 * @file
 * Controls: Create content - Provides a user panel for accessing content creation pages - controls.
 */

/**
 * Implements hook_controls_info().
 */
function controls_cc_controls_info() {
  $controls = array(
    'controls_cc' => array(
      'create_content' => array(
      ),
    ),
  );

  $cc =& $controls['controls_cc']['create_content'];

  $cc['user:user'] = array(
    'title' => t('Add new %type', array('%type' => 'User')),
    'href' => 'admin/people/create',
    'entity_type' => 'user',
  );

  foreach (node_type_get_types() as $type => $data) {
    $cc["node:$type"] = array(
      'title' => t('Add new %type', array('%type' => $data->name)),
      'href' => 'node/add/' . str_replace('_', '-', $type),
      'entity_type' => 'node',
    );
  }

  return $controls;
}