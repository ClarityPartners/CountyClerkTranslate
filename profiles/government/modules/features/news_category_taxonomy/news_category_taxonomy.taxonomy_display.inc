<?php
/**
 * @file
 * news_category_taxonomy.taxonomy_display.inc
 */

/**
 * Implements hook_taxonomy_display_default_displays().
 */
function news_category_taxonomy_taxonomy_display_default_displays() {
  $export = array();

  $taxonomy_display = new stdClass();
  $taxonomy_display->api_version = 1;
  $taxonomy_display->machine_name = 'news_category';
  $taxonomy_display->term_display_plugin = 'TaxonomyDisplayTermDisplayHandlerCore';
  $taxonomy_display->term_display_options = '';
  $taxonomy_display->associated_display_plugin = 'TaxonomyDisplayAssociatedDisplayHandlerCore';
  $taxonomy_display->associated_display_options = array(
    'associated_per_page' => '10',
    'empty_text' => 'There is currently no content classified with this term.',
  );
  $taxonomy_display->add_feed = TRUE;
  $taxonomy_display->breadcrumb_display_plugin = 'TaxonomyDisplayBreadcrumbDisplayHandlerCore';
  $taxonomy_display->breadcrumb_display_options = '';
  $export['news_category'] = $taxonomy_display;

  return $export;
}
