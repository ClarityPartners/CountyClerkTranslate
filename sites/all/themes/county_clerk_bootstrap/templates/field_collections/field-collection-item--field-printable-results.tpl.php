<?php
$file = file_create_url($content['field_printable_results_file']['#items'][0]['uri']);
$url = $content['field_printable_results_url']['#items'][0]['value'];
if($url == ''){
  $link = $file;
} else{
  $link = $url;
} ?>
<a target="_blank" href="<?php echo $link; ?>">
  <?php print render($content['field_printable_results_title']); ?>
</a>