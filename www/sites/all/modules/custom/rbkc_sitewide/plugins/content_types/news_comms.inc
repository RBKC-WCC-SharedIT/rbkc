<?php

$plugin = array(
  'single' => FALSE,
  'title' => t('News Comms'),
  'description' => t('Configurable news comms content block'),
  'category' => t('RBKC'),
  'edit form' => 'rbkc_news_comms_edit_form',
  'render callback' => 'rbkc_news_comms_render',
  'admin info' => 'rbkc_news_comms_admin_info',
  'defaults' => array(
    'comms_label' => 'Latest news',
    'comms_image' => '',
    'itemone_title' => '',
    'itemone_body' => '',
    'itemone_link' => '',
    'itemtwo_title' => '',
    'itemtwo_body' => '',
    'itemtwo_link' => '',
    'itemthree_title' => '',
    'itemthree_body' => '',
    'itemthree_link' => '',
  )
);

/**
 * 'admin info' callback for panel pane.
 */
function rbkc_news_comms_admin_info($subtype, $conf, $contexts) {
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
function rbkc_news_comms_edit_form($form, &$form_state) {
  form_load_include($form_state, 'inc', 'rbkc_sitewide', 'plugins/content_types/news_comms');

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
    '#name' => 'rbkc_news_comms_image',
    '#title' => t('Comms image'),
    '#description' => t("Please upload the image to be displayed on this news comm."),
    '#default_value' => $conf['comms_image'],
    '#upload_location' => 'public://'
  );

  $items = array('itemone', 'itemtwo', 'itemthree');
  foreach($items as $item) {
    $form[$item] = array(
      '#type' => 'fieldset',
      '#title' => t($item),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form[$item][$item . '_title'] = array(
      '#title' => t('Title'),
      '#description' => t(''),
      '#type' => 'textfield',
      '#default_value' => $conf[$item . '_title'],
      '#required' => FALSE,
    );
    $form[$item][$item . '_body'] = array(
      '#title' => t('Body'),
      '#description' => t(''),
      '#type' => 'textarea',
      '#default_value' => $conf[$item . '_body'],
      '#required' => FALSE,
    );
    $form[$item][$item . '_link'] = array(
      '#title' => t('Link'),
      '#description' => t(''),
      '#type' => 'textfield',
      '#default_value' => $conf[$item . '_link'],
      '#required' => FALSE,
    );
  }

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function rbkc_news_comms_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }

  if (isset($form_state['values']['comms_image'])) {
    if ($file = file_load($form_state['values']['comms_image'])) {
      if ($file->status !== FILE_STATUS_PERMANENT) {
        $file->status = FILE_STATUS_PERMANENT;
        file_save($file);
      }
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function rbkc_news_comms_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();
  $rawimage = file_load($conf['comms_image']);

  $image = '';
  if (FALSE !== $rawimage) {
    $breakpoints = picture_get_mapping_breakpoints(picture_mapping_load('rbkc'));
    $image = theme('picture', array('style_name' => 'banner', 'uri' => $rawimage->uri, 'breakpoints' => $breakpoints,));
  }

  $items = array('itemone', 'itemtwo', 'itemthree');
  foreach ($items as $item) {
    $news[$item] = array(
      'title' => $conf[$item . '_title'],
      'body' => $conf[$item . '_body'],
      'link' => $conf[$item . '_link'],
    );
  }

  $block->title = '';
  $block->content = theme('rbkc_news_comms', array(
    'comms_label' => $conf['comms_label'],
    'comms_image' => $image,
    'news' => $news,
    ));

  return $block;
}