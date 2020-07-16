<?php
/**
 * @file
 * i_want_to_queues.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function i_want_to_queues_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'i_want_to_queue';
  $queue->label = 'I want to queue';
  $queue->language = 'en';
  $queue->handler = 'multiple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'i_want_to' => 'i_want_to',
      'service' => 'service',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 0,
  );
  $export['i_want_to_queue'] = $queue;

  return $export;
}
