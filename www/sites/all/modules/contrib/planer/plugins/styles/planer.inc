<?php
/**
 * @file
 * Style plugin for Planer.
 */

$plugin = array(
  'title' => t('Planer'),
  'description' => t('A plainer style of panel.'),

  // Region.
  'render region' => 'planer_render_region',
  'settings form' => 'planer_region_settings_form',
  'settings form submit' => 'planer_pane_settings_form_submit',

  // Pane.
  'render pane' => 'planer_render_pane',
  'pane settings form' => 'planer_pane_settings_form',
  'pane settings form submit' => 'planer_pane_settings_form_submit',
);

/**
 * Region settings form.
 */
function planer_region_settings_form($settings, $display, $pid, $type, $form_state) {
  $form = array();

  $wrappers = array(
    'region_wrapper' => array(
      'title' => 'Wrapper',
      'weight' => 0,
    ),
  );

  $form = planer_wrappers_form($wrappers, $settings);

  $form['separator']['active'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add separator'),
    '#description' => t('Enable/disable separator between panes.'),
    '#default_value' => $settings['separator']['active'],
  );
  $form['separator']['element_type'] = array(
    '#title' => t('HTML element'),
    '#type' => 'textfield',
    '#size' => '10',
    '#default_value' => $settings['separator']['element_type'],
    '#dependency' => array(
      'edit-settings-separator-active' => array(1),
    ),
    '#tree' => TRUE,
  );
  $form['separator']['show_css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create a CSS class'),
    '#default_value' => !empty($settings['separator']['show_css']),
    '#dependency' => array(
      'edit-settings-separator-active' => array(TRUE),
    ),
    '#tree' => TRUE,
  );
  $form['separator']['element_class'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS class'),
    '#default_value' => $settings['separator']['element_class'],
    '#dependency' => array(
      'edit-settings-separator-show-css' => array(TRUE),
      'edit-settings-separator-active' => array(TRUE),
    ),
    '#dependency_count' => 2,
    '#tree' => TRUE,
  );

  return $form;
}

/**
 * Render region.
 */
function theme_planer_render_region($vars) {
  $settings = $vars['settings'];
  $output = '';
  $separator = '';

  // Region wrapper.
  if (isset($settings['region_wrapper'])) {
    $wrapper = $settings['region_wrapper'];
    $vars['wrapper_type'] = check_plain($wrapper['type']);
  }

  if(!empty($vars['wrapper_type'])){
    $vars['attributes_array'] = array();
    $vars['classes_array'] = array();

    if ($wrapper['class_enable'] && !empty($wrapper['class'])) {
      $vars['classes_array'][] = $wrapper['class'];
      $vars['attributes_array']['class'] = $wrapper['class'];
    }

    if (!empty($wrapper['attributes_array'])) {
      $vars['attributes_array'] = array_merge((array) $vars['attributes_array'], $wrapper['attributes_array']);
    }
  }

  // Pane separator.
  if (!empty($settings['separator']) && $settings['separator']['active'] === 1) {
    $attributes = array();

    if (!empty($settings['separator']['show_css']) && !empty($settings['separator']['element_class'])) {
      $attributes['class'] = $settings['separator']['element_class'];
    }

    $separator = "<{$settings['separator']['element_type']}" . drupal_attributes($attributes) . "></{$settings['separator']['element_type']}>";
  }

  $output = implode($separator, $vars['panes']);

  drupal_alter('planer_region', $output, $vars);

  // Add the wrapper.

  if (!empty($vars['wrapper_type'])) {
    $prefix = '<' . check_plain($vars['wrapper_type']);
    if (!empty($vars['attributes_array'])){
      $prefix .= drupal_attributes($vars['attributes_array']);
    }
    $prefix .= '>';
    $suffix = '</' . $vars['wrapper_type'] . '>';

    $output = $prefix . $output . $suffix;
  }

  return $output;
}

/**
 * Pane settings form.
 */
function planer_pane_settings_form($settings) {

  $form = array();

  // No reason why this couldn't be expanded.
  // I'm sure we could have wrappers of wrappers if we wanted to.
  $wrappers = array(
    'element_wrapper' => array(
      'title' => 'Wrapper',
      'weight' => 0,
    ),
    'element_title' => array(
      'title' => 'Title',
      'weight' => 1,
    ),
    'element_content' => array(
      'title' => 'Content',
      'weight' => 2,
    ),
  );

  $form = planer_wrappers_form($wrappers, $settings);

  return $form;
}

/**
 * Returns a generic from section for a wrapper.
 */
