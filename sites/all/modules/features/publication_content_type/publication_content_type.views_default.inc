<?php
/**
 * @file
 * publication_content_type.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function publication_content_type_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'publications_bw_publications';
  $view->description = 'Publications listing ';
  $view->tag = 'Publications';
  $view->base_table = 'node';
  $view->human_name = 'Publications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Form and Document Library';
  $handler->display->display_options['css_class'] = 'publications-list container';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'plain_text',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'pager' => array(
      'bef_format' => 'default',
      'is_secondary' => 0,
    ),
    'title' => array(
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
    'field_publication_categories_target_id' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
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
    'field_publication_type_target_id' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
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
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '';
  $handler->display->display_options['pager']['options']['quantity'] = '';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Show';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '6, 12, 24, 48, 96';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['style_options']['alignment'] = 'vertical';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'Switch';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<span class="grid-view"><h4><a href="/publications">GRID VIEW</a>&nbsp;|&nbsp; LIST VIEW</h4></span>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No publications have been created.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Publication File */
  $handler->display->display_options['fields']['field_publication_file']['id'] = 'field_publication_file';
  $handler->display->display_options['fields']['field_publication_file']['table'] = 'field_data_field_publication_file';
  $handler->display->display_options['fields']['field_publication_file']['field'] = 'field_publication_file';
  $handler->display->display_options['fields']['field_publication_file']['label'] = '';
  $handler->display->display_options['fields']['field_publication_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_publication_file']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_publication_file']['settings'] = array(
    'image_style' => 'publication_small',
  );
  /* Field: Content: Publication Image */
  $handler->display->display_options['fields']['field_publication_image']['id'] = 'field_publication_image';
  $handler->display->display_options['fields']['field_publication_image']['table'] = 'field_data_field_publication_image';
  $handler->display->display_options['fields']['field_publication_image']['field'] = 'field_publication_image';
  $handler->display->display_options['fields']['field_publication_image']['label'] = '';
  $handler->display->display_options['fields']['field_publication_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_publication_image']['alter']['text'] = '<a href="[field_publication_file]" target="_blank">[field_publication_image]</a>';
  $handler->display->display_options['fields']['field_publication_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_image']['empty'] = '[field_publication_file]';
  $handler->display->display_options['fields']['field_publication_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_publication_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_publication_image']['settings'] = array(
    'image_style' => 'publication_small',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_publication_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_publication_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[field_publication_file]" target="_blank">[title]</a>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Publication Type */
  $handler->display->display_options['fields']['field_publication_type']['id'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['table'] = 'field_data_field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['field'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['label'] = '';
  $handler->display->display_options['fields']['field_publication_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_type']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_publication_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date Posted';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '<h4>Date Posted</h4> [created]';
  $handler->display->display_options['fields']['created']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'n/j/Y  \\a\\t\\ g:ia';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'full_with_time';
  /* Field: Content: Publication File */
  $handler->display->display_options['fields']['field_publication_file_1']['id'] = 'field_publication_file_1';
  $handler->display->display_options['fields']['field_publication_file_1']['table'] = 'field_data_field_publication_file';
  $handler->display->display_options['fields']['field_publication_file_1']['field'] = 'field_publication_file';
  $handler->display->display_options['fields']['field_publication_file_1']['label'] = 'Title';
  $handler->display->display_options['fields']['field_publication_file_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_file_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_publication_file_1']['alter']['text'] = '<h4>Title</h4> [field_publication_file_1] ';
  $handler->display->display_options['fields']['field_publication_file_1']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_publication_file_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_file_1']['click_sort_column'] = 'fid';
  /* Field: Content: Publication File */
  $handler->display->display_options['fields']['field_publication_file_2']['id'] = 'field_publication_file_2';
  $handler->display->display_options['fields']['field_publication_file_2']['table'] = 'field_data_field_publication_file';
  $handler->display->display_options['fields']['field_publication_file_2']['field'] = 'field_publication_file';
  $handler->display->display_options['fields']['field_publication_file_2']['label'] = 'Type';
  $handler->display->display_options['fields']['field_publication_file_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_file_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_publication_file_2']['alter']['text'] = '<h4>Type </h4><div>[field_publication_file_2]</div>';
  $handler->display->display_options['fields']['field_publication_file_2']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_publication_file_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_file_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_publication_file_2']['type'] = 'file_url_plain';
  /* Field: Content: Publication Categories */
  $handler->display->display_options['fields']['field_publication_categories']['id'] = 'field_publication_categories';
  $handler->display->display_options['fields']['field_publication_categories']['table'] = 'field_data_field_publication_categories';
  $handler->display->display_options['fields']['field_publication_categories']['field'] = 'field_publication_categories';
  $handler->display->display_options['fields']['field_publication_categories']['label'] = 'Categories';
  $handler->display->display_options['fields']['field_publication_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_categories']['alter']['text'] = '<h4>Categories</h4> [field_publication_categories] ';
  $handler->display->display_options['fields']['field_publication_categories']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_publication_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_categories']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_publication_categories']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="pub-container">
<div class="upper pub row">
<div class="col col-md-5 imagery">
[field_publication_image] 
</div>
<div class="col col-md-7 copy">
<span>[field_publication_file_1]</span> 
<span class="file-type">[field_publication_file_2] </span>
<span>[created]</span>
</div>
</div>
<div class="lower pub">
<h4>Categories</h4>
[field_publication_categories]
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Sort by */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['ui_name'] = 'Sort by';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post Date';
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
    'publication' => 'publication',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page: Publications Grid */
  $handler = $view->new_display('page', 'Page: Publications Grid', 'publications_page_grid');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'publications-grid container';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'responsive_grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['column_classes'] = 'views-column col-sm-12 col-md-4 col-md-offset-2';
  $handler->display->display_options['style_options']['row_classes'] = 'views-row row';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
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
    'publication' => 'publication',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search Documents';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = '';
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'publication_categories';
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_1']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['operator_id'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['tid_1']['expose']['operator'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['identifier'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['tid_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['tid_1']['vocabulary'] = 'publication_types';
  $handler->display->display_options['path'] = 'pub';
  $handler->display->display_options['menu']['title'] = 'Forms / Documents';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page: Publications List */
  $handler = $view->new_display('page', 'Page: Publications List', 'publications_page_list');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_publication_file' => 'field_publication_file',
    'field_publication_image' => 'field_publication_image',
    'title' => 'title',
    'field_publication_type' => 'field_publication_type',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_publication_file' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_publication_image' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_publication_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
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
    'publication' => 'publication',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search Documents';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Publication Type (field_publication_type) */
  $handler->display->display_options['filters']['field_publication_type_target_id']['id'] = 'field_publication_type_target_id';
  $handler->display->display_options['filters']['field_publication_type_target_id']['table'] = 'field_data_field_publication_type';
  $handler->display->display_options['filters']['field_publication_type_target_id']['field'] = 'field_publication_type_target_id';
  $handler->display->display_options['filters']['field_publication_type_target_id']['operator'] = '!=';
  $handler->display->display_options['filters']['field_publication_type_target_id']['value']['value'] = '124';
  $handler->display->display_options['path'] = 'pub/list';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Forms';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page: Annual Reports */
  $handler = $view->new_display('page', 'Page: Annual Reports', 'publications_page_annual');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Annual Reports';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'publications-annual container';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_publication_file' => 'field_publication_file',
    'field_publication_image' => 'field_publication_image',
    'title' => 'title',
    'field_publication_type' => 'field_publication_type',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_publication_file' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_publication_image' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_publication_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
    'publication' => 'publication',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Publication Type (field_publication_type) */
  $handler->display->display_options['filters']['field_publication_type_target_id']['id'] = 'field_publication_type_target_id';
  $handler->display->display_options['filters']['field_publication_type_target_id']['table'] = 'field_data_field_publication_type';
  $handler->display->display_options['filters']['field_publication_type_target_id']['field'] = 'field_publication_type_target_id';
  $handler->display->display_options['filters']['field_publication_type_target_id']['value']['value'] = '124';
  $handler->display->display_options['path'] = 'publications/reports/list';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Annual Reports';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['publications_bw_publications'] = $view;

  $view = new view();
  $view->name = 'pubs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'Pubs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Document Center';
  $handler->display->display_options['css_class'] = 'publications-grid container';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
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
    'pager' => array(
      'bef_format' => 'default',
      'is_secondary' => 0,
    ),
    'search_api_views_fulltext' => array(
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
    'field_publication_categories' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
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
    'field_publication_type' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
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
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Show:';
  $handler->display->display_options['style_plugin'] = 'responsive_grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['column_classes'] = 'views-column col-sm-12 col-md-4 col-md-offset-2';
  $handler->display->display_options['style_options']['row_classes'] = 'views-row row';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Showing @start to @end of @total entries';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '<h4>Date Posted</h4> [created]';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'n/j/Y  \\a\\t\\ g:ia';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'event_time_date';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Field: Indexed Node: Publication Categories */
  $handler->display->display_options['fields']['field_publication_categories']['id'] = 'field_publication_categories';
  $handler->display->display_options['fields']['field_publication_categories']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_publication_categories']['field'] = 'field_publication_categories';
  $handler->display->display_options['fields']['field_publication_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_categories']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_publication_categories']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_publication_categories']['bypass_access'] = 0;
  /* Field: Indexed Node: Publication Image */
  $handler->display->display_options['fields']['field_publication_image']['id'] = 'field_publication_image';
  $handler->display->display_options['fields']['field_publication_image']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_publication_image']['field'] = 'field_publication_image';
  $handler->display->display_options['fields']['field_publication_image']['label'] = '';
  $handler->display->display_options['fields']['field_publication_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_publication_image']['settings'] = array(
    'image_style' => 'publication_medium',
    'image_link' => 'content',
  );
  /* Field: Indexed Node: Publication Type */
  $handler->display->display_options['fields']['field_publication_type']['id'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_publication_type']['field'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['label'] = '';
  $handler->display->display_options['fields']['field_publication_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_publication_type']['alter']['text'] = '<h4>Type</h4> [field_publication_type]';
  $handler->display->display_options['fields']['field_publication_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_publication_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_publication_type']['bypass_access'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h4>Title</h4>[title]';
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'copy-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="pub-container">
<div class="upper pub row">
<div class="col col-md-5 imagery">
[field_publication_image] 
</div>
<div class="col col-md-7 copy">
<span class="copy-title">[title]</span> 
<span class="file-type">[field_publication_type] </span>
<span>[created]</span>
</div>
</div>
<div class="lower pub">
<h4>Categories</h4>
[field_publication_categories]
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Publication File */
  $handler->display->display_options['fields']['field_publication_file']['id'] = 'field_publication_file';
  $handler->display->display_options['fields']['field_publication_file']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_publication_file']['field'] = 'field_publication_file';
  $handler->display->display_options['fields']['field_publication_file']['label'] = '';
  $handler->display->display_options['fields']['field_publication_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_file']['click_sort_column'] = 'fid';
  /* Sort criterion: Indexed Node: Date changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search Documents';
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
  /* Filter criterion: Indexed Node: Publication Type */
  $handler->display->display_options['filters']['field_publication_type']['id'] = 'field_publication_type';
  $handler->display->display_options['filters']['field_publication_type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_publication_type']['field'] = 'field_publication_type';
  $handler->display->display_options['filters']['field_publication_type']['value'] = array(
    158 => '158',
    119 => '119',
    149 => '149',
    154 => '154',
    218 => '218',
    117 => '117',
    181 => '181',
    171 => '171',
    115 => '115',
    197 => '197',
    214 => '214',
  );
  $handler->display->display_options['filters']['field_publication_type']['group'] = 1;
  $handler->display->display_options['filters']['field_publication_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publication_type']['expose']['operator_id'] = 'field_publication_type_op';
  $handler->display->display_options['filters']['field_publication_type']['expose']['label'] = 'Type:';
  $handler->display->display_options['filters']['field_publication_type']['expose']['operator'] = 'field_publication_type_op';
  $handler->display->display_options['filters']['field_publication_type']['expose']['identifier'] = 'field_publication_type';
  $handler->display->display_options['filters']['field_publication_type']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_publication_type']['expose']['reduce'] = 1;
  $handler->display->display_options['filters']['field_publication_type']['type'] = 'select';
  /* Filter criterion: Indexed Node: Publication Categories */
  $handler->display->display_options['filters']['field_publication_categories']['id'] = 'field_publication_categories';
  $handler->display->display_options['filters']['field_publication_categories']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_publication_categories']['field'] = 'field_publication_categories';
  $handler->display->display_options['filters']['field_publication_categories']['value'] = array();
  $handler->display->display_options['filters']['field_publication_categories']['group'] = 1;
  $handler->display->display_options['filters']['field_publication_categories']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publication_categories']['expose']['operator_id'] = 'field_publication_categories_op';
  $handler->display->display_options['filters']['field_publication_categories']['expose']['label'] = 'Category:';
  $handler->display->display_options['filters']['field_publication_categories']['expose']['operator'] = 'field_publication_categories_op';
  $handler->display->display_options['filters']['field_publication_categories']['expose']['identifier'] = 'field_publication_categories';
  $handler->display->display_options['filters']['field_publication_categories']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_publication_categories']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_publication_categories']['type'] = 'select';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'publications';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'publications-list container';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_publication_image' => 'field_publication_image',
    'title' => 'title',
    'field_publication_type' => 'field_publication_type',
    'field_publication_categories' => 'field_publication_categories',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_publication_image' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_publication_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_publication_categories' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: Publication Image */
  $handler->display->display_options['fields']['field_publication_image']['id'] = 'field_publication_image';
  $handler->display->display_options['fields']['field_publication_image']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_publication_image']['field'] = 'field_publication_image';
  $handler->display->display_options['fields']['field_publication_image']['label'] = 'Thumbnail';
  $handler->display->display_options['fields']['field_publication_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_publication_image']['settings'] = array(
    'image_style' => 'publication_medium',
    'image_link' => 'content',
  );
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h4>Title</h4>[title]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Publication Type */
  $handler->display->display_options['fields']['field_publication_type']['id'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_publication_type']['field'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['label'] = 'Type';
  $handler->display->display_options['fields']['field_publication_type']['alter']['text'] = '<h4>Type</h4> [field_publication_type]';
  $handler->display->display_options['fields']['field_publication_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_publication_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_publication_type']['bypass_access'] = 0;
  /* Field: Indexed Node: Publication Categories */
  $handler->display->display_options['fields']['field_publication_categories']['id'] = 'field_publication_categories';
  $handler->display->display_options['fields']['field_publication_categories']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_publication_categories']['field'] = 'field_publication_categories';
  $handler->display->display_options['fields']['field_publication_categories']['label'] = 'Categories';
  $handler->display->display_options['fields']['field_publication_categories']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_publication_categories']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_publication_categories']['bypass_access'] = 0;
  /* Field: Indexed Node: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Date Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'event_time_date';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'event_time_date';
  $handler->display->display_options['fields']['changed']['link_to_entity'] = 0;
  $handler->display->display_options['path'] = 'publications/list';
  $export['pubs'] = $view;

  return $export;
}
