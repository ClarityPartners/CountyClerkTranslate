<?php
/**
 * @file
 * submenu_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function submenu_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'service_sidebar';
  $context->description = 'service node location sidebar';
  $context->tag = 'Menu';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'service' => 'service',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-level_3_menu-block_5' => array(
          'module' => 'views',
          'delta' => 'level_3_menu-block_5',
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
  t('Menu');
  t('service node location sidebar');
  $export['service_sidebar'] = $context;

  return $export;
}
