<?php
/**
 * @file
 * department_panel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function department_panel_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}
