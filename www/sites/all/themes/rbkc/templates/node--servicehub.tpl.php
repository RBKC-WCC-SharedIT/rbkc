  <?php print render($content['field_popular_tasks']); ?>

  <?php print render($content['field_popular_topics']); ?>

  <div class="row"><!-- add an if? -->

    <?php print render($content['field_other_popular_content']); ?>

    <?php print render($content['field_news_stories']); ?>

  </div><!-- end row -->
  <?php
  // Render the rest of the node, including links added by various modules.
  print render($content);
  ?>
