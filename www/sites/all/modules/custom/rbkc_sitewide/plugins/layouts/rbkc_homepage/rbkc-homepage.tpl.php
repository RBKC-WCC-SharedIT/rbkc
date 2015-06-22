<?php
/**
 * @file
 * RBKC - Homepage Layout
 */
?>

<div class="middle middle--hp">

  <div class="inner order-homepage">
    <?php print $content['menu']; ?>

    <div class="inner cust-serv">
      <div class="colorbox-700">
        <?php print $content['content']; ?>
      </div><!-- end local events -->
    </div><!-- end innerNoPadding -->

    <div class="comms row">
      <?php print $content['comms']; ?>
    </div>


  </div><!-- end inner -->

  <div class="local group">
    <div class="inner">
      <?php print $content['local_life']; ?>
    </div><!-- end inner -->
  </div><!-- end local -->

  <div class="presstweet">
    <div class="inner">
      <?php print $content['presstweet']; ?>
      <p class="smallest-text"><a href="http://www.geograph.org.uk/photo/1700705" target="_blank">High Street Kensington Station image</a> &copy; Copyright Ruth Sharville</p>
    </div><!-- end inner -->
  </div><!-- end presstweet -->
</div>