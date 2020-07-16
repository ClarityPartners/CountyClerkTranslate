<?php
/**
 * @file
 * gov_sharethis.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gov_sharethis_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