function planer_wrappers_form($wrappers, $settings) {
  $form = array();

  foreach ($wrappers as $wrapper => $wrapper_settings) {
    $wrapper_id = str_replace('_', '-', $wrapper);
    $form[$wrapper] = array(
      '#type' => 'fieldset',
      '#title' => t($wrapper_settings['title']),
      '#weight' => $wrapper_settings['weight'] ? $wrapper_settings['weight'] : 0,
      '#collapsible' => FALSE,
    );
    $form[$wrapper]['type'] = array(
      '#title' => t('HTML element'),
      '#type' => 'textfield',
      '#size' => '10',
      '#default_value' => $settings[$wrapper]['type'],
      '#fieldset' => $wrapper,
    );
    $form[$wrapper]['add_default_classes'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add default classes'),
      '#description' => t('If checked default classes will be added on this element. Without default classes contextual links won\'t work.'),
      '#default_value' => isset($settings[$wrapper]['add_default_classes']) ? $settings[$wrapper]['add_default_classes'] : FALSE,
      '#states' => array(
         'visible' => array(
           '#edit-settings-' . $wrapper_id . '-type' => array('filled' => TRUE),
         ),
       ),
      '#fieldset' => $wrapper,
    );
    $form[$wrapper]['class_enable'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add CSS class(es)'),
      '#default_value' => !empty($settings[$wrapper]['class']),
      '#states' => array(
         'visible' => array(
           '#edit-settings-' . $wrapper_id . '-type' => array('filled' => TRUE),
         ),
       ),
      '#fieldset' => $wrapper,
    );
    $form[$wrapper]['class'] = array(
      '#type' => 'textfield',
      '#title' => t('CSS class(es)'),
      '#default_value' => $settings[$wrapper]['class'],
      '#states' => array(
         'visible' => array(
           '#edit-settings-' . $wrapper_id . '-type' => array('filled' => TRUE),
           '#edit-settings-' . $wrapper_id . '-class-enable' => array('checked' => TRUE),
         ),
       ),
      '#fieldset' => $wrapper,
    );
    $form[$wrapper]['attributes_enable'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add additional attribute(s)'),
      '#default_value' => $settings[$wrapper]['attributes_enable'],
      '#states' => array(
         'visible' => array(
           '#edit-settings-' . $wrapper_id . '-type' => array('filled' => TRUE),
         ),
       ),
      '#fieldset' => $wrapper,
    );
    $form[$wrapper]['attributes'] = array(
      '#title' => t('Additional attributes'),
      '#type' => 'textarea',
      '#rows' => '3',
      '#default_value' => $settings[$wrapper]['attributes'],
      '#states' => array(
         'visible' => array(
           '#edit-settings-' . $wrapper_id . '-type' => array('filled' => TRUE),
           '#edit-settings-' . $wrapper_id . '-attributes-enable' => array('checked' => TRUE),
         ),
       ),
      '#fieldset' => $wrapper,
      '#description' => t('Write the full attribute, one per line.<br />e.g. id=main'),
    );
  }
  return $form;
}

/**
 * Pane settings form submit handler.
 */
function planer_pane_settings_form_submit($form, &$settings, $form_state) {

  foreach ($settings as &$setting) {
    if ($setting['attributes_enable'] && !empty($setting['attributes'])) {
      $setting['attributes_array'] = array();
      // Attributes should be saved as one attribute per line.
      // Explode and see how we go.
      // We want to end up with a nice array for drupal_attributes.
      $setting['attributes_array'] = planer_extract_attributes($setting['attributes']);
    }
  }
}

/**
 * Preprocess variables for semantic-panels-pane.tpl.php
 */
function template_preprocess_planer_pane(&$vars) {
  // Make $vars contain all the stuff that the normal panels_pane has.
  template_preprocess_panels_pane($vars);

  $pane_semantic_settings = $vars['settings'];

  // Title wrapper.
  $vars['title_html'] = '';

  if ($vars['title']) {
    $element_data = array(
      'content' => $vars['title'],
      'default_type' => 'h2',
      'default_classes' => 'pane-title',
    );

    $vars['title_html'] = _planer_get_html('element_title', $element_data, $pane_semantic_settings);
  }

  // Content wrapper.
  $vars['content_html'] = '';

  if ($vars['content']) {
    $element_data = array(
      'content' => $vars['content'],
      'default_type' => 'div',
      'default_classes' => 'pane-content',
    );

    $vars['content_html'] = _planer_get_html('element_content', $element_data, $pane_semantic_settings);
  }

  // Full pane wrapper.
  $vars['wrapper_type'] = _planer_get_type($pane_semantic_settings['element_wrapper']['type']);

  if(!empty($vars['wrapper_type'])){

    if (!$vars['settings']['element_wrapper']['add_default_classes']) {
      $vars['classes_array'] = array();
    }

    if ($pane_semantic_settings['element_wrapper']['class_enable'] && !empty($pane_semantic_settings['element_wrapper']['class'])) {
      $vars['classes_array'][] = $pane_semantic_settings['element_wrapper']['class'];
    }

    if (!empty($pane_semantic_settings['element_wrapper']['attributes_array'])) {
      $vars['attributes_array'] = array_merge((array) $vars['attributes_array'], $pane_semantic_settings['element_wrapper']['attributes_array']);
    }

  }
}

/**
 * Render pane.
 */
function theme_planer_render_pane($vars) {
  return theme('planer_pane', $vars);
}

/**
 * Parses a string of attributes into an array.
 *
 * @param $string
 *   The list of allowed values in string format described in
 *   list_allowed_values_string().
 *
 * @return
 *   The array of extracted key/value pairs, or NULL if the string is invalid.
 */
function planer_extract_attributes($string) {
  $values = array();

  $list = explode("\n", $string);
  $list = array_map('trim', $list);
  $list = array_filter($list, 'strlen');

  foreach ($list as $position => $text) {
    $value = $key = FALSE;

    // Check for an explicit key.
    $matches = array();
    if (preg_match('/(.*)\=(.*)/', $text, $matches)) {
      $key = filter_xss(trim($matches[1]));
      $value = filter_xss(trim($matches[2]));
    }
    else {
      return;
    }

    $values[$key] = $value;
  }

  return $values;
}