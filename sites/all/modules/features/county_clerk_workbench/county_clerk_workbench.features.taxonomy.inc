<?php
/**
 * @file
 * county_clerk_workbench.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function county_clerk_workbench_taxonomy_default_vocabularies() {
  return array(
    'content_publishing_workflow' => array(
      'name' => 'Content Publishing Workflow',
      'machine_name' => 'content_publishing_workflow',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
