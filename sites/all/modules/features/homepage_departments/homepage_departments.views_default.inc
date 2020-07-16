<?php
/**
 * @file
 * homepage_departments.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function homepage_departments_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'departments';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Departments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cook County Clerk Departments';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entityqueue: Node Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'homepage_departments' => 'homepage_departments',
    'homepage_jump_menu' => 0,
    'county_board' => 0,
    'ethics' => 0,
    'property_taxes' => 0,
    'elections' => 0,
    'vital_records' => 0,
    'homepage' => 0,
  );
  /* Field: Content: External Resource(s) */
  $handler->display->display_options['fields']['field_agency_link']['id'] = 'field_agency_link';
  $handler->display->display_options['fields']['field_agency_link']['table'] = 'field_data_field_agency_link';
  $handler->display->display_options['fields']['field_agency_link']['field'] = 'field_agency_link';
  $handler->display->display_options['fields']['field_agency_link']['label'] = '';
  $handler->display->display_options['fields']['field_agency_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_agency_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_agency_link']['type'] = 'link_absolute';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Icon Type */
  $handler->display->display_options['fields']['field_icon_type']['id'] = 'field_icon_type';
  $handler->display->display_options['fields']['field_icon_type']['table'] = 'field_data_field_icon_type';
  $handler->display->display_options['fields']['field_icon_type']['field'] = 'field_icon_type';
  $handler->display->display_options['fields']['field_icon_type']['label'] = '';
  $handler->display->display_options['fields']['field_icon_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_icon_type']['alter']['text'] = '<span class="fa fa-[field_icon_type] icon"></span>';
  $handler->display->display_options['fields']['field_icon_type']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_icon_type']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_icon_type']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_icon_type']['element_class'] = 'icon-type';
  $handler->display->display_options['fields']['field_icon_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_icon_type']['empty'] = '<a href="[path]"><span class="fa fa-asterisk icon"></span><a>';
  $handler->display->display_options['fields']['field_icon_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Icon Type */
  $handler->display->display_options['fields']['field_icon_type_1']['id'] = 'field_icon_type_1';
  $handler->display->display_options['fields']['field_icon_type_1']['table'] = 'field_data_field_icon_type';
  $handler->display->display_options['fields']['field_icon_type_1']['field'] = 'field_icon_type';
  $handler->display->display_options['fields']['field_icon_type_1']['label'] = '';
  $handler->display->display_options['fields']['field_icon_type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_icon_type_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_icon_type_1']['alter']['text'] = 'fa-[field_icon_type_1]';
  $handler->display->display_options['fields']['field_icon_type_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_icon_type_1']['empty'] = 'fa-asterisk';
  $handler->display->display_options['fields']['field_icon_type_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="hidden-lg hidden-sm hidden-md fa [field_icon_type_1] icon"></span>
[title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'dept-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '<span class="hidden-lg hidden-sm hidden-md fa fa-youtube-play icon"></span>
[title_1]';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Field: Body */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['label'] = '';
  $handler->display->display_options['fields']['field_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_body']['settings'] = array(
    'trim_length' => '150',
  );
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['label'] = '';
  $handler->display->display_options['fields']['field_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_summary']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_type'] = 'div';
  $handler->display->display_options['fields']['views_conditional']['element_class'] = 'dept-title-icon';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'I Want To';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<a href="[field_agency_link]">[title_1]</a> 
<div class="views-field-field-agency-description">[field_summary]</div>';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[title]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Content: Body Content */
  $handler->display->display_options['fields']['field_agency_description']['id'] = 'field_agency_description';
  $handler->display->display_options['fields']['field_agency_description']['table'] = 'field_data_field_agency_description';
  $handler->display->display_options['fields']['field_agency_description']['field'] = 'field_agency_description';
  $handler->display->display_options['fields']['field_agency_description']['label'] = '';
  $handler->display->display_options['fields']['field_agency_description']['element_label_colon'] = FALSE;
  /* Sort criterion: Entityqueue: Node Queue Position */
  $handler->display->display_options['sorts']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['sorts']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['sorts']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['departments'] = $view;

  return $export;
}
