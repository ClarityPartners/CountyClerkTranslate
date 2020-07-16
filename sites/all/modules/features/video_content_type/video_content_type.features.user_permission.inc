<?php
/**
 * @file
 * video_content_type.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function video_content_type_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create video content'.
  $permissions['create video content'] = array(
    'name' => 'create video content',
    'roles' => array(
      'Site Builder' => 'Site Builder',
      'Site Editor' => 'Site Editor',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video content'.
  $permissions['delete any video content'] = array(
    'name' => 'delete any video content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video content'.
  $permissions['delete own video content'] = array(
    'name' => 'delete own video content',
    'roles' => array(
      'Site Builder' => 'Site Builder',
      'Site Editor' => 'Site Editor',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video content'.
  $permissions['edit any video content'] = array(
    'name' => 'edit any video content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Builder' => 'Site Builder',
      'Site Editor' => 'Site Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video content'.
  $permissions['edit own video content'] = array(
    'name' => 'edit own video content',
    'roles' => array(
      'Site Builder' => 'Site Builder',
      'Site Editor' => 'Site Editor',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
