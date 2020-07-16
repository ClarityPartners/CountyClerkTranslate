<?php
/**
 * @file
 * homepage_department_queue.features.inc
 */

/**
 * Implements hook_entityqueue_api().
 */
function homepage_department_queue_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}
