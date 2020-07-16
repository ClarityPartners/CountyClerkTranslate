<?php
/**
 * @file
 * search_results_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function search_results_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
