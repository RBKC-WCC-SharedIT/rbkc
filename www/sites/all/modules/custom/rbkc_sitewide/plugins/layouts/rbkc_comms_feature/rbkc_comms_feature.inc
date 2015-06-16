<?php
/**
 * @file
 * Layout definition for LEP - 1 col.
 */

/**
 * Panel plugin definition for LEP - 1 col layout.
 */
$plugin = array(
  'title'    => t('RBKC Comms Feature'),
  'category' => t('RBKC'),
  'icon'     => 'rbkc_comms_feature.png',
  'theme'    => 'rbkc_comms_feature',
  'css'      => 'rbkc_comms_feature.css',
  'regions'  => array(
    // Regions in this panel
    'comms_header'  => t('Comms Header'),
    'comms_content' => t('Comms content'),
  ),
);
