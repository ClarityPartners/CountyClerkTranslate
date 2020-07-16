<?php
/**
 * @file
 * paragraph_types.features.inc
 */

/**
 * Implements hook_paragraphs_info().
 */
function paragraph_types_paragraphs_info() {
  $items = array(
    'home' => array(
      'name' => 'home-blocks',
      'bundle' => 'home',
      'locked' => '1',
    ),
    'home_card' => array(
      'name' => 'home-card',
      'bundle' => 'home_card',
      'locked' => '1',
    ),
  );
  return $items;
}
