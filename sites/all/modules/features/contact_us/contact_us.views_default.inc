<?php
/**
 * @file
 * contact_us.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function contact_us_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'contact_us';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'contact us';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contact Us';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_location_target_id']['id'] = 'field_event_location_target_id';
  $handler->display->display_options['relationships']['field_event_location_target_id']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['relationships']['field_event_location_target_id']['field'] = 'field_event_location_target_id';
  /* Relationship: Content: Contact Info (field_contact_info) */
  $handler->display->display_options['relationships']['field_contact_info_value']['id'] = 'field_contact_info_value';
  $handler->display->display_options['relationships']['field_contact_info_value']['table'] = 'field_data_field_contact_info';
  $handler->display->display_options['relationships']['field_contact_info_value']['field'] = 'field_contact_info_value';
  $handler->display->display_options['relationships']['field_contact_info_value']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Location: Address */
  $handler->display->display_options['fields']['address']['id'] = 'address';
  $handler->display->display_options['fields']['address']['table'] = 'location';
  $handler->display->display_options['fields']['address']['field'] = 'address';
  $handler->display->display_options['fields']['address']['relationship'] = 'field_event_location_target_id';
  $handler->display->display_options['fields']['address']['label'] = '';
  $handler->display->display_options['fields']['address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['address']['hide'] = array(
    'name' => 'name',
    'additional' => 'additional',
    'country' => 'country',
    'locpick' => 'locpick',
    'province_name' => 'province_name',
    'country_name' => 'country_name',
    'map_link' => 'map_link',
    'coords' => 'coords',
    'street' => 0,
    'city' => 0,
    'province' => 0,
    'postal_code' => 0,
  );
  $handler->display->display_options['fields']['address']['exclude_cck'] = 0;
  /* Field: Content: Contact Info */
  $handler->display->display_options['fields']['field_contact_info']['id'] = 'field_contact_info';
  $handler->display->display_options['fields']['field_contact_info']['table'] = 'field_data_field_contact_info';
  $handler->display->display_options['fields']['field_contact_info']['field'] = 'field_contact_info';
  $handler->display->display_options['fields']['field_contact_info']['label'] = '';
  $handler->display->display_options['fields']['field_contact_info']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_contact_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_info']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_contact_info']['settings'] = array(
    'view_mode' => 'full',
  );
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
    'use_content_language' => 0,
  );
  /* Field: Content: Related Publication(s) */
  $handler->display->display_options['fields']['field_agency_document']['id'] = 'field_agency_document';
  $handler->display->display_options['fields']['field_agency_document']['table'] = 'field_data_field_agency_document';
  $handler->display->display_options['fields']['field_agency_document']['field'] = 'field_agency_document';
  $handler->display->display_options['fields']['field_agency_document']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_document']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_agency_document']['delta_offset'] = '0';
  /* Field: Field: Phone Number */
  $handler->display->display_options['fields']['field_phone_number']['id'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['table'] = 'field_data_field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['field'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['relationship'] = 'field_contact_info_value';
  $handler->display->display_options['fields']['field_phone_number']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_phone_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_phone_number']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone_number']['settings'] = array(
    'title' => '',
  );
  $handler->display->display_options['fields']['field_phone_number']['delta_offset'] = '0';
  /* Field: Field collection item: Fax Number */
  $handler->display->display_options['fields']['field_fax_number']['id'] = 'field_fax_number';
  $handler->display->display_options['fields']['field_fax_number']['table'] = 'field_data_field_fax_number';
  $handler->display->display_options['fields']['field_fax_number']['field'] = 'field_fax_number';
  $handler->display->display_options['fields']['field_fax_number']['relationship'] = 'field_contact_info_value';
  $handler->display->display_options['fields']['field_fax_number']['label'] = 'Fax ';
  $handler->display->display_options['fields']['field_fax_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fax_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_fax_number']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_fax_number']['settings'] = array(
    'title' => '',
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'contact' => 'contact',
  );
  /* Filter criterion: Content: Primary Contact (field_primary_contact_) */
  $handler->display->display_options['filters']['field_primary_contact__value']['id'] = 'field_primary_contact__value';
  $handler->display->display_options['filters']['field_primary_contact__value']['table'] = 'field_data_field_primary_contact_';
  $handler->display->display_options['filters']['field_primary_contact__value']['field'] = 'field_primary_contact__value';
  $handler->display->display_options['filters']['field_primary_contact__value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_primary_contact__value']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'contact-body container';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'responsive_grid';
  $handler->display->display_options['style_options']['wrapper_classes'] = 'contact-grid';
  $handler->display->display_options['style_options']['column_classes'] = 'views-column ';
  $handler->display->display_options['style_options']['row_classes'] = 'views-row row';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'accent';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Location: Address */
  $handler->display->display_options['fields']['address']['id'] = 'address';
  $handler->display->display_options['fields']['address']['table'] = 'location';
  $handler->display->display_options['fields']['address']['field'] = 'address';
  $handler->display->display_options['fields']['address']['relationship'] = 'field_event_location_target_id';
  $handler->display->display_options['fields']['address']['label'] = '';
  $handler->display->display_options['fields']['address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['address']['element_type'] = 'strong';
  $handler->display->display_options['fields']['address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['address']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['address']['element_wrapper_class'] = 'padding';
  $handler->display->display_options['fields']['address']['hide'] = array(
    'name' => 'name',
    'city' => 'city',
    'province' => 'province',
    'postal_code' => 'postal_code',
    'country' => 'country',
    'locpick' => 'locpick',
    'province_name' => 'province_name',
    'country_name' => 'country_name',
    'map_link' => 'map_link',
    'coords' => 'coords',
    'street' => 0,
    'additional' => 0,
  );
  $handler->display->display_options['fields']['address']['exclude_cck'] = 0;
  /* Field: Location: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'location';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  $handler->display->display_options['fields']['city']['relationship'] = 'field_event_location_target_id';
  $handler->display->display_options['fields']['city']['label'] = '';
  $handler->display->display_options['fields']['city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['city']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['city']['alter']['text'] = '[city],';
  $handler->display->display_options['fields']['city']['element_label_colon'] = FALSE;
  /* Field: Location: Province */
  $handler->display->display_options['fields']['province']['id'] = 'province';
  $handler->display->display_options['fields']['province']['table'] = 'location';
  $handler->display->display_options['fields']['province']['field'] = 'province';
  $handler->display->display_options['fields']['province']['relationship'] = 'field_event_location_target_id';
  $handler->display->display_options['fields']['province']['label'] = '';
  $handler->display->display_options['fields']['province']['exclude'] = TRUE;
  $handler->display->display_options['fields']['province']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['province']['style'] = 'code';
  /* Field: Location: Postal Code */
  $handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['table'] = 'location';
  $handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
  $handler->display->display_options['fields']['postal_code']['relationship'] = 'field_event_location_target_id';
  $handler->display->display_options['fields']['postal_code']['label'] = '';
  $handler->display->display_options['fields']['postal_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['postal_code']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<strong>[address]</strong>
[city] [province] [postal_code]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'padding';
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_event_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_location']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_event_location']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_event_location']['settings'] = array(
    'view_mode' => 'teaser',
    'links' => 0,
    'use_content_language' => 0,
  );
  /* Field: Content: Optional Name/Employee */
  $handler->display->display_options['fields']['field_optional_title']['id'] = 'field_optional_title';
  $handler->display->display_options['fields']['field_optional_title']['table'] = 'field_data_field_optional_title';
  $handler->display->display_options['fields']['field_optional_title']['field'] = 'field_optional_title';
  $handler->display->display_options['fields']['field_optional_title']['label'] = '';
  $handler->display->display_options['fields']['field_optional_title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_optional_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_optional_title']['hide_empty'] = TRUE;
  /* Field: Content: Optional Title */
  $handler->display->display_options['fields']['field_optional_job']['id'] = 'field_optional_job';
  $handler->display->display_options['fields']['field_optional_job']['table'] = 'field_data_field_optional_job';
  $handler->display->display_options['fields']['field_optional_job']['field'] = 'field_optional_job';
  $handler->display->display_options['fields']['field_optional_job']['label'] = '';
  $handler->display->display_options['fields']['field_optional_job']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_optional_job']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_optional_job']['element_wrapper_class'] = 'optional-title';
  /* Field: Field: Phone Number */
  $handler->display->display_options['fields']['field_phone_number']['id'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['table'] = 'field_data_field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['field'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['relationship'] = 'field_contact_info_value';
  $handler->display->display_options['fields']['field_phone_number']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_phone_number']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_phone_number']['element_label_class'] = 'view-label';
  $handler->display->display_options['fields']['field_phone_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_phone_number']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone_number']['settings'] = array(
    'title' => '',
  );
  $handler->display->display_options['fields']['field_phone_number']['delta_offset'] = '0';
  /* Field: Field collection item: Cell Number */
  $handler->display->display_options['fields']['field_cell_number']['id'] = 'field_cell_number';
  $handler->display->display_options['fields']['field_cell_number']['table'] = 'field_data_field_cell_number';
  $handler->display->display_options['fields']['field_cell_number']['field'] = 'field_cell_number';
  $handler->display->display_options['fields']['field_cell_number']['relationship'] = 'field_contact_info_value';
  $handler->display->display_options['fields']['field_cell_number']['label'] = 'Cell';
  $handler->display->display_options['fields']['field_cell_number']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_cell_number']['element_label_class'] = 'view-label';
  $handler->display->display_options['fields']['field_cell_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cell_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_cell_number']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_cell_number']['settings'] = array(
    'title' => '',
  );
  /* Field: Field collection item: Fax Number */
  $handler->display->display_options['fields']['field_fax_number']['id'] = 'field_fax_number';
  $handler->display->display_options['fields']['field_fax_number']['table'] = 'field_data_field_fax_number';
  $handler->display->display_options['fields']['field_fax_number']['field'] = 'field_fax_number';
  $handler->display->display_options['fields']['field_fax_number']['relationship'] = 'field_contact_info_value';
  $handler->display->display_options['fields']['field_fax_number']['label'] = 'Fax ';
  $handler->display->display_options['fields']['field_fax_number']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_fax_number']['element_label_class'] = 'view-label';
  $handler->display->display_options['fields']['field_fax_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fax_number']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_fax_number']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_fax_number']['settings'] = array(
    'title' => '',
  );
  /* Field: Field: Location Email */
  $handler->display->display_options['fields']['field_location_email']['id'] = 'field_location_email';
  $handler->display->display_options['fields']['field_location_email']['table'] = 'field_data_field_location_email';
  $handler->display->display_options['fields']['field_location_email']['field'] = 'field_location_email';
  $handler->display->display_options['fields']['field_location_email']['relationship'] = 'field_contact_info_value';
  $handler->display->display_options['fields']['field_location_email']['label'] = 'Email';
  $handler->display->display_options['fields']['field_location_email']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_location_email']['element_label_class'] = 'view-label';
  $handler->display->display_options['fields']['field_location_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_email']['hide_empty'] = TRUE;
  /* Field: Field collection item: Additional Email Title */
  $handler->display->display_options['fields']['field_additional_email_title']['id'] = 'field_additional_email_title';
  $handler->display->display_options['fields']['field_additional_email_title']['table'] = 'field_data_field_additional_email_title';
  $handler->display->display_options['fields']['field_additional_email_title']['field'] = 'field_additional_email_title';
  $handler->display->display_options['fields']['field_additional_email_title']['relationship'] = 'field_contact_info_value';
  $handler->display->display_options['fields']['field_additional_email_title']['label'] = '';
  $handler->display->display_options['fields']['field_additional_email_title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_additional_email_title']['element_class'] = 'view-label';
  $handler->display->display_options['fields']['field_additional_email_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_additional_email_title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_additional_email_title']['element_wrapper_class'] = 'padding more-info';
  $handler->display->display_options['fields']['field_additional_email_title']['hide_empty'] = TRUE;
  /* Field: Field collection item: Additional Email */
  $handler->display->display_options['fields']['field_additional_email']['id'] = 'field_additional_email';
  $handler->display->display_options['fields']['field_additional_email']['table'] = 'field_data_field_additional_email';
  $handler->display->display_options['fields']['field_additional_email']['field'] = 'field_additional_email';
  $handler->display->display_options['fields']['field_additional_email']['relationship'] = 'field_contact_info_value';
  $handler->display->display_options['fields']['field_additional_email']['label'] = '';
  $handler->display->display_options['fields']['field_additional_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_additional_email']['hide_empty'] = TRUE;
  /* Field: Content: Related Publication(s) */
  $handler->display->display_options['fields']['field_agency_document']['id'] = 'field_agency_document';
  $handler->display->display_options['fields']['field_agency_document']['table'] = 'field_data_field_agency_document';
  $handler->display->display_options['fields']['field_agency_document']['field'] = 'field_agency_document';
  $handler->display->display_options['fields']['field_agency_document']['label'] = 'More Information';
  $handler->display->display_options['fields']['field_agency_document']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_agency_document']['element_label_class'] = 'view-label-info';
  $handler->display->display_options['fields']['field_agency_document']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agency_document']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_agency_document']['element_wrapper_class'] = 'padding more-info';
  $handler->display->display_options['fields']['field_agency_document']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_agency_document']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_agency_document']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_agency_document']['multi_type'] = 'ul';
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
    'contact' => 'contact',
  );
  /* Filter criterion: Content: Primary Contact (field_primary_contact_) */
  $handler->display->display_options['filters']['field_primary_contact__value']['id'] = 'field_primary_contact__value';
  $handler->display->display_options['filters']['field_primary_contact__value']['table'] = 'field_data_field_primary_contact_';
  $handler->display->display_options['filters']['field_primary_contact__value']['field'] = 'field_primary_contact__value';
  $handler->display->display_options['filters']['field_primary_contact__value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['path'] = 'contact-us';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'contact-header';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_location_target_id']['id'] = 'field_event_location_target_id';
  $handler->display->display_options['relationships']['field_event_location_target_id']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['relationships']['field_event_location_target_id']['field'] = 'field_event_location_target_id';
  /* Relationship: Content: Contact Info (field_contact_info) */
  $handler->display->display_options['relationships']['field_contact_info_value']['id'] = 'field_contact_info_value';
  $handler->display->display_options['relationships']['field_contact_info_value']['table'] = 'field_data_field_contact_info';
  $handler->display->display_options['relationships']['field_contact_info_value']['field'] = 'field_contact_info_value';
  $handler->display->display_options['relationships']['field_contact_info_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Location: Address */
  $handler->display->display_options['fields']['address']['id'] = 'address';
  $handler->display->display_options['fields']['address']['table'] = 'location';
  $handler->display->display_options['fields']['address']['field'] = 'address';
  $handler->display->display_options['fields']['address']['relationship'] = 'field_event_location_target_id';
  $handler->display->display_options['fields']['address']['label'] = '';
  $handler->display->display_options['fields']['address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['address']['hide'] = array(
    'name' => 'name',
    'country' => 'country',
    'locpick' => 'locpick',
    'province_name' => 'province_name',
    'country_name' => 'country_name',
    'map_link' => 'map_link',
    'coords' => 'coords',
    'street' => 0,
    'additional' => 0,
    'city' => 0,
    'province' => 0,
    'postal_code' => 0,
  );
  $handler->display->display_options['fields']['address']['exclude_cck'] = 0;
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
    'use_content_language' => 0,
  );
  /* Field: Field: Location Email */
  $handler->display->display_options['fields']['field_location_email']['id'] = 'field_location_email';
  $handler->display->display_options['fields']['field_location_email']['table'] = 'field_data_field_location_email';
  $handler->display->display_options['fields']['field_location_email']['field'] = 'field_location_email';
  $handler->display->display_options['fields']['field_location_email']['relationship'] = 'field_contact_info_value';
  $handler->display->display_options['fields']['field_location_email']['label'] = '';
  $handler->display->display_options['fields']['field_location_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location_email']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_event_location_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="contact-map">[address]</div><div class="contact-prime-email">[field_location_email]</div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'contact-primary-wrapper';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Field: Phone Number */
  $handler->display->display_options['fields']['field_phone_number_1']['id'] = 'field_phone_number_1';
  $handler->display->display_options['fields']['field_phone_number_1']['table'] = 'field_data_field_phone_number';
  $handler->display->display_options['fields']['field_phone_number_1']['field'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number_1']['label'] = '';
  $handler->display->display_options['fields']['field_phone_number_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone_number_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone_number_1']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone_number_1']['settings'] = array(
    'title' => '',
  );
  /* Field: Content: Primary Contact Info */
  $handler->display->display_options['fields']['field_primary_contact_info']['id'] = 'field_primary_contact_info';
  $handler->display->display_options['fields']['field_primary_contact_info']['table'] = 'field_data_field_primary_contact_info';
  $handler->display->display_options['fields']['field_primary_contact_info']['field'] = 'field_primary_contact_info';
  $handler->display->display_options['fields']['field_primary_contact_info']['label'] = '';
  $handler->display->display_options['fields']['field_primary_contact_info']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_primary_contact_info']['element_class'] = 'lang-phone';
  $handler->display->display_options['fields']['field_primary_contact_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_primary_contact_info']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_primary_contact_info']['element_wrapper_class'] = 'lang-wrapper';
  $handler->display->display_options['fields']['field_primary_contact_info']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_primary_contact_info']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_primary_contact_info']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_primary_contact_info']['multi_type'] = 'ul';
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
    'contact' => 'contact',
  );
  /* Filter criterion: Content: Primary Contact (field_primary_contact_) */
  $handler->display->display_options['filters']['field_primary_contact__value']['id'] = 'field_primary_contact__value';
  $handler->display->display_options['filters']['field_primary_contact__value']['table'] = 'field_data_field_primary_contact_';
  $handler->display->display_options['filters']['field_primary_contact__value']['field'] = 'field_primary_contact__value';
  $handler->display->display_options['filters']['field_primary_contact__value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['contact_us'] = $view;

  return $export;
}
