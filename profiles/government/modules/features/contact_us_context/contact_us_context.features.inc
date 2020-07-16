<?php
/**
 * @file
 * contact_us_context.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function contact_us_context_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
