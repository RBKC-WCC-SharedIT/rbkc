<?php
/**
 * @file
 * Babcock menu - Controls the display of the menu at the top of the page - themes.
 */

function theme_controls_nav($variables) {
  $elements = $variables['elements'];

  $elements['#attributes']['class'][] = 'controls-nav';
  $elements['#attributes']['class'][] = 'controls-nav-level-' . $elements['#level'];

  if ($elements['#children'] == '') {
    $elements['#children'] = drupal_render_children($elements);
  }

  return '<ul' . drupal_attributes($elements['#attributes']) . '>' . $elements['#children'] . '</ul>';
}

function theme_controls_nav_item($variables) {

  $element = $variables['element'];
  $control = $element['#control'];

  $element['#children'] = is_array($element['#children']) ? drupal_render($element['#children']) : '';

  if (!isset($control['is_visible'])) {
    // Calculate this if it hasn't been done before
    $control['is_visible'] = _controls_is_visible($control);
  }

  if (!$control['is_visible']) {
    return '';
  }

  if (!isset($control['is_active'])) {
    // Calculate this if it hasn't been done before
    $control['is_active'] = _controls_is_active($control);
  }

  if ($control['is_active']) {
    $element['#attributes']['class'][] = $element['#options']['attributes']['class'][] = 'active';
  }

  $link = l($element['#title'], $element['#href'], $element['#options']) . $control['extra'];
  return ($link!='') ? '<li' . drupal_attributes($element['#attributes']) . '>' . $link . $element['#children'] . '</li>' : '';
}
