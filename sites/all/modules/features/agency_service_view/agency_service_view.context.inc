<?php
/**
 * @file
 * agency_service_view.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function agency_service_view_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'service_landing';
  $context->description = 'Service landing pages, Agency';
  $context->tag = 'content type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'agency' => 'agency',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'node_taxonomy' => array(
      'values' => array(
        124 => 124,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '~node/*/edit' => '~node/*/edit',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-services-block' => array(
          'module' => 'views',
          'delta' => 'services-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-i_want_to_queues-block_6' => array(
          'module' => 'views',
          'delta' => 'i_want_to_queues-block_6',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-news_homepage-whats_new' => array(
          'module' => 'views',
          'delta' => 'news_homepage-whats_new',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-banners-block_1' => array(
          'module' => 'views',
          'delta' => 'banners-block_1',
          'region' => 'upper_footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Service landing pages, Agency');
  t('content type');
  $export['service_landing'] = $context;

  return $export;
}
