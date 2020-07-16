<?php
/**
 * @file
 * Default output for a FlexSlider object.
*/
?>
<div class="featured-media-slider">
  <div <?php print drupal_attributes($settings['attributes'])?>>
    <?php print theme('flexslider_list', array('items' => $items, 'settings' => $settings)); ?>
  </div>
  <?php if($settings['optionset']->options['controlNav'] == 'thumbnails' && sizeof($items) > 1): ?>
    <div class="thumbnail-carousel flexslider">
      <?php print theme('flexslider_thumbnail_list', array('items' => $items, 'settings' => $settings)); ?>
    </div>
  <?php endif ?>
</div>
