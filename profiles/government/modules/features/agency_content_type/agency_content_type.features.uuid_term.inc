<?php
/**
 * @file
 * agency_content_type.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function agency_content_type_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Department',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '0b69f22e-f229-4445-ba70-9a794c5ca2cb',
    'vocabulary_machine_name' => 'agency_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Board',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '1d29a457-2e9d-4351-b03b-8797fb9d72b6',
    'vocabulary_machine_name' => 'agency_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Function',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '4b3c835d-0728-4a98-a8ac-36bfbb233fcd',
    'vocabulary_machine_name' => 'agency_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Authority',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '73ced99e-c2f4-488f-9c1b-7488e339a175',
    'vocabulary_machine_name' => 'agency_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
