<h2><?php print $title ?></h2>
<p>
<?php
  hide($content['field_contact_department']);
  hide($content['deeplink_form']);
  hide($content['rbkc_related_content']);
  hide($content['sharethis']);
  hide($content['field_tag']);
  print render($content);
?>
</p>

