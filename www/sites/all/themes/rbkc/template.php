<?php

/**
 * Adding classes for footer menu links.
 *
 * @param type $variables
 *
 * @return type
 */
function rbkc_menu_tree__menu_footer_links($variables) {
  return '<ul class="footerglobal__links lightlinks">' . $variables['tree'] . '</ul>';
}

/**
 * Removing 'leaf' classes from menus.
 *
 * @param type $variables
 *
 * @return type
 */
function rbkc_menu_link__menu_footer_links($variables) {
	foreach ($variables['element']['#attributes']['class'] as $index => $class) {
		if ('leaf' == $class) {
			unset($variables['element']['#attributes']['class'][$index]);
		}
	}

	$element = $variables['element'];
	$sub_menu = '';

	if ($element['#below']) {
		$sub_menu = drupal_render($element['#below']);
	}

	$output = l($element['#title'], $element['#href'],
	$element['#localized_options']);

	return '<li' . drupal_attributes($element['#attributes']) . '>' .
	$output . $sub_menu . "</li>\n";

}

/**
 * Override theme_menu_link for the drop down service menu.
 *
 * @param type $variables
 *
 * @return type
 */
function rbkc_menu_link__menu_drop_down_service_menu($variables) {
	foreach ($variables['element']['#attributes']['class'] as $index => $class) {
		if ('leaf' == $class) {
			unset($variables['element']['#attributes']['class'][$index]);
		}
	}

	$element = $variables['element'];
	$sub_menu = '';

	if ($element['#below']) {
		$sub_menu = drupal_render($element['#below']);
	}

	$output = l($element['#title'], $element['#href'],
	$element['#localized_options']);

	return '<li' . drupal_attributes($element['#attributes']) . '>' .
	$output . $sub_menu . "</li>\n";

}

/**
 * Add class to menu ul.
 */
function rbkc_menu_tree__drop_down_service_menu($variables) {
  return '<ul class="servicelist__list-one">' . $variables['tree'] . '</ul>';
}

/**
 * Add class to menu ul.
 */
