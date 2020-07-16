<?php
$text_content = variable_get('text_modal', '');
$text_content_2 = variable_get('text_modal_2', '');
$text_content_3 = variable_get('text_modal_3', '');
$text_content_4 = variable_get('text_modal_4', '');
?>

<div class="modal fade" id="electionsModal">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <a class="close" data-dismiss="modal">×</a>
      </div>
        <div class="modal-body row">
            <!--Suburban Cook Green-->
            <?php if (!empty($text_content)):?><a href="/VoterInfo" class="election-blocks green"><div>
              <?php echo $text_content; ?>
            </div></a><?php endif; ?>
            <!-- Voters grey -->
            <?php if (!empty($text_content_3)):?><a href="https://chicagoelections.com/en/your-voter-information.html" target="_blank" class="election-blocks grey"><div>
              <?php echo $text_content_3; ?>
            </div></a><?php endif; ?>
            <!--Clerk Red-->
            <?php if (!empty($text_content_4)):?><a class="election-blocks red" data-dismiss="modal"><div>
              <?php echo $text_content_4; ?>
            </div></a><?php endif; ?>
             <!--Election results Blue-->
             <?php if (!empty($text_content_2)):?><a href="/election-results?field_election_date_value%5Bvalue%5D%5Byear%5D=2020" class="election-blocks blue"><div>
              <?php echo $text_content_2; ?>
            </div></a><?php endif; ?>
        </div>
      <div class="modal-footer">
        <?php if (user_access('administer site configuration')): ?>
          <a class="edit-modal" href="/admin/structure/block/manage/elections/block/configure">Edit Block</a>
        <?php endif; ?>
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
      </div>
    </div>
  </div>
</div>
