<?php
/**
 * @file
 * general_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function general_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function general_content_type_node_info() {
  $items = array(
    'general' => array(
      'name' => t('General'),
      'base' => 'node_content',
      'description' => t('General content. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
