<?php
/**
 * @file
 * The primary PHP file for this theme.
 */
function county_clerk_bootstrap_preprocess_paragraphs_items(&$vars) {
  $par = $vars['element'];
}

//adding div variables to style certain pages diff
function county_clerk_bootstrap_preprocess_page(&$vars, $hook) {
  //$media_library = views_get_page_view('media_room');
  $vars['container_fixed'] = 'container';
  $vars['page_body'] = 'body-class';

  //because of agency having two layouts and use of sidebar being sporadic custom classes have to
  //change a few times to keep the site consistent.
  if (isset($vars['node']) && ($vars['node']->type == 'agency')) {
    $items = field_get_items('node', $vars['node'], 'field_agency_display');
    $vars['landing'] = $items[0]['entity']->name == 'Landing Page';

    if (isset($vars['node']->field_agency_display) && $items[0]['entity']->name == 'Landing Page') {
      $vars['title'] = FALSE; //remove title for landing pages only
      $vars['content_column_class'] = 'col-sm-12';
      $vars['container_fixed'] = 'container-fluid';
      $vars['page_body'] = 'body-class-landing';
    }
    else {
      $vars['class_name'] = 'agency-title';
      $vars['page_body'] = 'body-class';
      $vars['container_fixed'] = 'container';
      $vars['content_column_class'] = 'class="col-sm-9 section-padding"';
    }
  }
  else {
    if (isset($vars['node']) && !drupal_is_front_page() && $vars['node']->type == 'service') {
      $vars['content_column_class'] = 'class="col-sm-9 section-padding"';
    }
    else {
      if (!drupal_is_front_page()) {
        $vars['content_column_class'] = 'class="col-sm-12 section-padding"';
      }
    }
  }

  $views_page = views_get_page_view();
  if (is_object($views_page) || drupal_is_front_page()) {
    // We are on views page
    $vars['container_fixed'] = 'container_fluid view';
    $vars['page_body'] = 'body-class';
    if (is_object($views_page) && $views_page->name == 'primary_search_view') {
      $vars['content_column_class'] = 'class="col-sm-9"';
      $vars['container_fixed'] = 'container view-search';
    }
  }

  //main menu variable to pull into page.tpl.php
  $main_menu_tree = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
  $vars['main_menu'] = $main_menu_tree;

  if ($node = menu_get_object()) {
    // Get the nid
    $nid = $node->nid;
    //never repeat this horribleness
    //landing or non landing page in draft view
    if (isset($vars['page']['content']['system_main']['nodes'][$nid]['field_agency_description'])) {
      $displayName = $vars['page']['content']['system_main']['nodes'][$nid]['field_agency_description']['#object']->field_agency_display['und'][0]['entity']->name;

      if ($displayName == 'Landing Page') {
        $vars['title'] = FALSE; //remove title for landing pages only
        $vars['content_column_class'] = 'col-sm-12';
        $vars['container_fixed'] = 'container-fluid';
        $vars['page_body'] = 'body-class-landing';
        $vars['page']['sidebar_second'] = '';
      }
    }
  }

  // Show Other Search Block on homepage
  if(drupal_is_front_page() && $vars['node']->type == 'page' && $vars['node']->field_show_other_search_block['und'][0]['value']) {
    $vars['page_body'] .= ' show-search';
    //dpm($vars['node']->field_show_other_search_block);
  }
}

// To add CSS class to the main menu ul
function county_clerk_bootstrap_menu_tree__main_menu(&$vars) {
  return '<ul class="menu nav list-inline">' . $vars['tree'] . '</ul>';
}

//add bean type templates
function county_clerk_process_entity(&$vars) {
  if ($vars['entity_type'] == 'bean') {
    if ($vars['bean']->type == 'video') {
      //$vars['theme_hook_suggestions'][] = 'bean__' . $vars['bean']->type;
    }
  }
}

//agency page split template for landing pages
function county_clerk_bootstrap_preprocess_node(&$vars) {
  if (isset($vars['node']) && $vars['node']->type == 'agency') {
    if (isset($vars['field_agency_display'][0]) && $vars['field_agency_display'][0]['entity']->name == 'Landing Page') {
      $vars['theme_hook_suggestions'][] = 'node__agency__landing'; //overriding node agency template for just landing pages
    }
  }
  elseif ($vars['node']->type == 'location' && $vars['view_mode'] == 'full') {
    $vars['theme_hook_suggestions'][] = 'node__location__landing'; //template for default view mode only to keep from adding to other content types
  }
}

function county_clerk_bootstrap_preprocess_entity(&$vars) {
  if ($vars['elements']['#entity_type'] == 'field_collection_item' && $vars['elements']['#bundle'] == 'field_printable_results') {
    //dpm($vars);
  }
}

