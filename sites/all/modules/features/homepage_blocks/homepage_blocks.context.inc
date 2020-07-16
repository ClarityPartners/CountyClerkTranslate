<?php
/**
 * @file
 * homepage_blocks.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function homepage_blocks_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage_blocks';
  $context->description = 'homepage blocks';
  $context->tag = 'Homepage';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'panels_mini-homepage_departments' => array(
          'module' => 'panels_mini',
          'delta' => 'homepage_departments',
          'region' => 'content',
          'weight' => '0',
        ),
        'views-banners-block' => array(
          'module' => 'views',
          'delta' => 'banners-block',
          'region' => 'content',
          'weight' => '1',
        ),
        'bean-whats-new-cookcountyclerk' => array(
          'module' => 'bean',
          'delta' => 'whats-new-cookcountyclerk',
          'region' => 'content',
          'weight' => '2',
        ),
        'bean-meet-the-clerk' => array(
          'module' => 'bean',
          'delta' => 'meet-the-clerk',
          'region' => 'content',
          'weight' => '4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Homepage');
  t('homepage blocks');
  $export['homepage_blocks'] = $context;

  return $export;
}
