<?php
/**
 * @file
 * video_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function video_content_type_taxonomy_default_vocabularies() {
  return array(
    'file_types' => array(
      'name' => 'File Types',
      'machine_name' => 'file_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
