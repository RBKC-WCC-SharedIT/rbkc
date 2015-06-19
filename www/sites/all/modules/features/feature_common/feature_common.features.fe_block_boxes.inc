<?php
/**
 * @file
 * feature_common.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function feature_common_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Add the Govmetric snippet so that users can rate the page';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'govmetric';
  $fe_block_boxes->body = '<!-- WebMetric snippet starts here --><div class="gm_sidebar gm_sidebar_cnr" id="govmetric" style="line-height: initial"><a class="gm_sidebar_anchor" href="https://websurveys.govmetric.com/theme/gm/1611" rel="nofollow" target="_blank" title="please rate this page"><img alt="rating button" src="https://wsstatic.govmetric.com/imgs/triggers/cnr_rate.png"> </a></div>
<link href="https://wsstatic.govmetric.com/css/client/gm_sidebar_cnr.css" property="stylesheet" rel="stylesheet" type="text/css"><script type="text/javascript" src="https://wsstatic.govmetric.com/js/client/gm_sidebar.js"></script><script type="text/javascript" src="https://hitcounter.govmetric.com/1612"></script><!-- WebMetric snippet ends here -->';

  $export['govmetric'] = $fe_block_boxes;

  return $export;
}
