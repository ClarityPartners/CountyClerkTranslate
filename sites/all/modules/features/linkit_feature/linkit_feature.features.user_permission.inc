<?php
/**
 * @file
 * linkit_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function linkit_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer linkit'.
  $permissions['administer linkit'] = array(
    'name' => 'administer linkit',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'linkit',
  );

  return $permissions;
}
