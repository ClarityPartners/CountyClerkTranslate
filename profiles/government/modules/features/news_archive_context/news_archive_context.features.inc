<?php
/**
 * @file
 * news_archive_context.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function news_archive_context_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
