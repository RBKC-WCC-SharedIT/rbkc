<?php

/**
 * @file
 * Plugin to output search_title.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('RBKC Need To Menu'),
  'description' => t('Need To Menu Split into two UL lists'),
  'category' => t('RBKC'),
  'defaults' => array(),
  'render callback' => 'rbkc_sitewide_need_to_menu',
);

/**
 * Output function for the 'search_title' content type.
 */
function rbkc_sitewide_need_to_menu($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $links = menu_tree_all_data('menu-i-need-to');
  $link_count = count($links);
  $collection1 = array_slice($links, 0, intval($link_count / 2), true);
  $collection2 = array_diff_key($links, $collection1);

  $render1 = drupal_render(menu_tree_output($collection1));
  $render2 = drupal_render(menu_tree_output($collection2));

  $block->title = '';

  $block->content = '<div class="quicklinks">
            <div class="impact iconlinks">
              <div class="impact__inner group">
                <h2>I need to...</h2>' . $render1 . $render2 . '</div>
            </div>
            </div>';
  return $block;
}