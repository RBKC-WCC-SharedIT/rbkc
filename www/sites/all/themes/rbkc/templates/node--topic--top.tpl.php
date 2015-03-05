<?php
  for ( $i = 0; $i < 3; $i++ ) {
    print render($content['field_topic_link'][$i]);
  }
?>
<h3><a href="<?php print $node_url;?>">More in <?php print $content['field_topic_link']['#object']->title;?>...</a></h3>