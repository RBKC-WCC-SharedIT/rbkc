<?php
/**
 * @file
 * Controls navigation - Provides a separate way of building a main navigation menu - registry.
 */

/**
 * Implements hook_theme().
 */
function _controls_nav_theme() {
  return array(
    'controls_nav' => array(
      'render element' => 'elements',
      'file' => 'controls_nav.themes.inc',
    ),
    'controls_nav_item' => array(
      'render element' => 'element',
      'file' => 'controls_nav.themes.inc',
    ),
  );
}

/**
 * Implements hook_menu().
 */
function _controls_nav_menu() {
  $items = array();

  // Admin menu callback to clear Controls Nav cache.
  $items['controls_nav/flush-cache'] = array(
    'page callback' => 'controls_nav_flush_cache_callback',
    'access arguments' => array('flush caches'),
    'type' => MENU_CALLBACK,
    'file' => 'controls_nav.inc',
  );

  return $items;
}


/**
 * Implements hook_admin_menu_output_alter().
 *
 * Adds the cache clear function to the admin menu
 * - note the use of the token for security.
 */
function _controls_nav_admin_menu_output_alter(&$content) {
  $content['icon']['icon']['flush-cache']['controls_nav'] = array(
    '#title' => t('Controls: Navigation'),
    '#href' => 'controls_nav/flush-cache',
    '#options' => array(
      'query' => drupal_get_destination() + array('token' => drupal_get_token('controls_nav/flush-cache')),
    ),
  );
}