function rbkc_menu_tree__menu_i_need_to($variables) {
  return '<ul class="quicklinks__list-one">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_link
 */
function rbkc_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  $element['#localized_options']['html'] = TRUE;

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  if (!empty($element['#attributes']['class'])) {
    foreach ($element['#attributes']['class'] as $key => $class) {
      if ($class == 'first') {
        // To remove the last class.
        unset($element['#attributes']['class'][$key]);
      }
      if ($class == 'last') {
        // To remove the last class.
        unset($element['#attributes']['class'][$key]);
      }
    }
  }

  /**
   * Add menu item's description below the menu title
   */
  if ($element['#original_link']['menu_name'] == "drop-down-service-menu" && isset($element['#localized_options']['attributes']['title'])){
    $element['#title'] .= '<span class="servicelist__desc">' . $element['#localized_options']['attributes']['title'] . '</span>';
  }
  if ($element['#original_link']['menu_name'] == "menu-i-need-to" && isset($element['#localized_options']['attributes']['title'])){
    unset($element['#attributes']['class']);
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Override theme_menu_link for the publication table of contents.
 *
 * @param $variables
 *
 * @return string
 */
function rbkc_menu_link__book_toc_publication(&$variables) {
  // Remove all classes from book menu links.
  unset($variables['element']['#attributes']['class']);

  // Get the menu link id (mlid) of the tip of the active menu trail.
  $active_trail = menu_get_active_trail();
  $active_tip = array_pop($active_trail);
  $active_tip_mlid = $active_tip['mlid'];

  // Compare this against the menu link we're processing.
  if ($active_tip_mlid === $variables['element']['#original_link']['mlid']) {
    $variables['element']['#attributes']['class'][] = 'active';
  }

  $element = $variables['element'];

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";
}


/**
 * Override theme_menu_tree variables.
 */
function rbkc_preprocess_menu_tree(&$variables) {
  // Add theme suggestions for guide and publication menus.
  switch ($variables['theme_hook_original']) {
    case 'menu_tree__book_toc_guide':
      $variables['theme_hook_suggestions'][] = 'menu_tree__book_guide';
      break;

    case 'menu_tree__book_toc_publication':
      $variables['theme_hook_suggestions'][] = 'menu_tree__book_publication';
      break;
  }
}

/**
 * Guide table of contents menu theme function.
 */
function rbkc_menu_tree__book_toc_guide_left(&$variables) {
  return '<ol class="toc__numlist floatleft">' . $variables['tree'] . '</ol>';
}

/**
 * Guide table of contents menu theme function.
 */
function rbkc_menu_tree__book_toc_guide_right(&$variables) {
  $start = str_replace('menu_tree__book_toc_guide_right__', '', $variables['theme_hook_original']);
  return '<ol class="toc__numlist floatright" start="' . $start . '">' . $variables['tree'] . '</ol>';
}

/**
 * Publication table of contents menu theme function.
 */
function rbkc_menu_tree__book_toc_publication(&$variables) {
  return '<ul class="toc__chapter-list">' . $variables['tree'] . '</ul>';
}

/**
 * Override menu link variables.
 *
 * @param array $variables
 *
 * @return string
 */
function rbkc_menu_link__book_toc_guide(array $variables) {
  // Remove all classes from book menu links.
  unset($variables['element']['#attributes']['class']);

  // Get the menu link id (mlid) of the tip of the active menu trail.
  $active_trail = menu_get_active_trail();
  $active_tip = array_pop($active_trail);
  $active_tip_mlid = $active_tip['mlid'];

  $element = $variables['element'];

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  // Compare this against the menu link we're processing.
  if ($active_tip_mlid === $variables['element']['#original_link']['mlid']) {
    $retStr = '<li class="active"' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";
  }

  else {
    $retStr = '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";
  }

  return $retStr;
}

/**
 * Implements template_preprocess_node().
 *
 * This is so that we can style how content appears when it's pulled through
 * onto other pages.
 *
 * @param type $vars
 */
function rbkc_preprocess_node(&$vars) {
  if ($vars['view_mode'] == 'teaser') {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__teaser';
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__teaser';
  }

  if ($vars['view_mode'] == 'top_three_topics') {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__top';
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__top';
  }

  if ($vars['view_mode'] == 'link_field') {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__link';
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__link';
  }
}

/**
 * Returns HTML for a link to a file.
 *
 * @param $variables
 *   An associative array containing:
 *   - file: A file object to which the link will be created.
 *   - icon_directory: (optional) A path to a directory of icons to be used for
 *     files. Defaults to the value of the "file_icon_directory" variable.
 *
 * @ingroup themeable
 */
function rbkc_file_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $url = file_create_url($file->uri);
  $icon = theme('file_icon', array('file' => $file, 'icon_directory' => $icon_directory));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
    ),
  );

  // Use the description as the link text if available.
  if (empty($file->description)) {
    $link_text = $file->filename;
  }
  else {
    $link_text = $file->description;
    $options['attributes']['title'] = check_plain($file->filename);
  }

  return '<span class="file">' . $icon . ' ' . l($link_text, $url, $options) . '</span>';
}

/**
 * Returns HTML for an image with an appropriate icon for the given file.
 *
 * @param $variables
 *   An associative array containing:
 *   - file: A file object for which to make an icon.
 *   - icon_directory: (optional) A path to a directory of icons to be used for
 *     files. Defaults to the value of the "file_icon_directory" variable.
 *
 * @ingroup themeable
 */
function rbkc_file_icon($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $mime = check_plain($file->filemime);
  $icon_url = file_icon_url($file, $icon_directory);
  return '<img class="file-icon" alt="" title="' . $mime . '" src="' . $icon_url . '" />';
}

/**
 * Implements hook_css_alter().
 */
function rbkc_css_alter(&$css) {
  $exclude = array(
    'modules/system/system.menus.css' => FALSE,
    'sites/all/modules/contrib/scald/modules/library/dnd/css/editor-global.css' => FALSE,
  );
  $css = array_diff_key($css, $exclude);
}

/**
 * Implements hook_form_FORMID_alter().
 * See https://api.drupal.org/api/drupal/modules%21system%21system.api.php/function/hook_form_FORM_ID_alter/7
 */
