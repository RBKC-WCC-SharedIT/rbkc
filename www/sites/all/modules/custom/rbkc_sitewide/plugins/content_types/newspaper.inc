<?php

$plugin = array(
  'single' => FALSE,
  'title' => t('Newspaper'),
  'description' => t('Configurable Newspaper content block'),
  'category' => t('RBKC'),
  'edit form' => 'rbkc_newspaper_edit_form',
  'render callback' => 'rbkc_newspaper_render',
  'admin info' => 'rbkc_newspaper_admin_info',
  'defaults' => array(
    'readmore' => 'Read the latest edition here',
    'newspaper_image' => '',
    'newspaper_body' => array('value' => '', 'format' => filter_default_format()),
  )
);

/**
 * 'admin info' callback for panel pane.
 */
function rbkc_newspaper_admin_info($subtype, $conf, $contexts) {
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
function rbkc_newspaper_edit_form($form, &$form_state) {
  form_load_include($form_state, 'inc', 'rbkc_sitewide', 'plugins/content_types/newspaper');

  $conf = $form_state['conf'];

  $form['readmore'] = array(
    '#title' => t('Readmore Text'),
    '#description' => t(''),
    '#type' => 'textfield',
    '#default_value' => $conf['readmore'],
    '#required' => TRUE,
  );
  $form['newspaper_image'] = array(
    '#type' => 'managed_file',
    '#name' => 'rbkc_newspaper_image',
    '#title' => t('Newspaper image'),
    '#size' => 40,
    '#description' => t("Please upload the image to be displayed on this newspaper block"),
    '#default_value' => $conf['newspaper_image'],
    '#upload_location' => 'public://'
  );
  $form['newspaper_body'] = array(
    '#type' => 'text_format',
    '#title' => t('Body'),
    '#default_value' => $conf['newspaper_body']['value'],
    '#format' => $conf['newspaper_body']['format'],
    '#weight' => 10,
    '#required' => TRUE,
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function rbkc_newspaper_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }

  if (isset($form_state['values']['newspaper_image'])) {
    if ($file = file_load($form_state['values']['newspaper_image'])) {
      if ($file->status !== FILE_STATUS_PERMANENT) {
        $file->status = FILE_STATUS_PERMANENT;
        file_save($file);
        file_usage_add($file, 'rbkc_sitewide', 'pane', $file->fid);
      }
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function rbkc_newspaper_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();
  $rawimage = file_load($conf['newspaper_image']);
  $breakpoints = picture_get_mapping_breakpoints(picture_mapping_load('rbkc'));
  $image = theme('picture', array('style_name' => 'banner', 'uri' => $rawimage->uri, 'breakpoints' => $breakpoints,));

  // initial content is blank
  $block->title = 'Royal Borough newspaper';
  $block->content = theme('rbkc_newspaper', array(
    'readmore' => $conf['readmore'],
    'newspaper_image' => $image,
    'newspaper_body'  => check_markup($conf['newspaper_body']['value'], $conf['newspaper_body']['format'], LANGUAGE_NONE),
    ));

  return $block;
}