<?php
/**
 * @file
 * all_news_view.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function all_news_view_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-news_categories_menu-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'news_categories_menu-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'county_clerk_bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'county_clerk_bootstrap',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-news_categories_menu-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'news_categories_menu-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'county_clerk_bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'county_clerk_bootstrap',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
