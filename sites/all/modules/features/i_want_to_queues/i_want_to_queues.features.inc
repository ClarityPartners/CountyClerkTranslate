<?php
/**
 * @file
 * i_want_to_queues.features.inc
 */

/**
 * Implements hook_entityqueue_api().
 */
function i_want_to_queues_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}
