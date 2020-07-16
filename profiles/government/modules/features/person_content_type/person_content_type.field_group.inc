<?php
/**
 * @file
 * person_content_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function person_content_type_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_person_contact_info|node|person|form';
  $field_group->group_name = 'group_person_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '10',
    'children' => array(
      0 => 'field_person_office_location',
      1 => 'field_person_alt_address',
      2 => 'field_person_alt_phone',
      3 => 'field_person_alt_fax',
      4 => 'field_person_alt_email',
      5 => 'field_person_phone',
      6 => 'field_person_fax',
      7 => 'field_person_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contact Information',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-person-contact-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact Information');

  return $field_groups;
}
