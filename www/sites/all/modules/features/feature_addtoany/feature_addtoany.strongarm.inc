<?php
/**
 * @file
 * feature_addtoany.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_addtoany_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_additional_html';
  $strongarm->value = '<a class="a2a_button_facebook"></a>
<a class="a2a_button_twitter"></a>
';
  $export['addtoany_additional_html'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_additional_html_placement';
  $strongarm->value = 'before';
  $export['addtoany_additional_html_placement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_additional_js';
  $strongarm->value = 'a2a_config.track_links = \'bitly\';
a2a_config.track_links_key = \'rbkcwebmaster|R_326b58e755b047e2b12f15babc0547cc\'; // username|API key delimited by |
a2a_config.menu_type = "mail";
a2a_config.show_title = true;
a2a_config.templates = {
    email: {
        subject: "${title}",
        body: "I thought you might be interested in this link from RBKC:\\n${link}"
    }
};
a2a_config.templates = {
    twitter: "${title} ${link} via @RBKC"
};
a2a_config.templates = {
    facebook: "${title} ${link} by RBKC"
};';
  $export['addtoany_additional_js'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_buttons_size';
  $strongarm->value = '32';
  $export['addtoany_buttons_size'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_custom_image';
  $strongarm->value = '';
  $export['addtoany_custom_image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_display_in_nodecont';
  $strongarm->value = 1;
  $export['addtoany_display_in_nodecont'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_display_in_nodelink';
  $strongarm->value = 0;
  $export['addtoany_display_in_nodelink'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_display_in_rss';
  $strongarm->value = 0;
  $export['addtoany_display_in_rss'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_display_in_teasers';
  $strongarm->value = 0;
  $export['addtoany_display_in_teasers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_display_weight';
  $strongarm->value = '40';
  $export['addtoany_display_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_image';
  $strongarm->value = 'a2a_svg_32';
  $export['addtoany_image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_image_attributes';
  $strongarm->value = 'alt="Email"';
  $export['addtoany_image_attributes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_link_text';
  $strongarm->value = 'Email';
  $export['addtoany_link_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_nodetypes';
  $strongarm->value = array(
    'answer' => 'answer',
    'press_release' => 'press_release',
    'feed' => 0,
    'guide' => 0,
    'publication' => 0,
    'servicehub' => 0,
    'subhub' => 0,
    'survey' => 0,
    'topic' => 0,
  );
  $export['addtoany_nodetypes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_no_3p';
  $strongarm->value = 1;
  $export['addtoany_no_3p'] = $strongarm;

  return $export;
}
