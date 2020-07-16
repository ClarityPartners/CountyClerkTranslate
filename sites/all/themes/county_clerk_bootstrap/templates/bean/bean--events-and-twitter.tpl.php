<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="content bean-type events"<?php print $content_attributes; ?>>
      <div class="container events">
        <div class="row">
            <div class="bean-title"><h2><?php echo $title; ?></h2></div>
            <div class="col col-md-6 col-with-vspace">
                <div class="bean-view"><?php echo render($content['field_view_reference']); ?></div>
                <div class="bean-link"><?php echo render($content['field_media_room_link']); ?></div>
            </div>
            <div class="col col-md-6">
                
                <div class="bean-view twitter"><?php echo views_embed_view('twitter', $display_id = 'block'); ?></div>
                <div class="bean-link twitter"><?php echo render($content['field_twitter_follow_link']); ?></div>
            </div>
        </div>
      </div>
  </div>
</div>
