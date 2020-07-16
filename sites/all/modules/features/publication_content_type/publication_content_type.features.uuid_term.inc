<?php
/**
 * @file
 * publication_content_type.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function publication_content_type_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Elections',
    'description' => '',
    'format' => 'full_html',
    'weight' => 2,
    'uuid' => '11aed8ec-e0ea-490f-b594-77710fe5760b',
    'vocabulary_machine_name' => 'publication_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Maps - County Commissioner Districts',
    'description' => '',
    'format' => 'full_html',
    'weight' => 13,
    'uuid' => '13a9a8e9-8748-43f3-8a14-ae9151a5a69e',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Maps - State Representative Districts',
    'description' => '',
    'format' => 'full_html',
    'weight' => 20,
    'uuid' => '2e97aa2a-243e-41b5-907d-4e6e832d932e',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Maps - TIFs',
    'description' => '',
    'format' => 'full_html',
    'weight' => 22,
    'uuid' => '3552fcca-9473-46b0-b0eb-3096e5962ca6',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Maps - Municipalities',
    'description' => '',
    'format' => 'full_html',
    'weight' => 18,
    'uuid' => '356a7149-2426-4bd5-9adc-40da33ac7b9f',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Maps - County Board of Review Districts',
    'description' => '',
    'format' => 'full_html',
    'weight' => 12,
    'uuid' => '45be72be-462f-481e-bf52-4363a9689afd',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Maps - Judicial Subcircuit Districts',
    'description' => '',
    'format' => 'full_html',
    'weight' => 17,
    'uuid' => '4a63c5c2-8a9e-4fbb-acf3-b4d1b9c94494',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Maps - Congressional Districts',
    'description' => '',
    'format' => 'full_html',
    'weight' => 11,
    'uuid' => '4eb230c5-589b-4604-88d9-81c079ee87c1',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Map',
    'description' => '',
    'format' => 'full_html',
    'weight' => 5,
    'uuid' => '69319c2a-4e46-424d-b244-33c54b73b067',
    'vocabulary_machine_name' => 'publication_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Press Release',
    'description' => '',
    'format' => 'full_html',
    'weight' => 25,
    'uuid' => '90002572-fffe-4de7-801e-43952cfbb295',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Maps - Countywide',
    'description' => '',
    'format' => 'full_html',
    'weight' => 14,
    'uuid' => '9e6a6b81-6d24-4b57-a226-7e95ab56f3f1',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Real Estate and Taxes',
    'description' => '',
    'format' => 'full_html',
    'weight' => 7,
    'uuid' => 'a0455ca3-a00c-4ff0-a36b-82a1a91ee718',
    'vocabulary_machine_name' => 'publication_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Advertisement',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'a7b57471-d344-461a-b958-9ab506ba397a',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Maps - Townships',
    'description' => '',
    'format' => 'full_html',
    'weight' => 23,
    'uuid' => 'b7de39e0-13b6-472e-a650-7db69132749c',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Maps - School Districts',
    'description' => '',
    'format' => 'full_html',
    'weight' => 19,
    'uuid' => 'c3c7423b-fc51-4cb3-a684-3f3d9bb3a972',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Employment',
    'description' => '',
    'format' => 'full_html',
    'weight' => 6,
    'uuid' => 'cd21f2cf-7b01-4027-ba39-8f8760225a3b',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Forms',
    'description' => '',
    'format' => 'full_html',
    'weight' => 9,
    'uuid' => 'cdb151bb-8d85-45c6-b687-09ba745693ab',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Contested Races',
    'description' => '',
    'format' => 'full_html',
    'weight' => 4,
    'uuid' => 'd0c8dc3f-539f-4c4f-9637-810cb5ef880d',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Vital Records',
    'description' => '',
    'format' => 'full_html',
    'weight' => 8,
    'uuid' => 'd432f831-d9e1-4875-bb81-cfa34cd4cd32',
    'vocabulary_machine_name' => 'publication_types',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Maps - Election Results',
    'description' => '',
    'format' => 'full_html',
    'weight' => 16,
    'uuid' => 'd75b68d1-8644-47cc-a556-e5aed7fa8da6',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Maps - Early Voting',
    'description' => '',
    'format' => 'full_html',
    'weight' => 15,
    'uuid' => 'da96dac5-f2d3-4aca-ac73-b901ca115e70',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Maps - State Senate Districts',
    'description' => '',
    'format' => 'full_html',
    'weight' => 21,
    'uuid' => 'de452554-fb44-44ce-a0f9-4cf3b966339e',
    'vocabulary_machine_name' => 'publication_categories',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
