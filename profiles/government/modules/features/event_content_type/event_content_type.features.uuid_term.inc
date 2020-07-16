<?php
/**
 * @file
 * event_content_type.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function event_content_type_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Vital Records',
    'description' => '',
    'format' => 'full_html',
    'weight' => 3,
    'uuid' => '269f7e25-50cd-4b4e-9ef3-facc9504a575',
    'vocabulary_machine_name' => 'event_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Ethics',
    'description' => '',
    'format' => 'full_html',
    'weight' => 1,
    'uuid' => '3d0830bc-48f7-4055-b7a3-fd7169a05ccf',
    'vocabulary_machine_name' => 'event_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Elections',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '53a173ec-3962-4197-84b6-78932dafe17b',
    'vocabulary_machine_name' => 'event_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Clerk of the Board',
    'description' => '',
    'format' => 'full_html',
    'weight' => 4,
    'uuid' => '6e41e603-76cd-461c-92fe-de28f03b435e',
    'vocabulary_machine_name' => 'event_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Real Estate and Tax',
    'description' => '',
    'format' => 'full_html',
    'weight' => 2,
    'uuid' => 'b2806d5b-35d2-438b-9cae-5b6fd91580ef',
    'vocabulary_machine_name' => 'event_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
