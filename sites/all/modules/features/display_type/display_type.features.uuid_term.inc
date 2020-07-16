<?php
/**
 * @file
 * display_type.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function display_type_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Landing Page',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '5d6f0fa2-b4e7-4b28-af3f-ae072fa15913',
    'vocabulary_machine_name' => 'display_type',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'non-Landing Page',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '72113e4a-8b0d-4cea-9653-9604ad60e772',
    'vocabulary_machine_name' => 'display_type',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
