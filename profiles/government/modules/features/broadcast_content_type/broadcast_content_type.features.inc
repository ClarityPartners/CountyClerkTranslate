<?php
/**
 * @file
 * broadcast_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function broadcast_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function broadcast_content_type_node_info() {
  $items = array(
    'broadcast' => array(
      'name' => t('Broadcast'),
      'base' => 'node_content',
      'description' => t('Holds information for display in time-sensitive messages across the entire site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
