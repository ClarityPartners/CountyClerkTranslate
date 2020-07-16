<?php
/**
 * @file
 * banner_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function banner_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function banner_content_type_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function banner_content_type_image_default_styles() {
  $styles = array();

  // Exported image style: banner_horizontal_rail.
  $styles['banner_horizontal_rail'] = array(
    'label' => 'banner horizontal rail',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 262,
          'height' => 196,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_internal.
  $styles['banner_internal'] = array(
    'label' => 'banner internal',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 385,
          'height' => 290,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_internal_vertical.
  $styles['banner_internal_vertical'] = array(
    'label' => 'banner internal vertical',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 262,
          'height' => 393,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_vertical.
  $styles['banner_vertical'] = array(
    'label' => 'banner vertical',
    'effects' => array(
      10 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 465,
          'upscale' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: banners.
  $styles['banners'] = array(
    'label' => 'Banners',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 358,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: home_banners.
  $styles['home_banners'] = array(
    'label' => 'Home Banners',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 850,
          'height' => 635,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function banner_content_type_node_info() {
  $items = array(
    'banner' => array(
      'name' => t('Banner'),
      'base' => 'node_content',
      'description' => t('Holds highlighted content that will be displayed in a highlighted region.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
