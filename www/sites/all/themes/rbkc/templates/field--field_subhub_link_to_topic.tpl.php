<?php foreach ($items as $delta => $item): ?>
<div class="row sub-hub-topic blue-border-top">
  <section>
  <div class="col5">
    <h2><?php  //print render($item['#node']->title);
              print render( $item['node'][21]['field_topic_link']['#object']->title);
        ?>
    </h2>
  </div>
  <div class="col7">
    <?php  print render($item);?>
  </div><!--end col 7-->
  </section>
</div> <!--end blueBorderTop-->
<?php endforeach; ?>
