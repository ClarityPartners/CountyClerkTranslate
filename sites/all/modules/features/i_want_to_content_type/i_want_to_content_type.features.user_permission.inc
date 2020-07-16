<?php
/**
 * @file
 * i_want_to_content_type.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function i_want_to_content_type_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create i_want_to content'.
  $permissions['create i_want_to content'] = array(
    'name' => 'create i_want_to content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Builder' => 'Site Builder',
      'Site Editor' => 'Site Editor',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any i_want_to content'.
  $permissions['delete any i_want_to content'] = array(
    'name' => 'delete any i_want_to content',
    'roles' => array(
      'Site Builder' => 'Site Builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own i_want_to content'.
  $permissions['delete own i_want_to content'] = array(
    'name' => 'delete own i_want_to content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Builder' => 'Site Builder',
      'Site Editor' => 'Site Editor',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any i_want_to content'.
  $permissions['edit any i_want_to content'] = array(
    'name' => 'edit any i_want_to content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Builder' => 'Site Builder',
      'Site Editor' => 'Site Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own i_want_to content'.
  $permissions['edit own i_want_to content'] = array(
    'name' => 'edit own i_want_to content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Builder' => 'Site Builder',
      'Site Editor' => 'Site Editor',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
