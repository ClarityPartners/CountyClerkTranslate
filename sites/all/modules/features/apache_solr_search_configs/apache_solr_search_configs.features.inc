<?php
/**
 * @file
 * apache_solr_search_configs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function apache_solr_search_configs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
