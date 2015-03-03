<?php


// adding classes for footer menu links
function rbkc_menu_tree__menu_footer_links($variables) {
  return '<ul class="footerglobal__links lightlinks">' . $variables['tree'] . '</ul>';
}


function rbkc_preprocess_node(&$vars) {
  if($vars['view_mode'] == 'teaser') {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__teaser';
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__teaser';
  }
}

// removing 'leaf' classes from menus
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
 * Override menu link variables.
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
 * Override menu tree variables.
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

//  // Get the menu link id (mlid) of the tip of the active menu trail.
//  $active_trail = menu_get_active_trail();
//  $active_tip = array_pop($active_trail);
//  $active_tip_mlid = $active_tip['mlid'];
//
//  // Compare this against the menu link we're processing.
//  if ($active_tip_mlid === $variables['element']['#original_link']['mlid']) {
//    $variables['element']['#attributes']['class'][] = 'active';
//  }

  $element = $variables['element'];

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";
}