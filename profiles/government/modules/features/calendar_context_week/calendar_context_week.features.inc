<?php
/**
 * @file
 * calendar_context_week.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function calendar_context_week_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
