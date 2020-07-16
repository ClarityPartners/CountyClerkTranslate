<?php
/**
 * @file
 * broadcast_type.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function broadcast_type_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Alert (yellow)',
    'description' => '<p>medium level alert</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '19909a2e-5608-4a74-a091-0679f38f01fa',
    'vocabulary_machine_name' => 'broadcast_type',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Emergency (red)',
    'description' => '<p>high level alert</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '2a2f9a47-93ca-4050-a8a6-28d36067e79c',
    'vocabulary_machine_name' => 'broadcast_type',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Announcement (green)',
    'description' => '<p>low level alert</p>
',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'c99dcc47-cf4a-4c92-a873-fd59d5753f3a',
    'vocabulary_machine_name' => 'broadcast_type',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
