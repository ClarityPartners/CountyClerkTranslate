<?php
/**
 * @file
 * services_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function services_content_type_taxonomy_default_vocabularies() {
  return array(
    'service_category' => array(
      'name' => 'Service Types',
      'machine_name' => 'service_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
