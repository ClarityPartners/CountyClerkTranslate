<?php
/**
 * @file
 * upcoming_events_view.features.inc
 */

/**
 * Implements hook_views_api().
 */
function upcoming_events_view_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_date_custom_date_formats().
 */
function upcoming_events_view_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['g:i A'] = 'g:i A';
  return $custom_date_formats;
}
