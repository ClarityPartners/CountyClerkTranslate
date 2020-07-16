<?php
/**
 * @file
 * event_context.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function event_context_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fe_date_custom_date_formats().
 */
function event_context_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['F Y'] = 'F Y';
  $custom_date_formats['Y-m'] = 'Y-m';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function event_context_date_format_types() {
  $format_types = array();
  // Exported date format type: month_and_year
  $format_types['month_and_year'] = 'Month and Year';
  // Exported date format type: year_day
  $format_types['year_day'] = 'Year-day';
  return $format_types;
}
