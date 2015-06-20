<div class="comms__feature">
  <?php if (!empty($comms_image)): ?>
  <div class="comms__img">
    <!-- editable header -->
    <h2><?php print $comms_label; ?></h2>
    <!-- div with editable background image -->
    <span class="comms__overlay"></span>
    <!-- editable link around image -->
    <?php print l($comms_image, $comms_link, array('html' => TRUE)); ?>
  </div>
  <?php endif; ?>
  <div class="comms__content">
    <div class="hollowpointer">
      <span class="hollowpointer1"></span>
      <div class="hollowpointer-center">
        <span class="hollowpointer2"></span>
        <span class="hollowpointer3"></span>
      </div>
      <span class="hollowpointer4"></span>
    </div>
    <div class="comms__item" >
      <div class="comms__feature__inner">
        <!-- editable content -->
        <h3><?php print l($comms_title, $comms_link); ?></h3>
        <?php print t($comms_body); ?>
      </div>
      <span class="fadeout">
        <a href="<?php print $comms_link; ?>" class="comms__readmore linkheader">Read more</a>
      </span>
    </div>
  </div><!-- end comms content -->
</div><!-- end comms feature -->