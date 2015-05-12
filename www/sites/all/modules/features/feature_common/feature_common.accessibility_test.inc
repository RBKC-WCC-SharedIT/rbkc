<?php
/**
 * @file
 * feature_common.accessibility_test.inc
 */

/**
 * Implements hook_accessibility_test_default().
 */
function feature_common_accessibility_test_default() {
$accessibility_tests = array();
$accessibility_tests['aMustContainText'] = (object)array(
  'language' => 'en',
  'name' => 'Links should contain text',
  'quail_name' => 'aMustContainText',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Because many users of screen-readers use links to navigate the page, providing links with no text (or with images that have empty "alt" attributes and no other readable text) hinders these users.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Because many users of screen-readers use links to navigate the page, providing links with no text (or with images that have empty "alt" attributes and no other readable text) hinders these users.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['aSuspiciousLinkText'] = (object)array(
  'language' => 'en',
  'name' => 'Link text should be useful',
  'quail_name' => 'aSuspiciousLinkText',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Because many users of screen-readers use links to navigate the page, providing links with text that simply read "click here" gives no hint of the function of the link',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Because many users of screen-readers use links to navigate the page, providing links with text that simply read "click here" gives no hint of the function of the link</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['appletContainsTextEquivalent'] = (object)array(
  'language' => 'en',
  'name' => 'All applets should contain the same content within the body of the applet',
  'quail_name' => 'appletContainsTextEquivalent',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Applets should contain their text equivalents or description within the <code>applet</code>. /code> tag itself.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Applets should contain their text equivalents or description within the <code>applet</code>. /code&gt; tag itself.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['areaDontOpenNewWindow'] = (object)array(
  'language' => 'en',
  'name' => 'No "area" elements should open a new window without warning',
  'quail_name' => 'areaDontOpenNewWindow',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'No <code>area</code>. /code> elements should open a new window without warning.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>No <code>area</code>. /code&gt; elements should open a new window without warning.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['areaHasAltValue'] = (object)array(
  'language' => 'en',
  'name' => 'All "area" elements must have an "alt" attribute',
  'quail_name' => 'areaHasAltValue',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'All <code>area</code>. /code> elements within a <code>map</code>. /code> must have an "alt" attribute.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>All <code>area</code>. /code&gt; elements within a <code>map</code>. /code&gt; must have an "alt" attribute.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['areaLinksToSoundFile'] = (object)array(
  'language' => 'en',
  'name' => 'All "area" elements which link to a sound file should also provide a link to a transcript',
  'quail_name' => 'areaLinksToSoundFile',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'All <code>area</code>. /code> elements which link to a sound file should have a text transcript',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>All <code>area</code>. /code&gt; elements which link to a sound file should have a text transcript</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['basefontIsNotUsed'] = (object)array(
  'language' => 'en',
  'name' => 'Basefont" should not be used',
  'quail_name' => 'basefontIsNotUsed',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The <code>basefont</code>. /code> tag is deprecated and should not be used. Investigate using stylesheets instead.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The <code>basefont</code>. /code&gt; tag is deprecated and should not be used. Investigate using stylesheets instead.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['blinkIsNotUsed'] = (object)array(
  'language' => 'en',
  'name' => 'The "blink" tag should not be used',
  'quail_name' => 'blinkIsNotUsed',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The <code>blink</code>. /code> tag should not be used. Ever.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The <code>blink</code>. /code&gt; tag should not be used. Ever.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['bodyActiveLinkColorContrast'] = (object)array(
  'language' => 'en',
  'name' => 'Contrast between active link text and background should be 5:1',
  'quail_name' => 'bodyActiveLinkColorContrast',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The contrast ratio of active link text should be at lest 5:1 between the foreground text and the background. <a href="http://www.w3.org/TR/WCAG20/#contrast-ratiodef">Learn more about color contrast and how to measure it.</a>',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The contrast ratio of active link text should be at lest 5:1 between the foreground text and the background. <a href="http://www.w3.org/TR/WCAG20/#contrast-ratiodef">Learn more about color contrast and how to measure it.</a></p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['bodyColorContrast'] = (object)array(
  'language' => 'en',
  'name' => 'Contrast between text and background should be 5:1',
  'quail_name' => 'bodyColorContrast',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The contrast ratio of text should be at lest 5:1 between the foreground text and the background. <a href="http://www.w3.org/TR/WCAG20/#contrast-ratiodef">Learn more about color contrast and how to measure it.</a>',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The contrast ratio of text should be at lest 5:1 between the foreground text and the background. <a href="http://www.w3.org/TR/WCAG20/#contrast-ratiodef">Learn more about color contrast and how to measure it.</a></p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['bodyLinkColorContrast'] = (object)array(
  'language' => 'en',
  'name' => 'Contrast between link text and background should be 5:1',
  'quail_name' => 'bodyLinkColorContrast',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The contrast ratio of link text should be at lest 5:1 between the foreground text and the background. <a href="http://www.w3.org/TR/WCAG20/#contrast-ratiodef">Learn more about color contrast and how to measure it.</a>',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The contrast ratio of link text should be at lest 5:1 between the foreground text and the background. <a href="http://www.w3.org/TR/WCAG20/#contrast-ratiodef">Learn more about color contrast and how to measure it.</a></p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['bodyVisitedLinkColorContrast'] = (object)array(
  'language' => 'en',
  'name' => 'Contrast between visited link text and background should be 5:1',
  'quail_name' => 'bodyVisitedLinkColorContrast',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The contrast ratio of visited link text should be at lest 5:1 between the foreground text and the background. <a href="http://www.w3.org/TR/WCAG20/#contrast-ratiodef">Learn more about color contrast and how to measure it.</a>',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The contrast ratio of visited link text should be at lest 5:1 between the foreground text and the background. <a href="http://www.w3.org/TR/WCAG20/#contrast-ratiodef">Learn more about color contrast and how to measure it.</a></p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['boldIsNotUsed'] = (object)array(
  'language' => 'en',
  'name' => 'The "b" (bold) element is not used',
  'quail_name' => 'boldIsNotUsed',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The <code>b</code>. /code> (bold) element provides no emphasis for non-sighted readers. Use the <code>strong</code>. /code> tag instead.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The <code>b</code>. /code&gt; (bold) element provides no emphasis for non-sighted readers. Use the <code>strong</code>. /code&gt; tag instead.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['checkboxHasLabel'] = (object)array(
  'language' => 'en',
  'name' => 'All checkboxes must have a corresponding label',
  'quail_name' => 'checkboxHasLabel',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'All <code>input</code>. /code> elements with a type of "checkbox" should have a corresponding <code>label</code>. /code> element. Screen readers often enter a "form mode" where only label text is read aloud to the user',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>All <code>input</code>. /code&gt; elements with a type of "checkbox" should have a corresponding <code>label</code>. /code&gt; element. Screen readers often enter a "form mode" where only label text is read aloud to the user</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['cssTextHasContrast'] = (object)array(
  'language' => 'en',
  'name' => 'All elements should have appropriate color contrast',
  'quail_name' => 'cssTextHasContrast',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'For users who have color blindness, all text or other elements should have a color contrast of 5:1.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>For users who have color blindness, all text or other elements should have a color contrast of 5:1.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['documentAllColorsAreSet'] = (object)array(
  'language' => 'en',
  'name' => 'All the document colors must be set',
  'quail_name' => 'documentAllColorsAreSet',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'If any colors for text or the background are set in the <code>body</code>. /code> element, then all colors must be set.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>If any colors for text or the background are set in the <code>body</code>. /code&gt; element, then all colors must be set.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['documentAutoRedirectNotUsed'] = (object)array(
  'language' => 'en',
  'name' => 'Auto-redirect with "meta" elements must not be used',
  'quail_name' => 'documentAutoRedirectNotUsed',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Because different users have different speeds and abilities when it comes to parsing the content of a page, a "meta-refresh" method to redirect users can prevent users from fully understanding the document before being redirected. If a pure redirect is needed',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Because different users have different speeds and abilities when it comes to parsing the content of a page, a "meta-refresh" method to redirect users can prevent users from fully understanding the document before being redirected. If a pure redirect is needed</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['documentHasTitleElement'] = (object)array(
  'language' => 'en',
  'name' => 'The document should have a title element',
  'quail_name' => 'documentHasTitleElement',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The document should have a title element.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The document should have a title element.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['documentIDsMustBeUnique'] = (object)array(
  'language' => 'en',
  'name' => 'All element "id" attributes must be unique',
  'quail_name' => 'documentIDsMustBeUnique',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Element "id" attributes must be unique.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Element "id" attributes must be unique.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['documentLangIsISO639Standard'] = (object)array(
  'language' => 'en',
  'name' => 'The document\'s language attribute should be a standard code',
  'quail_name' => 'documentLangIsISO639Standard',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The document should have a default langauge, and that language should use the valid 2 or 3 letter language code according to ISO specification 639.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The document should have a default langauge, and that language should use the valid 2 or 3 letter language code according to ISO specification 639.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['documentLangNotIdentified'] = (object)array(
  'language' => 'en',
  'name' => 'The document must have a "lang" attribute',
  'quail_name' => 'documentLangNotIdentified',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The document should have a default langauge, by setting the "lang" attribute in the <code>html</code>. /code> element.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The document should have a default langauge, by setting the "lang" attribute in the <code>html</code>. /code&gt; element.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['documentMetaNotUsedWithTimeout'] = (object)array(
  'language' => 'en',
  'name' => 'Meta" elements must not be used to refresh the content of a page',
  'quail_name' => 'documentMetaNotUsedWithTimeout',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Because different users have different speeds and abilities when it comes to parsing the content of a page, a "meta-refresh" method to reload the content of the page can prevent users from having full access to the content. Try to use a "refresh this" link instead..',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Because different users have different speeds and abilities when it comes to parsing the content of a page, a "meta-refresh" method to reload the content of the page can prevent users from having full access to the content. Try to use a "refresh this" link instead..</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['documentTitleIsNotPlaceholder'] = (object)array(
  'language' => 'en',
  'name' => 'The document title should not be placeholder text',
  'quail_name' => 'documentTitleIsNotPlaceholder',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The document title should not be wasted placeholder text which does not describe the page.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The document title should not be wasted placeholder text which does not describe the page.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['documentTitleNotEmpty'] = (object)array(
  'language' => 'en',
  'name' => 'The document should not have an empty title',
  'quail_name' => 'documentTitleNotEmpty',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The document should have a title element that is not white space',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The document should have a title element that is not white space</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['documentVisualListsAreMarkedUp'] = (object)array(
  'language' => 'en',
  'name' => 'Visual lists of items are marked using ordered or unordered lists',
  'quail_name' => 'documentVisualListsAreMarkedUp',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Use the ordered (<code>ol</code>.  or unordered (<code>ul</code>.  elements for lists of items, instead of just using new lines which start with numbers or characters to create a visual list.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Use the ordered (<code>ol</code>.  or unordered (<code>ul</code>.  elements for lists of items, instead of just using new lines which start with numbers or characters to create a visual list.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['embedHasAssociatedNoEmbed'] = (object)array(
  'language' => 'en',
  'name' => 'All "embed" elements have an associated "noembed" element',
  'quail_name' => 'embedHasAssociatedNoEmbed',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Because some users cannot use the <code>embed</code>. /code> element, provide alternative content in a <code>noembed</code>. /code> element.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Because some users cannot use the <code>embed</code>. /code&gt; element, provide alternative content in a <code>noembed</code>. /code&gt; element.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['fileHasLabel'] = (object)array(
  'language' => 'en',
  'name' => 'All "file" input elements have a corresponding label',
  'quail_name' => 'fileHasLabel',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'All <code>input</code>. /code> elements of type "file" should have a corresponding <code>label</code>. /code> element. Screen readers often enter a "form mode" where only label text is read aloud to the user',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>All <code>input</code>. /code&gt; elements of type "file" should have a corresponding <code>label</code>. /code&gt; element. Screen readers often enter a "form mode" where only label text is read aloud to the user</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['fontIsNotUsed'] = (object)array(
  'language' => 'en',
  'name' => 'Font" elements should not be used',
  'quail_name' => 'fontIsNotUsed',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The <code>basefont</code>. /code> tag is deprecated and should not be used. Investigate using stylesheets instead.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The <code>basefont</code>. /code&gt; tag is deprecated and should not be used. Investigate using stylesheets instead.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['framesHaveATitle'] = (object)array(
  'language' => 'en',
  'name' => 'All "frame" elements should have a "title" attribute',
  'quail_name' => 'framesHaveATitle',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Each <code>frame</code>. /code> elements should have a "title" attribute.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Each <code>frame</code>. /code&gt; elements should have a "title" attribute.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['headersHaveText'] = (object)array(
  'language' => 'en',
  'name' => 'All headers should contain readable text',
  'quail_name' => 'headersHaveText',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Users with screen readers use headings like the tabs <em>h1</em> to navigate the structure of a page. All headings should contain either text, or images with appropriate <em>alt</em> attributes.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Users with screen readers use headings like the tabs <em>h1</em> to navigate the structure of a page. All headings should contain either text, or images with appropriate <em>alt</em> attributes.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['iIsNotUsed'] = (object)array(
  'language' => 'en',
  'name' => 'The "i" (italic) element is not used',
  'quail_name' => 'iIsNotUsed',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The <code>i</code>. /code> (italic) element provides no emphasis for non-sighted readers. Use the <code>em</code>. /code> tag instead.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The <code>i</code>. /code&gt; (italic) element provides no emphasis for non-sighted readers. Use the <code>em</code>. /code&gt; tag instead.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['imgAltIsTooLong'] = (object)array(
  'language' => 'en',
  'name' => 'Image Alt text is short',
  'quail_name' => 'imgAltIsTooLong',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'All "alt" attributes for <code>img</code>. /code> elements should be clear and concise. "Alt" attributes over 100 characters long should be reviewed to see if they are too long.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>All "alt" attributes for <code>img</code>. /code&gt; elements should be clear and concise. "Alt" attributes over 100 characters long should be reviewed to see if they are too long.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['imgAltNotEmptyInAnchor'] = (object)array(
  'language' => 'en',
  'name' => 'An image within a link cannot have an empty "alt" attribute if there is no other text within the link',
  'quail_name' => 'imgAltNotEmptyInAnchor',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Any image that is within a link (an <code>a</code>. /code> element) that has no other text cannot have an empty or missing "alt" attribute.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Any image that is within a link (an <code>a</code>. /code&gt; element) that has no other text cannot have an empty or missing "alt" attribute.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['imgAltNotPlaceHolder'] = (object)array(
  'language' => 'en',
  'name' => 'Images should not have a simple placeholder text as an "alt" attribute',
  'quail_name' => 'imgAltNotPlaceHolder',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Any image that is not used decorativey or which is purely for layout purposes cannot have an "alt" attribute that consists solely of placeholders. Placeholders include:',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Any image that is not used decorativey or which is purely for layout purposes cannot have an "alt" attribute that consists solely of placeholders. Placeholders include:</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['imgGifNoFlicker'] = (object)array(
  'language' => 'en',
  'name' => 'Any animated GIF should not flicker',
  'quail_name' => 'imgGifNoFlicker',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Animated GIF files should not flicker with a frequency over 2 Hz and lower than 55 Hz. You can check the flicker rate of this GIF <a href="http://tools.webaccessibile.org/test/check.aspx">using an online tool</a>.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Animated GIF files should not flicker with a frequency over 2 Hz and lower than 55 Hz. You can check the flicker rate of this GIF <a href="http://tools.webaccessibile.org/test/check.aspx">using an online tool</a>.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['imgHasAlt'] = (object)array(
  'language' => 'en',
  'name' => 'Image elements must have an "alt" attribute',
  'quail_name' => 'imgHasAlt',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'All <code>img</code>. /code> elements must have an alt attribute',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>All <code>img</code>. /code&gt; elements must have an alt attribute</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['imgHasLongDesc'] = (object)array(
  'language' => 'en',
  'name' => 'A "longdesc" attribute is required for any image where additional information not in the "alt" attribute is required',
  'quail_name' => 'imgHasLongDesc',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Any image that has an "alt" attribute that does not fully convey the meaning of the image must have a "longdesc" attribute.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Any image that has an "alt" attribute that does not fully convey the meaning of the image must have a "longdesc" attribute.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['inputCheckboxRequiresFieldset'] = (object)array(
  'language' => 'en',
  'name' => 'Logical groups of check boxes should be grouped with a "fieldset',
  'quail_name' => 'inputCheckboxRequiresFieldset',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Related "checkbox" input fields should be grouped together using a <code>fieldset</code>.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Related "checkbox" input fields should be grouped together using a <code>fieldset</code>.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['inputElementsDontHaveAlt'] = (object)array(
  'language' => 'en',
  'name' => 'Input elements which are not images should not have an "alt" attribute',
  'quail_name' => 'inputElementsDontHaveAlt',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Because of inconsistencies in how user agents use the "alt" attribute',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Because of inconsistencies in how user agents use the "alt" attribute</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['inputImageAltIsNotPlaceholder'] = (object)array(
  'language' => 'en',
  'name' => 'All "input" elements with a type of "image" must have an "alt" attribute which is not placeholder text',
  'quail_name' => 'inputImageAltIsNotPlaceholder',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'All <code>input</code>. /code> elements with a type of "image" should have an "alt" attribute',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>All <code>input</code>. /code&gt; elements with a type of "image" should have an "alt" attribute</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['inputImageAltIsShort'] = (object)array(
  'language' => 'en',
  'name' => 'All "input" elements with a type of "image" must have an "alt" attribute which is as short as possible',
  'quail_name' => 'inputImageAltIsShort',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'All <code>input</code>. /code> elements with a type of "image" should have an "alt" attribute',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>All <code>input</code>. /code&gt; elements with a type of "image" should have an "alt" attribute</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['inputImageHasAlt'] = (object)array(
  'language' => 'en',
  'name' => 'All "input" elements with a type of "image" must have an "alt" attribute',
  'quail_name' => 'inputImageHasAlt',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'All <code>input</code>. /code> elements with a type of "image" should have an "alt" attribute.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>All <code>input</code>. /code&gt; elements with a type of "image" should have an "alt" attribute.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['inputTextHasLabel'] = (object)array(
  'language' => 'en',
  'name' => 'All "input" elements should have a corresponding "label',
  'quail_name' => 'inputTextHasLabel',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'All <code>input</code>. /code> elements should have a corresponding <code>label</code>. /code> element. Screen readers often enter a "form mode" where only label text is read aloud to the user',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>All <code>input</code>. /code&gt; elements should have a corresponding <code>label</code>. /code&gt; element. Screen readers often enter a "form mode" where only label text is read aloud to the user</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['labelMustBeUnique'] = (object)array(
  'language' => 'en',
  'name' => 'Every form input must have only one label',
  'quail_name' => 'labelMustBeUnique',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Each form input should have only one <code>label</code>. /code> element.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Each form input should have only one <code>label</code>. /code&gt; element.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['labelMustNotBeEmpty'] = (object)array(
  'language' => 'en',
  'name' => 'Labels must contain text',
  'quail_name' => 'labelMustNotBeEmpty',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => '.. code-block:: html',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>.. code-block:: html</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['marqueeIsNotUsed'] = (object)array(
  'language' => 'en',
  'name' => 'The "marquee" tag should not be used',
  'quail_name' => 'marqueeIsNotUsed',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The <code>marquee</code>. /code> element is difficult for users to read and is not a standard HTML element. Try to find another way to convey the importance of this text.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The <code>marquee</code>. /code&gt; element is difficult for users to read and is not a standard HTML element. Try to find another way to convey the importance of this text.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['objectMustContainText'] = (object)array(
  'language' => 'en',
  'name' => 'Objects must contain their text equivalents',
  'quail_name' => 'objectMustContainText',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'All <code>object</code>. /code> elements should contain a text equivalent if the object cannot be rendered.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>All <code>object</code>. /code&gt; elements should contain a text equivalent if the object cannot be rendered.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['pNotUsedAsHeader'] = (object)array(
  'language' => 'en',
  'name' => 'Paragraphs must not be used for headers',
  'quail_name' => 'pNotUsedAsHeader',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Headers like <code>h1</code>. h6 are extremely useful for non-sighted users to navigate the structure of the page, and formatting a paragraph to just be big or bold, while it might visually look like a header, does not make it one.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Headers like <code>h1</code>. h6 are extremely useful for non-sighted users to navigate the structure of the page, and formatting a paragraph to just be big or bold, while it might visually look like a header, does not make it one.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['passwordHasLabel'] = (object)array(
  'language' => 'en',
  'name' => 'All password input elements should have a corresponding label',
  'quail_name' => 'passwordHasLabel',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'All <code>input</code>. /code> elements with a type of "password"should have a corresponding <code>label</code>. /code> element. Screen readers often enter a "form mode" where only label text is read aloud to the user',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>All <code>input</code>. /code&gt; elements with a type of "password"should have a corresponding <code>label</code>. /code&gt; element. Screen readers often enter a "form mode" where only label text is read aloud to the user</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['radioHasLabel'] = (object)array(
  'language' => 'en',
  'name' => 'All "radio" input elements have a corresponding label',
  'quail_name' => 'radioHasLabel',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'All <code>input</code>. /code> elements of type "radio" should have a corresponding <code>label</code>. /code> element. Screen readers often enter a "form mode" where only label text is read aloud to the user',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>All <code>input</code>. /code&gt; elements of type "radio" should have a corresponding <code>label</code>. /code&gt; element. Screen readers often enter a "form mode" where only label text is read aloud to the user</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['radioMarkedWithFieldgroupAndLegend'] = (object)array(
  'language' => 'en',
  'name' => 'All radio button groups are marked using fieldset and legend elements.',
  'quail_name' => 'radioMarkedWithFieldgroupAndLegend',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'form element content must contain both fieldset and legend elements if there are related radio buttons.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>form element content must contain both fieldset and legend elements if there are related radio buttons.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['scriptOndblclickRequiresOnKeypress'] = (object)array(
  'language' => 'en',
  'name' => 'Any element with an "ondblclick" attribute shoul have a keyboard-related action as well',
  'quail_name' => 'scriptOndblclickRequiresOnKeypress',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'If an element has an "ondblclick" attribute',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>If an element has an "ondblclick" attribute</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['scriptOnmousedownRequiresOnKeypress'] = (object)array(
  'language' => 'en',
  'name' => 'If an element has a "mousedown" attribute',
  'quail_name' => 'scriptOnmousedownRequiresOnKeypress',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'it should also have an "onkeydown" attribute',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>it should also have an "onkeydown" attribute</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['scriptOnmousemove'] = (object)array(
  'language' => 'en',
  'name' => 'Any element with an "onmousemove" attribute shoul have a keyboard-related action as well',
  'quail_name' => 'scriptOnmousemove',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'If an element has an "onmousemove" attribute',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>If an element has an "onmousemove" attribute</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['scriptOnmouseoutHasOnmouseblur'] = (object)array(
  'language' => 'en',
  'name' => 'If an element has a "onmouseout" attribute',
  'quail_name' => 'scriptOnmouseoutHasOnmouseblur',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'it should also have an "onblur" attribute',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>it should also have an "onblur" attribute</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['scriptOnmouseoverHasOnfocus'] = (object)array(
  'language' => 'en',
  'name' => 'If an element has an "onmouseover" attribute',
  'quail_name' => 'scriptOnmouseoverHasOnfocus',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'it should also have an "onfocus" attribute',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>it should also have an "onfocus" attribute</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['scriptOnmouseupHasOnkeyup'] = (object)array(
  'language' => 'en',
  'name' => 'If an element has an "onmouseup" attribute',
  'quail_name' => 'scriptOnmouseupHasOnkeyup',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'it should also have an "onkeyup" attribute',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>it should also have an "onkeyup" attribute</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['selectDoesNotChangeContext'] = (object)array(
  'language' => 'en',
  'name' => 'Select" elemetns must not contain an "onchange" attribute',
  'quail_name' => 'selectDoesNotChangeContext',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Actions like "onchange" can take control away from users who are trying to navigate the page. Using an "onchange" attribute for things like select-list menus should instead be replaced with a drop-down and a button which initiates the action.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Actions like "onchange" can take control away from users who are trying to navigate the page. Using an "onchange" attribute for things like select-list menus should instead be replaced with a drop-down and a button which initiates the action.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['selectHasAssociatedLabel'] = (object)array(
  'language' => 'en',
  'name' => 'All select elements have an explicitly associated label.',
  'quail_name' => 'selectHasAssociatedLabel',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'All <code>select</code>. /code> elements should have a corresponding <code>label</code>. /code> element. Screen readers often enter a "form mode" where only label text is read aloud to the user',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>All <code>select</code>. /code&gt; elements should have a corresponding <code>label</code>. /code&gt; element. Screen readers often enter a "form mode" where only label text is read aloud to the user</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['svgContainsTitle'] = (object)array(
  'language' => 'en',
  'name' => 'Inline SVG should use Title elements',
  'quail_name' => 'svgContainsTitle',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Any inline SVG image should have an embedded <code>title</code>. /code> element',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Any inline SVG image should have an embedded <code>title</code>. /code&gt; element</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['tableDataShouldHaveTh'] = (object)array(
  'language' => 'en',
  'name' => 'Data tables should contain "th" elements',
  'quail_name' => 'tableDataShouldHaveTh',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Tables which contain data (as opposed to layout tables) should contain <code>th</code>. /code> elements to mark headers for screen readers and enhance the structure of the document.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Tables which contain data (as opposed to layout tables) should contain <code>th</code>. /code&gt; elements to mark headers for screen readers and enhance the structure of the document.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['tableLayoutHasNoCaption'] = (object)array(
  'language' => 'en',
  'name' => 'All tables used for layout have no "caption" element',
  'quail_name' => 'tableLayoutHasNoCaption',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'If a table contains no data, and is used simply for layout, then it should not contain a <code>caption</code>. /code> element.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>If a table contains no data, and is used simply for layout, then it should not contain a <code>caption</code>. /code&gt; element.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['tableSummaryDoesNotDuplicateCaption'] = (object)array(
  'language' => 'en',
  'name' => 'Table "summary" elements should not duplicate the "caption" element',
  'quail_name' => 'tableSummaryDoesNotDuplicateCaption',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'The summary and the caption must be different, as both provide different information. A <code>caption</code>. /code element identifies the table., while the "summary" attribute describes the table contents.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>The summary and the caption must be different, as both provide different information. A <code>caption</code>. /code element identifies the table., while the "summary" attribute describes the table contents.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['tableUsesCaption'] = (object)array(
  'language' => 'en',
  'name' => 'Data tables should contain a "caption" element if not described elsewhere',
  'quail_name' => 'tableUsesCaption',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'Unless otherwise described in the document, tables should contain <code>caption</code>. /code> elements to describe the purpose of the table.',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>Unless otherwise described in the document, tables should contain <code>caption</code>. /code&gt; elements to describe the purpose of the table.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
$accessibility_tests['textareaHasAssociatedLabel'] = (object)array(
  'language' => 'en',
  'name' => 'All textareas should have a corresponding label',
  'quail_name' => 'textareaHasAssociatedLabel',
  'severity' => 'severe',
  'status' => 1,
  'data' => array(),
  'error_description' => array(
    'und' => array(
      0 => array(
        'value' => 'All <code>textarea</code>. /code> elements should have a corresponding <code>label</code>. /code> element. Screen readers often enter a "form mode" where only label text is read aloud to the user',
        'summary' => NULL,
        'format' => 'full_html',
        'safe_value' => '<p>All <code>textarea</code>. /code&gt; elements should have a corresponding <code>label</code>. /code&gt; element. Screen readers often enter a "form mode" where only label text is read aloud to the user</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
);
return $accessibility_tests;
}
