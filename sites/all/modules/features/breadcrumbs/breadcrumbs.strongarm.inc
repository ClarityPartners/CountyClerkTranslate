<?php
/**
 * @file
 * breadcrumbs.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function breadcrumbs_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_home_link_title';
  $strongarm->value = 'Home';
  $export['crumbs_home_link_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_minimum_trail_items';
  $strongarm->value = '3';
  $export['crumbs_minimum_trail_items'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_node_parent_patterns';
  $strongarm->value = array(
    'agency' => '',
    'banner' => '',
    'page' => '',
    'broadcast' => '',
    'date' => '',
    'event' => '',
    'faq' => '',
    'file' => '',
    'government_body' => '',
    'i_want_to' => '',
    'jobs' => '',
    'location' => '',
    'news' => '',
    'person' => '',
    'program' => '',
    'service' => '[node:field_service_provider]',
    'video' => '',
  );
  $export['crumbs_node_parent_patterns'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_original_theme_breadcrumb';
  $strongarm->value = array(
    'county_clerk_bootstrap' => 'theme_breadcrumb',
    'adminimal' => 'theme_breadcrumb',
  );
  $export['crumbs_original_theme_breadcrumb'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_override_theme_breadcrumb';
  $strongarm->value = array(
    'theme_breadcrumb' => 'theme_breadcrumb',
  );
  $export['crumbs_override_theme_breadcrumb'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_separator';
  $strongarm->value = ' &raquo; ';
  $export['crumbs_separator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_separator_span';
  $strongarm->value = 0;
  $export['crumbs_separator_span'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_show_current_page';
  $strongarm->value = '2';
  $export['crumbs_show_current_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_show_front_page';
  $strongarm->value = 1;
  $export['crumbs_show_front_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_weights';
  $strongarm->value = array(
    'entityreference.*' => 1,
    'crumbs.entityParent.node.service' => 2,
    '*' => FALSE,
    'crumbs.*' => FALSE,
    'crumbs.home_title' => FALSE,
    'menu.hierarchy.*' => FALSE,
    'path' => FALSE,
    'entityreference.field_service_type.*' => FALSE,
    'entityreference.field_service_type.node.service' => FALSE,
    'entityreference.field_agency_type.*' => FALSE,
  );
  $export['crumbs_weights'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_breadcrumb2__breadcrumb2';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_breadcrumb2__breadcrumb2'] = $strongarm;

  return $export;
}
