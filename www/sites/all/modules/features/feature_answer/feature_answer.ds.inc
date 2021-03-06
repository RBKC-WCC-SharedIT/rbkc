<?php
/**
 * @file
 * feature_answer.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function feature_answer_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|answer|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'answer';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|answer|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|answer|teaser_large';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'answer';
  $ds_fieldsetting->view_mode = 'teaser_large';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|answer|teaser_large'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|answer|teaser_medium';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'answer';
  $ds_fieldsetting->view_mode = 'teaser_medium';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|answer|teaser_medium'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function feature_answer_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|answer|teaser_large';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'answer';
  $ds_layout->view_mode = 'teaser_large';
  $ds_layout->layout = 'panels-rbkc_comms_large';
  $ds_layout->settings = array(
    'regions' => array(
      'comms_content' => array(
        0 => 'title',
        1 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'comms_content',
      'body' => 'comms_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'comms_header' => 'div',
      'comms_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|answer|teaser_large'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|answer|teaser_medium';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'answer';
  $ds_layout->view_mode = 'teaser_medium';
  $ds_layout->layout = 'panels-rbkc_comms_feature';
  $ds_layout->settings = array(
    'regions' => array(
      'comms_content' => array(
        0 => 'title',
        1 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'comms_content',
      'body' => 'comms_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'comms_header' => 'div',
      'comms_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|answer|teaser_medium'] = $ds_layout;

  return $export;
}
