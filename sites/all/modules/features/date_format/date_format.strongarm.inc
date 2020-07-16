<?php
/**
 * @file
 * date_format.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function date_format_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_event_time_date';
  $strongarm->value = 'F j, Y g:ia';
  $export['date_format_event_time_date'] = $strongarm;

  return $export;
}
