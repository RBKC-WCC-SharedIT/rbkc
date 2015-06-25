<?php
/**
 * @file
 * feature_newsroom.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function feature_newsroom_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'newsroom';
  $page->task = 'page';
  $page->admin_title = 'Newsroom';
  $page->admin_description = '';
  $page->path = 'newsroom';
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
  $handler->name = 'page_newsroom__panel_context_d1ae3064-d551-4ca6-b3b3-de5ebcff3ee3';
  $handler->task = 'page';
  $handler->subtask = 'newsroom';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Newsroom',
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
  $display->layout = 'rbkc_newsroom';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
      'row_one' => array(
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
      'row_two' => array(
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
      'row_one_col_one' => NULL,
      'row_one_col_two' => array(
        'region_wrapper' => array(
          'type' => 'section',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 1,
          'attributes' => 'id=pressReleases',
          'attributes_array' => array(
            'id' => 'pressReleases',
          ),
        ),
        'separator' => array(
          'active' => 0,
          'element_type' => '',
          'show_css' => 0,
          'element_class' => '',
        ),
      ),
      'row_two_col_two' => NULL,
      'row_two_col_one' => NULL,
    ),
    'row_two' => array(
      'style' => 'planer',
    ),
    'row_one' => array(
      'style' => 'planer',
    ),
    'row_two_col_one' => array(
      'style' => 'naked',
    ),
    'row_one_col_two' => array(
      'style' => 'planer',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b8f321a8-d0a8-4341-99bd-86fe58b20928';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-315f6206-a24d-47a6-a35d-a07b37abecbc';
    $pane->panel = 'row_one_col_one';
    $pane->type = 'custom';
    $pane->subtype = 'newsroom_top_stories_slider';
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
      'settings' => array(
        'element_wrapper' => array(
          'type' => 'section',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 1,
          'attributes' => 'id=latestNews',
          'attributes_array' => array(
            'id' => 'latestNews',
          ),
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
          'type' => 'div',
          'add_default_classes' => 0,
          'class_enable' => 1,
          'class' => 'sectionContent',
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
    $pane->uuid = '315f6206-a24d-47a6-a35d-a07b37abecbc';
    $display->content['new-315f6206-a24d-47a6-a35d-a07b37abecbc'] = $pane;
    $display->panels['row_one_col_one'][0] = 'new-315f6206-a24d-47a6-a35d-a07b37abecbc';
    $pane = new stdClass();
    $pane->pid = 'new-f73e9cc1-8db6-42ca-839a-15c6de4fb55e';
    $pane->panel = 'row_one_col_two';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Press releases title',
      'title' => '',
      'body' => '<h2>Press releases</h2>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f73e9cc1-8db6-42ca-839a-15c6de4fb55e';
    $display->content['new-f73e9cc1-8db6-42ca-839a-15c6de4fb55e'] = $pane;
    $display->panels['row_one_col_two'][0] = 'new-f73e9cc1-8db6-42ca-839a-15c6de4fb55e';
    $pane = new stdClass();
    $pane->pid = 'new-35efe18c-6491-4e4e-b306-8f8e053a4143';
    $pane->panel = 'row_one_col_two';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Search press releases link',
      'title' => '',
      'body' => '<p class="fixedItem"><span style="float:right"><a href="/pressrelease/search.aspx">Search press releases</a></span></p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '35efe18c-6491-4e4e-b306-8f8e053a4143';
    $display->content['new-35efe18c-6491-4e4e-b306-8f8e053a4143'] = $pane;
    $display->panels['row_one_col_two'][1] = 'new-35efe18c-6491-4e4e-b306-8f8e053a4143';
    $pane = new stdClass();
    $pane->pid = 'new-850be167-8285-4c1a-ae83-d9f05d412baf';
    $pane->panel = 'row_one_col_two';
    $pane->type = 'views_panes';
    $pane->subtype = 'press_releases-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link_to_view' => 0,
      'more_link' => 1,
      'items_per_page' => '7',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'planer',
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
          'type' => 'div',
          'add_default_classes' => 0,
          'class_enable' => 1,
          'class' => 'sectionContent',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
      ),
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '850be167-8285-4c1a-ae83-d9f05d412baf';
    $display->content['new-850be167-8285-4c1a-ae83-d9f05d412baf'] = $pane;
    $display->panels['row_one_col_two'][2] = 'new-850be167-8285-4c1a-ae83-d9f05d412baf';
    $pane = new stdClass();
    $pane->pid = 'new-911aff5a-0ffd-46e2-9ce4-e69047181f93';
    $pane->panel = 'row_two_col_one';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Newsletters',
      'title' => '',
      'body' => '<h2>Newsletters</h2><p class="fixedItem"><span style="float:right"><a href="/newsroom/signuptooure-newsletters.aspx">Sign up for newsletters</a></span></p><div class="sectionContent content"><p><strong>Here are the latest issues of the Council\'s enewsletters.</strong></p><ul><li><p><a href="http://rbkc.newsweaver.co.uk/rbkcdirect">RBKC Direct</a></p></li><li><p><a href="http://rbkc.newsweaver.co.uk/nicknotes">Leader\'s newsletter</a></p></li><li><p><a href="http://rbkc.newsweaver.co.uk/businessdirect">Business Direct</a></p></li><li><p><a href="http://rbkc.newsweaver.co.uk/artstinformation">Arts newsletters</a></p></li><li><p><a href="http://rbkc.newsweaver.co.uk/commercialwaste">Commercial waste</a></p></li><li><p><a href="http://rbkc.newsweaver.co.uk/gardenersnewsletter">Community gardeners</a></p></li><li><p><a href="http://rbkc.newsweaver.co.uk/PlanningBulletin">Planning Direct</a></p></li><li><p><a href="http://rbkc.newsweaver.co.uk/CityLivingLocalLife">City Living, Local Life</a></p></li></ul></div>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'planer',
      'settings' => array(
        'element_wrapper' => array(
          'type' => 'section',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 1,
          'attributes' => 'id=newsletters',
          'attributes_array' => array(
            'id' => 'newsletters',
          ),
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
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '911aff5a-0ffd-46e2-9ce4-e69047181f93';
    $display->content['new-911aff5a-0ffd-46e2-9ce4-e69047181f93'] = $pane;
    $display->panels['row_two_col_one'][0] = 'new-911aff5a-0ffd-46e2-9ce4-e69047181f93';
    $pane = new stdClass();
    $pane->pid = 'new-56448fda-f60a-44ef-90a9-d143e1a1d4b5';
    $pane->panel = 'row_two_col_one';
    $pane->type = 'views';
    $pane->subtype = 'newsroom_capital_projects';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'planer',
      'settings' => array(
        'element_wrapper' => array(
          'type' => 'section',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 1,
          'attributes' => 'id=capital_projects
class=row',
          'attributes_array' => array(
            'id' => 'capital_projects',
            'class' => 'row',
          ),
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
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '56448fda-f60a-44ef-90a9-d143e1a1d4b5';
    $display->content['new-56448fda-f60a-44ef-90a9-d143e1a1d4b5'] = $pane;
    $display->panels['row_two_col_one'][1] = 'new-56448fda-f60a-44ef-90a9-d143e1a1d4b5';
    $pane = new stdClass();
    $pane->pid = 'new-c213450e-1589-474b-96b1-9db69fef6ec1';
    $pane->panel = 'row_two_col_two';
    $pane->type = 'twitter';
    $pane->subtype = 'twitter';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'show_social' => 'Show',
      'username' => 'RBKC',
      'tweets_to_show' => '5',
      'widget_id' => '346591497258422273',
      'chrome' => array(
        'noscrollbar' => 'noscrollbar',
        'noheader' => 0,
        'nofooter' => 0,
        'noborders' => 0,
        'transparent' => 0,
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'naked',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c213450e-1589-474b-96b1-9db69fef6ec1';
    $display->content['new-c213450e-1589-474b-96b1-9db69fef6ec1'] = $pane;
    $display->panels['row_two_col_two'][0] = 'new-c213450e-1589-474b-96b1-9db69fef6ec1';
    $pane = new stdClass();
    $pane->pid = 'new-255e110d-9cf3-4d4d-bd1d-39495cde99d0';
    $pane->panel = 'row_two_col_two';
    $pane->type = 'newspaper';
    $pane->subtype = 'newspaper';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'readmore' => 'Read the latest edition here',
      'newspaper_image' => 0,
      'newspaper_body' => array(
        'value' => '<p><strong>For the latest news and events read the Royal Borough, the Council\'s quarterly newspaper.</strong></p><p>&nbsp;</p><p><strong>Also search the archive for back issues.</strong></p>',
        'format' => 'full_html',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'element_wrapper' => array(
          'type' => 'section',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 1,
          'attributes' => 'id=royalBorough',
          'attributes_array' => array(
            'id' => 'royalBorough',
          ),
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
    $pane->uuid = '255e110d-9cf3-4d4d-bd1d-39495cde99d0';
    $display->content['new-255e110d-9cf3-4d4d-bd1d-39495cde99d0'] = $pane;
    $display->panels['row_two_col_two'][1] = 'new-255e110d-9cf3-4d4d-bd1d-39495cde99d0';
    $pane = new stdClass();
    $pane->pid = 'new-d08c25f9-d371-492f-a8c0-c6f520ffefb0';
    $pane->panel = 'row_two_col_two';
    $pane->type = 'custom';
    $pane->subtype = 'contact_us';
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
      'settings' => array(
        'element_wrapper' => array(
          'type' => 'section',
          'add_default_classes' => 0,
          'class_enable' => 0,
          'class' => '',
          'attributes_enable' => 1,
          'attributes' => 'id=pressContact',
          'attributes_array' => array(
            'id' => 'pressContact',
          ),
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
          'type' => 'div',
          'add_default_classes' => 0,
          'class_enable' => 1,
          'class' => 'sectionContent content',
          'attributes_enable' => 0,
          'attributes' => '',
        ),
      ),
      'style' => 'planer',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd08c25f9-d371-492f-a8c0-c6f520ffefb0';
    $display->content['new-d08c25f9-d371-492f-a8c0-c6f520ffefb0'] = $pane;
    $display->panels['row_two_col_two'][2] = 'new-d08c25f9-d371-492f-a8c0-c6f520ffefb0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['newsroom'] = $page;

  return $pages;

}
