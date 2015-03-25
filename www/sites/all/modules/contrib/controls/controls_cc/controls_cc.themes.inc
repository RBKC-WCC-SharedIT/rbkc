<?php
/**
 * @file
 * Controls: Create content - Provides a user panel for accessing content creation pages - themes.
 */

function theme_controls_cc($variables) {
  $elements = $variables['elements'];

  $elements['#attributes']['class'][] = 'controls-cc';

  if ($elements['#children'] == '') {
    $elements['#children'] = drupal_render_children($elements);
  }

  return '<ul' . drupal_attributes($elements['#attributes']) . '>' . $elements['#children'] . '</ul>';
}

function theme_controls_cc_group($variables) {
  $elements = $variables['elements'];

  $elements['#attributes']['class'][] = 'controls-cc-group';

  if ($elements['#children'] == '') {
    $elements['#children'] = drupal_render_children($elements);
  }
  if (empty($elements['#children'])) {
    return '';
  }

  $header = '<h4 class="entity-type">' . $elements['#title'] . '</h4>';

  return "<li>$header<ul" . drupal_attributes($elements['#attributes']) . ">{$elements['#children']}</ul></li>";
}

function theme_controls_cc_item($variables) {

  $element = $variables['element'];
  $control = $element['#control'];

  $element['#children'] = is_array($element['#children']) ? drupal_render($element['#children']) : '';

  if (!isset($control['is_visible'])) {
    // Calculate this is it hasn't been done before
    $control['is_visible'] = _controls_is_visible($control);
  }

  if (!$control['is_visible']) {
    return '';
  }
  $element['#options'] += array('html' => TRUE);
  $element['#options'] += array('query' => drupal_get_destination());

  $link = l($element['#title'], $element['#href'], $element['#options']);
  return ($link!='') ? '<li' . drupal_attributes($element['#attributes']) . '>' . $link . $element['#children'] . '</li>' : '';
}
