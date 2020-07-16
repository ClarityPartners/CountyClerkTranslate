<?php
/**
 * @file
 * bean_types.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bean_types_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'edit any image bean'.
  $permissions['edit any image bean'] = array(
    'name' => 'edit any image bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'view any events_and_twitter bean'.
  $permissions['view any events_and_twitter bean'] = array(
    'name' => 'view any events_and_twitter bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'view any hero bean'.
  $permissions['view any hero bean'] = array(
    'name' => 'view any hero bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'view any video bean'.
  $permissions['view any video bean'] = array(
    'name' => 'view any video bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
