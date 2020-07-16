<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="content bean-type video"<?php print $content_attributes; ?>>
      <div class="container video">
        <div class="row">
            <div class="col col-md-5 col-with-vspace video-content">
          <?php echo render($content['field_video']); ?>
            </div>
            <div class="col col-md-7">
                <h2><?php echo $title; ?></h2>
                <div class="bean-body"><?php echo render($content['field_body']); ?></div>
            </div>
        </div>
      </div>
  </div>
</div>
