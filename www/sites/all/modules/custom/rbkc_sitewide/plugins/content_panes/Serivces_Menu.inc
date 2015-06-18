<?php
$content = new stdClass();
$content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
$content->api_version = 1;
$content->name = 'services_menu_static';
$content->admin_title = 'Services Menu';
$content->admin_description = 'Content Pane containing the HTML for the Services Menu';
$content->category = 'RBKC';

$body = '<div class="servicelist" id="services"><div class="impact">
    <div class="impact__inner group">
      <h2>Services</h2>
      <nav role="navigation">
        <ul class="servicelist__list-one ">
          <li>
            <span>
              <a class="first" href="http://www.rbkc.gov.uk/adviceandbenefits.aspx" title="Advice and benefits">Advice and benefits<span class="servicelist__desc">Check your eligibility, make a claim</span></a>
            </span>
          </li>
          <li>
            <span>
              <a href="http://www.rbkc.gov.uk/binsandrecycling.aspx" title="Bins and recycling">
                Bins and recycling
                <span class="servicelist__desc">Collections, recycling centres and bulky waste info</span>
              </a>
            </span>
          </li>
          <li>
            <span>
              <a href="http://www.rbkc.gov.uk/birthsdeathsmarriages.aspx" title="Births, deaths and marriages">
                Births, deaths and marriages
                <span class="servicelist__desc">Registrars services and nationality checking</span>
              </a>
            </span>
          </li>
          <li>
            <span>
              <a href="http://www.rbkc.gov.uk/businessandenterprise.aspx" title="Business and enterprise">
                Business and enterprise
                <span class="servicelist__desc">Helping you do business in the borough</span>
              </a>
            </span>
          </li>
          <li>
            <span>
              <a href="http://www.rbkc.gov.uk/educationandlearning.aspx" title="Children and education">
                Children and education
                <span class="servicelist__desc">Schools and adult learning</span>
              </a>
            </span>
          </li>
          <li>
            <span>
              <a href="http://www.rbkc.gov.uk/community.aspx" title="Community and local life">
                Community and local life
                <span class="servicelist__desc">How to get involved, community safety</span>
              </a>
            </span>
          </li>
          <li>
            <span>
              <a href="http://www.rbkc.gov.uk/councilanddemocracy.aspx" title="Council">
                Council
                <span class="servicelist__desc">How we work, make decisions and manage our finances</span>
              </a>
            </span>
          </li>
          <li>
            <span>
              <a href="http://www.rbkc.gov.uk/councilanddemocracy/counciltax.aspx" title="Council tax">
                Council tax
                <span class="servicelist__desc">Pay online, discounts and exemptions</span>
              </a>
            </span>
          </li>
          <li>
            <span>
              <a class="servicelist-last" href="http://www.rbkc.gov.uk/environmentandtransport.aspx" title="Environment">
                Environment
                <span class="servicelist__desc">Environmental considerations for residents and visitors</span>
              </a>
            </span>
          </li>
        </ul>
        <ul class="servicelist__list-two hide margin700">
          <li>
            <span>
              <a href="http://www.rbkc.gov.uk/healthandsocialcare.aspx" title="Health and social care">
                Health and social care
                <span class="servicelist__desc">Adult social care, children and families</span>
              </a>
            </span>
          </li>
          <li>
            <span>
              <a href="http://www.rbkc.gov.uk/housing.aspx" title="Housing">
                Housing
                <span class="servicelist__desc">The Royal Boroughs housing services</span>
              </a>
            </span>
          </li>
          <li>
            <span>
              <a href="http://www.rbkc.gov.uk/jobs.aspx" title="Jobs">
Jobs
                <span class="servicelist__desc">Working with the Royal Borough</span>
              </a>
            </span>
          </li>
          <li>
            <span>
              <a href="http://www.rbkc.gov.uk/leisureandlibraries.aspx" title="Leisure and culture">
Leisure and culture
<span class="servicelist__desc">Museums, markets and activities</span>
              </a>
            </span>
          </li>
          <li>
            <span>
              <a href="http://www.rbkc.gov.uk/leisureandlibraries/libraries.aspx" title="Libraries">
Libraries
                <span class="servicelist__desc">Join, renew books</span>
              </a>
            </span>
          </li>
          <li>
            <span>
              <a href="http://www.rbkc.gov.uk/environmentandtransport/licensing.aspx" title="Licensing">
Licensing
                <span class="servicelist__desc">Businesses, residents and visitors, initiatives, policy</span>
              </a>
            </span>
          </li>
          <li>
            <span>
              <a  href="http://www.rbkc.gov.uk/environmentandtransport/parking.aspx" title="Parking, transport and streets">
Parking, transport and streets
<span class="servicelist__desc">Parking tickets, permits and travel options</span>
              </a>
            </span>
          </li>
          <li>
            <span>
              <a href="http://www.rbkc.gov.uk/leisureandlibraries/parksandgardens.aspx" title="Parks and ecology">
Parks and ecology
<span class="servicelist__desc">Award winning parks and open spaces</span>
              </a>
            </span>
          </li>
          <li>
            <span>
              <a class="servicelist-last" href="http://www.rbkc.gov.uk/planningandbuildingcontrol.aspx" title="Planning">
Planning
                <span class="servicelist__desc">Apply, search, view and comment on applications</span>
              </a>
            </span>
          </li>
        </ul>
        <a class="servicelist__viewall" href="http://www.rbkc.gov.uk/services.aspx"><span>View more services</span></a>
      </nav>
    </div>
  </div>
</div>';

$content->settings = array(
  'admin_title' => 'Services Menu',
  'title' => '',
  'body' => $body,
  'format' => 'systemhtml',
  'substitute' => 0,
);