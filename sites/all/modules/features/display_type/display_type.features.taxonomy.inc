<?php
/**
 * @file
 * display_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function display_type_taxonomy_default_vocabularies() {
  return array(
    'display_type' => array(
      'name' => 'Display Type',
      'machine_name' => 'display_type',
      'description' => 'display type for context ',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
