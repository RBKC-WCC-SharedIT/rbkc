<?php
/**
 * @file
 * feature_images.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function feature_images_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'RBKC';
  $picture_mapping->machine_name = 'rbkc';
  $picture_mapping->breakpoint_group = 'rbkc';
  $picture_mapping->mapping = array(
    'breakpoints.theme.rbkc.wide' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'rbkc_breakpoints_theme_rbkc_wide_1x',
      ),
    ),
    'breakpoints.theme.rbkc.narrow' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'rbkc_breakpoints_theme_rbkc_narrow_1x',
      ),
    ),
    'breakpoints.theme.rbkc.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'rbkc_breakpoints_theme_rbkc_mobile_1x',
      ),
    ),
  );
  $export['rbkc'] = $picture_mapping;

  return $export;
}
