<?php
/**
 * @file
 * news_events_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function news_events_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'news_homepage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News Homepage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events Homepage';
  $handler->display->display_options['css_class'] = 'events home';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_what_s_new_target_id']['id'] = 'field_what_s_new_target_id';
  $handler->display->display_options['relationships']['field_what_s_new_target_id']['table'] = 'field_data_field_what_s_new';
  $handler->display->display_options['relationships']['field_what_s_new_target_id']['field'] = 'field_what_s_new_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_location']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_event_location']['settings'] = array(
    'view_mode' => 'teaser',
    'links' => 0,
    'use_content_language' => 1,
  );
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_date_and_time']['id'] = 'field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time']['table'] = 'field_data_field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time']['field'] = 'field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time']['label'] = '';
  $handler->display->display_options['fields']['field_date_and_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_and_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_and_time']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'M',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_date_and_time']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_date_and_time']['delta_offset'] = '0';
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_date_and_time_1']['id'] = 'field_date_and_time_1';
  $handler->display->display_options['fields']['field_date_and_time_1']['table'] = 'field_data_field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time_1']['field'] = 'field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_and_time_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_and_time_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_and_time_1']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'j',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_date_and_time_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_date_and_time_1']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="event-image">
<div class="event-date">
[field_date_and_time]
[field_date_and_time_1]
</div>
[field_event_image]
</div>
<div class="event-content">
<h3>[title]</h3>
[field_event_location]
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Youtube URL */
  $handler->display->display_options['fields']['field_youtube_url']['id'] = 'field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url']['table'] = 'field_data_field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url']['field'] = 'field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url']['label'] = '';
  $handler->display->display_options['fields']['field_youtube_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_youtube_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_youtube_url']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_youtube_url']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_youtube_url']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Content: Youtube URL */
  $handler->display->display_options['fields']['field_youtube_url_1']['id'] = 'field_youtube_url_1';
  $handler->display->display_options['fields']['field_youtube_url_1']['table'] = 'field_data_field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url_1']['field'] = 'field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url_1']['label'] = '';
  $handler->display->display_options['fields']['field_youtube_url_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_youtube_url_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_youtube_url_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_youtube_url_1']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_youtube_url_1']['settings'] = array(
    'file_view_mode' => 'preview',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Field: Featured Image */
  $handler->display->display_options['fields']['field_file_image']['id'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['table'] = 'field_data_field_file_image';
  $handler->display->display_options['fields']['field_file_image']['field'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['label'] = '';
  $handler->display->display_options['fields']['field_file_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_file_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file_image']['empty'] = '<div class="blank-img"></div>';
  $handler->display->display_options['fields']['field_file_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_image']['settings'] = array(
    'image_style' => '190x190',
    'image_link' => 'content',
  );
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'Video';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="youtube_vid">[field_youtube_url]</div> 
<div class="vid_overlay">
<div class="event-image">
<div class="event-date">
[field_date_and_time]
[field_date_and_time_1]
</div>
[field_youtube_url_1]
</div>
<div class="event-content">
<h3>[title]</h3>
[field_video_caption]
<div class="media-type">[type]</div>
</div></div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="event-image">
<div class="event-date">
[field_date_and_time] 
[field_date_and_time_1]
</div>
[field_file_image]
<div class="[type]"></div>
</div>
<div class="event-content">
<h3>[title]</h3>
[field_event_location]
<div class="media-type">[type]</div>
</div>';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_news_page_display_value']['id'] = 'field_news_page_display_value';
  $handler->display->display_options['filters']['field_news_page_display_value']['table'] = 'field_data_field_news_page_display';
  $handler->display->display_options['filters']['field_news_page_display_value']['field'] = 'field_news_page_display_value';
  $handler->display->display_options['filters']['field_news_page_display_value']['value'] = array(
    0 => '0',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityqueue: Node Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'whats_new_homepage' => 'whats_new_homepage',
    'homepage_jump_menu' => 0,
    'county_board' => 0,
    'ethics' => 0,
    'property_taxes' => 0,
    'elections' => 0,
    'vital_records' => 0,
    'homepage' => 0,
    'homepage_departments' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_location']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_event_location']['settings'] = array(
    'view_mode' => 'teaser',
    'links' => 0,
    'use_content_language' => 1,
  );
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_date_and_time']['id'] = 'field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time']['table'] = 'field_data_field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time']['field'] = 'field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time']['label'] = '';
  $handler->display->display_options['fields']['field_date_and_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_and_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_and_time']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'M',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_date_and_time']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_date_and_time']['delta_offset'] = '0';
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_date_and_time_1']['id'] = 'field_date_and_time_1';
  $handler->display->display_options['fields']['field_date_and_time_1']['table'] = 'field_data_field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time_1']['field'] = 'field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_and_time_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_and_time_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_and_time_1']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'j',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_date_and_time_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_date_and_time_1']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="event-image">
