<?php
/**
 * @file
 * event_context.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function event_context_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_month_and_year';
  $strongarm->value = 'F Y';
  $export['date_format_month_and_year'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_year_day';
  $strongarm->value = 'Y-m';
  $export['date_format_year_day'] = $strongarm;

  return $export;
}
