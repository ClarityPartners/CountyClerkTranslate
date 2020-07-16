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
<?php //background image
$bkimage = file_create_url($content['field_background_image']['#object']->field_background_image['und'][0]['uri']);
$block = module_invoke('views', 'block_view', '-exp-primary_search_view-page_1');
$secondarybody = $content['field_basic_body']['#items'][0]['value']; //alternative: $content['field_basic_body'][0]['#markup'];
?>

<div class="home-card paragraph <?php print $classes; ?>"<?php print $attributes; ?> style="background-image:url('<?php echo $bkimage ?>')">
  <div class="content container"<?php print $content_attributes; ?>>
      <?php hide($content['field_background_image']); ?>
      <?php hide($content['field_basic_body']); ?>
      <div class="para-content">
          <h1 class="hero-title"><?php echo render($content['field_title']); ?></h1>
        <?php print render($content); ?>
      </div>
      <?php if (empty($secondarybody)) { ?>
        <div class="para-search">
          <?php if(isset($block)):?>
            <div class="jump-title"><?php echo t('Search our Site'); ?></div>
            <?php echo render($block['content']); ?>
          <?php endif; ?>
        </div>
      <?php } else { ?> 
        <?php echo render($content['field_basic_body']); ?> 
      <?php } ?>
  </div>
</div>
