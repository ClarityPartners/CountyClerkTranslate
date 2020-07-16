<?php
/**
 * @file
 * location_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function location_content_type_taxonomy_default_vocabularies() {
  return array(
    'location_category' => array(
      'name' => 'Location Category',
      'machine_name' => 'location_category',
      'description' => 'location categories',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'location_types' => array(
      'name' => 'Location Types',
      'machine_name' => 'location_types',
      'description' => 'Types of locations.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
