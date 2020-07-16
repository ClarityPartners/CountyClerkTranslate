<?php
/**
 * @file
 * government_body_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function government_body_content_type_taxonomy_default_vocabularies() {
  return array(
    'government_position_types' => array(
      'name' => 'Government Position Types',
      'machine_name' => 'government_position_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
