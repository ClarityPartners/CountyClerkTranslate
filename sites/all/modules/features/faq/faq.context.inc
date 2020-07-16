<?php
/**
 * @file
 * faq.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function faq_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'service_page_faq';
  $context->description = 'service content type FAQ';
  $context->tag = 'content types';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'agency' => 'agency',
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
        'views-faq-block' => array(
          'module' => 'views',
          'delta' => 'faq-block',
          'region' => 'upper_footer',
          'weight' => '-11',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('content types');
  t('service content type FAQ');
  $export['service_page_faq'] = $context;

  return $export;
}
