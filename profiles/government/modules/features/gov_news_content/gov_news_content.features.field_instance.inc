<?php
/**
 * @file
 * gov_news_content.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function gov_news_content_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-news-field_teaser_image'.
  $field_instances['node-news-field_teaser_image'] = array(
    'bundle' => 'news',
    'deleted' => 0,
    'description' => 'This image will appear on the news listing page next to the summary/teaser for the story.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'search_index' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_teaser_image',
    'label' => 'Teaser image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 386,
      'file_directory' => 'news_images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '300x300',
      'min_resolution' => '50x50',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'imce_filefield_on' => 0,
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Teaser image');
  t('This image will appear on the news listing page next to the summary/teaser for the story.');

  return $field_instances;
}
