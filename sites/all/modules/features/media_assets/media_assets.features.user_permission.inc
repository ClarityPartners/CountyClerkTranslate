<?php
/**
 * @file
 * media_assets.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function media_assets_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create media_assets content'.
  $permissions['create media_assets content'] = array(
    'name' => 'create media_assets content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any media_assets content'.
  $permissions['delete any media_assets content'] = array(
    'name' => 'delete any media_assets content',
    'roles' => array(
      'Site Builder' => 'Site Builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own media_assets content'.
  $permissions['delete own media_assets content'] = array(
    'name' => 'delete own media_assets content',
    'roles' => array(
      'Site Builder' => 'Site Builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any media_assets content'.
  $permissions['edit any media_assets content'] = array(
    'name' => 'edit any media_assets content',
    'roles' => array(
      'Editor' => 'Editor',
      'Site Builder' => 'Site Builder',
      'Site Editor' => 'Site Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own media_assets content'.
  $permissions['edit own media_assets content'] = array(
    'name' => 'edit own media_assets content',
    'roles' => array(
      'Site Builder' => 'Site Builder',
      'Site Editor' => 'Site Editor',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
