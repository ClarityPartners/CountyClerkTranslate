<?php
/**
 * @file
 * news_landing_context.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function news_landing_context_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'News Rooms sidebar link block';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'news_rooms_links';
  $fe_block_boxes->body = '<div class="block-name-block-press-rooms"><div class="field-items"><div class="field-item even"><a href="/pressroom" title="Press Room">Press Room</a></div><div class="field-item odd"><a href="/content/media-assets" title="Media Assets">Media Assets</a></div></div></div>';

  $export['news_rooms_links'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Rss Feed icon for News Landing page';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'rss_feed';
  $fe_block_boxes->body = '<a href="/news/rss.xml" class="rss-link">RSS Feed</a>';

  $export['rss_feed'] = $fe_block_boxes;

  return $export;
}
