<?php
/**
 * @file
 * person_content_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function person_content_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_person_email'.
  $field_bases['field_person_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_person_email',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'email',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'email',
  );

  return $field_bases;
}
