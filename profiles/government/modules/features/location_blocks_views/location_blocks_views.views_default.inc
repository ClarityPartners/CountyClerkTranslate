<?php
/**
 * @file
 * location_blocks_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function location_blocks_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'location_blocks';
  $view->description = 'Blocks showing main and secondary locations';
  $view->tag = 'blocks, agency';
  $view->base_table = 'node';
  $view->human_name = 'location_blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Content: Location (field_location) */
  $handler->display->display_options['relationships']['field_location_value']['id'] = 'field_location_value';
  $handler->display->display_options['relationships']['field_location_value']['table'] = 'field_data_field_location';
  $handler->display->display_options['relationships']['field_location_value']['field'] = 'field_location_value';
  $handler->display->display_options['relationships']['field_location_value']['delta'] = '-1';
  /* Field: Field collection item: Location Title */
  $handler->display->display_options['fields']['field_location_title']['id'] = 'field_location_title';
  $handler->display->display_options['fields']['field_location_title']['table'] = 'field_data_field_location_title';
  $handler->display->display_options['fields']['field_location_title']['field'] = 'field_location_title';
  $handler->display->display_options['fields']['field_location_title']['relationship'] = 'field_location_value';
  $handler->display->display_options['fields']['field_location_title']['label'] = '';
  $handler->display->display_options['fields']['field_location_title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['relationship'] = 'field_location_value';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Field collection item: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['relationship'] = 'field_location_value';
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['relationship'] = 'field_location_value';
  $handler->display->display_options['fields']['field_phone']['label'] = 'Telephone';
  $handler->display->display_options['fields']['field_phone']['hide_empty'] = TRUE;
  /* Field: Field collection item: Fax */
  $handler->display->display_options['fields']['field_fax']['id'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['table'] = 'field_data_field_fax';
  $handler->display->display_options['fields']['field_fax']['field'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['relationship'] = 'field_location_value';
  $handler->display->display_options['fields']['field_fax']['hide_empty'] = TRUE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'agency' => 'agency',
    'service' => 'service',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field collection item: Location Type (field_main_location) */
  $handler->display->display_options['filters']['field_main_location_value']['id'] = 'field_main_location_value';
  $handler->display->display_options['filters']['field_main_location_value']['table'] = 'field_data_field_main_location';
  $handler->display->display_options['filters']['field_main_location_value']['field'] = 'field_main_location_value';
  $handler->display->display_options['filters']['field_main_location_value']['relationship'] = 'field_location_value';
  $handler->display->display_options['filters']['field_main_location_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_main_location_value']['group'] = 1;
  /* Filter criterion: Field collection item: Address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['filters']['field_address_thoroughfare']['id'] = 'field_address_thoroughfare';
  $handler->display->display_options['filters']['field_address_thoroughfare']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_thoroughfare']['field'] = 'field_address_thoroughfare';
  $handler->display->display_options['filters']['field_address_thoroughfare']['relationship'] = 'field_location_value';
  $handler->display->display_options['filters']['field_address_thoroughfare']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_address_thoroughfare']['group'] = 1;

  /* Display: Main address Block */
  $handler = $view->new_display('block', 'Main address Block', 'block');

  /* Display: Map Main Location Block */
  $handler = $view->new_display('block', 'Map Main Location Block', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['relationship'] = 'field_location_value';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['type'] = 'addressfield_staticmap';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'zoom_level' => '14',
    'map_size' => '400x186',
    'map_style' => 'roadmap',
    'advanced_settings_index' => '0',
  );

  /* Display: Main Location Hours Block */
  $handler = $view->new_display('block', 'Main Location Hours Block', 'block_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Hours */
  $handler->display->display_options['fields']['field_hours']['id'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['table'] = 'field_data_field_hours';
  $handler->display->display_options['fields']['field_hours']['field'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['relationship'] = 'field_location_value';
  $handler->display->display_options['fields']['field_hours']['label'] = '';
  $handler->display->display_options['fields']['field_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['click_sort_column'] = 'day';
  $handler->display->display_options['fields']['field_hours']['settings'] = array(
    'showclosed' => 'all',
    'date_first_day' => '0',
    'daysformat' => 'long',
    'hoursformat' => '1',
    'compress' => 0,
    'grouped' => 0,
    'closedformat' => 'Closed',
    'separator_days' => '<br />',
    'separator_grouped_days' => ' - ',
    'separator_day_hours' => ': ',
    'separator_hours_hours' => '-',
    'separator_more_hours' => ', ',
    'current_status' => array(
      'position' => 'hide',
      'open_text' => 'Currently open!',
      'closed_text' => 'Currently closed',
    ),
  );
  $handler->display->display_options['fields']['field_hours']['delta_offset'] = '0';

  /* Display: Secondary Locations Block */
  $handler = $view->new_display('block', 'Secondary Locations Block', 'block_3');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Location Title */
  $handler->display->display_options['fields']['field_location_title']['id'] = 'field_location_title';
  $handler->display->display_options['fields']['field_location_title']['table'] = 'field_data_field_location_title';
  $handler->display->display_options['fields']['field_location_title']['field'] = 'field_location_title';
  $handler->display->display_options['fields']['field_location_title']['relationship'] = 'field_location_value';
  $handler->display->display_options['fields']['field_location_title']['label'] = '';
  $handler->display->display_options['fields']['field_location_title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['relationship'] = 'field_location_value';
  $handler->display->display_options['fields']['field_address']['label'] = '';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['relationship'] = 'field_location_value';
  $handler->display->display_options['fields']['field_phone']['label'] = 'Telephone';
  $handler->display->display_options['fields']['field_phone']['hide_empty'] = TRUE;
  /* Field: Field collection item: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['relationship'] = 'field_location_value';
  $handler->display->display_options['fields']['field_email']['hide_empty'] = TRUE;
  /* Field: Field collection item: Fax */
  $handler->display->display_options['fields']['field_fax']['id'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['table'] = 'field_data_field_fax';
  $handler->display->display_options['fields']['field_fax']['field'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['relationship'] = 'field_location_value';
  $handler->display->display_options['fields']['field_fax']['hide_empty'] = TRUE;
  /* Field: Field collection item: Hours */
  $handler->display->display_options['fields']['field_hours']['id'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['table'] = 'field_data_field_hours';
  $handler->display->display_options['fields']['field_hours']['field'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['relationship'] = 'field_location_value';
  $handler->display->display_options['fields']['field_hours']['click_sort_column'] = 'day';
  $handler->display->display_options['fields']['field_hours']['settings'] = array(
    'showclosed' => 'open',
    'date_first_day' => '0',
    'daysformat' => 'long',
    'hoursformat' => '1',
    'compress' => 0,
    'grouped' => 1,
    'closedformat' => 'Closed',
    'separator_days' => '<br />',
    'separator_grouped_days' => ' - ',
    'separator_day_hours' => ': ',
    'separator_hours_hours' => '-',
    'separator_more_hours' => ', ',
    'current_status' => array(
      'position' => 'hide',
      'open_text' => 'Currently open!',
      'closed_text' => 'Currently closed',
    ),
  );
  $handler->display->display_options['fields']['field_hours']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'agency' => 'agency',
    'service' => 'service',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field collection item: Location Type (field_main_location) */
  $handler->display->display_options['filters']['field_main_location_value']['id'] = 'field_main_location_value';
  $handler->display->display_options['filters']['field_main_location_value']['table'] = 'field_data_field_main_location';
  $handler->display->display_options['filters']['field_main_location_value']['field'] = 'field_main_location_value';
  $handler->display->display_options['filters']['field_main_location_value']['relationship'] = 'field_location_value';
  $handler->display->display_options['filters']['field_main_location_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_main_location_value']['value'] = array(
    1 => '1',
    3 => '3',
  );
  $handler->display->display_options['filters']['field_main_location_value']['group'] = 1;
  /* Filter criterion: Field collection item: Address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['filters']['field_address_thoroughfare']['id'] = 'field_address_thoroughfare';
  $handler->display->display_options['filters']['field_address_thoroughfare']['table'] = 'field_data_field_address';
  $handler->display->display_options['filters']['field_address_thoroughfare']['field'] = 'field_address_thoroughfare';
  $handler->display->display_options['filters']['field_address_thoroughfare']['relationship'] = 'field_location_value';
  $handler->display->display_options['filters']['field_address_thoroughfare']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_address_thoroughfare']['group'] = 1;
  $export['location_blocks'] = $view;

  return $export;
}
