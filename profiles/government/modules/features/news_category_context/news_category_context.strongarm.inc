<?php
/**
 * @file
 * news_category_context.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function news_category_context_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_entity_taxonomy_term_event_categories';
  $strongarm->value = 0;
  $export['uuid_features_entity_taxonomy_term_event_categories'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_entity_taxonomy_term_event_category';
  $strongarm->value = 0;
  $export['uuid_features_entity_taxonomy_term_event_category'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_entity_taxonomy_term_news_categories';
  $strongarm->value = 0;
  $export['uuid_features_entity_taxonomy_term_news_categories'] = $strongarm;

  return $export;
}
