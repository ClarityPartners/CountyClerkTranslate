<?php
/**
 * @file
 * agency_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function agency_content_type_taxonomy_default_vocabularies() {
  return array(
    'agency_types' => array(
      'name' => 'Agency Types',
      'machine_name' => 'agency_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
