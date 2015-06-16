<?php
$content = new stdClass();
$content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
$content->api_version = 1;
$content->name = 'need_to_menu';
$content->admin_title = 'I Need To Menu';
$content->admin_description = 'Content Pane containing the HTML for the I Need To Menu';
$content->category = 'RBKC';

$body = '<div class="quicklinks">
      <div class="impact iconlinks">
        <div class="impact__inner group">
          <h2>I need to...</h2>
          <ul class="quicklinks__list-one">
            <li><a class="first" href="http://www.rbkc.gov.uk/payitonline.aspx" title="Make a payment">Make a payment</a></li>
            <li><a href="http://www.rbkc.gov.uk/reportit.aspx" title="Report a problem">Report a problem</a></li>
            <li><a href="http://www.rbkc.gov.uk/bincollections/default.aspx" title="Find my bin collection day">Find my bin collection day</a></li>
            <li><a href="https://www.rbkc.gov.uk/onlinepayments/parkingpermits/default.aspx" title="Apply for a parking permit">Apply for a parking permit</a></li>
            <li><a href="http://uk.sitestat.com/rbkc/rbkc/s?LibraryCatalogue&amp;ns_type=clickout" title="Renew a library book">Renew a library book</a></li>
          </ul>
          <ul class="quicklinks__list-two">
            <li><a href="https://www.rbkc.gov.uk/myrbkc/login.aspx" title="Log into MyRBKC">Log into MyRBKC</a></li>
            <li><a href="http://www.rbkc.gov.uk/contactsdirectory/records.asp" title="Find service contact details">Find service contact details</a></li>
            <!--<li><a href="http://www.rbkc.gov.uk/findmynearest/findmynearest.aspx" title="Find my nearest">Find my nearest</a></li>-->
            <li><a href="http://www.rbkc.gov.uk/yourcouncil/localdemocracy/postcodesearch.asp" title="Find my polling station">Find my polling station</a></li>
            <li><a class="last" href="http://www.rbkc.gov.uk/ineedto.aspx" title="See more things to do"><strong>See more things to do</strong></a></li>
          </ul>
        </div>
      </div>
    </div>';

$content->settings = array(
  'admin_title' => 'I Need To Menu',
  'title' => '',
  'body' => $body,
  'format' => 'systemhtml',
  'substitute' => 0,
);