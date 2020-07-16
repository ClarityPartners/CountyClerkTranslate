<?php
/**
 * @file
 * homepage_jump_entityqueue.features.inc
 */

/**
 * Implements hook_entityqueue_api().
 */
function homepage_jump_entityqueue_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}
