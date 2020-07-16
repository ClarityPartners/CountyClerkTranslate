<?php
/**
 * @file
 * news_sidebar_.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function news_sidebar__context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news_sidebar';
  $context->description = 'events sidebar';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news' => 'news',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-news_categories_menu-block_1' => array(
          'module' => 'views',
          'delta' => 'news_categories_menu-block_1',
          'region' => 'sidebar_second',
          'weight' => '-30',
        ),
        'views-news_categories_menu-block' => array(
          'module' => 'views',
          'delta' => 'news_categories_menu-block',
          'region' => 'sidebar_second',
          'weight' => '-29',
        ),
        'gov_news_archive-news_archive_sidebar_block' => array(
          'module' => 'gov_news_archive',
          'delta' => 'news_archive_sidebar_block',
          'region' => 'sidebar_second',
          'weight' => '-28',
        ),
        'views-date_document_block-news_block' => array(
          'module' => 'views',
          'delta' => 'date_document_block-news_block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('events sidebar');
  $export['news_sidebar'] = $context;

  return $export;
}
