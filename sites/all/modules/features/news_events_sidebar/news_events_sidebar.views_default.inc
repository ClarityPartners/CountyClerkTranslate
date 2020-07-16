<?php
/**
 * @file
 * news_events_sidebar.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function news_events_sidebar_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'date_document_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'date & document block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Downloads';
  $handler->display->display_options['css_class'] = 'publish-block';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_location_target_id']['id'] = 'field_event_location_target_id';
  $handler->display->display_options['relationships']['field_event_location_target_id']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['relationships']['field_event_location_target_id']['field'] = 'field_event_location_target_id';
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_news_author']['id'] = 'field_news_author';
  $handler->display->display_options['fields']['field_news_author']['table'] = 'field_data_field_news_author';
  $handler->display->display_options['fields']['field_news_author']['field'] = 'field_news_author';
  $handler->display->display_options['fields']['field_news_author']['label'] = '';
  $handler->display->display_options['fields']['field_news_author']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_news_author']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_news_author']['element_class'] = 'published-by-author';
  $handler->display->display_options['fields']['field_news_author']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_news_author']['element_label_colon'] = FALSE;
  /* Field: Content: Document(s) */
  $handler->display->display_options['fields']['field_event_documents']['id'] = 'field_event_documents';
  $handler->display->display_options['fields']['field_event_documents']['table'] = 'field_data_field_event_documents';
  $handler->display->display_options['fields']['field_event_documents']['field'] = 'field_event_documents';
  $handler->display->display_options['fields']['field_event_documents']['label'] = '';
  $handler->display->display_options['fields']['field_event_documents']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_event_documents']['element_class'] = 'related-docs';
  $handler->display->display_options['fields']['field_event_documents']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_documents']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_documents']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_event_documents']['multi_type'] = 'ul';
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
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'news_block');

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'location-block';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class="block-title">Location Information</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Office Hours */
  $handler->display->display_options['fields']['field_location_office_hours']['id'] = 'field_location_office_hours';
  $handler->display->display_options['fields']['field_location_office_hours']['table'] = 'field_data_field_location_office_hours';
  $handler->display->display_options['fields']['field_location_office_hours']['field'] = 'field_location_office_hours';
  $handler->display->display_options['fields']['field_location_office_hours']['relationship'] = 'field_event_location_target_id';
  $handler->display->display_options['fields']['field_location_office_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_office_hours']['click_sort_column'] = 'day';
  $handler->display->display_options['fields']['field_location_office_hours']['settings'] = array(
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
  $handler->display->display_options['fields']['field_location_office_hours']['delta_offset'] = '0';
  /* Field: Content: External Event Link */
  $handler->display->display_options['fields']['field_event_link']['id'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['table'] = 'field_data_field_event_link';
  $handler->display->display_options['fields']['field_event_link']['field'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_link']['click_sort_column'] = 'url';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_event_registration']['id'] = 'field_event_registration';
  $handler->display->display_options['fields']['field_event_registration']['table'] = 'field_data_field_event_registration';
  $handler->display->display_options['fields']['field_event_registration']['field'] = 'field_event_registration';
  $handler->display->display_options['fields']['field_event_registration']['element_label_colon'] = FALSE;
  /* Field: Field: Location Email */
  $handler->display->display_options['fields']['field_location_email']['id'] = 'field_location_email';
  $handler->display->display_options['fields']['field_location_email']['table'] = 'field_data_field_location_email';
  $handler->display->display_options['fields']['field_location_email']['field'] = 'field_location_email';
  $handler->display->display_options['fields']['field_location_email']['relationship'] = 'field_event_location_target_id';
  $handler->display->display_options['fields']['field_location_email']['element_label_colon'] = FALSE;
  /* Field: Content: Phone Numbers */
  $handler->display->display_options['fields']['field_location_phone']['id'] = 'field_location_phone';
  $handler->display->display_options['fields']['field_location_phone']['table'] = 'field_data_field_location_phone';
  $handler->display->display_options['fields']['field_location_phone']['field'] = 'field_location_phone';
  $handler->display->display_options['fields']['field_location_phone']['relationship'] = 'field_event_location_target_id';
  $handler->display->display_options['fields']['field_location_phone']['label'] = '';
  $handler->display->display_options['fields']['field_location_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_phone']['settings'] = array(
    'add' => 'Add',
    'edit' => 'Edit',
    'translate' => '',
    'delete' => 'Delete',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_location_phone']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_location_phone']['multi_type'] = 'ul';
  /* Field: Content: Location Type */
  $handler->display->display_options['fields']['field_location_type']['id'] = 'field_location_type';
  $handler->display->display_options['fields']['field_location_type']['table'] = 'field_data_field_location_type';
  $handler->display->display_options['fields']['field_location_type']['field'] = 'field_location_type';
  $handler->display->display_options['fields']['field_location_type']['relationship'] = 'field_event_location_target_id';
  $handler->display->display_options['fields']['field_location_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_type']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'news_block' => 0,
    'block_1' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Location Information';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'location-block';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class="block-title">Location Information</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_location_target_id']['id'] = 'field_event_location_target_id';
  $handler->display->display_options['relationships']['field_event_location_target_id']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['relationships']['field_event_location_target_id']['field'] = 'field_event_location_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_service_main_location_target_id']['id'] = 'field_service_main_location_target_id';
  $handler->display->display_options['relationships']['field_service_main_location_target_id']['table'] = 'field_data_field_service_main_location';
  $handler->display->display_options['relationships']['field_service_main_location_target_id']['field'] = 'field_service_main_location_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_service_other_location_target_id']['id'] = 'field_service_other_location_target_id';
  $handler->display->display_options['relationships']['field_service_other_location_target_id']['table'] = 'field_data_field_service_other_location';
  $handler->display->display_options['relationships']['field_service_other_location_target_id']['field'] = 'field_service_other_location_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_service_main_location_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: Content: Office Hours */
  $handler->display->display_options['fields']['field_location_office_hours']['id'] = 'field_location_office_hours';
  $handler->display->display_options['fields']['field_location_office_hours']['table'] = 'field_data_field_location_office_hours';
  $handler->display->display_options['fields']['field_location_office_hours']['field'] = 'field_location_office_hours';
  $handler->display->display_options['fields']['field_location_office_hours']['relationship'] = 'field_service_main_location_target_id';
  $handler->display->display_options['fields']['field_location_office_hours']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_location_office_hours']['click_sort_column'] = 'day';
  $handler->display->display_options['fields']['field_location_office_hours']['settings'] = array(
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
  $handler->display->display_options['fields']['field_location_office_hours']['delta_offset'] = '0';
  /* Field: Field: Location Email */
  $handler->display->display_options['fields']['field_location_email']['id'] = 'field_location_email';
  $handler->display->display_options['fields']['field_location_email']['table'] = 'field_data_field_location_email';
  $handler->display->display_options['fields']['field_location_email']['field'] = 'field_location_email';
  $handler->display->display_options['fields']['field_location_email']['relationship'] = 'field_service_main_location_target_id';
  $handler->display->display_options['fields']['field_location_email']['hide_empty'] = TRUE;
  /* Field: Content: Phone Numbers */
  $handler->display->display_options['fields']['field_location_phone']['id'] = 'field_location_phone';
  $handler->display->display_options['fields']['field_location_phone']['table'] = 'field_data_field_location_phone';
  $handler->display->display_options['fields']['field_location_phone']['field'] = 'field_location_phone';
  $handler->display->display_options['fields']['field_location_phone']['relationship'] = 'field_service_main_location_target_id';
  $handler->display->display_options['fields']['field_location_phone']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_location_phone']['settings'] = array(
    'add' => 'Add',
    'edit' => 'Edit',
    'translate' => '',
    'delete' => 'Delete',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_location_phone']['delta_offset'] = '0';
  /* Field: Content: Location Type */
  $handler->display->display_options['fields']['field_location_type']['id'] = 'field_location_type';
  $handler->display->display_options['fields']['field_location_type']['table'] = 'field_data_field_location_type';
  $handler->display->display_options['fields']['field_location_type']['field'] = 'field_location_type';
  $handler->display->display_options['fields']['field_location_type']['relationship'] = 'field_service_main_location_target_id';
  $handler->display->display_options['fields']['field_location_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_location_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Other Location(s) */
  $handler->display->display_options['fields']['field_service_other_location']['id'] = 'field_service_other_location';
  $handler->display->display_options['fields']['field_service_other_location']['table'] = 'field_data_field_service_other_location';
  $handler->display->display_options['fields']['field_service_other_location']['field'] = 'field_service_other_location';
  $handler->display->display_options['fields']['field_service_other_location']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_service_other_location']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_service_other_location']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_service_other_location']['multi_type'] = 'ul';

  /* Display: agency location Block */
  $handler = $view->new_display('block', 'agency location Block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Location Information';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'location-block';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class="block-title">Location Information</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_location_target_id']['id'] = 'field_event_location_target_id';
  $handler->display->display_options['relationships']['field_event_location_target_id']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['relationships']['field_event_location_target_id']['field'] = 'field_event_location_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_agency_main_location_target_id']['id'] = 'field_agency_main_location_target_id';
  $handler->display->display_options['relationships']['field_agency_main_location_target_id']['table'] = 'field_data_field_agency_main_location';
  $handler->display->display_options['relationships']['field_agency_main_location_target_id']['field'] = 'field_agency_main_location_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_agency_other_locations_target_id']['id'] = 'field_agency_other_locations_target_id';
  $handler->display->display_options['relationships']['field_agency_other_locations_target_id']['table'] = 'field_data_field_agency_other_locations';
  $handler->display->display_options['relationships']['field_agency_other_locations_target_id']['field'] = 'field_agency_other_locations_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_agency_main_location_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: Content: Office Hours */
  $handler->display->display_options['fields']['field_location_office_hours']['id'] = 'field_location_office_hours';
  $handler->display->display_options['fields']['field_location_office_hours']['table'] = 'field_data_field_location_office_hours';
  $handler->display->display_options['fields']['field_location_office_hours']['field'] = 'field_location_office_hours';
  $handler->display->display_options['fields']['field_location_office_hours']['relationship'] = 'field_agency_main_location_target_id';
  $handler->display->display_options['fields']['field_location_office_hours']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_location_office_hours']['click_sort_column'] = 'day';
  $handler->display->display_options['fields']['field_location_office_hours']['settings'] = array(
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
  $handler->display->display_options['fields']['field_location_office_hours']['delta_offset'] = '0';
  /* Field: Field: Location Email */
  $handler->display->display_options['fields']['field_location_email']['id'] = 'field_location_email';
  $handler->display->display_options['fields']['field_location_email']['table'] = 'field_data_field_location_email';
  $handler->display->display_options['fields']['field_location_email']['field'] = 'field_location_email';
  $handler->display->display_options['fields']['field_location_email']['relationship'] = 'field_agency_main_location_target_id';
  $handler->display->display_options['fields']['field_location_email']['hide_empty'] = TRUE;
  /* Field: Content: Phone Numbers */
  $handler->display->display_options['fields']['field_location_phone']['id'] = 'field_location_phone';
  $handler->display->display_options['fields']['field_location_phone']['table'] = 'field_data_field_location_phone';
  $handler->display->display_options['fields']['field_location_phone']['field'] = 'field_location_phone';
  $handler->display->display_options['fields']['field_location_phone']['relationship'] = 'field_agency_main_location_target_id';
  $handler->display->display_options['fields']['field_location_phone']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_location_phone']['settings'] = array(
    'add' => 'Add',
    'edit' => 'Edit',
    'translate' => '',
    'delete' => 'Delete',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_location_phone']['delta_offset'] = '0';
  /* Field: Content: Location Type */
  $handler->display->display_options['fields']['field_location_type']['id'] = 'field_location_type';
  $handler->display->display_options['fields']['field_location_type']['table'] = 'field_data_field_location_type';
  $handler->display->display_options['fields']['field_location_type']['field'] = 'field_location_type';
  $handler->display->display_options['fields']['field_location_type']['relationship'] = 'field_agency_main_location_target_id';
  $handler->display->display_options['fields']['field_location_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_location_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Other Location(s) */
  $handler->display->display_options['fields']['field_agency_other_locations']['id'] = 'field_agency_other_locations';
  $handler->display->display_options['fields']['field_agency_other_locations']['table'] = 'field_data_field_agency_other_locations';
  $handler->display->display_options['fields']['field_agency_other_locations']['field'] = 'field_agency_other_locations';
  $handler->display->display_options['fields']['field_agency_other_locations']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_agency_other_locations']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_agency_other_locations']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_agency_other_locations']['multi_type'] = 'ul';
  $export['date_document_block'] = $view;

  return $export;
}
