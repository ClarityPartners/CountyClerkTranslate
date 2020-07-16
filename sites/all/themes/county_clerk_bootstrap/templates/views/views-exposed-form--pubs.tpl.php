<?php

/**
 * @file
 * This template handles the layout of the views exposed filter form.
 *
 * Variables available:
 * - $widgets: An array of exposed form widgets. Each widget contains:
 * - $widget->label: The visible label to print. May be optional.
 * - $widget->operator: The operator for the widget. May be optional.
 * - $widget->widget: The widget itself.
 * - $sort_by: The select box to sort the view using an exposed form.
 * - $sort_order: The select box with the ASC, DESC options to define order. May be optional.
 * - $items_per_page: The select box with the available items per page. May be optional.
 * - $offset: A textfield to define the offset of the view. May be optional.
 * - $reset_button: A button to reset the exposed filter applied. May be optional.
 * - $button: The submit button for the form.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($q)): ?>
  <?php
    // This ensures that, if clean URLs are off, the 'q' is added first so that
    // it shows up first in the URL.
    print $q;
  ?>
<?php //unfortunate code needed here
/*function clarity_switch_get_views_display_switch() {

  $switch = l(t('Grid'), 'media-library-grid', array(
    'query' => drupal_get_query_parameters(), // This ensures the view will keep filter settings when switching the display.
    'attributes' => array(
      'class' => array('page-grid-switch') // Adding a css class for this link.
    )
  ));
  //$switch .= ' | ';
  $switch .= l(t('List'), 'media-library-list', array(
    'query' => drupal_get_query_parameters(),
    'attributes' => array(
      'class' => array('page-list-switch')
    )
  ));

  // Adding CSS class for whole switch.
  $switch = "<div class='page-display-switch'>" . $switch . "</div>";
  return $switch;
}*/
?>
<?php endif; ?>
<div class="views-exposed-form">
    <div class="pub-search-container">
        <div class="pub-search container">
            <?php //dpm($widgets);?>
          <?php foreach ($widgets as $id => $widget): ?>
              <div id="<?php print $widget->id; ?>-wrapper" class="views-exposed-widget views-widget-<?php print $id; ?>">
                <?php if (!empty($widget->label) && ($widget->id == 'edit-search-api-views-fulltext')): ?>
                  <label for="<?php print $widget->id; ?>">
                    <?php print $widget->label; ?>
                  </label>
                <?php endif; ?>
      <?php if ($widget->id == 'edit-search-api-views-fulltext'): ?>
                <div class="views-widget">
                <?php //if ($widget->id == 'edit-search-api-views-fulltext'): ?>
                  <?php print $widget->widget;
                  //dpm($widget->widget);
                  //dpm($widget->id); ?>
               <?php //endif; ?>
                </div>
      <?php endif; ?>
                <?php if (!empty($widget->description)): ?>
                  <div class="description">
                    <?php print $widget->description; ?>
                  </div>
                <?php endif; ?>
              </div>
            <?php endforeach; ?>
        </div>
    </div>

    <div class="views-exposed-widgets clearfix">
        <div class="pub-exposed pubs">
            <?php echo clarity_switch_get_views_pub_display_switch(); ?>
            <?php if (!empty($sort_by)): ?>
              <div class="views-exposed-widget views-widget-sort-by">
                <?php print $sort_by; ?>
              </div>
              <div class="views-exposed-widget views-widget-sort-order">
                <?php print $sort_order; ?>
              </div>
            <?php endif; ?>
            <?php if (!empty($items_per_page)): ?>
              <div class="views-exposed-widget views-widget-per-page col col-md-2">
                <?php print $items_per_page; ?>
              </div>
            <?php endif; ?>



            <?php //moved filter down here for design ?>
            <?php foreach ($widgets as $id => $widget): ?>
              <div id="<?php print $widget->id; ?>-wrapper" class="views-exposed-widget views-widget-<?php print $id; ?>">
                <?php if (!empty($widget->label) && ($widget->id != 'edit-search-api-views-fulltext')): ?>
                  <label for="<?php print $widget->id; ?>">
                    <?php print $widget->label; ?>
                  </label>
                <?php endif; ?>
                <?php if (!empty($widget->operator)): ?>
                  <div class="views-operator">
                    <?php print $widget->operator; ?>
                  </div>
                <?php endif; ?>
                <div class="views-widget">
                <?php if ($widget->id != 'edit-search-api-views-fulltext'): ?>
                  <?php print $widget->widget;
                  //dpm($widget->widget);
                  //dpm($widget->id); ?>
               <?php endif; ?>
                </div>
                <?php if (!empty($widget->description)): ?>
                  <div class="description">
                    <?php print $widget->description; ?>
                  </div>
                <?php endif; ?>
              </div>
            <?php endforeach; ?>





            <?php if (!empty($offset)): ?>
              <div class="views-exposed-widget views-widget-offset">
                <?php print $offset; ?>
              </div>
            <?php endif; ?>
            <div class="views-exposed-widget views-submit-button">
              <?php print $button; ?>
            </div>
            <?php if (!empty($reset_button)): ?>
              <div class="views-exposed-widget views-reset-button">
                <?php print $reset_button; ?>
              </div>
            <?php endif; ?>
        </div>
  </div>
</div>