<?php
/**
 * @file
 * i_want_to_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function i_want_to_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'i_want_to_queues';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'I Want To Queues';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'I Want To Queues';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'jump_menu';
  $handler->display->display_options['style_options']['hide'] = TRUE;
  $handler->display->display_options['style_options']['path'] = 'views_conditional';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entityqueue: Node Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'homepage_jump_menu' => 0,
    'county_board' => 0,
    'ethics' => 0,
    'property_taxes' => 0,
    'elections' => 0,
    'vital_records' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'I Want To';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[field_agency_link]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[path]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
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

  /* Display: Elections */
  $handler = $view->new_display('block', 'Elections', 'block');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityqueue: Node Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'elections' => 'elections',
    'homepage_jump_menu' => 0,
    'county_board' => 0,
    'ethics' => 0,
    'property_taxes' => 0,
    'vital_records' => 0,
  );

  /* Display: Ethics */
  $handler = $view->new_display('block', 'Ethics', 'block_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityqueue: Node Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'ethics' => 'ethics',
    'homepage_jump_menu' => 0,
    'county_board' => 0,
    'property_taxes' => 0,
    'elections' => 0,
    'vital_records' => 0,
  );

  /* Display: Vital Records */
  $handler = $view->new_display('block', 'Vital Records', 'block_2');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityqueue: Node Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'vital_records' => 'vital_records',
    'homepage_jump_menu' => 0,
    'county_board' => 0,
    'ethics' => 0,
    'property_taxes' => 0,
    'elections' => 0,
  );

  /* Display: County Board */
  $handler = $view->new_display('block', 'County Board', 'block_3');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityqueue: Node Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'county_board' => 'county_board',
    'homepage_jump_menu' => 0,
    'ethics' => 0,
    'property_taxes' => 0,
    'elections' => 0,
    'vital_records' => 0,
  );

  /* Display: Property Taxes */
  $handler = $view->new_display('block', 'Property Taxes', 'block_4');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityqueue: Node Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'property_taxes' => 'property_taxes',
    'homepage_jump_menu' => 0,
    'county_board' => 0,
    'ethics' => 0,
    'elections' => 0,
    'vital_records' => 0,
  );

  /* Display: Landing Jump */
  $handler = $view->new_display('block', 'Landing Jump', 'block_5');
  $handler->display->display_options['display_description'] = 'landing page jump menu';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_i_want_to__target_id']['id'] = 'field_i_want_to__target_id';
  $handler->display->display_options['relationships']['field_i_want_to__target_id']['table'] = 'field_data_field_i_want_to_';
  $handler->display->display_options['relationships']['field_i_want_to__target_id']['field'] = 'field_i_want_to__target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_i_want_to_page_reference_target_id']['id'] = 'field_i_want_to_page_reference_target_id';
  $handler->display->display_options['relationships']['field_i_want_to_page_reference_target_id']['table'] = 'field_data_field_i_want_to_page_reference';
  $handler->display->display_options['relationships']['field_i_want_to_page_reference_target_id']['field'] = 'field_i_want_to_page_reference_target_id';
  $handler->display->display_options['relationships']['field_i_want_to_page_reference_target_id']['relationship'] = 'field_i_want_to__target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_i_want_to__target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_i_want_to_page_reference_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: External Resource(s) */
  $handler->display->display_options['fields']['field_agency_link']['id'] = 'field_agency_link';
  $handler->display->display_options['fields']['field_agency_link']['table'] = 'field_data_field_agency_link';
  $handler->display->display_options['fields']['field_agency_link']['field'] = 'field_agency_link';
  $handler->display->display_options['fields']['field_agency_link']['relationship'] = 'field_i_want_to__target_id';
  $handler->display->display_options['fields']['field_agency_link']['label'] = '';
  $handler->display->display_options['fields']['field_agency_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_agency_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_agency_link']['type'] = 'link_absolute';
  /* Field: Content: Link Type */
  $handler->display->display_options['fields']['field_link_type']['id'] = 'field_link_type';
  $handler->display->display_options['fields']['field_link_type']['table'] = 'field_data_field_link_type';
  $handler->display->display_options['fields']['field_link_type']['field'] = 'field_link_type';
  $handler->display->display_options['fields']['field_link_type']['relationship'] = 'field_i_want_to__target_id';
  $handler->display->display_options['fields']['field_link_type']['label'] = '';
  $handler->display->display_options['fields']['field_link_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_type']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_link_type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'Internal';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[path]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[field_agency_link]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Landing Jump Optional */
  $handler = $view->new_display('block', 'Landing Jump Optional', 'block_6');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'optional-jump';
  $handler->display->display_options['display_description'] = 'landing page jump menu';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jump_menu';
  $handler->display->display_options['style_options']['path'] = 'views_conditional';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>I Want To...</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_i_want_to__target_id']['id'] = 'field_i_want_to__target_id';
  $handler->display->display_options['relationships']['field_i_want_to__target_id']['table'] = 'field_data_field_i_want_to_';
  $handler->display->display_options['relationships']['field_i_want_to__target_id']['field'] = 'field_i_want_to__target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_i_want_to_page_reference_target_id']['id'] = 'field_i_want_to_page_reference_target_id';
  $handler->display->display_options['relationships']['field_i_want_to_page_reference_target_id']['table'] = 'field_data_field_i_want_to_page_reference';
  $handler->display->display_options['relationships']['field_i_want_to_page_reference_target_id']['field'] = 'field_i_want_to_page_reference_target_id';
  $handler->display->display_options['relationships']['field_i_want_to_page_reference_target_id']['relationship'] = 'field_i_want_to__target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_i_want_to__target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_i_want_to_page_reference_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: External Resource(s) */
  $handler->display->display_options['fields']['field_agency_link']['id'] = 'field_agency_link';
  $handler->display->display_options['fields']['field_agency_link']['table'] = 'field_data_field_agency_link';
  $handler->display->display_options['fields']['field_agency_link']['field'] = 'field_agency_link';
  $handler->display->display_options['fields']['field_agency_link']['relationship'] = 'field_i_want_to__target_id';
  $handler->display->display_options['fields']['field_agency_link']['label'] = '';
  $handler->display->display_options['fields']['field_agency_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_agency_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_agency_link']['type'] = 'link_absolute';
  /* Field: Content: Link Type */
  $handler->display->display_options['fields']['field_link_type']['id'] = 'field_link_type';
  $handler->display->display_options['fields']['field_link_type']['table'] = 'field_data_field_link_type';
  $handler->display->display_options['fields']['field_link_type']['field'] = 'field_link_type';
  $handler->display->display_options['fields']['field_link_type']['relationship'] = 'field_i_want_to__target_id';
  $handler->display->display_options['fields']['field_link_type']['label'] = '';
  $handler->display->display_options['fields']['field_link_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_type']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_link_type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'Internal';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[path]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[field_agency_link]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
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
  /* Filter criterion: Content: Optional Copy (field_optional_copy) */
  $handler->display->display_options['filters']['field_optional_copy_value']['id'] = 'field_optional_copy_value';
  $handler->display->display_options['filters']['field_optional_copy_value']['table'] = 'field_data_field_optional_copy';
  $handler->display->display_options['filters']['field_optional_copy_value']['field'] = 'field_optional_copy_value';
  $handler->display->display_options['filters']['field_optional_copy_value']['value'] = array(
    1 => '1',
  );
  $export['i_want_to_queues'] = $view;

  return $export;
}
