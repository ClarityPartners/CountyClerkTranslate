<?php
/**
 * @file
 * event_category_taxonomy.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function event_category_taxonomy_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'County Holiday',
    'description' => '',
    'format' => 'full_html',
    'weight' => 2,
    'uuid' => '0cc24e94-8e14-4555-ba8a-1020a33a30bb',
    'vocabulary_machine_name' => 'event_category',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'High School or College Event',
    'description' => '',
    'format' => 'full_html',
    'weight' => 4,
    'uuid' => '2555bab9-a295-4235-8da5-3108751cf1f9',
    'vocabulary_machine_name' => 'event_category',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Deadline or Due Date',
    'description' => '',
    'format' => 'full_html',
    'weight' => 3,
    'uuid' => '2d236873-cf89-40fe-b067-15ab8da138ba',
    'vocabulary_machine_name' => 'event_category',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Voter Registration Training',
    'description' => '',
    'format' => 'full_html',
    'weight' => 1,
    'uuid' => '433d649f-207a-4aed-94c5-9c3a7666bb50',
    'vocabulary_machine_name' => 'event_category',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => 'e0e5d462-7ae0-4b86-815d-29dd6eb75630',
    ),
  );
  $terms[] = array(
    'name' => 'Informational Session on Clerk\'s office services',
    'description' => '',
    'format' => 'full_html',
    'weight' => 5,
    'uuid' => '6f9b9327-85ef-4830-99b6-658e44c2b767',
    'vocabulary_machine_name' => 'event_category',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Public Festival, Parade or Concert',
    'description' => '',
    'format' => 'full_html',
    'weight' => 7,
    'uuid' => '823c1647-dbc2-4e8a-ab0a-faabb7650039',
    'vocabulary_machine_name' => 'event_category',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Community Meeting or Forum',
    'description' => '',
    'format' => 'full_html',
    'weight' => 1,
    'uuid' => '962869d1-157c-4f5a-bc8d-c05639ad74df',
    'vocabulary_machine_name' => 'event_category',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Deputy Registrar Training',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'd5f84d4d-7459-47b4-8afa-f38c9b3d1712',
    'vocabulary_machine_name' => 'event_category',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => 'e0e5d462-7ae0-4b86-815d-29dd6eb75630',
    ),
  );
  $terms[] = array(
    'name' => 'Training',
    'description' => '',
    'format' => 'full_html',
    'weight' => 8,
    'uuid' => 'e0e5d462-7ae0-4b86-815d-29dd6eb75630',
    'vocabulary_machine_name' => 'event_category',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Board Meeting',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e863ba80-cdce-4036-a289-723c642965dc',
    'vocabulary_machine_name' => 'event_category',
  );
  return $terms;
}
