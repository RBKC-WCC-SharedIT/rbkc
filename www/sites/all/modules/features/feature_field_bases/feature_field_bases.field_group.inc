<?php
/**
 * @file
 * feature_field_bases.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_field_bases_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_external_carousel_link|field_collection_item|field_carousel|form';
  $field_group->group_name = 'group_external_carousel_link';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_carousel';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'External link',
    'weight' => '3',
    'children' => array(
      0 => 'field_external_carousel_h2',
      1 => 'field_external_carousel_teaser',
      2 => 'field_external_carousel_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'External link',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'If linking the carousel to content that is not an Answer page or Press Release, expand these fields',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_external_carousel_link|field_collection_item|field_carousel|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_external_link|field_collection_item|field_other_popular_content|form';
  $field_group->group_name = 'group_external_link';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_other_popular_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'External link',
    'weight' => '1',
    'children' => array(
      0 => 'field_link_to_an_external_page',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'External link',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-external-link field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_external_link|field_collection_item|field_other_popular_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_external_link|field_collection_item|field_popular_tasks|form';
  $field_group->group_name = 'group_external_link';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_popular_tasks';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'External link',
    'weight' => '1',
    'children' => array(
      0 => 'field_external_popular_task',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'External link',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-external-link field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_external_link|field_collection_item|field_popular_tasks|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_external_link|field_collection_item|field_popular_topics|form';
  $field_group->group_name = 'group_external_link';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_popular_topics';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'External link',
    'weight' => '1',
    'children' => array(
      0 => 'field_external_link',
      1 => 'field_external_link_teaser',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'External link',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-external-link field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_external_link|field_collection_item|field_popular_topics|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_external_link|field_collection_item|field_subpage_link_and_teaser|form';
  $field_group->group_name = 'group_external_link';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_subpage_link_and_teaser';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'External link',
    'weight' => '35',
    'children' => array(
      0 => 'field_external_link_and_teaser',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'External link',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-external-link field-group-fieldset',
        'description' => 'Enter link and summary for an external web page',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_external_link|field_collection_item|field_subpage_link_and_teaser|form'] = $field_group;

  return $export;
}
