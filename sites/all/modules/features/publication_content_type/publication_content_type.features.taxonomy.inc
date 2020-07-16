<?php
/**
 * @file
 * publication_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function publication_content_type_taxonomy_default_vocabularies() {
  return array(
    'publication_categories' => array(
      'name' => 'Publication Categories',
      'machine_name' => 'publication_categories',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'publication_types' => array(
      'name' => 'Publication Types',
      'machine_name' => 'publication_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
