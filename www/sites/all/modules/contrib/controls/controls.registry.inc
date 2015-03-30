<?php
/**
 * @file
 * Controls - Central control gets data about different sections then passes it out as needed.
 *
 * Drupal 6 version
 *
 * This is a kind of lightweight version of the CTools plugin system
 */

/**
 * Implementation of hook_perm().
 */
function _controls_perm() {
  $perms = array();
  foreach (controls_get() as $control_group => $controls) {
    foreach ($controls as $name => $control) {
      if (isset($control['#permission']) && $control['#permission']) {
        $args = array(
          '[cg]' => $control_group,
          '[c]' => $name,
          '[ctitle]' => drupal_strtolower($control['title']),
        );
        $perms[] = t(CONTROLS_PERM_TITLE_TEMPLATE, $args); // defined in .module file
      }
    };
  }
  return $perms;
}

function _controls_fetch() {

  // Load any available [module].controls.inc files
  controls_include();

  // Fetch the raw control data
  $raw = module_invoke_all('controls_info');
  if (!isset($raw)) {
    $raw = array();
  }

  // Allow modules to modify the raw control data
  drupal_alter('controls_info', $raw);

  // Now we process the whole thing to group each control
  // and, if the control requires perm, only include
  // it if the user's roles have perm.
  $controls = array();
  foreach ($raw as $module => $control_groups) {
    $args = array();
    foreach ($control_groups as $group_name => $control_group) {
      // Set this up as an empty array, in case there are no
      // allowed controls for this user.
      if (!isset($controls[$group_name])) {
        $controls[$group_name] = array();
      }
      // Start building the argument array for perm substitution
      $args['[cg]'] = $group_name;
      foreach ($control_group as $name => $control) {
        $args['[c]'] = $name;
        $args['[ctitle]'] = drupal_strtolower($control['title']);
        // Check whether this user is allowed to see this control
        if (isset($control['#permission']) && $control['#permission']) {
          // This control does require a permission
          if (!user_access(t(CONTROLS_PERM_TITLE_TEMPLATE, $args))) {
            // This user doesn't have it, so skip to next.
            continue;
          }
        }

        // Set up the default values for the control
        $control += array(
          '#control_group' => $group_name,
          '#name' => $name,
          '#module' => $module,
          '#default_file' => array('inc', $module, "$module.controls"),
          '#callbacks' => array(),
        );

        $controls[$group_name][$name] = $control;
      }
    }
  }


  return $controls;
}

/**
 * General function to include the files that controls relies on for the real work.
 */
function controls_include() {
  static $loaded = FALSE;

  if (!$loaded) {
    foreach (array_keys(module_list(FALSE, FALSE)) as $module) {
      module_load_include('controls.inc', $module);
    }
    $loaded = TRUE;
  }
}

