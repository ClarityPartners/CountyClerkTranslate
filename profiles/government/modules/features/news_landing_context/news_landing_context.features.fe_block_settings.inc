<?php
/**
 * @file
 * news_landing_context.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function news_landing_context_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-news_rooms_links'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'news_rooms_links',
    'module' => 'block',
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
    'title' => 'News Rooms',
    'visibility' => 0,
  );

  $export['block-rss_feed'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'rss_feed',
    'module' => 'block',
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
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
