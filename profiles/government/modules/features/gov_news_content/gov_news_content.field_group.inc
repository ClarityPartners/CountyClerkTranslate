<?php
/**
 * @file
 * gov_news_content.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function gov_news_content_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_docs|node|news|default';
  $field_group->group_name = 'group_docs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Docs',
    'weight' => '3',
    'children' => array(
      0 => 'field_categories',
      1 => 'field_news_documents',
      2 => 'field_news_gov_references',
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
  $field_groups['group_docs|node|news|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Docs');

  return $field_groups;
}
