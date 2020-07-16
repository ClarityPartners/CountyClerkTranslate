<?php
/**
 * @file
 * footer_navigation_panel.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function footer_navigation_panel_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-about.
  $menus['menu-about'] = array(
    'menu_name' => 'menu-about',
    'title' => 'about',
    'description' => 'about menu',
  );
  // Exported menu: menu-footer-menu.
  $menus['menu-footer-menu'] = array(
    'menu_name' => 'menu-footer-menu',
    'title' => 'Footer Menu',
    'description' => '',
  );
  // Exported menu: menu-other-links.
  $menus['menu-other-links'] = array(
    'menu_name' => 'menu-other-links',
    'title' => 'other links',
    'description' => '',
  );
  // Exported menu: menu-social-menu.
  $menus['menu-social-menu'] = array(
    'menu_name' => 'menu-social-menu',
    'title' => 'social menu',
    'description' => 'social media menu ',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer Menu');
  t('about');
  t('about menu');
  t('other links');
  t('social media menu ');
  t('social menu');

  return $menus;
}
