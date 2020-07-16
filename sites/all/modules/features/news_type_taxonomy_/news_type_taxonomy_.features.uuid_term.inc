<?php
/**
 * @file
 * news_type_taxonomy_.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function news_type_taxonomy__uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Elections',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '6d66614d-5981-4841-b85e-e6fde8dd3ba5',
    'vocabulary_machine_name' => 'news_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Ethics',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '6e4c3e52-4ff6-4acc-935b-496a642e920b',
    'vocabulary_machine_name' => 'news_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Vital Records',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '9caa6cd3-6919-4985-9d0c-8d08cab0377d',
    'vocabulary_machine_name' => 'news_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Real Estate and Tax',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'b1371e64-6c1a-4fd2-a89d-b78fb5640a36',
    'vocabulary_machine_name' => 'news_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Clerk of the Board',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'd06ca1ee-c3bc-4ff8-9b82-097f6c1f57f3',
    'vocabulary_machine_name' => 'news_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
