<?php
/**
 * @file
 * feature_admin_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_admin_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_atoms:admin/atoms
  $menu_links['management_atoms:admin/atoms'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/atoms',
    'router_path' => 'admin/atoms',
    'link_title' => 'Atoms',
    'options' => array(
      'identifier' => 'management_atoms:admin/atoms',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_books:admin/books
  $menu_links['management_books:admin/books'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/books',
    'router_path' => 'admin/books',
    'link_title' => 'Books',
    'options' => array(
      'identifier' => 'management_books:admin/books',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_contact-departments:admin/structure/contact-departments
  $menu_links['management_contact-departments:admin/structure/contact-departments'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/contact-departments',
    'router_path' => 'admin/structure/contact-departments',
    'link_title' => 'Contact departments',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage contact departments.',
      ),
      'identifier' => 'management_contact-departments:admin/structure/contact-departments',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_my-workbench:admin/workbench
  $menu_links['management_my-workbench:admin/workbench'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/workbench',
    'router_path' => 'admin/workbench',
    'link_title' => 'My Workbench',
    'options' => array(
      'attributes' => array(
        'title' => 'My Workbench area',
      ),
      'identifier' => 'management_my-workbench:admin/workbench',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_people:admin/people
  $menu_links['management_people:admin/people'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/people',
    'router_path' => 'admin/people',
    'link_title' => 'People',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage user accounts, roles, and permissions.',
      ),
      'identifier' => 'management_people:admin/people',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_webforms:admin/webforms
  $menu_links['management_webforms:admin/webforms'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/webforms',
    'router_path' => 'admin/webforms',
    'link_title' => 'Webforms',
    'options' => array(
      'identifier' => 'management_webforms:admin/webforms',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Atoms');
  t('Books');
  t('Contact departments');
  t('My Workbench');
  t('People');
  t('Webforms');


  return $menu_links;
}
