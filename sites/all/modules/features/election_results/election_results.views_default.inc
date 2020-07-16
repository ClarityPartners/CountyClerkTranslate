<?php
/**
 * @file
 * election_results.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function election_results_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'election_results';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Election Results';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Election Results';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_election_date',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'field_election_date' => 'field_election_date',
    'field_election_date_1' => 'field_election_date_1',
    'title' => 'title',
    'field_online_results' => 'field_online_results',
    'field_printable_results' => 'field_printable_results',
    'field_certificates' => 'field_certificates',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_election_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_election_date_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_online_results' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_printable_results' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_certificates' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'The Cook County Clerk\'s office archives election results on our webpage going back to 1998. Search our Election Results and Statistics Database for results of general elections, primaries, and consolidated local elections.';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '*To view Election Result Certificates, click on "Available," search for a race, and select the <img id="44" style="height:40px; width:30px;" src="https://dev-drupal.cookcountyclerk-test.com/sites/default/files/filefield_paths/44_1.png" name="44" a="alt" /> from the top right of the table.';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* Field: Content: Election Date */
  $handler->display->display_options['fields']['field_election_date']['id'] = 'field_election_date';
  $handler->display->display_options['fields']['field_election_date']['table'] = 'field_data_field_election_date';
  $handler->display->display_options['fields']['field_election_date']['field'] = 'field_election_date';
  $handler->display->display_options['fields']['field_election_date']['label'] = '';
  $handler->display->display_options['fields']['field_election_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_election_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_election_date']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'Y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Election Date */
  $handler->display->display_options['fields']['field_election_date_1']['id'] = 'field_election_date_1';
  $handler->display->display_options['fields']['field_election_date_1']['table'] = 'field_data_field_election_date';
  $handler->display->display_options['fields']['field_election_date_1']['field'] = 'field_election_date';
  $handler->display->display_options['fields']['field_election_date_1']['label'] = 'Date';
  $handler->display->display_options['fields']['field_election_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_election_date_1']['settings'] = array(
    'format_type' => 'news',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Display Title */
  $handler->display->display_options['fields']['field_display_title']['id'] = 'field_display_title';
  $handler->display->display_options['fields']['field_display_title']['table'] = 'field_data_field_display_title';
  $handler->display->display_options['fields']['field_display_title']['field'] = 'field_display_title';
  $handler->display->display_options['fields']['field_display_title']['label'] = 'Election';
  /* Field: Content: Online Results */
  $handler->display->display_options['fields']['field_online_results']['id'] = 'field_online_results';
  $handler->display->display_options['fields']['field_online_results']['table'] = 'field_data_field_online_results';
  $handler->display->display_options['fields']['field_online_results']['field'] = 'field_online_results';
  $handler->display->display_options['fields']['field_online_results']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_online_results']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_online_results']['type'] = 'link_absolute';
  /* Field: Content: Printable Results */
  $handler->display->display_options['fields']['field_printable_results']['id'] = 'field_printable_results';
  $handler->display->display_options['fields']['field_printable_results']['table'] = 'field_data_field_printable_results';
  $handler->display->display_options['fields']['field_printable_results']['field'] = 'field_printable_results';
  $handler->display->display_options['fields']['field_printable_results']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_printable_results']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_printable_results']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_printable_results']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_printable_results']['multi_type'] = 'ul';
  /* Field: Content: Certificates */
  $handler->display->display_options['fields']['field_certificates']['id'] = 'field_certificates';
  $handler->display->display_options['fields']['field_certificates']['table'] = 'field_data_field_certificates';
  $handler->display->display_options['fields']['field_certificates']['field'] = 'field_certificates';
  $handler->display->display_options['fields']['field_certificates']['label'] = 'Certificates*';
  $handler->display->display_options['fields']['field_certificates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_certificates']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_certificates']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_certificates']['type'] = 'link_absolute';
  /* Sort criterion: Content: Election Date (field_election_date) */
  $handler->display->display_options['sorts']['field_election_date_value']['id'] = 'field_election_date_value';
  $handler->display->display_options['sorts']['field_election_date_value']['table'] = 'field_data_field_election_date';
  $handler->display->display_options['sorts']['field_election_date_value']['field'] = 'field_election_date_value';
  $handler->display->display_options['sorts']['field_election_date_value']['order'] = 'DESC';
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
    'election_results' => 'election_results',
  );
  /* Filter criterion: Content: Election Date (field_election_date) */
  $handler->display->display_options['filters']['field_election_date_value']['id'] = 'field_election_date_value';
  $handler->display->display_options['filters']['field_election_date_value']['table'] = 'field_data_field_election_date';
  $handler->display->display_options['filters']['field_election_date_value']['field'] = 'field_election_date_value';
  $handler->display->display_options['filters']['field_election_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_election_date_value']['expose']['operator_id'] = 'field_election_date_value_op';
  $handler->display->display_options['filters']['field_election_date_value']['expose']['label'] = 'Search Election Results';
  $handler->display->display_options['filters']['field_election_date_value']['expose']['operator'] = 'field_election_date_value_op';
  $handler->display->display_options['filters']['field_election_date_value']['expose']['identifier'] = 'field_election_date_value';
  $handler->display->display_options['filters']['field_election_date_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_election_date_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_election_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_election_date_value']['year_range'] = '-0:1998';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'election-results';
  $export['election_results'] = $view;

  return $export;
}
