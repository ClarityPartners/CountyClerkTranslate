<?php
/**
 * @file
 * level_3_menu_.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function level_3_menu__field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_docs|node|agency|default';
  $field_group->group_name = 'group_docs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'agency';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Docs',
    'weight' => '6',
    'children' => array(
      0 => 'field_agency_document',
      1 => 'field_agency_link',
      2 => 'field_agency_related',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Docs',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'docs field-group-div',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_group|node|agency|form';
  $field_group->group_name = 'group_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'agency';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '11',
    'children' => array(
      0 => 'group_landing',
      1 => 'group_non',
      2 => 'group_services',
      3 => 'group_rail',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-group field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_non|node|agency|form';
  $field_group->group_name = 'group_non';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'agency';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'non-Landing Page',
    'weight' => '11',
    'children' => array(
      0 => 'field_file_image',
      1 => 'group_location',
      2 => 'group_other',
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
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_other|node|agency|form';
  $field_group->group_name = 'group_other';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'agency';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_non';
  $field_group->data = array(
    'label' => 'Other Information',
    'weight' => '11',
    'children' => array(
      0 => 'field_agency_document',
      1 => 'field_agency_link',
      2 => 'field_agency_related',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rail|node|agency|form';
  $field_group->group_name = 'group_rail';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'agency';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Rail Items',
    'weight' => '12',
    'children' => array(
      0 => 'field_rail_item_s_',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-rail field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rail|node|service|form';
  $field_group->group_name = 'group_rail';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'service';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tab';
  $field_group->data = array(
    'label' => 'Rail Items',
    'weight' => '11',
    'children' => array(
      0 => 'field_rail_item_s_',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-rail field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Docs');
  t('Group');
  t('Other Information');
  t('Rail Items');
  t('non-Landing Page');

  return $field_groups;
}
