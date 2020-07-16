<?php
/**
 * @file
 * broadcast_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function broadcast_type_taxonomy_default_vocabularies() {
  return array(
    'broadcast_type' => array(
      'name' => 'Broadcast Type',
      'machine_name' => 'broadcast_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
