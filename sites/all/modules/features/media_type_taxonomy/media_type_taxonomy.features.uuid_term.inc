<?php
/**
 * @file
 * media_type_taxonomy.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function media_type_taxonomy_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Ethics',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '0292b695-f070-410f-ac3b-9b583d9893c7',
    'vocabulary_machine_name' => 'media_type',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Vital Records',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '21cb6e82-080e-494c-8a38-e1b5192ea3d8',
    'vocabulary_machine_name' => 'media_type',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Elections',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '747ecf4d-0140-40fd-ac76-7488f0e15ae6',
    'vocabulary_machine_name' => 'media_type',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Real Estate and Tax',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'baa6af73-7ea9-4f70-adc9-e0770ad91546',
    'vocabulary_machine_name' => 'media_type',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Clerk of the Board',
    'description' => '<p>&nbsp;</p><p>&nbsp;</p>',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'e7be8b0d-47b6-4ab9-be33-0d5d81b27f03',
    'vocabulary_machine_name' => 'media_type',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
