<?php
/**
 * @file
 * search_api_solr_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function search_api_solr_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'primary_search_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_primary_search';
  $view->human_name = 'Primary Search View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search Results';
  $handler->display->display_options['css_class'] = 'primary-search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'search-row';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'test content ';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Indexed Node: Agency Type */
  $handler->display->display_options['fields']['field_agency_type']['id'] = 'field_agency_type';
  $handler->display->display_options['fields']['field_agency_type']['table'] = 'search_api_index_primary_search';
  $handler->display->display_options['fields']['field_agency_type']['field'] = 'field_agency_type';
  $handler->display->display_options['fields']['field_agency_type']['label'] = '';
  $handler->display->display_options['fields']['field_agency_type']['element_type'] = 'em';
  $handler->display->display_options['fields']['field_agency_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_type']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_agency_type']['element_wrapper_class'] = 'cat-type';
  $handler->display->display_options['fields']['field_agency_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_agency_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_agency_type']['bypass_access'] = 0;
  /* Field: Indexed Node: News Type */
  $handler->display->display_options['fields']['field_media_type']['id'] = 'field_media_type';
  $handler->display->display_options['fields']['field_media_type']['table'] = 'search_api_index_primary_search';
  $handler->display->display_options['fields']['field_media_type']['field'] = 'field_media_type';
  $handler->display->display_options['fields']['field_media_type']['label'] = '';
  $handler->display->display_options['fields']['field_media_type']['element_type'] = 'em';
  $handler->display->display_options['fields']['field_media_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_type']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_media_type']['element_wrapper_class'] = 'cat-type';
  $handler->display->display_options['fields']['field_media_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_media_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_media_type']['bypass_access'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_primary_search';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Date */
  $handler->display->display_options['fields']['field_date_and_time']['id'] = 'field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time']['table'] = 'search_api_index_primary_search';
  $handler->display->display_options['fields']['field_date_and_time']['field'] = 'field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time']['label'] = '';
  $handler->display->display_options['fields']['field_date_and_time']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_date_and_time']['element_class'] = 'search-date';
  $handler->display->display_options['fields']['field_date_and_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_and_time']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'F n, Y',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_date_and_time']['delta_offset'] = '0';
  /* Field: Indexed Node: Youtube URL */
  $handler->display->display_options['fields']['field_youtube_url']['id'] = 'field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url']['table'] = 'search_api_index_primary_search';
  $handler->display->display_options['fields']['field_youtube_url']['field'] = 'field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url']['label'] = '';
  $handler->display->display_options['fields']['field_youtube_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_youtube_url']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_youtube_url']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Location: Name (indexed) */
  $handler->display->display_options['fields']['field_location_name']['id'] = 'field_location_name';
  $handler->display->display_options['fields']['field_location_name']['table'] = 'search_api_index_primary_search';
  $handler->display->display_options['fields']['field_location_name']['field'] = 'field_location_name';
  $handler->display->display_options['fields']['field_location_name']['label'] = '';
  $handler->display->display_options['fields']['field_location_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_name']['link_to_entity'] = 0;
  /* Field: Location: Street (indexed) */
  $handler->display->display_options['fields']['field_location_street']['id'] = 'field_location_street';
  $handler->display->display_options['fields']['field_location_street']['table'] = 'search_api_index_primary_search';
  $handler->display->display_options['fields']['field_location_street']['field'] = 'field_location_street';
  $handler->display->display_options['fields']['field_location_street']['label'] = '';
  $handler->display->display_options['fields']['field_location_street']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_street']['link_to_entity'] = 0;
  /* Field: Location: Additional (indexed) */
  $handler->display->display_options['fields']['field_location_additional']['id'] = 'field_location_additional';
  $handler->display->display_options['fields']['field_location_additional']['table'] = 'search_api_index_primary_search';
  $handler->display->display_options['fields']['field_location_additional']['field'] = 'field_location_additional';
  $handler->display->display_options['fields']['field_location_additional']['label'] = '';
  $handler->display->display_options['fields']['field_location_additional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_additional']['link_to_entity'] = 0;
  /* Field: Location: City (indexed) */
  $handler->display->display_options['fields']['field_location_city']['id'] = 'field_location_city';
  $handler->display->display_options['fields']['field_location_city']['table'] = 'search_api_index_primary_search';
  $handler->display->display_options['fields']['field_location_city']['field'] = 'field_location_city';
  $handler->display->display_options['fields']['field_location_city']['label'] = '';
  $handler->display->display_options['fields']['field_location_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_city']['link_to_entity'] = 0;
  /* Field: Location: Postal code (indexed) */
  $handler->display->display_options['fields']['field_location_postal_code']['id'] = 'field_location_postal_code';
  $handler->display->display_options['fields']['field_location_postal_code']['table'] = 'search_api_index_primary_search';
  $handler->display->display_options['fields']['field_location_postal_code']['field'] = 'field_location_postal_code';
  $handler->display->display_options['fields']['field_location_postal_code']['label'] = '';
  $handler->display->display_options['fields']['field_location_postal_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_postal_code']['link_to_entity'] = 0;
  /* Field: Search: Excerpt */
  $handler->display->display_options['fields']['search_api_excerpt']['id'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['table'] = 'search_api_index_primary_search';
  $handler->display->display_options['fields']['search_api_excerpt']['field'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['label'] = '';
  $handler->display->display_options['fields']['search_api_excerpt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_excerpt']['link_to_entity'] = 0;
  /* Sort criterion: Indexed Node: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_primary_search';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_primary_search';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_primary_search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    7 => 0,
    9 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'attachments_field_documents' => 'attachments_field_documents',
    'attachments_field_event_documents' => 'attachments_field_event_documents',
    'attachments_field_publication_file' => 'attachments_field_publication_file',
    'attachments_field_video' => 'attachments_field_video',
    'field_agency_description:value' => 'field_agency_description:value',
    'field_basic_body:value' => 'field_basic_body:value',
    'field_body:value' => 'field_body:value',
    'field_broadcast_message' => 'field_broadcast_message',
    'field_description:summary' => 'field_description:summary',
    'field_description:value' => 'field_description:value',
    'field_event_location:title' => 'field_event_location:title',
    'field_event_location_detail' => 'field_event_location_detail',
    'field_faq:field_faq_question' => 'field_faq:field_faq_question',
    'field_location:additional' => 'field_location:additional',
    'field_location:city' => 'field_location:city',
    'field_location:country' => 'field_location:country',
    'field_location:country_name' => 'field_location:country_name',
    'field_location:name' => 'field_location:name',
    'field_location:postal_code' => 'field_location:postal_code',
    'field_location:street' => 'field_location:street',
    'field_location_email' => 'field_location_email',
    'field_news_author' => 'field_news_author',
    'field_person_email' => 'field_person_email',
    'field_publication_description:value' => 'field_publication_description:value',
    'field_publication_file:file:field_file_image_title_text' => 'field_publication_file:file:field_file_image_title_text',
    'field_publication_file:file:name' => 'field_publication_file:file:name',
    'field_service_description:value' => 'field_service_description:value',
    'search_api_viewed' => 'search_api_viewed',
    'title' => 'title',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'primary-search-view';

  /* Display: Search Block */
  $handler = $view->new_display('page', 'Search Block', 'page_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'primary-search-view';
  $export['primary_search_view'] = $view;

  return $export;
}
