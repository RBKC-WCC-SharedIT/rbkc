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
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
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
      8 => array(
        'name' => 'manualcrop_auto_reuse',
        'data' => array(
          'style_priority' => array(
            0 => 'manual_crop',
          ),
          'apply_all_effects' => 0,
          'fallback_style' => '',
        ),
        'weight' => -10,
      ),
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 400,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: rbkc_breakpoints_theme_rbkc_narrow_1x.
  $styles['rbkc_breakpoints_theme_rbkc_narrow_1x'] = array(
    'label' => 'rbkc_breakpoints_theme_rbkc_narrow_1x',
    'effects' => array(
      5 => array(
        'name' => 'manualcrop_auto_reuse',
        'data' => array(
          'style_priority' => array(
            0 => 'rbkc_breakpoints_theme_rbkc_mobile_1x',
            1 => 'manual_crop',
          ),
          'apply_all_effects' => 0,
          'fallback_style' => '',
        ),
        'weight' => -10,
      ),
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: rbkc_breakpoints_theme_rbkc_wide_1x.
  $styles['rbkc_breakpoints_theme_rbkc_wide_1x'] = array(
    'label' => 'rbkc_breakpoints_theme_rbkc_wide_1x',
    'effects' => array(
      2 => array(
        'name' => 'manualcrop_auto_reuse',
        'data' => array(
          'style_priority' => array(
            0 => 'rbkc_breakpoints_theme_rbkc_narrow_1x',
            1 => 'rbkc_breakpoints_theme_rbkc_mobile_1x',
            2 => 'manual_crop',
          ),
          'apply_all_effects' => 0,
          'fallback_style' => '',
        ),
        'weight' => 0,
      ),
    ),
  );

  return $styles;
}
