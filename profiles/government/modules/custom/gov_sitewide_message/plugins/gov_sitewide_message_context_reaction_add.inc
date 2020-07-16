<?php
// $Id:

/**
 * @file
 *   Adds a Context module reaction for the sitewide message module.
 */

/**
 * Add sitewide message code to the page.
 */
class gov_sitewide_message_context_reaction_add extends context_reaction {

  function options_form($context) {
    return array(
      'add' => array('#type' => 'value', '#value' => TRUE),
      'note' => array('#type' => 'markup', '#value' => t('Sitewide message code will be added to the page.')),
    );
  }

  function options_form_submit($values) {
    return array('add' => 1);
  }

  function execute() {
    $contexts = $this->get_contexts();
    foreach ($contexts as $context) {
      if (!empty($context->reactions[$this->plugin])) {
        return TRUE;
      }
    }
  }
}
