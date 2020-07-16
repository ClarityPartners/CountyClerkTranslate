<?php
/**
 * @file
 * agency_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function agency_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
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
function agency_content_type_node_info() {
  $items = array(
    'agency' => array(
      'name' => t('Agency'),
      'base' => 'node_content',
      'description' => t('Holds information about Bureaus, Departments, Offices, Functions, or Authorities.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
