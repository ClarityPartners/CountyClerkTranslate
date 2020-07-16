<?php
/**
 * @file
 * linkit_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function linkit_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_linkit-profiles:admin/config/content/linkit.
  $menu_links['management_linkit-profiles:admin/config/content/linkit'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/linkit',
    'router_path' => 'admin/config/content/linkit',
    'link_title' => 'Linkit Profiles',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage Linkit profiles.',
      ),
      'identifier' => 'management_linkit-profiles:admin/config/content/linkit',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_content-authoring:admin/config/content',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Linkit Profiles');

  return $menu_links;
}
