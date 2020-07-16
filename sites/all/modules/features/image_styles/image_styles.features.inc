<?php
/**
 * @file
 * image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: 190x190.
  $styles['190x190'] = array(
    'label' => '190x190',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 195,
          'height' => 195,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: events_featured.
  $styles['events_featured'] = array(
    'label' => 'events featured',
    'effects' => array(
      5 => NULL,
    ),
  );

  // Exported image style: hero_image.
  $styles['hero_image'] = array(
    'label' => 'hero image',
    'effects' => array(
      4 => NULL,
    ),
  );

  return $styles;
}
