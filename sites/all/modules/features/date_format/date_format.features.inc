<?php
/**
 * @file
 * date_format.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function date_format_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fe_date_custom_date_formats().
 */
function date_format_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['F Y'] = 'F Y';
  $custom_date_formats['F j, Y'] = 'F j, Y';
  $custom_date_formats['Y-m'] = 'Y-m';
  $custom_date_formats['g:i A - j F Y'] = 'g:i A - j F Y';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function date_format_date_format_types() {
  $format_types = array();
  // Exported date format type: event_time_date
  $format_types['event_time_date'] = 'Event Time & Date';
  // Exported date format type: events_news
  $format_types['events_news'] = 'events & news';
  // Exported date format type: month_and_year
  $format_types['month_and_year'] = 'Month and Year';
  // Exported date format type: news
  $format_types['news'] = 'News';
  // Exported date format type: twitter
  $format_types['twitter'] = 'Twitter';
  // Exported date format type: year_day
  $format_types['year_day'] = 'Year-day';
  return $format_types;
}
