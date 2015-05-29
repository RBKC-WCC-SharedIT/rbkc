<?php

$plugin = array(
  'single' => FALSE,
  'title' => t('Newsletters'),
  'description' => t('Configurable Newsletters content block'),
  'category' => t('RBKC'),
  'edit form' => 'rbkc_newsletters_edit_form',
  'render callback' => 'rbkc_newsletters_render',
  'admin info' => 'rbkc_newsletters_admin_info',
  'defaults' => array(
    'intro' => '',
  )
);

/**
 * 'admin info' callback for panel pane.
 */
function rbkc_newsletters_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = '';
    return $block;
  }
}

/**
 * 'Edit form' callback for the content type.
 */
function rbkc_newsletters_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['intro'] = array(
    '#title' => t('Intro Text'),
    '#description' => t(''),
    '#type' => 'textarea',
    '#default_value' => $conf['intro'],
    '#required' => TRUE,
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function rbkc_newsletters_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function rbkc_newsletters_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  $block->title = '';
  $block->content = theme('rbkc_news_comms', array(
    'intro' => $conf['intro'],
    ));

  return $block;
}