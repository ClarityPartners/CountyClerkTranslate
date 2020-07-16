<?php
/**
 * @file
 * broadcast_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function broadcast_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'broadcast';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Broadcast';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'broadcast';
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
  $handler->display->display_options['relationships']['field_broadcast_related_pages_target_id']['id'] = 'field_broadcast_related_pages_target_id';
  $handler->display->display_options['relationships']['field_broadcast_related_pages_target_id']['table'] = 'field_data_field_broadcast_related_pages';
  $handler->display->display_options['relationships']['field_broadcast_related_pages_target_id']['field'] = 'field_broadcast_related_pages_target_id';
  /* Field: Content: Broadcast Type */
  $handler->display->display_options['fields']['field_broadcast_type']['id'] = 'field_broadcast_type';
  $handler->display->display_options['fields']['field_broadcast_type']['table'] = 'field_data_field_broadcast_type';
  $handler->display->display_options['fields']['field_broadcast_type']['field'] = 'field_broadcast_type';
  $handler->display->display_options['fields']['field_broadcast_type']['label'] = '';
  $handler->display->display_options['fields']['field_broadcast_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_broadcast_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_broadcast_type']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_broadcast_type']['group_column'] = 'value';
  $handler->display->display_options['fields']['field_broadcast_type']['delta_offset'] = '0';
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_broadcast_url']['id'] = 'field_broadcast_url';
  $handler->display->display_options['fields']['field_broadcast_url']['table'] = 'field_data_field_broadcast_url';
  $handler->display->display_options['fields']['field_broadcast_url']['field'] = 'field_broadcast_url';
  $handler->display->display_options['fields']['field_broadcast_url']['label'] = '';
  $handler->display->display_options['fields']['field_broadcast_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_broadcast_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_broadcast_url']['click_sort_column'] = 'url';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Message */
  $handler->display->display_options['fields']['field_broadcast_message']['id'] = 'field_broadcast_message';
  $handler->display->display_options['fields']['field_broadcast_message']['table'] = 'field_data_field_broadcast_message';
  $handler->display->display_options['fields']['field_broadcast_message']['field'] = 'field_broadcast_message';
  $handler->display->display_options['fields']['field_broadcast_message']['label'] = '';
  $handler->display->display_options['fields']['field_broadcast_message']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_broadcast_message']['alter']['text'] = '<div class="[field_broadcast_type] broadcast-type">
<div class="container">
<div class="icon col-md-1">
</div>
<div class="message col-md-11">
<h4>[title]</h4>
[field_broadcast_message]
[field_broadcast_url]
</div>

</div>
</div>';
  $handler->display->display_options['fields']['field_broadcast_message']['element_label_colon'] = FALSE;
  /* Field: Content: Placement */
  $handler->display->display_options['fields']['field_broadcast_related_pages']['id'] = 'field_broadcast_related_pages';
  $handler->display->display_options['fields']['field_broadcast_related_pages']['table'] = 'field_data_field_broadcast_related_pages';
  $handler->display->display_options['fields']['field_broadcast_related_pages']['field'] = 'field_broadcast_related_pages';
  $handler->display->display_options['fields']['field_broadcast_related_pages']['label'] = '';
  $handler->display->display_options['fields']['field_broadcast_related_pages']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_broadcast_related_pages']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_broadcast_related_pages']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_broadcast_related_pages']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="[field_broadcast_type] broadcast-type">
<div class="container">
<div class="icon col-md-1">
</div>
<div class="message col-md-11">
<h4>[title]</h4>
[field_broadcast_message]
[field_broadcast_url]
</div>

</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_broadcast_related_pages_target_id';
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
    'broadcast' => 'broadcast',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['broadcast'] = $view;

  return $export;
}
