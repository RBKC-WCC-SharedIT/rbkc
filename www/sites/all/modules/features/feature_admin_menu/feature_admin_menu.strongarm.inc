<?php
/**
 * @file
 * feature_admin_menu.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_admin_menu_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_menu_source_settings';
  $strongarm->value = array(
    1 => array(
      'source' => '',
    ),
    2 => array(
      'source' => '',
    ),
    3 => array(
      'source' => 'menu-site-administrator-menu',
    ),
    5 => array(
      'source' => '',
    ),
    7 => array(
      'source' => '',
    ),
    9 => array(
      'source' => '',
    ),
  );
  $export['admin_menu_source_settings'] = $strongarm;

  return $export;
}
