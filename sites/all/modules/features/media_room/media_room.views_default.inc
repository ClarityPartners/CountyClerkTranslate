<?php
/**
 * @file
 * media_room.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function media_room_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'media_room';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Media Room';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'media-library list';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oldest';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Newest';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 1,
        'combine_param' => 'sort_bef_combine',
        'combine_rewrite' => 'Date and Time Oldest|Oldest
Date and Time Newest|Newest',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'autosubmit' => 1,
      ),
    ),
    'keys' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'type' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => 'All Media',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_date_and_time_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
        'datepicker_options' => '',
      ),
    ),
    'tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '-Any-|All Topics',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
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
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '[field_description-summary]';
  $handler->display->display_options['fields']['field_description']['settings'] = array(
    'trim_length' => '600',
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
[field_news_content]
[field_event_description]
<div class="media-type">[type]</div>
</div>';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Sort criterion: Content: Date and Time -  start date (field_date_and_time) */
  $handler->display->display_options['sorts']['field_date_and_time_value']['id'] = 'field_date_and_time_value';
  $handler->display->display_options['sorts']['field_date_and_time_value']['table'] = 'field_data_field_date_and_time';
  $handler->display->display_options['sorts']['field_date_and_time_value']['field'] = 'field_date_and_time_value';
  $handler->display->display_options['sorts']['field_date_and_time_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_date_and_time_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_date_and_time_value']['expose']['label'] = 'Date and Time';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'event' => 'event',
    'news' => 'news',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'type' => 'type',
    'field_description' => 'field_description',
    'field_body' => 'field_body',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'news' => 'news',
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'media_type';
  /* Filter criterion: Content: Date and Time -  start date (field_date_and_time) */
  $handler->display->display_options['filters']['field_date_and_time_value']['id'] = 'field_date_and_time_value';
  $handler->display->display_options['filters']['field_date_and_time_value']['table'] = 'field_data_field_date_and_time';
  $handler->display->display_options['filters']['field_date_and_time_value']['field'] = 'field_date_and_time_value';
  $handler->display->display_options['filters']['field_date_and_time_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_and_time_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_and_time_value']['expose']['operator_id'] = 'field_date_and_time_value_op';
  $handler->display->display_options['filters']['field_date_and_time_value']['expose']['operator'] = 'field_date_and_time_value_op';
  $handler->display->display_options['filters']['field_date_and_time_value']['expose']['identifier'] = 'field_date_and_time_value';
  $handler->display->display_options['filters']['field_date_and_time_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_date_and_time_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_date_and_time_value']['year_range'] = '+1:-17';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
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
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '[field_description-summary]';
  $handler->display->display_options['fields']['field_description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['preserve_tags'] = '<br>';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Field: Body */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['label'] = '';
  $handler->display->display_options['fields']['field_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_body']['element_label_colon'] = FALSE;
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
[field_body]
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
[field_description]
<div class="media-type">[type]</div>
</div>';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  $handler->display->display_options['metatags'] = array(
    'und' => array(
      'title' => array(
        'value' => '[view:title] | [current-page:pager][site:name]',
        'default' => '[view:title] | [current-page:pager][site:name]',
      ),
      'description' => array(
        'value' => '[view:description]',
        'default' => '[view:description]',
      ),
      'abstract' => array(
        'value' => '',
      ),
      'keywords' => array(
        'value' => '',
      ),
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'news_keywords' => array(
        'value' => '',
      ),
      'standout' => array(
        'value' => '',
      ),
      'rating' => array(
        'value' => '',
      ),
      'referrer' => array(
        'value' => '',
      ),
      'rights' => array(
        'value' => '',
      ),
      'image_src' => array(
        'value' => '',
      ),
      'canonical' => array(
        'value' => '[view:url]',
        'default' => '[view:url]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
        'default' => '[current-page:url:unaliased]',
      ),
      'publisher' => array(
        'value' => '',
      ),
      'author' => array(
        'value' => '',
      ),
      'original-source' => array(
        'value' => '',
      ),
      'prev' => array(
        'value' => '',
      ),
      'next' => array(
        'value' => '',
      ),
      'content-language' => array(
        'value' => '',
      ),
      'geo.position' => array(
        'value' => '',
      ),
      'geo.placename' => array(
        'value' => '',
      ),
      'geo.region' => array(
        'value' => '',
      ),
      'icbm' => array(
        'value' => '',
      ),
      'refresh' => array(
        'value' => '',
      ),
      'revisit-after' => array(
        'value' => '',
        'period' => '',
      ),
      'pragma' => array(
        'value' => '',
      ),
      'cache-control' => array(
        'value' => '',
      ),
      'expires' => array(
        'value' => '',
      ),
    ),
  );

  /* Display: List Layout */
  $handler = $view->new_display('page', 'List Layout', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_event_date_time' => 'field_event_date_time',
    'field_event_date_time_1' => 'field_event_date_time_1',
    'field_news_featured_media' => 'field_news_featured_media',
    'field_event_image' => 'field_event_image',
    'field_event_location' => 'field_event_location',
    'field_news_date' => 'field_news_date',
    'type' => 'type',
    'field_youtube_url' => 'field_youtube_url',
    'field_news_date_1' => 'field_news_date_1',
    'views_conditional' => 'views_conditional',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_event_date_time' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_event_date_time_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_news_featured_media' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_event_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_event_location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_news_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_youtube_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_news_date_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'views_conditional' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
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
  /* Field: Content: Body Content */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '[field_description-summary]';
  $handler->display->display_options['fields']['field_description']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['field_description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_description']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'node';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  $handler->display->display_options['fields']['type_1']['label'] = '';
  $handler->display->display_options['fields']['type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type_1']['element_label_colon'] = FALSE;
  /* Field: Field: Body */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['label'] = '';
  $handler->display->display_options['fields']['field_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_body']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = 'Description';
  $handler->display->display_options['fields']['views_conditional']['if'] = 'type_1';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '2';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'Video';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[field_description]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[field_body]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_date_and_time_1']['id'] = 'field_date_and_time_1';
  $handler->display->display_options['fields']['field_date_and_time_1']['table'] = 'field_data_field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time_1']['field'] = 'field_date_and_time';
  $handler->display->display_options['fields']['field_date_and_time_1']['label'] = 'Date';
  $handler->display->display_options['fields']['field_date_and_time_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_and_time_1']['settings'] = array(
    'format_type' => 'news',
    'custom_date_format' => 'j',
    'fromto' => 'both',
    'multiple_number' => '1',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_date_and_time_1']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_date_and_time_1']['delta_offset'] = '0';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['metatags'] = array(
    'und' => array(
      'title' => array(
        'value' => 'Media Room | [current-page:pager][site:name]',
        'default' => '[view:title] | [current-page:pager][site:name]',
      ),
      'description' => array(
        'value' => '[view:description]',
        'default' => '[view:description]',
      ),
      'abstract' => array(
        'value' => '',
      ),
      'keywords' => array(
        'value' => '',
      ),
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'news_keywords' => array(
        'value' => '',
      ),
      'standout' => array(
        'value' => '',
      ),
      'rating' => array(
        'value' => '',
      ),
      'referrer' => array(
        'value' => '',
      ),
      'rights' => array(
        'value' => '',
      ),
      'image_src' => array(
        'value' => '',
      ),
      'canonical' => array(
        'value' => '[view:url]',
        'default' => '[view:url]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
        'default' => '[current-page:url:unaliased]',
      ),
      'publisher' => array(
        'value' => '',
      ),
      'author' => array(
        'value' => '',
      ),
      'original-source' => array(
        'value' => '',
      ),
      'prev' => array(
        'value' => '',
      ),
      'next' => array(
        'value' => '',
      ),
      'content-language' => array(
        'value' => '',
      ),
      'geo.position' => array(
        'value' => '',
      ),
      'geo.placename' => array(
        'value' => '',
      ),
      'geo.region' => array(
        'value' => '',
      ),
      'icbm' => array(
        'value' => '',
      ),
      'refresh' => array(
        'value' => '',
      ),
      'revisit-after' => array(
        'value' => '',
        'period' => '',
      ),
      'pragma' => array(
        'value' => '',
      ),
      'cache-control' => array(
        'value' => '',
      ),
      'expires' => array(
        'value' => '',
      ),
    ),
  );
  $handler->display->display_options['path'] = 'media-library-list';

  /* Display: Grid Layout */
  $handler = $view->new_display('page', 'Grid Layout', 'page_2');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'media-library grid';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oldest';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Newest';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 1,
        'combine_param' => 'sort_bef_combine',
        'combine_rewrite' => 'Date and Time Newest|Newest
