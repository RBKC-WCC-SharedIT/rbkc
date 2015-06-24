<?php

$content = new stdClass();
$content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
$content->api_version = 1;
$content->name = 'newsroom_top_stories_slider';
$content->admin_title = 'Newsroom Top Stories Slider';
$content->admin_description = 'Slider showing Top Stories';
$content->category = 'RBKC';

$body = <<<'EOD'
<ul class="rslides">
  <li class="latestNewsIntro">
    <div class="newsPic"><a href="http://www.rbkc.gov.uk/pressrelease/pressreleasepage.aspx?id=6687"><img width="448" alt="InTRANSIT" title="InTRANSIT" src="/images/intransit_newsrm.jpg" height="294"></a></div>
    <div class="caption"><p><strong><span><a href="http://www.rbkc.gov.uk/pressrelease/pressreleasepage.aspx?id=6687">InTRANSIT Festival 2015</a></span></strong><br></p></div>
  </li>
  <li class="latestNewsIntro">
    <div class="newsPic"><p><a href="http://www.rbkc.gov.uk/newsroom/capitalprojects/northkensingtonlibrary1.aspx"><img width="448" alt="North Kensington Library" title="North Kensington Library" src="/images/newsroom_nklib.jpg" height="294"></a></p></div>
    <div class="caption"><p><strong><span><a href="http://www.rbkc.gov.uk/newsroom/capitalprojects/northkensingtonlibrary1.aspx">North Kensington Library to move to a brand new building</a></span></strong><br></p></div>
  </li>
  <li class="latestNewsIntro">
    <div class="newsPic"><a href="http://www.rbkc.gov.uk/pressrelease/pressreleasepage.aspx?id=6706"><img width="448" alt="Schools 'Art on Show'" title="Schools 'Art on Show'" src="/images/newsroom_colville.jpg" height="294"></a></div>
    <div class="caption"><p><strong><span><a href="http://www.rbkc.gov.uk/pressrelease/pressreleasepage.aspx?id=6706">Schools 'Art on Show' at Leighton House</a></span></strong><br></p></div>
  </li>
  <li class="latestNewsIntro">
    <div class="newsPic"><p><a href="http://www.rbkc.gov.uk/pressrelease/pressreleasepage.aspx?id=6703"><img width="448" alt="Volunteering" title="Volunteering" src="/images/newsroom_teamkc.jpg" height="294"></a></p></div>
    <div class="caption"><p><strong><span><a href="http://www.rbkc.gov.uk/pressrelease/pressreleasepage.aspx?id=6703">The Royal Borough gives volunteering a boost</a></span></strong><br></p></div>
  </li>
  <li class="latestNewsIntro">
    <div class="newsPic"><a href="http://www.operahollandpark.com/2015-season/"><img width="448" alt="Opera Holland Park" title="Opera Holland Park" src="/images/opera-holland-park_tent.jpg" height="294"></a></div>
    <div class="caption"><p><strong><span><a href="http://www.operahollandpark.com/2015-season/">Opera Holland Park book now for the 2015 season</a></span></strong><br></p></div>
  </li>
</ul>
EOD;

$content->settings = array(
  'admin_title' => $content->admin_title,
  'title' => '',
  'body' => $body,
  'format' => 'systemhtml',
  'substitute' => 0,
);