<?php
/**
 * @file
 * media_room_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function media_room_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hero_media_room';
  $context->description = 'hero image for media library';
  $context->tag = 'Specialty';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'media-library-list' => 'media-library-list',
        'media-library-grid' => 'media-library-grid',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-media-room-hero' => array(
          'module' => 'bean',
          'delta' => 'media-room-hero',
          'region' => 'content',
          'weight' => '-39',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Specialty');
  t('hero image for media library');
  $export['hero_media_room'] = $context;

  return $export;
}
