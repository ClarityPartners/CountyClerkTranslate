<?php
/**
 * @file
 * government_body_content_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function government_body_content_type_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_govb_location|node|government_body|form';
  $field_group->group_name = 'group_govb_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'government_body';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Location Information',
    'weight' => '8',
    'children' => array(
      0 => 'field_govb_alt_email',
      1 => 'field_govb_alt_fax',
      2 => 'field_govb_alt_phone',
      3 => 'field_govb_office_location',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_govb_location|node|government_body|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_landing|node|government_body|form';
  $field_group->group_name = 'group_landing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'government_body';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Landing Page',
    'weight' => '7',
    'children' => array(
      0 => 'field_display_type',
      1 => 'field_background_image_',
      2 => 'field_i_want_to_queue',
      3 => 'field_body',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-landing field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_landing|node|government_body|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_members|node|government_body|form';
  $field_group->group_name = 'group_members';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'government_body';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Members',
    'weight' => '9',
    'children' => array(
      0 => 'field_govb_members',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-members field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_members|node|government_body|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|government_body|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'government_body';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '9',
    'children' => array(
      0 => 'group_govb_location',
      1 => 'group_landing',
      2 => 'group_members',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_tabs|node|government_body|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Landing Page');
  t('Location Information');
  t('Members');
  t('Tabs');

  return $field_groups;
}
