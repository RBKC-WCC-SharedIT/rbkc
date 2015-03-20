<?php

/**
 * @file
 * Page callbacks.
 */

/**
 * Contact department edit form.
 *
 * @param $form
 * @param $form_state
 * @param $contact_department
 *
 * @return mixed
 */
function contact_department_form($form, &$form_state, $contact_department) {
  field_attach_form('contact_department', $contact_department, $form, $form_state);

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Contact department form validate handler.
 *
 * @param $form
 * @param $form_state
 */
function contact_department_form_validate($form, &$form_state) {
  field_attach_form_validate('contact_department', $form['#entity'], $form, $form_state);
}

/**
 * Contact department form submission handler.
 *
 * @param $form
 * @param $form_state
 */
function contact_department_form_submit($form, &$form_state) {
  $contact_department = $form['#entity'];
  if (isset($contact_department->is_new) && $contact_department->is_new) {
    $contact_department->created = time();
  }
  field_attach_presave('contact_department', $contact_department);
  field_attach_submit('contact_department', $contact_department, $form, $form_state);
  entity_save('contact_department', $contact_department);

  $form_state['redirect'] = 'admin/content/contact-departments';

  drupal_set_message(t('Contact department successfully saved.'));
}

/**
 * View callback.
 *
 * @param $contact_department
 *
 * @return bool
 */
function contact_department_view($contact_department) {
  return entity_view('contact_department', array($contact_department));
}

/**
 * Delete form callback.
 *
 * @param $contact_department
 *
 * @return mixed
 */
function contact_department_delete_confirm_form($form, &$form_state, $contact_department) {
  $form['contact_department_id'] = array(
    '#type' => 'hidden',
    '#value' => $contact_department->id,
  );

  $message = t('Are you sure you want to delete the contact department %contact_department?', array('%contact_department' => $contact_department->field_contact_department_name[LANGUAGE_NONE][0]['value']));

  $cancel_path = 'admin/content/contact-departments';

  return confirm_form($form, $message, $cancel_path);
}

/**
 * Delete form submit handler.
 *
 * @param $form
 * @param $form_state
 */
function contact_department_delete_confirm_form_submit($form, &$form_state) {
  entity_delete('contact_department', $form_state['values']['contact_department_id']);

  $form_state['redirect'] = 'admin/content/contact-departments';

  drupal_set_message(t('Contact department successfully deleted.'));
}