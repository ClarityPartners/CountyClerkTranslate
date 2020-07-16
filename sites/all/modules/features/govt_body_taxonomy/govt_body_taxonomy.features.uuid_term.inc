<?php
/**
 * @file
 * govt_body_taxonomy.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function govt_body_taxonomy_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Subcommittee',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '05ae4357-0e80-4529-80ee-42c88faf51b9',
    'vocabulary_machine_name' => 'government_body_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Board',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '1f66d76b-267c-4ac8-9220-df784cf29aaa',
    'vocabulary_machine_name' => 'government_body_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Task Force',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '6a8344fc-7ec3-4a64-a89c-c38951543ded',
    'vocabulary_machine_name' => 'government_body_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Commission',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '75637e86-1e62-46fb-ae74-3b66ea9008f2',
    'vocabulary_machine_name' => 'government_body_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Committee',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'ecde96af-ccbb-431b-90d7-8e8e0c295650',
    'vocabulary_machine_name' => 'government_body_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
