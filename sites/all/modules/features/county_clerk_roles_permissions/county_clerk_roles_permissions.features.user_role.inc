<?php
/**
 * @file
 * county_clerk_roles_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function county_clerk_roles_permissions_user_default_roles() {
  $roles = array();

  // Exported role: Author.
  $roles['Author'] = array(
    'name' => 'Author',
    'weight' => 16,
  );

  // Exported role: Editor.
  $roles['Editor'] = array(
    'name' => 'Editor',
    'weight' => 15,
  );

  // Exported role: Site Author.
  $roles['Site Author'] = array(
    'name' => 'Site Author',
    'weight' => 14,
  );

  // Exported role: Site Builder.
  $roles['Site Builder'] = array(
    'name' => 'Site Builder',
    'weight' => 11,
  );

  // Exported role: Site Editor.
  $roles['Site Editor'] = array(
    'name' => 'Site Editor',
    'weight' => 13,
  );

  // Exported role: Site Technical.
  $roles['Site Technical'] = array(
    'name' => 'Site Technical',
    'weight' => 12,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 10,
  );

  return $roles;
}