Date and Time Oldest|Oldest',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'autosubmit' => 1,
      ),
    ),
    'keys' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'type' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => 'All Media',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => 'All Topics',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_date_and_time_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '-Year|Year',
        ),
        'datepicker_options' => '',
      ),
    ),
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '[field_description-summary]';
  $handler->display->display_options['fields']['field_description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['preserve_tags'] = '<p><br>';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_description']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Field: Body */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['label'] = '';
  $handler->display->display_options['fields']['field_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_body']['element_label_colon'] = FALSE;
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
[field_body]
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
[field_description]
<div class="media-type">[type]</div>
</div>';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  $handler->display->display_options['metatags'] = array(
    'und' => array(
      'title' => array(
        'value' => 'Media Room | [current-page:pager][site:name]',
        'default' => '[view:title] | [current-page:pager][site:name]',
      ),
      'description' => array(
        'value' => '[view:description]',
        'default' => '[view:description]',
      ),
      'abstract' => array(
        'value' => '',
      ),
      'keywords' => array(
        'value' => '',
      ),
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'news_keywords' => array(
        'value' => '',
      ),
      'standout' => array(
        'value' => '',
      ),
      'rating' => array(
        'value' => '',
      ),
      'referrer' => array(
        'value' => '',
      ),
      'rights' => array(
        'value' => '',
      ),
      'image_src' => array(
        'value' => '',
      ),
      'canonical' => array(
        'value' => '[view:url]',
        'default' => '[view:url]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
        'default' => '[current-page:url:unaliased]',
      ),
      'publisher' => array(
        'value' => '',
      ),
      'author' => array(
        'value' => '',
      ),
      'original-source' => array(
        'value' => '',
      ),
      'prev' => array(
        'value' => '',
      ),
      'next' => array(
        'value' => '',
      ),
      'content-language' => array(
        'value' => '',
      ),
      'geo.position' => array(
        'value' => '',
      ),
      'geo.placename' => array(
        'value' => '',
      ),
      'geo.region' => array(
        'value' => '',
      ),
      'icbm' => array(
        'value' => '',
      ),
      'refresh' => array(
        'value' => '',
      ),
      'revisit-after' => array(
        'value' => '',
        'period' => '',
      ),
      'pragma' => array(
        'value' => '',
      ),
      'cache-control' => array(
        'value' => '',
      ),
      'expires' => array(
        'value' => '',
      ),
    ),
  );
  $handler->display->display_options['path'] = 'media-library-grid';
  $export['media_room'] = $view;

  return $export;
}
