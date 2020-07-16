$context = new stdClass();
$context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'banners_level3';
$context->description = 'level 3 page banners';
$context->tag = 'content types';
$context->conditions = array(
  'node' => array(
    'values' => array(
      'agency' => 'agency',
      'event' => 'event',
      'location' => 'location',
      'news' => 'news',
      'service' => 'service',
    ),
    'options' => array(
      'node_form' => '1',
    ),
  ),
  'node_taxonomy' => array(
    'values' => array(
      136 => 136,
    ),
    'options' => array(
      'node_form' => '0',
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
$context->condition_mode = 0;

// Translatables
// Included for use with string extractors like potx.
t('content types');
t('level 3 page banners');