<div class="event-date">
[field_date_and_time]
[field_date_and_time_1]
</div>
[field_event_image]
</div>
<div class="event-content">
<h3>[title]</h3>
[field_event_location]
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Youtube URL */
  $handler->display->display_options['fields']['field_youtube_url']['id'] = 'field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url']['table'] = 'field_data_field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url']['field'] = 'field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url']['label'] = '';
  $handler->display->display_options['fields']['field_youtube_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_youtube_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_youtube_url']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_youtube_url']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_youtube_url']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Content: Youtube URL */
  $handler->display->display_options['fields']['field_youtube_url_1']['id'] = 'field_youtube_url_1';
  $handler->display->display_options['fields']['field_youtube_url_1']['table'] = 'field_data_field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url_1']['field'] = 'field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url_1']['label'] = '';
  $handler->display->display_options['fields']['field_youtube_url_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_youtube_url_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_youtube_url_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_youtube_url_1']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_youtube_url_1']['settings'] = array(
    'file_view_mode' => 'preview',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Field: Featured Image */
  $handler->display->display_options['fields']['field_file_image']['id'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['table'] = 'field_data_field_file_image';
  $handler->display->display_options['fields']['field_file_image']['field'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['label'] = '';
  $handler->display->display_options['fields']['field_file_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_file_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file_image']['empty'] = '<div class="blank-img"></div>';
  $handler->display->display_options['fields']['field_file_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_image']['settings'] = array(
    'image_style' => '190x190',
    'image_link' => 'content',
  );
  /* Field: Content: Body Content */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '[field_description-summary] ';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'Video';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="youtube_vid">[field_youtube_url]</div> 
<div class="vid_overlay">
<div class="event-image">
[field_youtube_url_1]
</div>
<div class="event-content">
<h3>[title]</h3>
[field_description]
<div class="media-type">[type]</div>
</div></div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="event-image">
[field_file_image]
<div class="[type]"></div>
</div>
<div class="event-content">
<h3>[title]</h3>
[field_description]
<div class="media-type">[type]</div>
</div>';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Entityqueue: Node Queue Position */
  $handler->display->display_options['sorts']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['sorts']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['sorts']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'news' => 'news',
    'video' => 'video',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'whats_new');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'What\'s New';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'media-block';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/media-library-grid">Visit Media Room</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_what_s_new_target_id']['id'] = 'field_what_s_new_target_id';
  $handler->display->display_options['relationships']['field_what_s_new_target_id']['table'] = 'field_data_field_what_s_new';
  $handler->display->display_options['relationships']['field_what_s_new_target_id']['field'] = 'field_what_s_new_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_what_s_new_node']['id'] = 'reverse_field_what_s_new_node';
  $handler->display->display_options['relationships']['reverse_field_what_s_new_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_what_s_new_node']['field'] = 'reverse_field_what_s_new_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_location']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_event_location']['settings'] = array(
    'view_mode' => 'teaser',
    'links' => 0,
    'use_content_language' => 1,
  );
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_date_and_time']['id'] = 'field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time']['table'] = 'field_data_field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time']['field'] = 'field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time']['label'] = '';
  $handler->display->display_options['fields']['field_date_and_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_and_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_and_time']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'M',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_date_and_time']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_date_and_time']['delta_offset'] = '0';
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_date_and_time_1']['id'] = 'field_date_and_time_1';
  $handler->display->display_options['fields']['field_date_and_time_1']['table'] = 'field_data_field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time_1']['field'] = 'field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_and_time_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_and_time_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_and_time_1']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'j',
    'fromto' => 'value',
    'multiple_number' => '1',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_date_and_time_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_date_and_time_1']['delta_offset'] = '0';
  /* Field: Content: Youtube URL */
  $handler->display->display_options['fields']['field_youtube_url']['id'] = 'field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url']['table'] = 'field_data_field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url']['field'] = 'field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url']['label'] = '';
  $handler->display->display_options['fields']['field_youtube_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_youtube_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_youtube_url']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_youtube_url']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_youtube_url']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Content: Youtube URL */
  $handler->display->display_options['fields']['field_youtube_url_1']['id'] = 'field_youtube_url_1';
  $handler->display->display_options['fields']['field_youtube_url_1']['table'] = 'field_data_field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url_1']['field'] = 'field_youtube_url';
  $handler->display->display_options['fields']['field_youtube_url_1']['label'] = '';
  $handler->display->display_options['fields']['field_youtube_url_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_youtube_url_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_youtube_url_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_youtube_url_1']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_youtube_url_1']['settings'] = array(
    'file_view_mode' => 'preview',
  );
  /* Field: Field: Featured Image */
  $handler->display->display_options['fields']['field_file_image']['id'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['table'] = 'field_data_field_file_image';
  $handler->display->display_options['fields']['field_file_image']['field'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['label'] = '';
  $handler->display->display_options['fields']['field_file_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_file_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file_image']['empty'] = '<div class="blank-img"></div>';
  $handler->display->display_options['fields']['field_file_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_image']['settings'] = array(
    'image_style' => '190x190',
    'image_link' => 'content',
  );
  /* Field: Content: Body Content */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '[field_description-summary] ';
  $handler->display->display_options['fields']['field_description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'Video';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<div class="youtube_vid">[field_youtube_url]</div> 
<div class="vid_overlay">
<div class="event-image">
<div class="event-date">
[field_date_and_time]
[field_date_and_time_1]
</div>
[field_youtube_url_1]
</div>
<div class="event-content">
<h3>[title]</h3>
[field_description]
<div class="media-type">[type]</div>
</div></div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '<div class="event-image">
<div class="event-date">
[field_date_and_time]
[field_date_and_time_1]
</div>
[field_file_image]
</div>
<div class="event-content">
<h3>[title]</h3>
[field_description]
<div class="media-type">[type]</div>
</div>';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_what_s_new_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'news' => 'news',
    'video' => 'video',
  );
  $export['news_homepage'] = $view;

  return $export;
}
