<?php

/**
 * Class RBKCMigrationNodeTopic
 *
 * This is a two pass migration.
 *
 * This migration migrates the topic pages that have XML in two main nodes:
 * content (body) and topictext (the internal and external links).
 *
 * The RBKCMigrationNodeTopicFieldTopicLink field collection migration needs to
 * be run afterwards.
 */
class RBKCMigrationNodeTopic extends RBKCBaseNodeMigration {
  use RBKCMigrationCommon;
  use RBKCMigrationHandleRedirect;

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import of topic content.');
    $this->dependencies = array('RBKCMigrationSourceContentCSV', 'RBKCMigrationSourceDocumentsCSV');

    $source = drupal_get_path('module', 'rbkc_migration') . DIRECTORY_SEPARATOR . 'data' . DIRECTORY_SEPARATOR . 'RBKCSource' . 'Topic' . '.csv';
    $columns = array();
    $options = array(
      'enclosure' => '$',
      'delimiter' => ',',
      'header_rows' => 1,
      'embedded_newlines' => TRUE,
    );
    $this->source = new MigrateSourceCSV($source, $columns, $options);

    $destination = 'topic';
    $this->destination = new MigrateDestinationNode($destination);

    $this->addFieldMapping('body', 'body_html');
    $this->addFieldMapping('body:summary', 'body:summary');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('body:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('field_service_hub', 'path')->callbacks(array(self, 'callbackResolveservicehubterm'));
    $this->addFieldMapping('field_short_title', 'field_short_title');
    $this->addFieldMapping('field_short_title:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('metatag_title', 'metatag_title');
    $this->addFieldMapping('metatag_description', 'metatag_description');
    $this->addFieldMapping('metatag_keywords', 'metatag_keywords');
    $this->addFieldMapping('created', 'created')->callbacks(array(self, 'callbackTransformcreateddate'));
    $this->addFieldMapping('language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('pathauto')->defaultValue(1);
  }

  public function prepareRow($row) {
    if (FALSE == parent::prepareRow($row)) {
      return FALSE;
    }

    $row->body_html = self::extractNodeFromXML($row->body, 'content');
    $row->body_html = $this->transformSourceLinkTokens($row->body_html);
    $row->body_html = $this->transformSourceDocumentTokens($row->body_html);
    $row->body_html = $this->transformClasses($row->body_html);

    return TRUE;
  }
}