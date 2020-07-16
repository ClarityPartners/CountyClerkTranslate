<?php
/**
 * @file
 * location_content_type.default_cer_presets.inc
 */

/**
 * Implements hook_default_cer().
 */
function location_content_type_default_cer() {
  $export = array();

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'node*location*field_at_this_location*node*agency*field_agency_main_location';
  $cnr_obj->enabled = 1;
  $export['node*location*field_at_this_location*node*agency*field_agency_main_location'] = $cnr_obj;

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'node*location*field_at_this_location*node*agency*field_agency_other_locations';
  $cnr_obj->enabled = 1;
  $export['node*location*field_at_this_location*node*agency*field_agency_other_locations'] = $cnr_obj;

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'node*location*field_at_this_location*node*event*field_event_location';
  $cnr_obj->enabled = 1;
  $export['node*location*field_at_this_location*node*event*field_event_location'] = $cnr_obj;

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'node*location*field_at_this_location*node*government_body*field_govb_office_location';
  $cnr_obj->enabled = 1;
  $export['node*location*field_at_this_location*node*government_body*field_govb_office_location'] = $cnr_obj;

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'node*location*field_at_this_location*node*person*field_person_office_location';
  $cnr_obj->enabled = 1;
  $export['node*location*field_at_this_location*node*person*field_person_office_location'] = $cnr_obj;

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'node*location*field_at_this_location*node*program*field_program_main_location';
  $cnr_obj->enabled = 1;
  $export['node*location*field_at_this_location*node*program*field_program_main_location'] = $cnr_obj;

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'node*location*field_at_this_location*node*program*field_program_other_location';
  $cnr_obj->enabled = 1;
  $export['node*location*field_at_this_location*node*program*field_program_other_location'] = $cnr_obj;

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'node*location*field_at_this_location*node*service*field_service_main_location';
  $cnr_obj->enabled = 1;
  $export['node*location*field_at_this_location*node*service*field_service_main_location'] = $cnr_obj;

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'node*location*field_at_this_location*node*service*field_service_other_location';
  $cnr_obj->enabled = 1;
  $export['node*location*field_at_this_location*node*service*field_service_other_location'] = $cnr_obj;

  return $export;
}
