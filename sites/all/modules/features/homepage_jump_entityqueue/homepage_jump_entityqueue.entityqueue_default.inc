<?php
/**
 * @file
 * homepage_jump_entityqueue.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function homepage_jump_entityqueue_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'homepage_jump_menu';
  $queue->label = 'Homepage jump menu';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'agency' => 'agency',
      'i_want_to' => 'i_want_to',
      'service' => 'service',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 1,
  );
  $export['homepage_jump_menu'] = $queue;

  return $export;
}
