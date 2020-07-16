<?php
/**
 * @file
 * county_clerk_workbench.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function county_clerk_workbench_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
