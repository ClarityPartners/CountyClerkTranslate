<?php
/**
 * @file
 * news_archive_context.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function news_archive_context_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['gov_news_archive-news_archive_sidebar_block'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'news_archive_sidebar_block',
    'module' => 'gov_news_archive',
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

  $export['views-news_archive-by_year'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'news_archive-by_year',
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
