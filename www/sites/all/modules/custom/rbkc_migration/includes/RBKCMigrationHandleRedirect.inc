<?php

/**
 * Class RBKCMigrationHandleRedirect
 */
trait RBKCMigrationHandleRedirect {
  public function handleRedirect($entity, stdClass $row) {
    if (!empty($row->path)) {
      $redirect = new stdClass();
      $url = $row->path;

      redirect_object_prepare($redirect, array(
        'source' => $url,
        'source_options' => array(),
        'redirect' => 'node/' . $entity->nid,
        'redirect_options' => array(),
        'language' => LANGUAGE_NONE,
      ));

      $alias = db_query('SELECT alias FROM {url_alias} WHERE source = :src_path', array(':src_path' => 'node/'. $entity->nid))->fetchField();

      if (FALSE === $alias) {
        redirect_save($redirect);
      }
    }
  }
}