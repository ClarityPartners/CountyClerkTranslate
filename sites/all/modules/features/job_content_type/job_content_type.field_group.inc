<?php
/**
 * @file
 * job_content_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function job_content_type_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location_title|node|jobs|default';
  $field_group->group_name = 'group_location_title';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'jobs';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '1',
    'children' => array(
      0 => 'field_title',
      1 => 'field_date_and_time',
      2 => 'field_location_address',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Location',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'job-location',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Location');

  return $field_groups;
}
