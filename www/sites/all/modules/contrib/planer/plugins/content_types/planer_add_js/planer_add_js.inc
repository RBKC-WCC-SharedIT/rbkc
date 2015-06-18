<?php
/**
 * @file
 * Plugin to output JS using drupal_add_js.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Add JS'),
  'description' => t('Add JS to a pane.'),
  'category' => t('Planer'),
  'defaults' => array(),
);

/**
 * Output function.
 */
function planer_planer_add_js_content_type_render($subtype, $conf, $panel_args, $context) {
  if (!isset($conf['path']) || !file_exists($conf['path'])) {
    return;
  }
  $path = $conf['path'];

  $block = new stdClass();
  $block->module  = 'planer';
  $block->delta   = 'planer_add_js';
  $block->title   = '';
  // Return a renderable array.
  // We want to avoid adding any markup and let the theme functions take care of all that.
  $block->content = array(
    '#attached' => array(
      'js' => array(
        array(
          'data' => $path,
          'options' => array(
            'group' => JS_LIBRARY,
            'preprocess' => TRUE,
          ),
        ),
      ),
    ),
  );
  return $block;
}

/**
 * Returns the administrative title.
 */
function planer_planer_add_js_content_type_admin_title($subtype, $conf) {
  return t('Add JS');
}

function planer_planer_add_js_content_type_admin_info($subtype, $conf) {
  $block = new stdClass;
  $block->title = 'drupal_add_js()';
  $block->content = isset($conf['path']) ? $conf['path'] : t('No path set.');
  return $block;
}

/**
 * Returns an edit form for custom type settings.
 */
function planer_planer_add_js_content_type_edit_form($form, &$form_state) {
  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);
  $form['path'] = array(
    '#type' => 'textfield',
    '#title' => 'JavaScript to include',
    '#default_value' => $form_state['conf']['path'],
    '#description' => t('Path needs to be relative to the Drupal root.'),
    '#required' => TRUE,
  );
  return $form;
}

/**
 * Submit handler for the custom type settings form.
 */
function planer_planer_add_js_content_type_edit_form_submit($form, &$form_state) {
  foreach ($form_state['values'] as $k => $v) {
    if (!empty($form_state['values'][$k])) {
      $form_state['conf'][$k] = $form_state['values'][$k];
    }
  }
}