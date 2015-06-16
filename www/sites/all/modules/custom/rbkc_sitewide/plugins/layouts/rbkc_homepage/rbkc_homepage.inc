<?php
/**
 * @file
 * Layout definition for LEP - 1 col.
 */

/**
 * Panel plugin definition for LEP - 1 col layout.
 */
$plugin = array(
  'title'    => t('RBKC Homepage'),
  'category' => t('RBKC'),
  'icon'     => 'rbkc_homepage.png',
  'theme'    => 'rbkc_homepage',
  'css'      => 'rbkc_homepage.css',
  'regions'  => array(
    // Regions in this panel
    'menu'        => t('Menus'),
    'content'     => t('Main content'),
    'comms'       => t('Comms'),
    'local_life'  => t('Local Life'),
    'presstweet'  => t('Press / Tweet'),
  ),
);
