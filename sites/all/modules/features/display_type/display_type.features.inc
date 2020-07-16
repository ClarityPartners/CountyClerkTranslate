<?php
/**
 * @file
 * display_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function display_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
