$context = new stdClass();
$context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'vita_records';
$context->description = 'vital records specific blocks';
$context->tag = 'Specialty';
$context->conditions = array(
  'path' => array(
    'values' => array(
      'content/vital-records' => 'content/vital-records',
    ),
  ),
);
$context->reactions = array(
  'block' => array(
    'blocks' => array(
      'views-news_homepage-whats_new' => array(
        'module' => 'views',
        'delta' => 'news_homepage-whats_new',
        'region' => 'content',
        'weight' => '-10',
      ),
    ),
  ),
);
$context->condition_mode = 0;

// Translatables
// Included for use with string extractors like potx.
t('Specialty');
t('vital records specific blocks');
