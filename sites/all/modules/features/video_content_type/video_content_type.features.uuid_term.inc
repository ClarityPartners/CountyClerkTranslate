<?php
/**
 * @file
 * video_content_type.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function video_content_type_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Video',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'f613e35b-d3f0-4359-9348-e7cb22714aaa',
    'vocabulary_machine_name' => 'file_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
