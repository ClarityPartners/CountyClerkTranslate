<?php
/**
 * @file
 * i_want_to_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function i_want_to_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function i_want_to_content_type_node_info() {
  $items = array(
    'i_want_to' => array(
      'name' => t('I Want To'),
      'base' => 'node_content',
      'description' => t('Hold links for actionable items to be featured in "I Want To" section on site'),
      'has_title' => '1',
      'title_label' => t('Action'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
