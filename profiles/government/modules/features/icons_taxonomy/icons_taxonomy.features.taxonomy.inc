<?php
/**
 * @file
 * icons_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function icons_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'icons' => array(
      'name' => 'Icons',
      'machine_name' => 'icons',
      'description' => 'Term based icons.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
