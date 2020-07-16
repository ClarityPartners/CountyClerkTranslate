<?php
/**
 * @file
 * government_body_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function government_body_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function government_body_content_type_node_info() {
  $items = array(
    'government_body' => array(
      'name' => t('Government Body'),
      'base' => 'node_content',
      'description' => t('Holds information about entities such as boards, committees, commissions, etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
