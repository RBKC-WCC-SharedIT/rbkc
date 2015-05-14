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
  'title' => t('RBKC Services Menu'),
  'description' => t('Services Menu Split into two UL lists'),
  'category' => t('RBKC'),
  'defaults' => array(),
  'render callback' => 'rbkc_sitewide_services_menu',
);

/**
 * Output function for the 'search_title' content type.
 */
function rbkc_sitewide_services_menu($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $links = menu_tree_all_data('drop-down-service-menu');
  $link_count = count($links);
  $collection1 = array_slice($links, 0, intval($link_count / 2), true);
  $collection2 = array_diff_key($links, $collection1);

  $render1 = drupal_render(menu_tree_output($collection1));
  $render2 = drupal_render(menu_tree_output($collection2));

  $block->title = '';

  $block->content = '<div class="servicelist" id="services"><div class="impact">
<div class="impact__inner group">
        <h2>Services</h2>
        <nav role="navigation">' . $render1 . $render2 . '<a class="servicelist__viewall" href="http://www.rbkc.gov.uk/services.aspx"><span>View more services</span></a>
        </nav>
    </div>
</div>
</div>';
  return $block;
}