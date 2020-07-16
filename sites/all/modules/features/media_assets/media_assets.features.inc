<?php
/**
 * @file
 * media_assets.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function media_assets_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function media_assets_node_info() {
  $items = array(
    'media_assets' => array(
      'name' => t('Media Assets'),
      'base' => 'node_content',
      'description' => t('This content is for pictures and logos for press people to use in official media coverage.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('This single node should have all the main press assets attached.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
