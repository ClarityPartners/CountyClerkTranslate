<?php
/**
 * @file
 * agency_content_type.default_cer_presets.inc
 */

/**
 * Implements hook_default_cer().
 */
function agency_content_type_default_cer() {
  $export = array();

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'node*agency*field_agency_main_location*node*location*field_at_this_location';
  $cnr_obj->enabled = 1;
  $export['node*agency*field_agency_main_location*node*location*field_at_this_location'] = $cnr_obj;

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'node*agency*field_agency_other_locations*node*location*field_at_this_location';
  $cnr_obj->enabled = 1;
  $export['node*agency*field_agency_other_locations*node*location*field_at_this_location'] = $cnr_obj;

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'node*agency*field_agency_parent*node*agency*field_agency_parent';
  $cnr_obj->enabled = 0;
  $export['node*agency*field_agency_parent*node*agency*field_agency_parent'] = $cnr_obj;

  return $export;
}
