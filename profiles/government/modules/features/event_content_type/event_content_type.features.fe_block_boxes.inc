<?php
/**
 * @file
 * event_content_type.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function event_content_type_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Calendar Head for Hero Region';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'calendar_head_hero_region';
  $fe_block_boxes->body = '<p><span class="hero-region-head">Calendar</span></p>';

  $export['calendar_head_hero_region'] = $fe_block_boxes;

  return $export;
}
