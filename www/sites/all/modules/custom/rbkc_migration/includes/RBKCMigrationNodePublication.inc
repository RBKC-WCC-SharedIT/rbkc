<?php

/**
 * Class RBKCMigrationNodePublication
 *
 * This is a two pass migration.
 *
 * This class migrates publication parent and children pages but does not
 * associate the children with the parents.
 *
 * RBKCMigrationNodePublicationAssociateChildren should be run after this to
 * form the associations.
 */
class RBKCMigrationNodePublication extends RBKCBaseNodeMigration {
  use RBKCMigrationCommon;
  use RBKCMigrationHandleRedirect;

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import of publication parent and child pages.');
    $this->dependencies = array('RBKCMigrationSourceContentCSV', 'RBKCMigrationSourceDocumentsCSV');

    $source = drupal_get_path('module', 'rbkc_migration') . DIRECTORY_SEPARATOR . 'data' . DIRECTORY_SEPARATOR . 'RBKCSource' . 'Publication' . '.csv';
    $columns = array();
    $options = array(
      'enclosure' => '$',
      'delimiter' => ',',
      'header_rows' => 1,
      'embedded_newlines' => TRUE,
    );
    $this->source = new MigrateSourceCSV($source, $columns, $options);

    $destination = 'publication';
    $this->destination = new MigrateDestinationNode($destination);

    $this->addFieldMapping('body','body_html');
    $this->addFieldMapping('body:summary','body:summary');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('body:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('field_service_hub', 'path')->callbacks(array(self, 'callbackResolveServiceHubTerm'));
    $this->addFieldMapping('field_short_title', 'field_short_title');
    $this->addFieldMapping('field_short_title:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('metatag_title', 'metatag_title');
    $this->addFieldMapping('metatag_description', 'metatag_description');
    $this->addFieldMapping('metatag_keywords', 'metatag_keywords');
    $this->addFieldMapping('created', 'created')->callbacks(array(self, 'callbackTransformCreatedDate'));
    $this->addFieldMapping('book', 'book');
    $this->addFieldMapping('language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('pathauto')->defaultValue(1);
  }

  public function prepareRow($row) {
    if (FALSE == parent::prepareRow($row)) {
      return FALSE;
    }

    $row->body_html = self::extractNodeFromXML($row->body, 'contentsbox');
    $row->body_html = $this->transformSourceLinkTokens($row->body_html);
    $row->body_html = $this->transformSourceDocumentTokens($row->body_html);
    $row->body_html = $this->transformClasses($row->body_html);

    self::setBookIdIfParent($row);

    return TRUE;
  }

  protected static function setBookIdIfParent(stdClass $row) {
    if (self::isBookParent($row)) {
      $row->book = array('bid' => 'new');
    }
  }

  protected static function isBookParent($row) {
    if ('rf-pub-parent' === $row->template) {
      return TRUE;
    }

    return FALSE;
  }
}