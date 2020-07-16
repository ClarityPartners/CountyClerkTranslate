<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="content bean-type image"<?php print $content_attributes; ?>>
      <div class="container image">
        <div class="row">
            <div class="col col-md-3 col-with-vspace">
                <?php echo render($content['field_file_image']); ?>
            </div>
            <div class="col col-md-9">
                <h2><?php echo $title; ?></h2>
                <div class="bean-body"><?php echo render($content['field_body']); ?></div>
            </div>
        </div>
      </div>
  </div>
</div>
