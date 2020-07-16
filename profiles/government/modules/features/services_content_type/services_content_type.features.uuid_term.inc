<?php
/**
 * @file
 * services_content_type.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function services_content_type_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Vital Records',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '0bc556c1-20fc-4429-a91c-d5a35949e091',
    'vocabulary_machine_name' => 'service_category',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Ethics',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '40207d3b-174d-4a65-8dd2-6e087a9c0fa5',
    'vocabulary_machine_name' => 'service_category',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Elections',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '64fbbaaa-20d1-4cbd-9397-0ad69b39dbb6',
    'vocabulary_machine_name' => 'service_category',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Clerk of the Board',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'f5275de4-9e86-4428-908a-f4b6e9cc1283',
    'vocabulary_machine_name' => 'service_category',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Real Estate and Tax',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'fa51c39b-374f-406a-8383-f5fe4201ee7c',
    'vocabulary_machine_name' => 'service_category',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
