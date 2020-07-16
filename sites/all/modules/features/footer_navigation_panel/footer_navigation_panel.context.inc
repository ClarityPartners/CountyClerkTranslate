<?php
/**
 * @file
 * footer_navigation_panel.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function footer_navigation_panel_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'navigation';
  $context->description = 'navigation';
  $context->tag = 'global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'panels_mini-footer_navigation' => array(
          'module' => 'panels_mini',
          'delta' => 'footer_navigation',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('global');
  t('navigation');
  $export['navigation'] = $context;

  return $export;
}
