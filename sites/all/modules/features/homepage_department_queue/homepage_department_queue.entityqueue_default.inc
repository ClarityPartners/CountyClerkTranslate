<?php
/**
 * @file
 * homepage_department_queue.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function homepage_department_queue_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'homepage_departments';
  $queue->label = 'Homepage Departments';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'agency' => 'agency',
      'i_want_to' => 'i_want_to',
    ),
    'min_size' => '0',
    'max_size' => '6',
    'act_as_queue' => 1,
  );
  $export['homepage_departments'] = $queue;

  return $export;
}
