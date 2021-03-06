<?php
/**
 * @file
 * homepage_banner_entityqueue.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function homepage_banner_entityqueue_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'banners';
  $queue->label = 'Banners';
  $queue->language = 'en';
  $queue->handler = 'multiple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'banner' => 'banner',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 1,
  );
  $export['banners'] = $queue;

  return $export;
}
