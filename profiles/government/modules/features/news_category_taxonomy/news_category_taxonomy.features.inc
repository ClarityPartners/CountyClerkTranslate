<?php
/**
 * @file
 * news_category_taxonomy.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function news_category_taxonomy_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  if ($module == "taxonomy_display" && $api == "taxonomy_display") {
    return array("version" => "1");
  }
}
