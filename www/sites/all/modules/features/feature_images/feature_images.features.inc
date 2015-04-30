<?php
/**
 * @file
 * feature_images.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_images_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "scald" && $api == "context_config") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function feature_images_image_default_styles() {
  $styles = array();

  // Exported image style: manual_crop.
  $styles['manual_crop'] = array(
    'label' => 'Manual Crop',
    'effects' => array(
      1 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '',
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'manual_crop',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: rbkc_breakpoints_theme_rbkc_mobile_1x.
  $styles['rbkc_breakpoints_theme_rbkc_mobile_1x'] = array(
    'label' => 'rbkc_breakpoints_theme_rbkc_mobile_1x',
    'effects' => array(
      4 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '',
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'manual_crop',
        ),
        'weight' => 0,
      ),
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 400,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: rbkc_breakpoints_theme_rbkc_narrow_1x.
  $styles['rbkc_breakpoints_theme_rbkc_narrow_1x'] = array(
    'label' => 'rbkc_breakpoints_theme_rbkc_narrow_1x',
    'effects' => array(
      3 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '',
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'manual_crop',
        ),
        'weight' => 0,
      ),
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: rbkc_breakpoints_theme_rbkc_wide_1x.
  $styles['rbkc_breakpoints_theme_rbkc_wide_1x'] = array(
    'label' => 'rbkc_breakpoints_theme_rbkc_wide_1x',
    'effects' => array(
      2 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '',
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'manual_crop',
        ),
        'weight' => 0,
      ),
    ),
  );

  return $styles;
}
