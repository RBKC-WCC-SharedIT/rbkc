<?php


// adding classes for footer menu links
function rbkc_menu_tree__menu_footer_links($variables) {
  return '<ul class="footerglobal__links lightlinks">' . $variables['tree'] . '</ul>';
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
 * Implements template_preprocess_field().  - this is so that we can style the markup and output of specific fields
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
 * access fields - they are available deeply nested in the $page variable so we use a preprocess funtion for easier access https://www.drupal.org/node/950434
 */

/*function hook_preprocess_page(&$variables) {
        if (arg(0) == 'node') {
                $variables['node_content'] =& $variables['page']['content']['system_main']['nodes'][arg(1)];
        }
}*/



//  this is so that we can style how content appears when it's pulled through onto other pages
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