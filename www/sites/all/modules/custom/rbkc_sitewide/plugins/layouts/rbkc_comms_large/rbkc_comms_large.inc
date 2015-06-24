<?php

/**
 * @file
 * Panel plugin definition.
 */
$plugin = array(
  'title'    => t('RBKC Comms Large'),
  'category' => t('RBKC'),
  'icon'     => 'rbkc_comms_large.png',
  'theme'    => 'rbkc_comms_large',
  'css'      => 'rbkc_comms_large.css',
  'regions'  => array(
    // Regions in this panel
    'comms_header' => t('Comms Header'),
    'comms_content'     => t('Comms content'),
  ),
);
