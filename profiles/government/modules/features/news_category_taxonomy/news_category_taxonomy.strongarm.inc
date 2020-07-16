<?php
/**
 * @file
 * news_category_taxonomy.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function news_category_taxonomy_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_file_taxonomy_term_news_categories';
  $strongarm->value = 0;
  $export['uuid_features_file_taxonomy_term_news_categories'] = $strongarm;

  return $export;
}
