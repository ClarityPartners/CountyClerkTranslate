<?php

/**
 * @file
 * Default theme implementation for a single paragraph item.
 *
 * Available variables:
 * - $content: An array of content items. Use render($content) to print them
 *   all, or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity
 *   - entity-paragraphs-item
 *   - paragraphs-item-{bundle}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened into
 *   a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="content container"<?php print $content_attributes; ?>>
    <?php
    foreach ($content['field_blocks']['#items'] as $entity_uri){
      $block_item = entity_load('field_collection_item', $entity_uri);
				foreach ($block_item as $block_item_object ) {
          $linkURL = $block_item_object->field_link['und'][0]['url'];
          $linkTitle = $block_item_object->field_link['und'][0]['title'];
          $color = $block_item_object->field_colors['und'][0]['value'];

          echo '<div class="election-blocks '.$color.'"><a href="'.$linkURL.'">';
          echo $block_item_object->field_body['und'][0]['value'];
          echo '</a></div>';
          //dpm($block_item_object);
        }
    }
    ?>
  </div>
</div>
