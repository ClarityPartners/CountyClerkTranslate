<?php
/**
 * @file
 * location_content_type.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function location_content_type_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Event Location',
    'description' => '',
    'format' => 'full_html',
    'weight' => 1,
    'uuid' => '024cd397-9df1-4813-aff9-e63787955f41',
    'vocabulary_machine_name' => 'location_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Main Office Locations',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '272e8a53-deb2-45ce-ab93-28cbd5702f48',
    'vocabulary_machine_name' => 'location_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
