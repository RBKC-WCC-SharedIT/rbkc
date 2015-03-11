<?php
/**
 * @file
 * feature_contact_departments.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_contact_departments_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'contact_departments';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'contact_departments';
  $view->human_name = 'Contact departments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view contact departments';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Contact department: Name */
  $handler->display->display_options['fields']['field_contact_department_name']['id'] = 'field_contact_department_name';
  $handler->display->display_options['fields']['field_contact_department_name']['table'] = 'field_data_field_contact_department_name';
  $handler->display->display_options['fields']['field_contact_department_name']['field'] = 'field_contact_department_name';
  $handler->display->display_options['fields']['field_contact_department_name']['label'] = '';
  $handler->display->display_options['fields']['field_contact_department_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_department_name']['type'] = 'text_plain';
  /* Filter criterion: Contact department: Name (field_contact_department_name) */
  $handler->display->display_options['filters']['field_contact_department_name_value']['id'] = 'field_contact_department_name_value';
  $handler->display->display_options['filters']['field_contact_department_name_value']['table'] = 'field_data_field_contact_department_name';
  $handler->display->display_options['filters']['field_contact_department_name_value']['field'] = 'field_contact_department_name_value';
  $handler->display->display_options['filters']['field_contact_department_name_value']['operator'] = 'contains';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_contact_department_name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_contact_department_name' => 'field_contact_department_name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['contact_departments'] = $view;

  return $export;
}
