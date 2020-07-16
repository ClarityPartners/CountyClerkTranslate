<?php
/**
 * @file
 * workbench_login.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function workbench_login_default_rules_configuration() {
  $items = array();
  $items['rules_workbench_login'] = entity_import('rules_config', '{ "rules_workbench_login" : {
      "LABEL" : "Workbench login",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "DO" : [ { "redirect" : { "url" : "admin\\/workbench" } } ]
    }
  }');
  return $items;
}
