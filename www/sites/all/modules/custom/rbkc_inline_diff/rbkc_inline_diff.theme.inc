<?php

function theme_rbkc_inline_diff_view($vars) {
	$output = '';

	// links
	$output .= '<div id="toggle">';
	$output .= '<span class="toggle_link">'.l(t('Final with markup'), '', array('attributes' => array('id' => 'toggle_link_finalwithmarkup'))).'</span>';
	$output .= '<span class="toggle_link">'.l(t('Final'), '', array('attributes' => array('id' => 'toggle_link_final'))).'</span>';
	$output .= '<div>';

	// content
  $output .= '<div class="content">'; 
	$output .= '<div id="content_difference"><h1>'.t('Final with markup').'</h1>'.'<p>Title: '.$vars['difference_title'].'</p>'.$vars['difference']. '</div>';
	$output .= '<div id="content_new" style="display:none"><h1>'.t('Final').'</h1>'.'<p>Title: '.$vars['new_title'].'</p>'.$vars['new'].'</div>';
  $output .= '</div> <!-- div.content -->';

	return $output;
}

/**
 * Theme function to display the revisions formular. Copied from
 * diff.theme.inc in diff module, and added a link to the Inline Diff view
 * into the header, next to the Compare button
 */
function theme_rbkc_inline_diff_diff_node_revisions($vars) {
  $form = $vars['form'];
  $output = '';

  // Overview table:
  $header = array(
    t('Revision'),
    array('data' => drupal_render($form['submit']).' '.drupal_render($form['submit_inline']), 'colspan' => 2),
    array('data' => t('Operations'), 'colspan' => 2),
  );
  if (isset($form['info']) && is_array($form['info'])) {
    foreach (element_children($form['info']) as $key) {
      $row = array();
      if (isset($form['operations'][$key][0])) {
        // Note: even if the commands for revert and delete are not permitted,
        // the array is not empty since we set a dummy in this case.
        $row[] = drupal_render($form['info'][$key]);
        $row[] = drupal_render($form['diff']['old'][$key]);
        $row[] = drupal_render($form['diff']['new'][$key]);
        $row[] = drupal_render($form['operations'][$key][0]);
        $row[] = drupal_render($form['operations'][$key][1]);
        $rows[] = array(
          'data' => $row,
          'class' => array('diff-revision'),
        );
      }
      else {
        // The current revision (no commands to revert or delete).
        $row[] = array(
          'data' => drupal_render($form['info'][$key]),
          'class' => array('revision-current'),
        );
        $row[] = array(
          'data' => drupal_render($form['diff']['old'][$key]),
          'class' => array('revision-current'),
        );
        $row[] = array(
          'data' => drupal_render($form['diff']['new'][$key]),
          'class' => array('revision-current'),
        );
        $row[] = array(
          'data' => t('current revision'),
          'class' => array('revision-current'),
          'colspan' => '2',
        );
        $rows[] = array(
          'data' => $row,
          'class' => array('error diff-revision'),
        );
      }
    }
  }
  $output .= theme('table__diff__revisions', array(
    'header' => $header,
    'rows' => $rows,
    'sticky' => FALSE,
    'attributes' => array('class' => 'diff-revisions'),
  ));

  $output .= drupal_render_children($form);
  return $output;
}
