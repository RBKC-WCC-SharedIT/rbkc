<?php foreach ($items as $delta => $item): ?>
<div class="row sub-hub-topic blue-border-top">
  <section>
      <?php  print render($item);?>
  </section>
</div> <!--end blueBorderTop-->
<?php endforeach; ?>
