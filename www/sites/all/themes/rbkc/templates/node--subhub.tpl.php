  <div class="row col12 large-text">
    <?php
      hide($content['field_subhub_link_to_topic']);
      hide($content['deeplink_form']);
      print render($content);
    ?>
  </div><!-- end row -->
  <?php
    print render($content['field_subhub_link_to_topic']);
    print render($content['deeplink_form']);
  ?>

