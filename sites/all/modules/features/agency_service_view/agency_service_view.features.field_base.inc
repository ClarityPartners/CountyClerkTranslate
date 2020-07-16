<?php
/**
 * @file
 * agency_service_view.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function agency_service_view_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_agency_related'.
  $field_bases['field_agency_related'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_agency_related',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'entityqueue' => array(
            'status' => 0,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'agency' => 'agency',
          'general' => 'general',
          'service' => 'service',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
