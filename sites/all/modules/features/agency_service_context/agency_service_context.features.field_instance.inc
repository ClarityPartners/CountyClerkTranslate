<?php
/**
 * @file
 * agency_service_context.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function agency_service_context_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-agency-field_i_want_to_queue'.
  $field_instances['node-agency-field_i_want_to_queue'] = array(
    'bundle' => 'agency',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 25,
      ),
      'search_index' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_i_want_to_queue',
    'label' => 'I Want to Queue',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'admin_views_file' => 0,
        'admin_views_node' => 0,
        'admin_views_user' => 0,
        'departments' => 0,
        'entity_reference_list_by_section' => 0,
        'homepage_jump' => 0,
        'i_want_to_queues' => 'i_want_to_queues',
        'level_3_menu' => 0,
        'media_default' => 0,
        'news' => 0,
        'news_archive' => 0,
        'news_categories' => 0,
        'news_homepage' => 0,
        'services' => 0,
      ),
      'force_default' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('I Want to Queue');

  return $field_instances;
}
