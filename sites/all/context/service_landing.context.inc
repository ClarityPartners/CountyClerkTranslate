$context = new stdClass();
$context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'service_landing';
$context->description = 'Service landing pages, Agency';
$context->tag = 'content type';
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
      136 => 136,
    ),
    'options' => array(
      'node_form' => '1',
    ),
  ),
  'path' => array(
    'values' => array(
      'content/*' => 'content/*',
      '~node/7/*' => '~node/7/*',
    ),
  ),
);
$context->reactions = array(
  'block' => array(
    'blocks' => array(
      'views-services-block' => array(
        'module' => 'views',
        'delta' => 'services-block',
        'region' => 'content',
        'weight' => '-10',
      ),
      'views-news_homepage-whats_new' => array(
        'module' => 'views',
        'delta' => 'news_homepage-whats_new',
        'region' => 'content',
        'weight' => '-8',
      ),
    ),
  ),
);
$context->condition_mode = 1;

// Translatables
// Included for use with string extractors like potx.
t('Service landing pages, Agency');
t('content type');
