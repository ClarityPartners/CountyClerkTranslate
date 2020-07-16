$context = new stdClass();
$context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
$context->api_version = 3;
$context->name = 'submenu_agency';
$context->description = 'Service page submenu ';
$context->tag = 'Menu';
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
);
$context->reactions = array(
  'block' => array(
    'blocks' => array(
      'views-level_3_menu-block_4' => array(
        'module' => 'views',
        'delta' => 'level_3_menu-block_4',
        'region' => 'sidebar_second',
        'weight' => '-8',
      ),
      'views-banners-block_1' => array(
        'module' => 'views',
        'delta' => 'banners-block_1',
        'region' => 'upper_footer',
        'weight' => '-10',
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
      ),
    ),
    'county_clerk_bootstrap' => array(
      'disable' => array(
        'navigation' => 0,
        'header' => 0,
        'highlighted' => 0,
        'help' => 0,
        'content' => 0,
        'sidebar_first' => 0,
        'sidebar_second' => 0,
        'upper_footer' => 0,
        'footer' => 0,
        'page_top' => 0,
        'page_bottom' => 0,
      ),
    ),
  ),
);
$context->condition_mode = 1;

// Translatables
// Included for use with string extractors like potx.
t('Menu');
t('Service page submenu ');
