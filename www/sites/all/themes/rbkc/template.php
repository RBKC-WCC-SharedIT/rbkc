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

  $element = $variables['element'];

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";
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
  if($vars['view_mode'] == 'teaser') {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__teaser';
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__teaser';
  }
  if($vars['view_mode'] == 'top_three_topics') {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__top';
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__top';
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

function rbkc_css_alter(&$css) {
  $exclude = array(
    'modules/system/system.menus.css' => FALSE,
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
