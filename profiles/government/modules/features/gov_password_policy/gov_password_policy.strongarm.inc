<?php
/**
 * @file
 * gov_password_policy.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function gov_password_policy_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'password_policy_admin';
  $strongarm->value = 1;
  $export['password_policy_admin'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'password_policy_begin';
  $strongarm->value = '0';
  $export['password_policy_begin'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'password_policy_block';
  $strongarm->value = '0';
  $export['password_policy_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'password_policy_force_change_extra_allowed_paths';
  $strongarm->value = 'system/ajax';
  $export['password_policy_force_change_extra_allowed_paths'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'password_policy_force_change_reset';
  $strongarm->value = 0;
  $export['password_policy_force_change_reset'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'password_policy_show_restrictions';
  $strongarm->value = 0;
  $export['password_policy_show_restrictions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'password_policy_warning_body';
  $strongarm->value = '[user:name],

Your password at [site:name] will expire in less than [password-policy:days-left] day(s).

Please go to [password-policy:password-edit-url] to change your password.';
  $export['password_policy_warning_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'password_policy_warning_subject';
  $strongarm->value = 'Password expiration warning for [user:name] at [site:name]';
  $export['password_policy_warning_subject'] = $strongarm;

  return $export;
}
