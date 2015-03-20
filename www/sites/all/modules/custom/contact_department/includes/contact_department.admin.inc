<?php

/**
 * @file
 * Admin page callbacks.
 */

function contact_department_overview() {
  $header = array(t('Contact department'), t('Link'), array('data' => t('Operations'), 'colspan' => 2));
  $rows = array();

  if ($contact_departments = entity_load('contact_department')) {
    foreach ($contact_departments as $contact_department) {
      $rows[] = array(
        'data' => array(
          'name' => $contact_department->field_contact_department_name[LANGUAGE_NONE][0]['safe_value'],
          'link' => $contact_department->field_contact_department_link[LANGUAGE_NONE][0]['url'],
          'edit' => l(t('edit'), 'contact-department/' . $contact_department->id . '/edit'),
          'delete' => l(t('delete'), 'contact-department/' . $contact_department->id . '/delete'),
        ),
      );
    }
  }

  $content['contact_departments_table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No contact departments. <a href="@link">Add contact department</a>.', array('@link' => url('contact-department/add'))),
  );

  return $content;
}