function county_clerk_bootstrap_preprocess_html(&$vars) {

  $element = [
    '#tag' => 'meta',
    '#attributes' => [
      'http-equiv' => 'X-UA-Compatible',
      'content' => 'IE=edge,chrome=1',
    ],
  ];
  drupal_add_html_head($element, 'http_equiv');

}

//add block class to entire block view instead of just inside. viewblock_topclass module
function county_clerk_bootstrap_preprocess_block(&$variables) {

  if ($variables['block']->module != 'facetapi') {
    $variables['title'] = '';
  }

  if ($variables['block']->module == 'views') {
    // First, try to get info about the view from contextual links - The contextual links module does not have to be on,
    // but 'Hide contextual links' must be set to 'no' (the default).  We try this method first because its usually
    // available and may save us some performance overhead if the view object is already present.
    if (isset($variables['elements']['#views_contextual_links_info']['views_ui']['view'])) {
      $view = $variables['elements']['#views_contextual_links_info']['views_ui']['view'];
      $display_id = $variables['elements']['#views_contextual_links_info']['views_ui']['view_display_id'];
    }
    // Next, try to extrapolate the view and display name from the delta (this is how views module does it) and load
    // the view
    else {
      // If the delta doesn't contain valid data return nothing.
      $explode = explode('-', $variables['block']->delta);
      if (count($explode) != 2) {
        return;
      }
      list($name, $display_id) = $explode;

      $view = views_get_view($name);
    }

    // If we got a view and a display name, we can get the classes from it and put them on our block
    if (!empty($view) && !empty($display_id)) {
      // Get the css string as defined by the user for this display
      if (isset($view->display[$display_id]->display_options['css_class'])) {
        // If the css class is set but is empty, return - the user doesn't want to use a class
        if (!empty($view->display[$display_id]->display_options['css_class'])) {
          $view_css_string = $view->display[$display_id]->display_options['css_class'];
        }
        else {
          return;
        }
      }
      // If there are no classes set for this display, check if this display is using the default (all displays) settings
      elseif (isset($view->display['default']) && !empty($view->display['default']->display_options['css_class'])) {
        $view_css_string = $view->display['default']->display_options['css_class'];
      }
      else {
        // There's no CSS class, we can't do anything
        return;
      }

      // There may be more than one class separated by a space, parse them out:
      $view_classes = explode(' ', $view_css_string);

      if (!empty($view_classes)) {
        // Add each class to the blocks top level container with the string '-container' concatenated
        foreach ($view_classes as $view_class) {
          // Strip whitespace and add the class if we have anything left
          $view_class = trim($view_class);
          if (!empty($view_class)) {
            $variables['classes_array'][] = $view_class . '-container';
          }
        }
      }
    }

  }
}

/**
 * Implementing hook_apachesolr_search_snippets__file
 * This function provides the output for
 * attachment search results for solr search.
 */

function county_clerk_bootstrap_apachesolr_search_snippets__file($vars) {
  $doc = $vars['doc'];
  $title = $vars['doc']->label;
  $url = $vars['doc']->url;
  $snippets = $vars['flattened_snippets'];
  $parent_entity_links = [];

  // Retrieve our parent entities. They have been saved as
  // a small serialized entity
  foreach ($doc->zm_parent_entity as $parent_entity_encoded) {
    $parent_decoded = (object) drupal_json_decode($parent_entity_encoded);

    // Extract entity id from parent. List fetches the first item from the array.
    list($id) = entity_extract_ids($parent_decoded->entity_type, $parent_decoded);

    // Load parent entity
    $load = entity_load($parent_decoded->entity_type, [$id]);
    $parent_entity = array_shift($load);

    $parent_entity_uri = entity_uri($parent_decoded->entity_type, $parent_entity);
    $parent_entity_uri['options']['absolute'] = TRUE;
    $parent_label = entity_label($parent_decoded->entity_type, $parent_entity);
    $parent_entity_links[] = l($parent_label, $parent_entity_uri['path'], $parent_entity_uri['options']);
  }

  if (module_exists('file')) {
    $file_type = t('!icon', ['!icon' => theme('file_icon', ['file' => (object) ['filemime' => $doc->ss_filemime]])]);
  }
  else {
    $file_type = t('@filemime', ['@filemime' => $doc->ss_filemime]);
  }
  return '<div><h3>' . $file_type . "  " . l($title, $url) . '</h3></div>' . implode(' ... ', $snippets) . '<div class="source">Source</div>' . implode(', ', $parent_entity_links);
}