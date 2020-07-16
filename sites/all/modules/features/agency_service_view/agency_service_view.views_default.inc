<?php
/**
 * @file
 * agency_service_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function agency_service_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'services';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'services';
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
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_services_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_services_node';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'service' => 'service',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'service-content';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'ag-services';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_agency_services_node']['id'] = 'reverse_field_agency_services_node';
  $handler->display->display_options['relationships']['reverse_field_agency_services_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_agency_services_node']['field'] = 'reverse_field_agency_services_node';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_agency_services_target_id']['id'] = 'field_agency_services_target_id';
  $handler->display->display_options['relationships']['field_agency_services_target_id']['table'] = 'field_data_field_agency_services';
  $handler->display->display_options['relationships']['field_agency_services_target_id']['field'] = 'field_agency_services_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: External Resource(s) */
  $handler->display->display_options['fields']['field_agency_link']['id'] = 'field_agency_link';
  $handler->display->display_options['fields']['field_agency_link']['table'] = 'field_data_field_agency_link';
  $handler->display->display_options['fields']['field_agency_link']['field'] = 'field_agency_link';
  $handler->display->display_options['fields']['field_agency_link']['label'] = '';
  $handler->display->display_options['fields']['field_agency_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_agency_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_agency_link']['type'] = 'link_absolute';
  $handler->display->display_options['fields']['field_agency_link']['delta_offset'] = '0';
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_1']['id'] = 'views_conditional_1';
  $handler->display->display_options['fields']['views_conditional_1']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_1']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional_1']['condition'] = '7';
  $handler->display->display_options['fields']['views_conditional_1']['equalto'] = 'agency';
  $handler->display->display_options['fields']['views_conditional_1']['then'] = '[path]';
  $handler->display->display_options['fields']['views_conditional_1']['or'] = '[field_agency_link]';
  $handler->display->display_options['fields']['views_conditional_1']['strip_tags'] = 0;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_agency_link';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '6';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[views_conditional_1]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[path]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Content: Icon Type */
  $handler->display->display_options['fields']['field_icon_type']['id'] = 'field_icon_type';
  $handler->display->display_options['fields']['field_icon_type']['table'] = 'field_data_field_icon_type';
  $handler->display->display_options['fields']['field_icon_type']['field'] = 'field_icon_type';
  $handler->display->display_options['fields']['field_icon_type']['label'] = '';
  $handler->display->display_options['fields']['field_icon_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_icon_type']['alter']['text'] = '<span class="fa fa-[field_icon_type] icon"></span>';
  $handler->display->display_options['fields']['field_icon_type']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_icon_type']['alter']['path'] = '[views_conditional]';
  $handler->display->display_options['fields']['field_icon_type']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_icon_type']['element_class'] = 'icon-type';
  $handler->display->display_options['fields']['field_icon_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_icon_type']['empty'] = '<a href="[path]"><span class="fa fa-asterisk icon"></span><a>';
  $handler->display->display_options['fields']['field_icon_type']['settings'] = array(
    'bypass_access' => 0,
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="hidden-lg hidden-sm fa [field_icon_type_1] icon"></span>
[title]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[views_conditional]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'dept-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body Content */
  $handler->display->display_options['fields']['field_service_description_1']['id'] = 'field_service_description_1';
  $handler->display->display_options['fields']['field_service_description_1']['table'] = 'field_data_field_service_description';
  $handler->display->display_options['fields']['field_service_description_1']['field'] = 'field_service_description';
  $handler->display->display_options['fields']['field_service_description_1']['label'] = '';
  $handler->display->display_options['fields']['field_service_description_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_service_description_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_service_description_1']['alter']['preserve_tags'] = '<p><br>';
  $handler->display->display_options['fields']['field_service_description_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_service_description_1']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_service_description_1']['settings'] = array(
    'trim_length' => '150',
  );
  /* Field: Content: Body Content */
  $handler->display->display_options['fields']['field_agency_description']['id'] = 'field_agency_description';
  $handler->display->display_options['fields']['field_agency_description']['table'] = 'field_data_field_agency_description';
  $handler->display->display_options['fields']['field_agency_description']['field'] = 'field_agency_description';
  $handler->display->display_options['fields']['field_agency_description']['label'] = '';
  $handler->display->display_options['fields']['field_agency_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_agency_description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_agency_description']['alter']['preserve_tags'] = '<p><br>';
  $handler->display->display_options['fields']['field_agency_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_agency_description']['settings'] = array(
    'trim_length' => '150',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<p><br>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '150',
  );
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['label'] = '';
  $handler->display->display_options['fields']['field_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_agency_services_node';
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
    'agency' => 'agency',
    'general' => 'general',
    'i_want_to' => 'i_want_to',
    'service' => 'service',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'I Want To';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jump_menu';
  $handler->display->display_options['style_options']['hide'] = TRUE;
  $handler->display->display_options['style_options']['path'] = 'path';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_services_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_services_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $export['services'] = $view;

  return $export;
}
