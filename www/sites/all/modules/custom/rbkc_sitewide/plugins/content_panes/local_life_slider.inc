<?php
$content = new stdClass();
$content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
$content->api_version = 1;
$content->name = 'local_life_slider';
$content->admin_title = 'Local Life Slider';
$content->admin_description = 'Slider showing local life highlights';
$content->category = 'RBKC';

$body = '<div class="local group">
  <div class="inner">
    <h3 class="padded-mob">Local life <span class="show600">in the Royal Borough of Kensington and Chelsea</span></h3>

    <div class="local__slider ">
      <div class="local__slider__item local-visit">
        <a href="/subsites/visitkensingtonandchelsea.aspx">
          <span class="local__img"></span>
          <span class="local__text"><h2>Visit Kensington and Chelsea</h2></span>
        </a>
      </div>

      <div class="local__slider__item local-city">
        <a href="/subsites/citylivinglocallife.aspx">
          <span class="local__img"></span>
          <span class="local__text"><h2>City Living Local Life</h2></span>
        </a>
      </div>

      <div class="local__slider__item local-kcc">
        <a href="/subsites/kccentral.aspx">
          <span class="local__img"></span>
          <span class="local__text"><h2>KCcentral</h2></span>
        </a>
      </div>

      <div class="local__slider__item local-museums ie-morethanthree">
        <a href="/subsites/museums.aspx">
          <span class="local__img"></span>
          <span class="local__text"><h2>Museums</h2></span>
        </a>
      </div>
      <div class="local__slider__item local-wild ie-morethanthree">
        <a href="/subsites/wildlife.aspx">
          <span class="local__img"></span>
          <span class="local__text"><h2>Wildlife</h2></span>
        </a>
      </div>
      <div class="local__slider__item local-timemachine ie-morethanthree">
        <a href="https://rbkclocalstudies.wordpress.com/2014/10/23/adventure-playing-out-in-telford-road/">
          <span class="local__img"></span>
          <span class="local__text"><h2>Time Machine</h2></span>
        </a>
      </div>
    </div>

    <!--<h3 class="padded-mob"><a href="http://www.rbkc.gov.uk/events/default/default.asp">See upcoming events in the Royal Borough</a></h3>-->

  </div><!-- end inner -->
</div><!-- end local -->';

$content->settings = array(
  'admin_title' => 'Local Life Slider',
  'title' => '',
  'body' => $body,
  'format' => 'systemhtml',
  'substitute' => 0,
);