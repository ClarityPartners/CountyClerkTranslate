<?php
/**
 * @file
 * Default theme implementation for beans.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<?php //background image
$bkimage = file_create_url($content['field_background_image']['#object']->field_background_image['und'][0]['uri']);
?>
<div class="media-card paragraph <?php print $classes; ?>"<?php print $attributes; ?> style="background-image:url('<?php echo $bkimage ?>')">
  <div class="content container"<?php print $content_attributes; ?>>
      <?php hide($content['field_background_image']); ?>
      <div class="para-content">
          <h1 class="bean-title"><?php echo render($title); ?></h1>
        <?php  print render($content); ?>
      </div>
      <div class="para-search media">
        <?php //if(isset($block)):?>
          <div class="jump-title"><?php echo t('Search Media Room'); ?></div>
          <?php //echo drupal_render($form); ?>
          <div class="search-form media">
          <input placeholder="Search" class="fake-input form-control form-text" type="text" id="edit-keys" name="keys" value="" size="15" maxlength="128">
          <button type="submit" class="btn btn-fake"><span class="icon glyphicon glyphicon-search" aria-hidden="true"></span></button>
          </div>
        <?php //endif; ?>
      </div>
  </div>
</div>