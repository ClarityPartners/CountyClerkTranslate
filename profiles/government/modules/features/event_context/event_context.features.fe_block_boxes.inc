<?php
/**
 * @file
 * event_context.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function event_context_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Back to Calendar Overview Link';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'calendar_overview_link_block';
  $fe_block_boxes->body = '<div class="calendar-link"><a class="calendar-link" href="/calendar">Back to Calendar Overview</a></div>';

  $export['calendar_overview_link_block'] = $fe_block_boxes;

  return $export;
}
