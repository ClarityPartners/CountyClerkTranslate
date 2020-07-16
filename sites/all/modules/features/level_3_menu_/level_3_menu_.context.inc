<?php
/**
 * @file
 * level_3_menu_.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function level_3_menu__context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'banners_level3';
  $context->description = 'level 3 page banners';
  $context->tag = 'content types';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'location' => 'location',
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
        'views-banners-block_2' => array(
          'module' => 'views',
          'delta' => 'banners-block_2',
          'region' => 'upper_footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('content types');
  t('level 3 page banners');
  $export['banners_level3'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'banners_level3_agency';
  $context->description = 'level 3 agency page banners';
  $context->tag = 'content types';
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
        125 => 125,
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-banners-block_2' => array(
          'module' => 'views',
          'delta' => 'banners-block_2',
          'region' => 'upper_footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('content types');
  t('level 3 agency page banners');
  $export['banners_level3_agency'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'banners_level3_vertical';
  $context->description = 'level 3 service vertical';
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
        'views-banners-block_4' => array(
          'module' => 'views',
          'delta' => 'banners-block_4',
          'region' => 'sidebar_second',
          'weight' => '20',
        ),
        'views-banners-block_3' => array(
          'module' => 'views',
          'delta' => 'banners-block_3',
          'region' => 'sidebar_second',
          'weight' => '25',
        ),
        'views-banners-block_5' => array(
          'module' => 'views',
          'delta' => 'banners-block_5',
          'region' => 'sidebar_second',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('content types');
  t('level 3 service vertical');
  $export['banners_level3_vertical'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'submenu_agency';
  $context->description = 'Service page submenu ';
  $context->tag = 'Menu';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'agency' => 'agency',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-level_3_menu-block_4' => array(
          'module' => 'views',
          'delta' => 'level_3_menu-block_4',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-date_document_block-block_2' => array(
          'module' => 'views',
          'delta' => 'date_document_block-block_2',
          'region' => 'sidebar_second',
          'weight' => '-7',
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
      'bootstrap' => array(
        'disable' => array(
          'navigation' => 0,
          'header' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'footer' => 0,
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
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Menu');
  t('Service page submenu ');
  $export['submenu_agency'] = $context;

  return $export;
}
