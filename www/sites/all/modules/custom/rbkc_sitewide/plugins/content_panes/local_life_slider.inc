<?php
$content = new stdClass();
$content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
$content->api_version = 1;
$content->name = 'local_life_slider';
$content->admin_title = 'Local Life Slider';
$content->admin_description = 'Slider showing local life highlights';
$content->category = 'RBKC';

$body = '<h3 class="padded-mob">Local life <span class="show600">in the Royal Borough of Kensington and Chelsea</span></h3>

      <div class="local__slider  slick-initialized slick-slider">
        <div class="slick-list draggable" tabindex="0"><div class="slick-track" style="opacity: 1; width: 3840px; transform: translate3d(-2560px, 0px, 0px);"><div class="local__slider__item local-museums ie-morethanthree slick-slide slick-cloned" index="-3" style="width: 320px;">
              <a href="/subsites/museums.aspx">
                <span class="local__img"></span>
                <span class="local__text"><h2>Museums</h2></span>
              </a>
            </div><div class="local__slider__item local-wild ie-morethanthree slick-slide slick-cloned" index="-2" style="width: 320px;">
              <a href="/subsites/wildlife.aspx">
                <span class="local__img"></span>
                <span class="local__text"><h2>Wildlife</h2></span>
              </a>
            </div><div class="local__slider__item local-timemachine ie-morethanthree slick-slide slick-cloned" index="-1" style="width: 320px;">
              <a href="https://rbkclocalstudies.wordpress.com/2014/10/23/adventure-playing-out-in-telford-road/">
                <span class="local__img"></span>
                <span class="local__text"><h2>Time Machine</h2></span>
              </a>
            </div><div class="local__slider__item local-visit slick-slide" index="0" style="width: 320px;">
              <a href="/subsites/visitkensingtonandchelsea.aspx">
                <span class="local__img"></span>
                <span class="local__text"><h2>Visit Kensington and Chelsea</h2></span>
              </a>

            </div><div class="local__slider__item local-city slick-slide" index="1" style="width: 320px;">
              <a href="/subsites/citylivinglocallife.aspx">
                <span class="local__img"></span>
                <span class="local__text"><h2>City Living Local Life</h2></span>
              </a>
            </div><div class="local__slider__item local-kcc slick-slide" index="2" style="width: 320px;">
              <a href="/subsites/kccentral.aspx">
                <span class="local__img"></span>
                <span class="local__text"><h2>KCcentral</h2></span>
              </a>
            </div><div class="local__slider__item local-museums ie-morethanthree slick-slide" index="3" style="width: 320px;">
              <a href="/subsites/museums.aspx">
                <span class="local__img"></span>
                <span class="local__text"><h2>Museums</h2></span>
              </a>
            </div><div class="local__slider__item local-wild ie-morethanthree slick-slide" index="4" style="width: 320px;">
              <a href="/subsites/wildlife.aspx">
                <span class="local__img"></span>
                <span class="local__text"><h2>Wildlife</h2></span>
              </a>
            </div><div class="local__slider__item local-timemachine ie-morethanthree slick-slide slick-active" index="5" style="width: 320px;">
              <a href="https://rbkclocalstudies.wordpress.com/2014/10/23/adventure-playing-out-in-telford-road/">
                <span class="local__img"></span>
                <span class="local__text"><h2>Time Machine</h2></span>
              </a>
            </div><div class="local__slider__item local-visit slick-slide slick-cloned slick-active" index="6" style="width: 320px;">
              <a href="/subsites/visitkensingtonandchelsea.aspx">
                <span class="local__img"></span>
                <span class="local__text"><h2>Visit Kensington and Chelsea</h2></span>
              </a>

            </div><div class="local__slider__item local-city slick-slide slick-cloned slick-active" index="7" style="width: 320px;">
              <a href="/subsites/citylivinglocallife.aspx">
                <span class="local__img"></span>
                <span class="local__text"><h2>City Living Local Life</h2></span>
              </a>
            </div><div class="local__slider__item local-kcc slick-slide slick-cloned" index="8" style="width: 320px;">
              <a href="/subsites/kccentral.aspx">
                <span class="local__img"></span>
                <span class="local__text"><h2>KCcentral</h2></span>
              </a>
            </div></div></div>


        <!-- any item over third item must have class "ie-morethanthree" -->



        <button type="button" data-role="none" class="slick-prev" style="display: block;">Previous</button><button type="button" data-role="none" class="slick-next" style="display: block;">Next</button></div>

      <div class="localevents colorbox">
        <h3 class="padded-mob">Events</h3>
        <ul class="fit-1-2-3">
          <li>
            <a href="#">
                      <span class="colorbox__left">
                        <span class="localevents__date">
                          <span class="localevents__day">09</span>
                          <span class="localevents__month">Jan</span>
                        </span>

                      </span>
                      <span class="colorbox__content">
                        <h4>Toddlers nursery rhymes Notting Hill Library</h4>
                        <p>1 Pembridge Square</p>
                      </span>
              <span class="colorbox__pointer"></span>
            </a>
          </li>
          <li>
            <a class="purple" href="#">
                      <span class="colorbox__left">
                        <span class="localevents__date">
                          <span class="localevents__day">11</span>
                          <span class="localevents__month">Jan</span>
                        </span>
                        <span class="colorbox__pointer"></span>
                      </span>
                      <span class="colorbox__content">
                        <h4>Portobello Road Market festivities </h4>
                        <p>Portobello Road Markets</p>
                      </span>
            </a>
          </li>
          <li>
            <a href="#">
                      <span class="colorbox__left">
                        <span class="localevents__date">
                          <span class="localevents__day">15</span>
                          <span class="localevents__month">Jan</span>
                        </span>
                        <span class="colorbox__pointer"></span>
                      </span>
                      <span class="colorbox__content">
                        <h4>Winter Tree Walk: The Basics</h4>
                        <p>Holland Park</p>
                      </span>
            </a>
          </li>
        </ul>
      </div> <!-- end local events -->

      <!--<h3 class="padded-mob"><a href="http://www.rbkc.gov.uk/events/default/default.asp">See upcoming events in the Royal Borough</a></h3>-->';

$content->settings = array(
  'admin_title' => 'Local Life Slider',
  'title' => '',
  'body' => $body,
  'format' => 'systemhtml',
  'substitute' => 0,
);