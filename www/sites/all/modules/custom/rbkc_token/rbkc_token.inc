<?php


/**
 * Implements hook_entity_property_info_alter().
 */
function rbkc_token_entity_property_info_alter(&$info) {
  $info['node']['properties']['current-revision-author-mail'] = array(
    'label' => t('Revision author email'),
    'type' => 'text',
    'description' => t('The email of the author of the current revision of the node.'),
    'computed' => TRUE,
    'field' => FALSE,
  );
}


/**
 * Implements hook_tokens().
 */
function rbkc_token_tokens($type, $tokens, array $data = array(), array $options = array()) {

  if ($type == 'entity' && $data['entity_type'] == 'node') {
    $values = array ();
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'current-revision-author-mail':
          $node = $data['entity'];
          $account = user_load($node->revision_uid);
          $values[$original] = $account->mail;
          break;
      }
    }
    return $values;
  }
}

