<?php
/**
 * @file
 * event_content_type.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function event_content_type_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-calendar_head_hero_region'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'calendar_head_hero_region',
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
      'bootstrap_govt' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_govt',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
