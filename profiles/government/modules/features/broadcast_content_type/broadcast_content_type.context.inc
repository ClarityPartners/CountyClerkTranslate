<?php
/**
 * @file
 * broadcast_content_type.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function broadcast_content_type_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'broadcast_block';
  $context->description = 'broadcast dynamic block';
  $context->tag = 'global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-broadcast-block' => array(
          'module' => 'views',
          'delta' => 'broadcast-block',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('broadcast dynamic block');
  t('global');
  $export['broadcast_block'] = $context;

  return $export;
}
