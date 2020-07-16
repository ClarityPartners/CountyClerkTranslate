<?php
/**
 * @file
 * map_room.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function map_room_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'map_room';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'Map Room';
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
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p><big>The Cook County Clerk’s office produces a plethora of maps pertaining to elections and taxing districts. All of our available maps are posted here as PDFs <em>(<a href="http://get.adobe.com/reader/" target="_blank">Adobe Acrobat</a> may be required.)</em></big></p>

<p><br>
If you are looking for your polling location or your elected officials, please use the <a href="/service/your-voter-information-0">Your Voter Information tool</a>.</p>

<p>Property tax maps that show the boundaries of each parcel are available for purchase through the <a href="/service/tax-maps">Clerk\'s map department</a>.<br>
&nbsp;</p>

<h4><span style="color:#ff0000;"><em><strong>NEW!</strong></em></span>&nbsp; <a href="http://gis1.cookcountyil.gov/Electionresults/" target="_blank">Click here for interactive election results maps</a>.</h4>

<h4><span style="color:#ff0000;"><em><strong>NEW!</strong></em></span>&nbsp; <a href="https://maps.cookcountyil.gov/electionVwrLite/#" target="_blank">Election Viewer map application</a>.</h4>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
  /* Sort criterion: Indexed Node: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Indexed Node: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
  $handler->display->display_options['filters']['field_publication_type']['expose']['label'] = 'Publication Type';
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
  $handler->display->display_options['filters']['field_publication_type']['expose']['reduce'] = 0;
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

  /* Display: Page Grid */
  $handler = $view->new_display('page', 'Page Grid', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Map Room';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Publication Type */
  $handler->display->display_options['filters']['field_publication_type']['id'] = 'field_publication_type';
  $handler->display->display_options['filters']['field_publication_type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_publication_type']['field'] = 'field_publication_type';
  $handler->display->display_options['filters']['field_publication_type']['value'] = array(
    181 => '181',
  );
  $handler->display->display_options['filters']['field_publication_type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_publication_categories']['value'] = array(
    165 => '165',
    203 => '203',
    164 => '164',
    219 => '219',
    162 => '162',
    209 => '209',
    173 => '173',
    215 => '215',
    216 => '216',
    196 => '196',
    155 => '155',
    172 => '172',
    174 => '174',
  );
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
  $handler->display->display_options['filters']['field_publication_categories']['expose']['reduce'] = 1;
  $handler->display->display_options['filters']['field_publication_categories']['type'] = 'select';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
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
  $handler->display->display_options['path'] = 'map-room';

  /* Display: Page List */
  $handler = $view->new_display('page', 'Page List', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Map Room';
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
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
  /* Field: Indexed Node: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date Posted';
  $handler->display->display_options['fields']['created']['alter']['text'] = '<h4>Date Posted</h4> [created]';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'n/j/Y  \\a\\t\\ g:ia';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'event_time_date';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Publication Type */
  $handler->display->display_options['filters']['field_publication_type']['id'] = 'field_publication_type';
  $handler->display->display_options['filters']['field_publication_type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_publication_type']['field'] = 'field_publication_type';
  $handler->display->display_options['filters']['field_publication_type']['value'] = array(
    181 => '181',
  );
  $handler->display->display_options['filters']['field_publication_type']['group'] = 1;
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
  $handler->display->display_options['filters']['field_publication_categories']['value'] = array(
    165 => '165',
    203 => '203',
    164 => '164',
    219 => '219',
    162 => '162',
    209 => '209',
    173 => '173',
    215 => '215',
    216 => '216',
    196 => '196',
    155 => '155',
    172 => '172',
    174 => '174',
  );
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
  $handler->display->display_options['filters']['field_publication_categories']['expose']['reduce'] = 1;
  $handler->display->display_options['filters']['field_publication_categories']['type'] = 'select';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
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
  $handler->display->display_options['path'] = 'map-room';
  $export['map_room'] = $view;

  return $export;
}
