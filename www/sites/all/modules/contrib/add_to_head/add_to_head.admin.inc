<?php

/**
 * @file
 * This file contains all the admin-related callbacks
 */


/**
 * Overview page - provides a list of existing add to head profiles
 */
function add_to_head_overview() {
  $settings = variable_get('add_to_head_profiles', array());

  $rows = array();
  $header = array(t('Title'), t('Paths'), t('Visibility'), t('Scope'), t('Ops'));


  foreach ($settings as $delta => $settings) {
    $rows[] = array(
      check_plain($settings['name']),
      nl2br(check_plain($settings['paths'])),
      ($settings['path_visibility'] == 0 ? t('Exclude') : t('Include')),
      drupal_ucfirst($settings['scope']),
      implode(' | ', array(
        l(t('Edit'), 'admin/config/development/add-to-head/' . $delta),
        l(t('Delete'), 'admin/config/development/add-to-head/' . $delta . '/delete'),
      )),
    );
  }

  if (!empty($rows)) {
    $rows[] = array(array(
      'colspan' => count($header),
      'data' => l(t('Add another profile'), 'admin/config/development/add-to-head/add'),
    ));
  }

  return array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No profiles configured yet. !link', array('!link' => l(t('Add one now'), 'admin/config/development/add-to-head/add')))
  );
}


/**
 * This function provides the edit form.
 * The Add Profile form also uses this.
 * @see add_to_head_forms()
 */
function add_to_head_edit_profile($form, &$form_state, $profile = array()) {
  // Fill in profile defaults to ensure all keys exist.
  $profile += array(
    'name' => '',
    'code' => '',
    'path_visibility' => '',
    'paths' => '',
    'scope' => '',
  );

  $form['name_orig'] = array(
    '#type' => 'value',
    '#value' => $profile['name'],
  );

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('This is the unique name for this profile'),
    '#required' => TRUE,
    '#default_value' => $profile['name'],
  );

  $form['code'] = array(
    '#type' => 'textarea',
    '#title' => t('Code'),
    '#description' => t('Enter the code you would like to insert into the head of the page'),
    '#required' => TRUE,
    '#default_value' => $profile['code'],
    '#wysiwyg' => FALSE,
  );


  $form['path_visibility'] = array(
    '#type' => 'radios',
    '#title' => t('Embed code on specific pages'),
    '#options' => array(
      0 => t('Show on every page except the listed pages.'),
      1 => t('Show on only the listed pages.'),
    ),
    '#default_value' => $profile['path_visibility'],
  );

  $form['paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Paths'),
    '#description' => t("Enter one page per line as Drupal paths. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')),
    '#required' => TRUE,
    '#default_value' => $profile['paths'],
    '#wysiwyg' => FALSE,
  );

  $form['scope'] = array(
    '#type' => 'radios',
    '#title' => t('Scope of addition'),
    '#description' => t('Which section of the head would you like this snippet appended to?'),
    '#options' => array(
      'head' => t('Head - This appears early on in the head (before any CSS and JS are included)'),
      'styles' => t('Styles - It will be appended to the CSS files section. This is usually before any other JS is included.'),
      'scripts' => t('Scripts - It will be appended to the Javascripts section. This can, sometimes, be in the footer of the document depending on the theme.'),
    ),
    '#default_value' => $profile['scope'],
  );


  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}


/**
 * Validate handler for the add/edit form
 */
function add_to_head_edit_profile_validate($form, &$form_state) {
  $settings = variable_get('add_to_head_profiles', array());

  if (preg_match('/[^a-z0-9\-]/', $form_state['values']['name'])) {
    form_set_error('name', t('The name should only contain lower case letters, numbers and hyphens.'));
  }
  elseif ( ($form_state['values']['name'] != $form_state['values']['name_orig']) && (isset($settings[$form_state['values']['name']])) ) {
    form_set_error('name', t('This name has already been used. Please try another.'));
  }
}


/**
 * Submit handler for the add/edit form
 */
function add_to_head_edit_profile_submit($form, &$form_state) {
  $settings = variable_get('add_to_head_profiles', array());

  if ($form_state['values']['name'] != $form_state['values']['name_orig']) {
    unset($settings[$form_state['values']['name_orig']]);
  }

  $settings[$form_state['values']['name']] = array(
    'name'  => $form_state['values']['name'],
    'code'  => trim($form_state['values']['code']),
    'paths' => trim($form_state['values']['paths']),
    'scope' => $form_state['values']['scope'],
    'path_visibility' => $form_state['values']['path_visibility'],
  );

  variable_set('add_to_head_profiles', $settings);

  $form_state['redirect'] = 'admin/config/development/add-to-head';
}


/**
 * Delete confirm form for removing a profile
 */
function add_to_head_delete_profile_confirm($form, &$form_state, $profile) {
  $form['#profile'] = $profile;

  return confirm_form($form,
    t('Are you sure you want to delete the profile %name', array('%name' => $profile['name'])),
    'admin/config/development/add-to-head',
    t('This cannot be undone'),
    t('Delete'), t('Cancel')
  );
}


/**
 * Delete confirm form submit handler for removing a profile.
 */
function add_to_head_delete_profile_confirm_submit($form, &$form_state) {
  $settings = variable_get('add_to_head_profiles', array());

  unset($settings[$form['#profile']['name']]);

  variable_set('add_to_head_profiles', $settings);

  $form_state['redirect'] = 'admin/config/development/add-to-head';
}
