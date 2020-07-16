<?php
/**
 * @file
 * program_content_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function program_content_type_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_program_location|node|program|form';
  $field_group->group_name = 'group_program_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '5',
    'children' => array(
      0 => 'field_program_main_location',
      1 => 'field_program_other_location',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Location',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-program-location field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_program_location|node|program|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Location');

  return $field_groups;
}
