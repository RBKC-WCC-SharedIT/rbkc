<?php
/**
 * @file
 * feature_service_hub.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_service_hub_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-servicehub-field_news_stories'
  $field_instances['node-servicehub-field_news_stories'] = array(
    'bundle' => 'servicehub',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'News stories appear towards the bottom of the service hub page.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_news_stories',
    'label' => 'News stories',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-servicehub-field_other_popular_content'
  $field_instances['node-servicehub-field_other_popular_content'] = array(
    'bundle' => 'servicehub',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Start typing the title to link other popular content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_other_popular_content',
    'label' => 'Other popular content',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-servicehub-field_popular_tasks'
  $field_instances['node-servicehub-field_popular_tasks'] = array(
    'bundle' => 'servicehub',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Popular tasks appear at the top of the service hub page.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_popular_tasks',
    'label' => 'Popular tasks',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'required',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-servicehub-field_popular_topics'
  $field_instances['node-servicehub-field_popular_topics'] = array(
    'bundle' => 'servicehub',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Start typing the title to link a popular topic.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(
          'node_reference_view_mode' => 'teaser',
        ),
        'type' => 'node_reference_node',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_popular_topics',
    'label' => 'Popular topics',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('News stories');
  t('News stories appear towards the bottom of the service hub page.');
  t('Other popular content');
  t('Popular tasks');
  t('Popular tasks appear at the top of the service hub page.');
  t('Popular topics');
  t('Start typing the title to link a popular topic.');
  t('Start typing the title to link other popular content.');

  return $field_instances;
}
