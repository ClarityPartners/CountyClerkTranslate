<?php
/**
 * @file
 * file_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function file_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function file_content_type_node_info() {
  $items = array(
    'file' => array(
      'name' => t('File'),
      'base' => 'node_content',
      'description' => t('Allowable file upload types: doc docx xls xlsx pdf txt jpg png gif'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('The title will be the display name of the file for end users.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
