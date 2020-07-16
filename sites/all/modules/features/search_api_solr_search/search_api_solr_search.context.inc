<?php
/**
 * @file
 * search_api_solr_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function search_api_solr_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_page_context';
  $context->description = '';
  $context->tag = 'Specialty';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'primary_search_view:page' => 'primary_search_view:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-8sOFcyWzXHtaOxA9LUJs6MwaSVAOO4wk' => array(
          'module' => 'facetapi',
          'delta' => '8sOFcyWzXHtaOxA9LUJs6MwaSVAOO4wk',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'facetapi-25LCIcieISpv81iRb8Fg9H07eRafKRN4' => array(
          'module' => 'facetapi',
          'delta' => '25LCIcieISpv81iRb8Fg9H07eRafKRN4',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'facetapi-D9EH6koWCWOBS5MFomoi1m0vy8Qlua2K' => array(
          'module' => 'facetapi',
          'delta' => 'D9EH6koWCWOBS5MFomoi1m0vy8Qlua2K',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'facetapi-j0J5jqFhIE9lffwxE7BOtkKJmcUbWTfR' => array(
          'module' => 'facetapi',
          'delta' => 'j0J5jqFhIE9lffwxE7BOtkKJmcUbWTfR',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'facetapi-mKaFxD6c3xC84VkFwS80HofRvgK7WvzY' => array(
          'module' => 'facetapi',
          'delta' => 'mKaFxD6c3xC84VkFwS80HofRvgK7WvzY',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'facetapi-PGy660pXAClf4XlPH1AgEFsdixfqOSk9' => array(
          'module' => 'facetapi',
          'delta' => 'PGy660pXAClf4XlPH1AgEFsdixfqOSk9',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'facetapi-7Y2IiT6i0eEIVvMqU6ETf4NZt9K21wak' => array(
          'module' => 'facetapi',
          'delta' => '7Y2IiT6i0eEIVvMqU6ETf4NZt9K21wak',
          'region' => 'sidebar_second',
          'weight' => '-4',
        ),
        'facetapi-oP92PdBQh1ZtVHGtaqdoH4LUmdeRIZP8' => array(
          'module' => 'facetapi',
          'delta' => 'oP92PdBQh1ZtVHGtaqdoH4LUmdeRIZP8',
          'region' => 'sidebar_second',
          'weight' => '-3',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Specialty');
  $export['search_page_context'] = $context;

  return $export;
}
