<h2><a href="<?php print $node_url ?>"><?php print $title ?></a></h2>
<p>
<?php
  hide($content['links']);
  print render($content);
?>
</p>
