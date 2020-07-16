<?php
/**
 * @file
 * footer_navigation_panel.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function footer_navigation_panel_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'footer_navigation';
  $mini->category = 'footer';
  $mini->admin_title = 'footer navigation';
  $mini->admin_description = '';
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
          1 => 1,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'logo_',
          1 => 'logo',
          2 => 'center',
          3 => 'other_links',
        ),
        'parent' => 'main',
        'class' => 'upper-footer',
        'hide_empty' => 0,
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 25,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'about-pane',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'lower',
          1 => 'lower_footer_menu',
        ),
        'parent' => 'main',
        'class' => 'lower-footer',
        'hide_empty' => 0,
      ),
      'lower' => array(
        'type' => 'region',
        'title' => 'lower-pane',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'lower-pane',
        'hide_empty' => 0,
      ),
      'logo' => array(
        'type' => 'region',
        'title' => 'Cook County Clerk\'s Office',
        'width' => 25,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'office-pane',
        'hide_empty' => 0,
      ),
      'other_links' => array(
        'type' => 'region',
        'title' => 'other links',
        'width' => 25,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'other-pane',
        'hide_empty' => 0,
      ),
      'logo_' => array(
        'type' => 'region',
        'title' => 'logo',
        'width' => 25,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'logo-pane',
        'hide_empty' => 0,
      ),
      'lower_footer_menu' => array(
        'type' => 'region',
        'title' => 'lower-footer-menu',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'menu-pane translate',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'lower' => NULL,
      'logo' => NULL,
      'other_links' => NULL,
      'logo_' => NULL,
      'lower_footer_menu' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '57f4ec0f-85b4-4c95-a74c-d150b7a420c3';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'footer_navigation';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6a206273-4060-49d5-bb3f-a3a28daa83ec';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-about';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'About',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '6a206273-4060-49d5-bb3f-a3a28daa83ec';
  $display->content['new-6a206273-4060-49d5-bb3f-a3a28daa83ec'] = $pane;
  $display->panels['center'][0] = 'new-6a206273-4060-49d5-bb3f-a3a28daa83ec';
  $pane = new stdClass();
  $pane->pid = 'new-7d4582f2-3f57-4ff3-ada4-b05be1b0b93c';
  $pane->panel = 'logo';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Cook County Clerk\'s Office',
    'title_heading' => 'h2',
    'body' => '<p>Karen A. Yarbrough, Cook County Clerk<br />
69 W. Washington Street, Suite 500<br />
Chicago, IL 60602</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7d4582f2-3f57-4ff3-ada4-b05be1b0b93c';
  $display->content['new-7d4582f2-3f57-4ff3-ada4-b05be1b0b93c'] = $pane;
  $display->panels['logo'][0] = 'new-7d4582f2-3f57-4ff3-ada4-b05be1b0b93c';
  $pane = new stdClass();
  $pane->pid = 'new-3df30bec-93ca-4324-bae7-a7d8ac00d425';
  $pane->panel = 'logo';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-social-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Follow Us',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'social-pane',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3df30bec-93ca-4324-bae7-a7d8ac00d425';
  $display->content['new-3df30bec-93ca-4324-bae7-a7d8ac00d425'] = $pane;
  $display->panels['logo'][1] = 'new-3df30bec-93ca-4324-bae7-a7d8ac00d425';
  $pane = new stdClass();
  $pane->pid = 'new-ba8f0169-6c0e-425d-93e7-54927189f8a1';
  $pane->panel = 'logo_';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array(
    'logic' => 'and',
  );
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p>[[{"fid":"2","view_mode":"default","fields":{"format":"default","alignment":"","field_file_image_alt_text[und][0][value]":false,"field_file_image_title_text[und][0][value]":false},"type":"media","field_deltas":{"1":{"format":"default","alignment":"","field_file_image_alt_text[und][0][value]":false,"field_file_image_title_text[und][0][value]":false}},"attributes":{"height":"138","width":"139","class":"media-element file-default","data-delta":"1"}}]]</p>',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ba8f0169-6c0e-425d-93e7-54927189f8a1';
  $display->content['new-ba8f0169-6c0e-425d-93e7-54927189f8a1'] = $pane;
  $display->panels['logo_'][0] = 'new-ba8f0169-6c0e-425d-93e7-54927189f8a1';
  $pane = new stdClass();
  $pane->pid = 'new-3d6bd33a-9a63-453c-93cc-50657ac78184';
  $pane->panel = 'logo_';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p>[[{"fid":"8","view_mode":"default","fields":{"format":"default","alignment":"","field_file_image_alt_text[und][0][value]":false,"field_file_image_title_text[und][0][value]":false},"type":"media","field_deltas":{"1":{"format":"default","alignment":"","field_file_image_alt_text[und][0][value]":false,"field_file_image_title_text[und][0][value]":false}},"attributes":{"class":"media-element file-default","data-delta":"1"}}]]</p>',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3d6bd33a-9a63-453c-93cc-50657ac78184';
  $display->content['new-3d6bd33a-9a63-453c-93cc-50657ac78184'] = $pane;
  $display->panels['logo_'][1] = 'new-3d6bd33a-9a63-453c-93cc-50657ac78184';
  $pane = new stdClass();
  $pane->pid = 'new-24745e8b-211d-4f57-8f1a-9144f8c22cd4';
  $pane->panel = 'lower';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p>© Copyright 2016 Cook County Clerk\'s Office. All Rights Reserved.</p>',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
    'template_suggestion' => 'custom-copy',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '24745e8b-211d-4f57-8f1a-9144f8c22cd4';
  $display->content['new-24745e8b-211d-4f57-8f1a-9144f8c22cd4'] = $pane;
  $display->panels['lower'][0] = 'new-24745e8b-211d-4f57-8f1a-9144f8c22cd4';
  $pane = new stdClass();
  $pane->pid = 'new-71048d41-4f02-4749-baf9-674cfe57e6ba';
  $pane->panel = 'lower_footer_menu';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-footer-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '71048d41-4f02-4749-baf9-674cfe57e6ba';
  $display->content['new-71048d41-4f02-4749-baf9-674cfe57e6ba'] = $pane;
  $display->panels['lower_footer_menu'][0] = 'new-71048d41-4f02-4749-baf9-674cfe57e6ba';
  $pane = new stdClass();
  $pane->pid = 'new-ebedf971-a0d5-45d1-9279-65f7beaba7ae';
  $pane->panel = 'lower_footer_menu';
  $pane->type = 'block';
  $pane->subtype = 'gtranslate-gtranslate';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'g-translate',
    'template_suggestion' => 'block',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ebedf971-a0d5-45d1-9279-65f7beaba7ae';
  $display->content['new-ebedf971-a0d5-45d1-9279-65f7beaba7ae'] = $pane;
  $display->panels['lower_footer_menu'][1] = 'new-ebedf971-a0d5-45d1-9279-65f7beaba7ae';
  $pane = new stdClass();
  $pane->pid = 'new-352cdb1d-cc8e-43dd-847f-cdbcddd895f2';
  $pane->panel = 'lower_footer_menu';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p>Google Translate</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'g-translate-text',
    'template_suggestion' => 'custom',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '352cdb1d-cc8e-43dd-847f-cdbcddd895f2';
  $display->content['new-352cdb1d-cc8e-43dd-847f-cdbcddd895f2'] = $pane;
  $display->panels['lower_footer_menu'][2] = 'new-352cdb1d-cc8e-43dd-847f-cdbcddd895f2';
  $pane = new stdClass();
  $pane->pid = 'new-cd2381c9-3307-43e2-9d8d-9b2cd056a609';
  $pane->panel = 'other_links';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-other-links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Other Government Links',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'cd2381c9-3307-43e2-9d8d-9b2cd056a609';
  $display->content['new-cd2381c9-3307-43e2-9d8d-9b2cd056a609'] = $pane;
  $display->panels['other_links'][0] = 'new-cd2381c9-3307-43e2-9d8d-9b2cd056a609';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['footer_navigation'] = $mini;

  return $export;
}
