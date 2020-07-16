<?php
/**
 * @file
 * event_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function event_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fe_date_custom_date_formats().
 */
function event_content_type_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['F j, Y g:ia'] = 'F j, Y g:ia';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function event_content_type_date_format_types() {
  $format_types = array();
  // Exported date format type: full_with_time
  $format_types['full_with_time'] = 'full with time';
  return $format_types;
}

/**
 * Implements hook_node_info().
 */
function event_content_type_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Holds information about calendar-based public or social occasions.
'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Events represent something happening on a specific date or time. 
Events can be tagged to Agencies.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
