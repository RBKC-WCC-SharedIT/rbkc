<?php


// adding classes for footer menu links
function rbkc_menu_tree__menu_footer_links($variables) {
  return '<ul class="footerglobal__links lightlinks">' . $variables['tree'] . '</ul>';
}



// splitting service menu link into three
/*function rbkc_menu_tree__menu_drop_down_service_menu($variables) {

	$htmlString = $variables['tree'];
	$arrayItems = explode("</li>", $htmlString);
	$numEachMenu = floor(count($arrayItems)/3);
	$arrayItems = array_chunk($arrayItems, $numEachMenu);
	$arrayItems1 = implode($arrayItems[0]);
	$arrayItems2 = implode($arrayItems[1]);
	$arrayItems3 = implode($arrayItems[2]);

	return '<ul>'. $arrayItems1 .'</ul><ul>' . $arrayItems2 . '</ul><ul>' . $arrayItems3 . '</ul>';
}*/


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
