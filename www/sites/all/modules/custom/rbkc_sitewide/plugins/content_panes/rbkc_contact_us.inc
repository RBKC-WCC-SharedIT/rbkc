<?php
$content = new stdClass();
$content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
$content->api_version = 1;
$content->name = 'contact_us';
$content->admin_title = 'Contact Us';
$content->admin_description = 'Contact Us - Number and Email';
$content->category = 'RBKC';

$body = '<p><strong>Tel:</strong> <a href="tel://020-7361-2826/">020 73612826</a></p><p><strong>Email:</strong> <a href="mailto:pressbox@rbkc.gov.uk">pressbox@rbkc.gov.uk</a></p>';

$content->settings = array(
  'admin_title' => 'Contact Us',
  'title' => 'Contact Us',
  'body' => $body,
  'format' => 'full_html',
  'substitute' => 0,
);