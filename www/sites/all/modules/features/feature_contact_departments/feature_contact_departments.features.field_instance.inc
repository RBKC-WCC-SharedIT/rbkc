<?php
/**
 * @file
 * feature_contact_departments.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_contact_departments_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'contact_department-contact_department-field_contact_department_link'
  $field_instances['contact_department-contact_department-field_contact_department_link'] = array(
    'bundle' => 'contact_department',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the URL for this contact department.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_url',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'contact_department',
    'field_name' => 'field_contact_department_link',
    'label' => 'Link',
    'required' => 1,
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
      'title' => 'none',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'contact_department-contact_department-field_contact_department_name'
  $field_instances['contact_department-contact_department-field_contact_department_name'] = array(
    'bundle' => 'contact_department',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The name of the contact department. ',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'contact_department',
    'field_name' => 'field_contact_department_name',
    'label' => 'Name',
    'required' => 1,
    'settings' => array(
      'context' => '',
      'dnd_enabled' => 0,
      'mee_enabled' => 0,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Enter the URL for this contact department.');
  t('Link');
  t('Name');
  t('The name of the contact department. ');

  return $field_instances;
}
