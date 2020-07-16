$context = new stdClass();
$context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'testing_map';
$context->description = '';
$context->tag = 'testing';
$context->conditions = array(
  'node' => array(
    'values' => array(
      'location' => 'location',
    ),
    'options' => array(
      'node_form' => '1',
    ),
  ),
);
$context->reactions = array(
  'block' => array(
    'blocks' => array(
      'views-map-block' => array(
        'module' => 'views',
        'delta' => 'map-block',
        'region' => 'sidebar_second',
        'weight' => '-10',
      ),
    ),
  ),
);
$context->condition_mode = 0;

// Translatables
// Included for use with string extractors like potx.
t('testing');
