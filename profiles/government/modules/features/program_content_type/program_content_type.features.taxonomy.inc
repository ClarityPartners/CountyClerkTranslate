<?php
/**
 * @file
 * program_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function program_content_type_taxonomy_default_vocabularies() {
  return array(
    'program_types' => array(
      'name' => 'Program Types',
      'machine_name' => 'program_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
