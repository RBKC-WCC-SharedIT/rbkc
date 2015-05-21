<div class="col5">
  <h2>
    <?php print render($content['field_topic_link']['#object']->title);?>
  </h2>
</div>
<div class="col7">
  <?php
    for ( $i = 0; $i < 3; $i++ ) {
      print render($content['field_topic_link'][$i]);
    }
  ?>
  <h3><a href="<?php print $node_url;?>">More in <?php print render($content['field_topic_link']['#object']->title);?>...</a></h3>
</div><!--end col 7-->
