<div class="comms__news col8">
  <?php if (!empty($comms_image)): ?>
  <div class="comms__img">
    <h2>Latest news</h2>
    <!-- editable link around image -->
      <?php print l($comms_image, $news['itemone']['link'], array('html' => TRUE)); ?>
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

    <?php foreach($news as $item) { ?>
      <?php if (!empty($item['title'])):?>
      <div class="comms__item">
        <!-- editable content -->
        <h3><?php print l($item['title'],$item['link']); ?></h3>
        <p><?php print $item['body']; ?></p>
      </div>
        <?php endif ?>
    <?php } ?>
    <!-- repeating comms__item field -->

    <div class="comms__item comms__readmore">
      <h3><a href="/newsroom-beta.aspx">Visit the newsroom for more updates</a></h3>
    </div>
  </div><!-- end comms content -->
</div><!-- end comms news -->