<?php
/**
 * @file
 * event_category_taxonomy.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function event_category_taxonomy_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_event_category_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_event_category_pattern'] = $strongarm;

  return $export;
}
