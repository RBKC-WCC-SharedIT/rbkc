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
                    <span class="colorbox-700__left">
                      <span class="icon-twitter">
                      </span>
                      <span class="colorbox-700__pointer"></span>
                    </span>
                    <span class="colorbox-700__content">
                      <h3>Tweet us</h3>
                      <p>@RBKC_CS</p>
                    </span>

                  </a>
                </li>
                <li>
                  <a class="purple" href="https://www.eforms.rbkc.gov.uk/default.aspx/RenderForm/?F.Name=FoXT6rvnp4J">
                    <span class="colorbox-700__left">

                      <span class="icon-envelope">
                      </span>

                      <span class="colorbox-700__pointer"></span>
                    </span>
                    <span class="colorbox-700__content">
                      <h3>Email us</h3>
                      <p>Customer Services</p>
                    </span>
                  </a>
                </li>
                <li>
                  <a href="http://www.rbkc.gov.uk/contactus/telephoneandemail.aspx">
                    <span class="colorbox-700__left">
                      <span class="icon-phone">
                      </span>
                      <span class="colorbox-700__pointer"></span>
                    </span>
                    <span class="colorbox-700__content">
                      <h3>Call us</h3>
                      <p>Talk to one of our advisers</p>
                    </span>
                  </a>
                </li>
              </ul>';
  return $block;
}
