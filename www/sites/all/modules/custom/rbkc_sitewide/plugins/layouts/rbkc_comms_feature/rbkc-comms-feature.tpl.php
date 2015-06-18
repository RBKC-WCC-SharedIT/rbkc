<?php
/**
 * @file
 * RBKC - Comms Large Layout
 */
?>

<div class="comms__img">
  <?php print $content['comms_header']; ?>
</div>

<div class="comms__content">
  <div class="hollowpointer">
    <span class="hollowpointer1"></span>
    <div class="hollowpointer-center">
      <span class="hollowpointer2"></span>
      <span class="hollowpointer3"></span>
    </div>
    <span class="hollowpointer4"></span>
  </div>
  <!-- repeating comms__item field -->
  <div class="comms__item">
    <div class="comms__feature__inner">
      <?php print $content['comms_content']; ?>
    </div>
  </div>
</div>