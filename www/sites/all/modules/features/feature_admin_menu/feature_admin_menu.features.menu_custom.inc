<?php
/**
 * @file
 * feature_admin_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function feature_admin_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-site-administrator-menu.
  $menus['menu-site-administrator-menu'] = array(
    'menu_name' => 'menu-site-administrator-menu',
    'title' => 'Site Administrator Menu',
    'description' => 'Menu for site admin',
  );
  // Exported menu: menu-site-editor-menu.
  $menus['menu-site-editor-menu'] = array(
    'menu_name' => 'menu-site-editor-menu',
    'title' => 'Site Editor Menu',
    'description' => 'Menu for site editors.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Menu for site admin');
  t('Menu for site editors.');
  t('Site Administrator Menu');
  t('Site Editor Menu');


  return $menus;
}
