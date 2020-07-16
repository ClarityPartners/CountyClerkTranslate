<?php
/**
 * @file
 * calendar_context_month.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function calendar_context_month_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'calendar_month';
  $context->description = 'Event calendar view';
  $context->tag = 'base';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'event_calendar:page_1' => 'event_calendar:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'blockify-blockify-page-title' => array(
          'module' => 'blockify',
          'delta' => 'blockify-page-title',
          'region' => 'hero',
          'weight' => '-10',
        ),
        'views-broadcast-broadcast' => array(
          'module' => 'views',
          'delta' => 'broadcast-broadcast',
          'region' => 'broadcast',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'main_prefix',
          'weight' => '-9',
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
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'bartik' => array(
        'disable' => array(
          'header' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'highlighted' => 0,
          'featured' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'triptych_first' => 0,
          'triptych_middle' => 0,
          'triptych_last' => 0,
          'footer_firstcolumn' => 0,
          'footer_secondcolumn' => 0,
          'footer_thirdcolumn' => 0,
          'footer_fourthcolumn' => 0,
          'footer' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'clarity_aurora' => array(
        'disable' => array(
          'content' => 'content',
          'header' => 0,
          'navigation' => 0,
          'mega-menu-1' => 0,
          'mega-menu-2' => 0,
          'mega-menu-3' => 0,
          'mega-menu-4' => 0,
          'hero' => 0,
          'broadcast' => 0,
          'main_prefix' => 0,
          'col-1-3' => 0,
          'col-2-3' => 0,
          'col-3-3' => 0,
          'tray' => 0,
          'left_sidebar' => 0,
          'right_content' => 0,
          'left_content' => 0,
          'right_sidebar' => 0,
          'main_suffix' => 0,
          'footer-1' => 0,
          'footer-2' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'seven' => array(
        'disable' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'events-calendar',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Event calendar view');
  t('base');
  $export['calendar_month'] = $context;

  return $export;
}
