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
      'row_one_col_two' => NULL,
      'row_two_col_one' => NULL,
      'row_two_col_two' => NULL,
    ),
    'row_two' => array(
      'style' => 'planer',
    ),
    'row_one' => array(
      'style' => 'planer',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b8f321a8-d0a8-4341-99bd-86fe58b20928';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d50be500-cfde-4f4a-b8c6-fcc2a84e8a14';
    $pane->panel = 'row_one_col_two';
    $pane->type = 'views_panes';
    $pane->subtype = 'press_releases-panel_pane_1';
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
      'settings' => array(
        'element_wrapper' => array(
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
    $pane->uuid = 'd50be500-cfde-4f4a-b8c6-fcc2a84e8a14';
    $display->content['new-d50be500-cfde-4f4a-b8c6-fcc2a84e8a14'] = $pane;
    $display->panels['row_one_col_two'][0] = 'new-d50be500-cfde-4f4a-b8c6-fcc2a84e8a14';
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
      'settings' => array(
        'element_wrapper' => array(
          'type' => 'section',
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
      'newspaper_image' => '193',
      'newspaper_body' => 'For the latest news and events read the Royal Borough, the Council\'s quarterly newspaper.
 
Also search the archive for back issues.',
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
