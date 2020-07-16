<?php
/**
 * @file
 * homepage_banner_entityqueue.features.inc
 */

/**
 * Implements hook_entityqueue_api().
 */
function homepage_banner_entityqueue_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}
