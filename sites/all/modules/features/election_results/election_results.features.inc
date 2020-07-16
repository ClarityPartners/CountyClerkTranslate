<?php
/**
 * @file
 * election_results.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function election_results_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function election_results_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function election_results_node_info() {
  $items = array(
    'election_results' => array(
      'name' => t('Election Results'),
      'base' => 'node_content',
      'description' => t('This content type contains the results for an election'),
      'has_title' => '1',
      'title_label' => t('Election Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
