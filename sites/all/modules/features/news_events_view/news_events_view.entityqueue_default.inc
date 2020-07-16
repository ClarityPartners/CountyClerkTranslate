<?php
/**
 * @file
 * news_events_view.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function news_events_view_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'whats_new_homepage';
  $queue->label = 'whats new - homepage';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'event' => 'event',
      'news' => 'news',
    ),
    'min_size' => '2',
    'max_size' => '10',
    'act_as_queue' => 0,
  );
  $export['whats_new_homepage'] = $queue;

  return $export;
}
