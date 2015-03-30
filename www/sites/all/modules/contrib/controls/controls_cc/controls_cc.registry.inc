<?php
/**
 * @file
 * Controls navigation - Provides a separate way of building a main navigation menu - registry.
 */

/**
 * Implements hook_theme().
 */
function _controls_cc_theme() {
  return array(
    'controls_cc' => array(
      'render element' => 'elements',
      'file' => 'controls_cc.themes.inc',
    ),
    'controls_cc_group' => array(
      'render element' => 'elements',
      'file' => 'controls_cc.themes.inc',
    ),
    'controls_cc_item' => array(
      'render element' => 'element',
      'file' => 'controls_cc.themes.inc',
    ),
  );
}

/**
 * Implements hook_menu().
 */
function _controls_cc_menu() {
  $items = array();

  // Admin menu callback to clear Controls Nav cache.
  $items['controls_cc/flush-cache'] = array(
    'page callback' => 'controls_cc_flush_cache_callback',
    'access arguments' => array('flush caches'),
    'type' => MENU_CALLBACK,
    'file' => 'controls_cc.inc',
  );

  return $items;
}

/**
 * Implements hook_permission().
 */
function _controls_cc_permission() {
  return array(
    'access controls create content' => array(
      'title' => t('Access Controls: Create Content panel'),
      'description' => t('Allows the current user access to the panel for quick access to content creation.'),
    ),
  );
}


/**
 * Implements hook_admin_menu_output_alter().
 *
 * Adds the cache clear function to the admin menu
 * - note the use of the token for security.
 */
function _controls_cc_admin_menu_output_alter(&$content) {
  $content['icon']['icon']['flush-cache']['controls_cc'] = array(
    '#title' => t('Controls: Create content'),
    '#href' => 'controls_cc/flush-cache',
    '#options' => array(
      'query' => drupal_get_destination() + array('token' => drupal_get_token('controls_cc/flush-cache')),
    ),
  );
}
