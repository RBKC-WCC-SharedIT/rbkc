<?php

/**
 * @file
 * Panel plugin definition.
 */
$plugin = array(
  'title'    => t('RBKC Newsroom'),
  'category' => t('RBKC'),
  'icon'     => 'rbkc_newsroom.png',
  'theme'    => 'rbkc_newsroom',
  'css'      => 'rbkc_newsroom.css',
  'regions'  => array(
    // Regions in this panel
    'row_one_col_one' => t('Row One - Column One'),
    'row_one_col_two' => t('Row One - Column Two'),
    'row_two_col_one' => t('Row Two - Column One'),
    'row_two_col_two' => t('Row Two - Column Two'),
  ),
);
