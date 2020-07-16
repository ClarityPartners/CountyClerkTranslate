<?php
/**
 * @file
 * county_clerk_workbench.features.workbench_scheduler.inc
 */

/**
 * Implements hook_workbench_scheduler_export_schedules().
 */
function county_clerk_workbench_workbench_scheduler_export_schedules() {
  $items = array(
    'draft_to_published' => array(
      'name' => 'draft_to_published',
      'label' => 'Scheduled Publish - Draft to Published',
      'types' => array(
        0 => 'agency',
        1 => 'broadcast',
        2 => 'event',
        3 => 'general',
        4 => 'news',
        5 => 'page',
        6 => 'service',
        7 => 'video',
      ),
      'from_name' => 'draft',
      'to_name' => 'published',
    ),
    'scheduled_publish' => array(
      'name' => 'scheduled_publish',
      'label' => 'Scheduled Publish - Needs Review to Publish',
      'types' => array(
        0 => 'agency',
        1 => 'broadcast',
        2 => 'event',
        3 => 'general',
        4 => 'news',
        5 => 'page',
        6 => 'service',
        7 => 'video',
      ),
      'from_name' => 'needs_review',
      'to_name' => 'published',
    ),
  );
  return $items;
}
