<?php
/**
 * @file
 * search_results_page.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function search_results_page_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'solr_search_page';
  $context->description = 'This is the context for search results page';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/site/*' => 'search/site/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-nZyfBHmniLqoW1Rhu3PzKKZUAvhdx8f3' => array(
          'module' => 'facetapi',
          'delta' => 'nZyfBHmniLqoW1Rhu3PzKKZUAvhdx8f3',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'facetapi-VYXLBo74seLfMkhNmV4dL01fMYLmRL15' => array(
          'module' => 'facetapi',
          'delta' => 'VYXLBo74seLfMkhNmV4dL01fMYLmRL15',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'facetapi-GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu' => array(
          'module' => 'facetapi',
          'delta' => 'GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'facetapi-VDZ1zUxyel14eIH8QY1B1A4mPnt4fPk0' => array(
          'module' => 'facetapi',
          'delta' => 'VDZ1zUxyel14eIH8QY1B1A4mPnt4fPk0',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('This is the context for search results page');
  $export['solr_search_page'] = $context;

  return $export;
}
