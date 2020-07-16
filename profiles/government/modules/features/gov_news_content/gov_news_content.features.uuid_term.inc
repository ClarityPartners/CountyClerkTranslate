<?php
/**
 * @file
 * gov_news_content.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function gov_news_content_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Editorial',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '62b99d19-252d-4253-9f09-49bd454b2e23',
    'vocabulary_machine_name' => 'news_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'News Article',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'd1efe8b6-2610-4559-a84e-bd138f26f2fd',
    'vocabulary_machine_name' => 'news_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Press Release',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'd83d80aa-86e0-4adf-8c40-6d8f7edd1281',
    'vocabulary_machine_name' => 'news_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
