<?php
/**
 * @file
 * bean_types.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function bean_types_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'events_and_twitter';
  $bean_type->label = 'Events and twitter';
  $bean_type->options = '';
  $bean_type->description = 'block to contain twitter and events on homepage. ';
  $export['events_and_twitter'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'hero';
  $bean_type->label = 'Hero';
  $bean_type->options = '';
  $bean_type->description = 'Hero block for landing view pages. ';
  $export['hero'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'image';
  $bean_type->label = 'Image';
  $bean_type->options = '';
  $bean_type->description = 'Image w/text ';
  $export['image'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'video';
  $bean_type->label = 'video';
  $bean_type->options = '';
  $bean_type->description = 'video blocks with text. ';
  $export['video'] = $bean_type;

  return $export;
}
