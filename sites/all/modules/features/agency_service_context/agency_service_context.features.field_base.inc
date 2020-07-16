<?php
/**
 * @file
 * agency_service_context.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function agency_service_context_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_i_want_to_queue'.
  $field_bases['field_i_want_to_queue'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_i_want_to_queue',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'viewfield',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'viewfield',
  );

  return $field_bases;
}
