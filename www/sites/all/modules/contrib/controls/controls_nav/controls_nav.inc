<?php
/**
 * @file
 * Controls navigation - Provides a separate way of building a main navigation menu - build code.
 */

function _controls_nav() {
  $build = array(
    '#theme' => 'controls_nav',
    '#attributes' => array(),
    '#level' => 0,
    '#pre_render' => array('_controls_nav_main_pre_render'),
  );

  $nav_items = controls_get('navigation');

  // Remove any nav items this user can't access
  // and fill in the defaults for everything else
  // and set up the parent/child relationships
  foreach ($nav_items as $name => $control) {
    // Can this user access this?
    $router_item = menu_get_item($control['href']);
    if (!isset($router_item) || !$router_item['access']) {
      unset($nav_items[$name]);
    }

    // Defaults
    $control += array(
      'theme' => 'controls_nav_item',
      'title' => $router_item['title'],
      'options' => array(),
      'attributes' => array(),
      'weight' => 0,
      'extra' => '',
      'parent' => FALSE,
      'children' => array(),
      'detach children' => FALSE,
    );

    // Has this got a parent, make sure the parent knows.
    if ($parent = $control['parent']) {
      $nav_items[$parent]['children'][$name] = $control;
    }

    $nav_items[$name] = $control;
  }

  // Build the navigation renderable structure
  foreach ($nav_items as $name => $control) {

    // If this is a child item, skip it
    if ($control['parent']!==FALSE) {
      continue;
    }

    // Build the first level item
    $key = $control['#module'] . "_$name";
    $build[$key] = array(
      '#theme' => $control['theme'],
      '#title' => $control['title'],
      '#href' => $control['href'],
      '#options' => $control['options'],
      '#attributes' => $control['attributes'],
      '#weight' => $control['weight'],
      '#control' => $control,
    );

    // If there are no children skip the next bit
    if (empty($control['children'])) {
      continue;
    }

    $build[$key]['#children'] = array(
      '#theme' => 'controls_nav',
      '#attributes' => array(),
      '#level' => 1,
      '#pre_render' => array('_controls_nav_main_pre_render'),
    );

    // Add in child items
    foreach ($control['children'] as $kidname => $child) {
      if (!isset($child['attributes']['class'])) {
        $child['attributes']['class'] = array();
      }
      $child['attributes']['class'][] = 'second-level-item';
      $child['attributes']['class'][] = "child-of-$name";

      $build[$key]['#children'][$child['#module'] . "_$kidname"] = array(
        '#theme' => $child['theme'],
        '#title' => $child['title'],
        '#href' => $child['href'],
        '#options' => $child['options'],
        '#attributes' => $child['attributes'],
        '#weight' => isset($child['weight']) ? $child['weight'] : 0,
        '#control' => $child,
      );
    }

  }

  // Allow other modules to modify my structure
  drupal_alter('controls_nav', $build);
  return $build;
}

function _controls_nav_cache_clear() {
  // clear all block and page data which might include this block
  cache_clear_all('*', 'cache_block', TRUE);
  cache_clear_all('*', 'cache_page', TRUE);
  // Force my  menus to be rebuilt
  cache_clear_all('*', 'cache_controls_nav', TRUE);
}

/**
 * Page callback to clear the token registry caches.
 */
function controls_nav_flush_cache_callback() {
  if (!isset($_GET['token']) || !drupal_valid_token($_GET['token'], current_path())) {
    return MENU_NOT_FOUND;
  }

  _controls_nav_cache_clear();
  drupal_set_message(t('Controls Nav caches cleared.'));
  drupal_goto();
}


