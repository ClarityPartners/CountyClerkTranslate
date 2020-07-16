<?php
/**
 * @file
 * file_content_type.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function file_content_type_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Image',
    'description' => '<p>&nbsp;</p><p>&nbsp;</p>',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '6aefcafb-66fb-4c9b-9576-96d738ab2579',
    'vocabulary_machine_name' => 'file_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Audio',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '9dfb3715-def4-4c23-97e0-9ed15ac5dc7a',
    'vocabulary_machine_name' => 'file_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Document',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'da612498-1d69-4540-882f-b1c3724f9022',
    'vocabulary_machine_name' => 'file_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
