<?php
/**
 * @file
 * faq.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function faq_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-faq-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'faq-block',
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
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
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
