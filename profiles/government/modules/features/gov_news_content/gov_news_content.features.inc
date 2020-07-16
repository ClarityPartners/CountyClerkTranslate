<?php
/**
 * @file
 * gov_news_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gov_news_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function gov_news_content_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
