<?php
/**
 * @file
 * feature_display.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function feature_display_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'homepage';
  $page->task = 'page';
  $page->admin_title = 'Homepage';
  $page->admin_description = '';
  $page->path = 'welcome';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_homepage__panel_context_7f971c8b-fa7b-495f-9a2b-0612e760e0ee';
  $handler->task = 'page';
  $handler->subtask = 'homepage';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'rbkc_homepage';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'content' => NULL,
      'bottom' => NULL,
      'local_life' => NULL,
      'presstweet' => NULL,
      'menu' => array(
        'region_wrapper' => array(
          'type' => '',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
        'separator' => array(
          'active' => 0,
          'element_type' => '',
          'show_css' => 0,
          'element_class' => '',
        ),
      ),
      'comms' => array(
        'region_wrapper' => array(
          'type' => '',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
        'separator' => array(
          'active' => 0,
          'element_type' => '',
          'show_css' => 0,
          'element_class' => '',
        ),
      ),
    ),
    'menu' => array(
      'style' => 'planer',
    ),
    'comms' => array(
      'style' => 'planer',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a1be6a05-96c8-4f3a-94ea-2249e2ce8937';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-df55d36d-a80b-45fa-94ca-d344b02e807d';
    $pane->panel = 'comms';
    $pane->type = 'views_panes';
    $pane->subtype = 'rbkc_news-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'element_wrapper' => array(
          'type' => 'div',
          'add_default_classes' => 0,
          'class_enable' => 1,
          'class' => 'comms__news col8',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
        'element_title' => array(
          'type' => '',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
        'element_content' => array(
          'type' => '',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
      ),
      'style' => 'planer',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'df55d36d-a80b-45fa-94ca-d344b02e807d';
    $display->content['new-df55d36d-a80b-45fa-94ca-d344b02e807d'] = $pane;
    $display->panels['comms'][0] = 'new-df55d36d-a80b-45fa-94ca-d344b02e807d';
    $pane = new stdClass();
    $pane->pid = 'new-eec23489-e099-464d-9b7c-a3ab5f971927';
    $pane->panel = 'comms';
    $pane->type = 'views_panes';
    $pane->subtype = 'rbkc_events-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'element_wrapper' => array(
          'type' => 'div',
          'add_default_classes' => 0,
          'class_enable' => 1,
          'class' => 'comms__feature',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
        'element_title' => array(
          'type' => '',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
        'element_content' => array(
          'type' => '',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
      ),
      'style' => 'planer',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'eec23489-e099-464d-9b7c-a3ab5f971927';
    $display->content['new-eec23489-e099-464d-9b7c-a3ab5f971927'] = $pane;
    $display->panels['comms'][1] = 'new-eec23489-e099-464d-9b7c-a3ab5f971927';
    $pane = new stdClass();
    $pane->pid = 'new-0fa0c162-891a-4732-a915-505e19e098ad';
    $pane->panel = 'content';
    $pane->type = 'contact_us';
    $pane->subtype = 'contact_us';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0fa0c162-891a-4732-a915-505e19e098ad';
    $display->content['new-0fa0c162-891a-4732-a915-505e19e098ad'] = $pane;
    $display->panels['content'][0] = 'new-0fa0c162-891a-4732-a915-505e19e098ad';
    $pane = new stdClass();
    $pane->pid = 'new-559ad680-ecfa-486c-99be-d2c499666a6a';
    $pane->panel = 'local_life';
    $pane->type = 'custom';
    $pane->subtype = 'local_life_slider';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '559ad680-ecfa-486c-99be-d2c499666a6a';
    $display->content['new-559ad680-ecfa-486c-99be-d2c499666a6a'] = $pane;
    $display->panels['local_life'][0] = 'new-559ad680-ecfa-486c-99be-d2c499666a6a';
    $pane = new stdClass();
    $pane->pid = 'new-d23956d4-a541-4b88-a489-11497d58f0f0';
    $pane->panel = 'menu';
    $pane->type = 'rbkc_need_to_menu_split';
    $pane->subtype = 'rbkc_need_to_menu_split';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd23956d4-a541-4b88-a489-11497d58f0f0';
    $display->content['new-d23956d4-a541-4b88-a489-11497d58f0f0'] = $pane;
    $display->panels['menu'][0] = 'new-d23956d4-a541-4b88-a489-11497d58f0f0';
    $pane = new stdClass();
    $pane->pid = 'new-80a817c4-31f3-4f9d-952c-6736aad953ec';
    $pane->panel = 'menu';
    $pane->type = 'rbkc_services_menu_split';
    $pane->subtype = 'rbkc_services_menu_split';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'element_wrapper' => array(
          'type' => '',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
        'element_title' => array(
          'type' => '',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
        'element_content' => array(
          'type' => '',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
      ),
      'style' => 'planer',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '80a817c4-31f3-4f9d-952c-6736aad953ec';
    $display->content['new-80a817c4-31f3-4f9d-952c-6736aad953ec'] = $pane;
    $display->panels['menu'][1] = 'new-80a817c4-31f3-4f9d-952c-6736aad953ec';
    $pane = new stdClass();
    $pane->pid = 'new-95e4f755-b263-4918-b2a6-eec1c157d6dc';
    $pane->panel = 'presstweet';
    $pane->type = 'twitter';
    $pane->subtype = 'twitter';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'username' => 'RBKC',
      'tweets_to_show' => '5',
      'widget_id' => '346591497258422273',
      'chrome' => array(
        'nofooter' => 'nofooter',
        'noborders' => 'noborders',
        'noscrollbar' => 'noscrollbar',
        'transparent' => 'transparent',
        'noheader' => 0,
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'element_wrapper' => array(
          'type' => 'div',
          'add_default_classes' => 0,
          'class_enable' => 1,
          'class' => 'twitter newsmedia',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
        'element_title' => array(
          'type' => '',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
        'element_content' => array(
          'type' => '',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
      ),
      'style' => 'planer',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '95e4f755-b263-4918-b2a6-eec1c157d6dc';
    $display->content['new-95e4f755-b263-4918-b2a6-eec1c157d6dc'] = $pane;
    $display->panels['presstweet'][0] = 'new-95e4f755-b263-4918-b2a6-eec1c157d6dc';
    $pane = new stdClass();
    $pane->pid = 'new-332a5016-82ae-4176-b88c-6595cb83305a';
    $pane->panel = 'presstweet';
    $pane->type = 'views_panes';
    $pane->subtype = 'press_releases-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link_to_view' => 0,
      'more_link' => 0,
      'items_per_page' => '5',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'element_wrapper' => array(
          'type' => 'div',
          'add_default_classes' => 0,
          'class_enable' => 1,
          'class' => 'press newsmedia content',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
        'element_title' => array(
          'type' => 'h2',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
        'element_content' => array(
          'type' => '',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
      ),
      'style' => 'planer',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '332a5016-82ae-4176-b88c-6595cb83305a';
    $display->content['new-332a5016-82ae-4176-b88c-6595cb83305a'] = $pane;
    $display->panels['presstweet'][1] = 'new-332a5016-82ae-4176-b88c-6595cb83305a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['homepage'] = $page;

  return $pages;

}
