<?php
/**
 * @file
 * feature_roles_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_roles_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access_google_appliance_content'.
  $permissions['access_google_appliance_content'] = array(
    'name' => 'access_google_appliance_content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'google_appliance',
  );

  return $permissions;
}
