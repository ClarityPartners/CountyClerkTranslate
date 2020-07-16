<?php
/**
 * @file
 * agency_service_view.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function agency_service_view_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_agency_pattern';
  $strongarm->value = 'agency/[node:title]';
  $export['pathauto_node_agency_pattern'] = $strongarm;

  return $export;
}