function rbkc_form_google_appliance_block_form_alter(&$form, &$form_state) {
  // Add placeholder text to the Google Appliance search form.
  $form['search_keys']['#attributes']['placeholder'] = t('Enter search terms…');
}


/**
 * Implements template_preprocess_field().
 */
function rbkc_preprocess_field(&$variables, $hook) {
  $element = $variables['element'];

  if (!isset($element['#field_name'])) {
    return;
  }

  if ('field_popular_tasks' !== $element['#field_name']) {
    return;
  }

  if (!empty($variables['items'][0])) {
    $variables['items'][0]['#element']['attributes']['class'] = 'first';
  }

  $last_index = (count($variables['items'])) - 1;
  if (!empty($variables['items'][$last_index])) {
    $variables['items'][$last_index]['#element']['attributes']['class'] = 'last';
  }
}

function rbkc_mee_widget_embed($vars) {
  $classes = array('dnd-widget-wrapper', 'context-' . $vars['context'], 'type-' . $vars['atom']->type);

  if ('right' !== $vars['align'] && 'image_with_caption' === $vars['context']) {
    $vars['align'] = 'left';
  }

  if ($vars['align'] != 'none') {
    $classes[] = 'atom-align-' . $vars['align'];
  }

  if ('image_without_caption' === $vars['context'] && 'none' !== $vars['align']) {
    $classes[] = 'float' . $vars['align'];
  }


  $caption = '';
  if ($vars['caption'] || $vars['wysiwyg']) {
    // Note: The 'dnd-caption-wrapper' class is used by the CKEditor plugin to
    // identify the editable zone and should not be modified by theme overrides.
    $caption = '<div class="image-cap__text dnd-caption-wrapper">' . $vars['caption'] . '</div>';
  }

  $prefix = '';
  $suffix = '';
  if ('image_with_caption' === $vars['context']) {
    $prefix = '<div class="image-cap dnd-atom-wrapper type-image context-full" contenteditable="false"><div class="image-cap__pic float' . $vars['align'] . '">';
    $suffix = '</div>' . $caption . '</div>';
  }

  $output = '<div class="' . implode(' ', $classes) . '">';

  $output .= '<div class="dnd-atom-rendered">' . $prefix . $vars['content'] . $suffix . '</div>';

  $output .= '</div>';

  return $output;
}

function rbkc_print_pdf_tcpdf_content($vars) {
  $pdf = $vars['pdf'];
  // set content font
  $pdf->setFont($vars['font'][0], $vars['font'][1], $vars['font'][2]);

  // Remove the logo, published, breadcrumb and footer from the main content - and also rbkc webchat
  preg_match('!<body.*?>(.*)</body>!sim', $vars['html'], $matches);
  $pattern = '!(?:<div class="print-(?:logo|site_name|breadcrumb|footer)">.*?</div>|<hr class="print-hr" />|<div id="webchatplanning">.*?</div>)!si';
  $matches[1] = preg_replace($pattern, '', $matches[1]);

  // Make CCK fields look better
  $matches[1] = preg_replace('!(<div class="field.*?>)\s*!sm', '$1', $matches[1]);
  $matches[1] = preg_replace('!(<div class="field.*?>.*?</div>)\s*!sm', '$1', $matches[1]);
  $matches[1] = preg_replace('!<div( class="field-label.*?>.*?)</div>!sm', '<strong$1</strong>', $matches[1]);

  // Since TCPDF's writeHTML is so bad with <p>, do everything possible to make it look nice
  $matches[1] = preg_replace('!<(?:p(|\s+.*?)/?|/p)>!i', '<br$1 />', $matches[1]);
  $matches[1] = str_replace(array('<div', 'div>'), array('<span', 'span><br />'), $matches[1]);
  do {
    $prev = $matches[1];
    $matches[1] = preg_replace('!(</span>)<br />(\s*?</span><br />)!s', '$1$2', $matches[1]);
  } while ($prev != $matches[1]);

  // add line break after table caption to prevent table going off the page
  $matches[1] = str_replace('</caption>', '</caption><br /><br />', $matches[1]);

  @$pdf->writeHTML($matches[1]);

  return $pdf;
}
