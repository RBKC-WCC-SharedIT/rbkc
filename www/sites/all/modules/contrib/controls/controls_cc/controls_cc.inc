<?php
/**
 * @file
 * Controls: Create content - Provides a user panel for accessing content creation pages - build code.
 */

function _controls_cc() {
  $build = array(
    '#theme' => 'controls_cc',
    '#attributes' => array(),
    '#pre_render' => array('_controls_cc_main_pre_render'),
  );

  // Get the raw controls data
  $cc_items = controls_get('create_content');

  // Remove any create content items this user can't access
  // and fill in the defaults for everything else
  foreach ($cc_items as $name => $control) {
    // Can this user access this? If not, skip it
    $router_item = menu_get_item($control['href']);
    if (!isset($router_item) || !$router_item['access']) {
      unset($cc_items[$name]);
      continue;
    }

    // Defaults (entity_type is essential)
    $control += array(
      'theme' => 'controls_cc_item',
      'title' => $router_item['title'],
      'options' => array(),
      'attributes' => array(),
      'weight' => 0,
      'visible' => array(),
    );

    $cc_items[$name] = $control;
  }

  // Build the renderable structure
  foreach ($cc_items as $name => $control) {
    $key = "{$control['#module']}_$name";
    $entity_type = $control['entity_type'];

    if (!isset($build[$entity_type])) {
      $build[$entity_type] = array(
        '#theme' => 'controls_cc_group',
        '#title' => check_plain($entity_type),
      );
    }

    $build[$entity_type][$key] = array(
      '#theme' => $control['theme'],
      '#title' => $control['title'],
      '#href' => $control['href'],
      '#options' => $control['options'],
      '#attributes' => $control['attributes'],
      '#weight' => $control['weight'],
      '#control' => $control,
    );

  }

  // Allow other modules to modify this structure
  drupal_alter('controls_cc', $build);
  return $build;
}

function _controls_cc_cache_clear() {
  // clear all block and page data which might include this block
  cache_clear_all('*', 'cache_block', TRUE);
  cache_clear_all('*', 'cache_page', TRUE);
  // Force my content to be rebuilt
  cache_clear_all('*', 'cache_controls_cc', TRUE);
}

/**
 * Page callback to clear the token registry caches.
 */
function controls_cc_flush_cache_callback() {
  if (!isset($_GET['token']) || !drupal_valid_token($_GET['token'], current_path())) {
    return MENU_NOT_FOUND;
  }

  _controls_cc_cache_clear();
  drupal_set_message(t('Controls: Create Content cache cleared.'));
  drupal_goto();
}


