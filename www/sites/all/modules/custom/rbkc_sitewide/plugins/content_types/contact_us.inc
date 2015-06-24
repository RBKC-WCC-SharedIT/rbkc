<?php

/**
 * @file
 * Plugin to output search_title.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Contact Us'),
  'description' => t('Twitter, Email and Call Us links'),
  'category' => t('RBKC'),
  'defaults' => array(),
  'render callback' => 'rbkc_sitewide_contact_us_links',
);

/**
 * Output function for the 'search_title' content type.
 */
function rbkc_sitewide_contact_us_links($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = '';

  $block->content = '<ul class="fit-3">
                <li>
                  <a href="https://twitter.com/intent/tweet?screen_name=RBKC_CS">
                    <div class="colorbox-700__left">
                      <div class="icon-twitter">
                      </div>
                      <div class="colorbox-700__pointer"></div>
                    </div>
                    <div class="colorbox-700__content">
                      <h3>Tweet us</h3>
                      <p>@RBKC_CS</p>
                    </div>

                  </a>
                </li>
                <li>
                  <a class="purple" href="https://www.eforms.rbkc.gov.uk/default.aspx/RenderForm/?F.Name=FoXT6rvnp4J">
                    <div class="colorbox-700__left">

                      <div class="icon-envelope">
                      </div>

                      <div class="colorbox-700__pointer"></div>
                    </div>
                    <div class="colorbox-700__content">
                      <h3>Email us</h3>
                      <p>Customer Services</p>
                    </div>
                  </a>
                </li>
                <li>
                  <a href="/contact-us/telephone-and-email">
                    <div class="colorbox-700__left">
                      <div class="icon-phone">
                      </div>
                      <div class="colorbox-700__pointer"></div>
                    </div>
                    <div class="colorbox-700__content">
                      <h3>Call us</h3>
                      <p>Talk to one of our advisers</p>
                    </div>
                  </a>
                </li>
              </ul>';
  return $block;
}
