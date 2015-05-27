<?php

/**
 * @file
 *
 * Migrate topic pages.
 */

/**
 * Class RBKCMigrationNodeTopic
 *
 * This migration migrates the topic pages that have XML in two main nodes:
 * content (body) and topictext (the internal and external links).
 */
class RBKCMigrationNodeTopic extends RBKCBaseNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import of topic content.');

    $destination = 'topic';
    $this->destination = new migratedestinationnode($destination);

    $this->addfieldmapping('body', 'body_html');
    $this->addfieldmapping('body:summary', 'body:summary');
    $this->addfieldmapping('body:format')->defaultvalue('full_html');
    $this->addfieldmapping('body:language')->defaultvalue(language_none);

    $this->addfieldmapping('status', 'status');

    $this->addfieldmapping('field_service_hub', 'path')->callbacks(array(self, 'resolveservicehubterm'));

    $this->addfieldmapping('field_short_title', 'field_short_title');
    $this->addfieldmapping('field_short_title:language')->defaultvalue(language_none);

    $this->addfieldmapping('metatag_title', 'metatag_title');
    $this->addfieldmapping('metatag_description', 'metatag_description');
    $this->addfieldmapping('metatag_keywords', 'metatag_keywords');

    $this->addfieldmapping('created', 'created')->callbacks(array(self, 'transformcreateddate'));

    // field_topic_link (field collection) http://rbkc.vm/admin/structure/field-collections/field-topic-link/fields
  }

  public function prepareRow($row) {
    $row->template = trim($row->template);
    if ('rf-topic-planning' !== $row->template) {
      return FALSE;
    }

    if (FALSE == parent::prepareRow($row)) {
      return FALSE;
    }

    $row->body_html = self::extractNodeFromXML($row->body, 'content');
    $row->body_html = $this->transformSourceLinkTokens($row->body_html);
    $row->body_html = $this->transformSourceDocumentTokens($row->body_html);
    self::processTopicText($row);
    return TRUE;
  }

  protected static function processTopicText($row) {
    $topic_text = self::extractNodeFromXML($row->body, 'topictext');
  }
}