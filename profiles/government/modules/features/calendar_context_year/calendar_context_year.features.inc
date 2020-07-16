<?php
/**
 * @file
 * calendar_context_year.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function calendar_context_year_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
