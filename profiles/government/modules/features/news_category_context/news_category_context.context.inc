<?php
/**
 * @file
 * news_category_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function news_category_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news_category';
  $context->description = '';
  $context->tag = 'landing pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news-category/*' => 'news-category/*',
        'news-categories/*' => 'news-categories/*',
        'news-types/*' => 'news-types/*',
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
          'weight' => '-10',
        ),
        'views-news_categories_menu-block' => array(
          'module' => 'views',
          'delta' => 'news_categories_menu-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'gov_news_archive-news_archive_sidebar_block' => array(
          'module' => 'gov_news_archive',
          'delta' => 'news_archive_sidebar_block',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
    'region' => array(
      'adminimal' => array(
        'disable' => array(
          'hidden' => 0,
          'content_before' => 0,
          'sidebar_left' => 0,
          'content' => 0,
          'sidebar_right' => 0,
          'content_after' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
        ),
      ),
      'county_clerk_bootstrap' => array(
        'disable' => array(
          'navigation' => 0,
          'header' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'upper_footer' => 0,
          'footer' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'news-category',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('landing pages');
  $export['news_category'] = $context;

  return $export;
}
