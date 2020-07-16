<?php
/**
 * @file
 * contact_us_context.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function contact_us_context_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Contact info sidebar block for Contact Us page';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'contact_us_contact_info';
  $fe_block_boxes->body = '<p>For non-emergencies and general inquiries about the County, please use the information below.</p><ul class="fa-ul"><li><span class="fa-li fa fa-compass fa-3x">&zwnj;</span><span class="fa-li-text">118 N. Clark Street<br />Chicago, IL 60602</span></li><li><span class="fa-li fa fa-phone fa-3x">&zwnj;</span><span class="fa-li-text">(312) 443-5500</span></li><li><span class="fa-li fa fa-clock-o fa-3x">&zwnj;</span><span class="fa-li-text">8am - 5pm CST Mon-Fri</span></li><li><span class="fa-li fa fa-envelope fa-3x">&zwnj;</span><span class="fa-li-text">webmaster@cookcountyil.gov</span></li></ul>';

  $export['contact_us_contact_info'] = $fe_block_boxes;

  return $export;
}
