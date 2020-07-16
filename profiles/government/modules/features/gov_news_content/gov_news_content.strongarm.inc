<?php
/**
 * @file
 * gov_news_content.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function gov_news_content_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_news_categories_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_news_categories_pattern'] = $strongarm;

  return $export;
}
