<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
?>
<?php $block = module_invoke('views', 'block_view', '-exp-primary_search_view-page_1'); ?>
<?php //dpm($block); ?>
<div class="secondary-headermenu">
    <ul>
        <!--<li class="comment-icon"><a href="#"><span class="fa fa-commenting "></span></a></li>-->
        <li class="settings-icon"><a href="/general/accessibility-information"><span class="fa fa-gear"></span></a></li>
        <li class="search-icon"><div><span class="fa fa-search"><span class="sr-only"></span></span></div></li>
    </ul>
    <div class="search-bar">
    <?php
      echo render($block['content']);
    ?>
    </div>
</div>