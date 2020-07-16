<?php
/**
 * @file
 * event_context_menu.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function event_context_menu_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_sidebar';
  $context->description = 'events sidebar';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-date_document_block-news_block' => array(
          'module' => 'views',
          'delta' => 'date_document_block-news_block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-date_document_block-block_1' => array(
          'module' => 'views',
          'delta' => 'date_document_block-block_1',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('events sidebar');
  $export['events_sidebar'] = $context;

  return $export;
}
