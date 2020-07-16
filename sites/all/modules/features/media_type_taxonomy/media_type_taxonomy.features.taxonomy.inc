<?php
/**
 * @file
 * media_type_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function media_type_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'media_type' => array(
      'name' => 'Media Room Topic',
      'machine_name' => 'media_type',
      'description' => 'media type vocabulary ',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
