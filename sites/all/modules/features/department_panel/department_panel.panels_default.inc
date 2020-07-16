<?php
/**
 * @file
 * department_panel.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function department_panel_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'homepage_departments';
  $mini->category = '';
  $mini->admin_title = 'homepage departments';
  $mini->admin_description = 'home page department and jump menu blocks';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'department-section',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c4191ea4-ec2b-4bee-8779-cc97c893edbc';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'homepage_departments';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0df29086-0561-42d2-be11-6bff7a5685f8';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'views-departments-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'departments-pane',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0df29086-0561-42d2-be11-6bff7a5685f8';
  $display->content['new-0df29086-0561-42d2-be11-6bff7a5685f8'] = $pane;
  $display->panels['center'][0] = 'new-0df29086-0561-42d2-be11-6bff7a5685f8';
  $pane = new stdClass();
  $pane->pid = 'new-020f4783-4ca2-4c50-8a09-f6cb0dc39601';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'views-homepage_jump-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'jump-pane',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '020f4783-4ca2-4c50-8a09-f6cb0dc39601';
  $display->content['new-020f4783-4ca2-4c50-8a09-f6cb0dc39601'] = $pane;
  $display->panels['center'][1] = 'new-020f4783-4ca2-4c50-8a09-f6cb0dc39601';
  $pane = new stdClass();
  $pane->pid = 'new-ae5011ab-95f3-4b05-84ea-ca79565abd0e';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'views--exp-primary_search_view-page_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'ae5011ab-95f3-4b05-84ea-ca79565abd0e';
  $display->content['new-ae5011ab-95f3-4b05-84ea-ca79565abd0e'] = $pane;
  $display->panels['center'][2] = 'new-ae5011ab-95f3-4b05-84ea-ca79565abd0e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0df29086-0561-42d2-be11-6bff7a5685f8';
  $mini->display = $display;
  $export['homepage_departments'] = $mini;

  return $export;
}
