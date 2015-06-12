<?php

$plugin = array(
  'single' => FALSE,
  'title' => t('Feature Comms'),
  'description' => t('Configurable feature comms content block'),
  'category' => t('RBKC'),
  'edit form' => 'rbkc_feature_comms_edit_form',
  'render callback' => 'rbkc_feature_comms_render',
  'admin info' => 'rbkc_feature_comms_admin_info',
  'defaults' => array(
    'comms_label' => 'Events',
    'comms_image' => '',
    'comms_title' => '',
    'comms_body' => '',
    'comms_link' => '',
  )
);

/**
 * 'admin info' callback for panel pane.
 */
function rbkc_feature_comms_admin_info($subtype, $conf, $contexts) {
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
function rbkc_feature_comms_edit_form($form, &$form_state) {
  form_load_include($form_state, 'inc', 'rbkc_sitewide', 'plugins/content_types/feature_comms');

  $conf = $form_state['conf'];

  $form['comms_label'] = array(
    '#title' => t('Comms Label'),
    '#description' => t(''),
    '#type' => 'textfield',
    '#default_value' => $conf['comms_label'],
    '#required' => TRUE,
  );
  $form['comms_image'] = array(
    '#type' => 'managed_file',
    '#name' => 'rbkc_feature_comms_image',
    '#title' => t('Comms image'),
    '#size' => 40,
    '#description' => t("Please upload the image to be displayed on this feature comm"),
    '#upload_location' => 'public://'
  );
  $form['comms_title'] = array(
    '#title' => t('Title'),
    '#description' => t(''),
    '#type' => 'textfield',
    '#default_value' => $conf['comms_title'],
    '#required' => TRUE,
  );
  $form['comms_body'] = array(
    '#title' => t('Body'),
    '#description' => t(''),
    '#type' => 'textarea',
    '#default_value' => $conf['comms_body'],
    '#required' => TRUE,
  );
  $form['comms_link'] = array(
    '#title' => t('Link'),
    '#description' => t(''),
    '#type' => 'textfield',
    '#default_value' => $conf['comms_link'],
    '#required' => TRUE,
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function rbkc_feature_comms_edit_form_submit($form, &$form_state) {
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
function rbkc_feature_comms_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();
  $rawimage = file_load($conf['comms_image']);
  $breakpoints = picture_get_mapping_breakpoints(picture_mapping_load('rbkc'));
  $image = theme('picture', array('style_name' => 'banner', 'uri' => $rawimage->uri, 'breakpoints' => $breakpoints,));

  // initial content is blank
  $block->title = '';
  $block->content = theme('rbkc_feature_comms', array(
    'comms_label' => $conf['comms_label'],
    'comms_image' => $image,
    'comms_title' => $conf['comms_title'],
    'comms_body'  => $conf['comms_body'],
    'comms_link'  => $conf['comms_link'],
    ));

  return $block;
}