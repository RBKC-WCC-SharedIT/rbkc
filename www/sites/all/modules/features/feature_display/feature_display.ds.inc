<?php
/**
 * @file
 * feature_display.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function feature_display_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser_large';
  $ds_view_mode->label = 'Teaser Large';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['teaser_large'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser_medium';
  $ds_view_mode->label = 'Teaser Medium';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['teaser_medium'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser_small';
  $ds_view_mode->label = 'Teaser Small';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['teaser_small'] = $ds_view_mode;

  return $export;
}
