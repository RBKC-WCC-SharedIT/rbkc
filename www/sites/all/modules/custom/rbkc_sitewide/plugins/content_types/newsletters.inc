<?php

$plugin = array(
  'single' => FALSE,
  'title' => t('Newsletters'),
  'description' => t('Configurable Newsletters content block'),
  'category' => t('RBKC'),
  'edit form' => 'rbkc_newsletters_edit_form',
  'render callback' => 'rbkc_newsletters_render',
  'admin info' => 'rbkc_newsletters_admin_info',
  'defaults' => array(
    'intro' => '',
  )
);

/**
 * 'admin info' callback for panel pane.
 */
function rbkc_newsletters_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
    $block->content = '';
    return $block;
  }
}

/**
 * 'Edit form' callback for the content type.
 */
function rbkc_newsletters_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;
  $form['names_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('People coming to the picnic'),
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix' => '<div id="names-fieldset-wrapper">',
    '#suffix' => '</div>',
  );

  // Build the fieldset with the proper number of names. We'll use
  // $form_state['num_names'] to determine the number of textfields to build.
  if (empty($form_state['num_names'])) {
    $form_state['num_names'] = 1;
  }
  for ($i = 0; $i < $form_state['num_names']; $i++) {
    $form['names_fieldset']['name'][$i] = array(
      '#type' => 'textfield',
      '#title' => t('Name'),
    );
  }
  $form['names_fieldset']['add_name'] = array(
    '#type' => 'submit',
    '#value' => t('Add one more'),
    '#submit' => array('rbkc_newsletters_edit_form_add_one'),
    // See the examples in ajax_example.module for more details on the
    // properties of #ajax.
    '#ajax' => array(
      'callback' => 'rbkc_newsletters_edit_form_callback',
      'wrapper' => 'names-fieldset-wrapper',
    ),
  );
  if ($form_state['num_names'] > 1) {
    $form['names_fieldset']['remove_name'] = array(
      '#type' => 'submit',
      '#value' => t('Remove one'),
      '#submit' => array('rbkc_newsletters_edit_form_remove_one'),
      '#ajax' => array(
        'callback' => 'rbkc_newsletters_edit_form_callback',
        'wrapper' => 'names-fieldset-wrapper',
      ),
    );
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  // This simply allows us to demonstrate no-javascript use without
  // actually turning off javascript in the browser. Removing the #ajax
  // element turns off AJAX behaviors on that element and as a result
  // ajax.js doesn't get loaded.
  // For demonstration only! You don't need this.
  if ($no_js_use) {
    // Remove the #ajax from the above, so ajax.js won't be loaded.
    if (!empty($form['names_fieldset']['remove_name']['#ajax'])) {
      unset($form['names_fieldset']['remove_name']['#ajax']);
    }
    unset($form['names_fieldset']['add_name']['#ajax']);
  }

  return $form;
}

/**
 * Callback for both ajax-enabled buttons.
 *
 * Selects and returns the fieldset with the names in it.
 */
function rbkc_newsletters_edit_form_callback($form, $form_state) {
  return $form['names_fieldset'];
}

/**
 * Submit handler for the "add-one-more" button.
 *
 * Increments the max counter and causes a rebuild.
 */
function rbkc_newsletters_edit_form_add_one($form, &$form_state) {
  //var_dump($form_state['num_names']);
  $form_state['num_names']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for the "remove one" button.
 *
 * Decrements the max counter and causes a form rebuild.
 */
function rbkc_newsletters_edit_form_remove_one($form, &$form_state) {
  if ($form_state['num_names'] > 1) {
    $form_state['num_names']--;
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Final submit handler.
 *
 * Reports what values were finally set.
 */
function rbkc_newsletters_edit_form_submit($form, &$form_state) {
  $output = t('These people are coming to the picnic: @names',
    array(
      '@names' => implode(', ', $form_state['values']['names_fieldset']['name']),
    )
  );
  drupal_set_message($output);
}


/**
 * The submit form stores the data in $conf.
 */
//function rbkc_newsletters_edit_form_submit($form, &$form_state) {
//  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
//    if (isset($form_state['values'][$key])) {
//      $form_state['conf'][$key] = $form_state['values'][$key];
//    }
//  }
//}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function rbkc_newsletters_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  $block->title = '';
  $block->content = theme('rbkc_news_comms', array(
    'intro' => $conf['intro'],
    ));

  return $block;
}