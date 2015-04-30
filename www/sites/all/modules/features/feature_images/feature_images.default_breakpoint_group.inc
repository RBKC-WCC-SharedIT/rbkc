<?php
/**
 * @file
 * feature_images.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function feature_images_default_breakpoint_group() {
  $export = array();

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'rbkc';
  $breakpoint_group->name = 'RBKC';
  $breakpoint_group->breakpoints = array(
    0 => 'breakpoints.theme.rbkc.wide',
    1 => 'breakpoints.theme.rbkc.narrow',
    2 => 'breakpoints.theme.rbkc.mobile',
  );
  $breakpoint_group->type = 'theme';
  $breakpoint_group->overridden = 0;
  $export['rbkc'] = $breakpoint_group;

  return $export;
}
