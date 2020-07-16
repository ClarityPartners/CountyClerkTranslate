<?php
/**
 * @file
 * publication_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function publication_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function publication_content_type_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function publication_content_type_image_default_styles() {
  $styles = array();

  // Exported image style: publication_large.
  $styles['publication_large'] = array(
    'label' => 'publication_large',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 231,
          'height' => 300,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: publication_medium.
  $styles['publication_medium'] = array(
    'label' => 'publication_medium',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 154,
          'height' => 200,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: publication_small.
  $styles['publication_small'] = array(
    'label' => 'publication_small',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 118,
          'height' => 150,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function publication_content_type_node_info() {
  $items = array(
    'publication' => array(
      'name' => t('Publication'),
      'base' => 'node_content',
      'description' => t('A PDF document that is available for download.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
