<?php

$plugin = array(
  'single' => FALSE,
  'title' => t('Twitter timeline'),
  'description' => t('Shows a twitter timeline with basic configuration options.'),
  'category' => t('RBKC'),
  'edit form' => 'rbkc_twitter_timeline_edit_form',
  'render callback' => 'rbkc_twitter_timeline_render',
  'admin info' => 'rbkc_twitter_timeline_admin_info',
  'defaults' => array(
    'show_social' => '',
    'username' => 'RBKC',
    'tweets_to_show' => 5,
    'widget_id' => '346591497258422273',
    'chrome' => '',
  )
);

/**
 * 'admin info' callback for panel pane.
 */
function rbkc_twitter_timeline_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = t('Showing @tweets_to_show tweets from <em>@@username</em>.', array(
      '@tweets_to_show' => $conf['tweets_to_show'],
      '@username' => $conf['username'],
    ));
    return $block;
  }
}

/**
 * 'Edit form' callback for the content type.
 */
function rbkc_twitter_timeline_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['show_social'] = array(
    '#type' => 'select',
    '#options' => drupal_map_assoc(array(t('Show'),t('Hide'))),
    '#title' => t('Show social links?'),
    '#default_value' => $conf['show_social'],
  );

  $form['widget_id'] = array(
    '#title' => t('Twitter Widget ID'),
    '#description' => t('The widget_id/application ID from your twitter account.'),
    '#type' => 'textfield',
    '#default_value' => $conf['widget_id'],
    '#required' => TRUE,
  );

  $form['username'] = array(
    '#title' => t('Twitter username'),
    '#description' => t('The username of the twitter account in which to pull the tweets from.'),
    '#type' => 'textfield',
    '#default_value' => $conf['username'],
    '#required' => TRUE,
  );

  $form['tweets_to_show'] = array(
    '#title' => t('Number of tweets to show'),
    '#description' => t('Used to control the number of tweets shown on the page initially. Defaults to 5.'),
    '#type' => 'select',
    '#options' => drupal_map_assoc(range(3, 12)),
    '#default_value' => $conf['tweets_to_show'],
    '#required' => TRUE,
  );

  $form['chrome'] = array(
    '#title' => t('Control the widget layout'),
    '#description' => t('Control the widget layout and chrome by using the data-chrome="nofooter transparent" attribute on the embed code. Use a space-separated set of the following options'),
    '#type' => 'checkboxes',
    '#options' => array(
      'noheader' => t('No header'),
      'nofooter' => t('No footer'),
      'noborders' => t('No borders'),
      'noscrollbar' => t('No scrollbar'),
      'transparent' => t('Transparent'),
    ),
    '#default_value' => $conf['chrome'],
    '#required' => TRUE,
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function rbkc_twitter_timeline_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function rbkc_twitter_timeline_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();
  $render_icons = NULL;
  $twitter_icon = '<div class="twitter-header"></div>';
  if ($conf['show_social'] == 'Show') {
    $twitter_icon = '';
    $social_icons = array(
      'twitter' => array('link' => 'http://uk.sitestat.com/rbkc/rbkc/s?Twitter&ns_type=clickout', 'icon' => 'tweeter'),
      'flickr' => array('link' => 'http://uk.sitestat.com/rbkc/rbkc/s?Flickr&ns_type=clickout', 'icon' => 'flickr'),
      'facebook' => array('link' => 'http://uk.sitestat.com/rbkc/rbkc/s?Facebook&ns_type=clickout', 'icon' => 'facebook'),
      'youtube' => array('link' => 'http://uk.sitestat.com/rbkc/rbkc/s?Youtube&ns_type=clickout', 'icon' => 'youtube'),
    );
    $path = drupal_get_path('module','rbkc_sitewide');
    $path = $path . '/plugins/content_types/images/';
    $render_icons = '';
    foreach ($social_icons as $icon) {
      $render_icons .= '<span>' . l(theme('image', array('path' => $path . $icon['icon'])),$icon['link'], array('html' => TRUE)) . '</span>';
    }
  }

  // initial content is blank
  $block->title = '';
  // Include twitter javascript - by linking to the external file.
  drupal_add_js('//platform.twitter.com/widgets.js', 'external');
  $chrome = array();
  foreach ($conf['chrome'] as $option) {
    $chrome[] = check_plain($option);
  }
  $block->content = array(
    '#prefix' => $twitter_icon . '<section id="socialMedia"><h2>' . t('Social media') . '<span class="soc">' . $render_icons . '</span></h2></section>',
    '#type' => 'link',
    '#title' => t('Tweets by @username', array('@username' => $conf['username'])),
    '#href' => check_url('https://twitter.com/' . $conf['username']),
    '#options' => array(
      'attributes' => array(
        'class' => array('twitter-timeline'),
        'data-widget-id' => check_plain($conf['widget_id']),
        'data-chrome' => $chrome,
        'data-tweet-limit' => check_plain($conf['tweets_to_show']),
        'data-screen-name' => check_plain($conf['username']),
      ),
      'html' => FALSE,
    ),
  );

  if (!empty($conf['chrome'])) {
    $options = array();

    foreach ($conf['chrome'] as $option => $status) {
      if ($status) {
        $options[] = $option;
      }
    }

    if (count($options)) {
      $block->content['#options']['attributes']['data-chrome'] = implode(' ', $options);
    }
  }
  return $block;
}