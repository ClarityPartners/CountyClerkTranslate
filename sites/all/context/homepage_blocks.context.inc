$context = new stdClass();
$context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'homepage_blocks';
$context->description = 'homepage blocks';
$context->tag = 'Homepage';
$context->conditions = array(
  'path' => array(
    'values' => array(
      '<front>' => '<front>',
    ),
  ),
);
$context->reactions = array(
  'block' => array(
    'blocks' => array(
      'panels_mini-homepage_departments' => array(
        'module' => 'panels_mini',
        'delta' => 'homepage_departments',
        'region' => 'content',
        'weight' => '-20',
      ),
      'views-banners-block' => array(
        'module' => 'views',
        'delta' => 'banners-block',
        'region' => 'content',
        'weight' => '-19',
      ),
      'bean-whats-new-cookcountyclerk' => array(
        'module' => 'bean',
        'delta' => 'whats-new-cookcountyclerk',
        'region' => 'content',
        'weight' => '-18',
      ),
      'bean-homepage-video' => array(
        'module' => 'bean',
        'delta' => 'homepage-video',
        'region' => 'content',
        'weight' => '-17',
      ),
      'bean-meet-the-clerk' => array(
        'module' => 'bean',
        'delta' => 'meet-the-clerk',
        'region' => 'content',
        'weight' => '-16',
      ),
    ),
  ),
);
$context->condition_mode = 0;

// Translatables
// Included for use with string extractors like potx.
t('Homepage');
t('homepage blocks');
