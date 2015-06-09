<h3><a href="<?php print $node_url ?>"><?php print $title ?></a></h3>
<p>
<?php
  hide($content['links']);
  print render($content);
?>
</p>
