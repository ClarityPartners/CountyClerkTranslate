<?php
/**
 * @file
 * contact_us_context.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function contact_us_context_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-contact_us_contact_info'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'machine_name' => 'contact_us_contact_info',
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
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'clarity_aurora' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'clarity_aurora',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Contact Information',
    'visibility' => 0,
  );

  return $export;
}
