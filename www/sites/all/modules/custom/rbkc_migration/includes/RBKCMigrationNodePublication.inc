<?php

/**
 * @file
 *
 * Migrate publication parent and child pages.
 */

/**
 * Class RBKCMigrationNodePublication
 */
class RBKCMigrationNodePublication extends RBKCBaseNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import of publication parent and child pages.');

    $destination = 'publication';
    $this->destination = new MigrateDestinationNode($destination);

    $this->addFieldMapping('body','body_html');
    $this->addFieldMapping('body:summary','body:summary');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('body:language')->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('status', 'status');

    $this->addFieldMapping('field_service_hub', 'path')->callbacks(array(self, 'resolveServiceHubTerm'));

    $this->addFieldMapping('field_short_title', 'field_short_title');
    $this->addFieldMapping('field_short_title:language')->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('metatag_title', 'metatag_title');
    $this->addFieldMapping('metatag_description', 'metatag_description');
    $this->addFieldMapping('metatag_keywords', 'metatag_keywords');

    $this->addFieldMapping('created', 'created')->callbacks(array(self, 'transformCreatedDate'));

    $this->addFieldMapping('book', 'book');
  }

  public function prepareRow($row) {
    $row->template = trim($row->template);

    if ('rf-pub-parent' !== $row->template && 'rf-pub-child' !== $row->template) {
      return FALSE;
    }

    if (FALSE == parent::prepareRow($row)) {
      return FALSE;
    }

    $row->body_html = self::extractNodeFromXML($row->body, 'contentsbox');
    $row->body_html = $this->transformSourceLinkTokens($row->body_html);
    $row->body_html = $this->transformSourceDocumentTokens($row->body_html);

    $this->setBookIdIfParent($row);

    return TRUE;
  }

  public function complete(stdClass $node, stdClass $row) {
    // Parse the pagination HTML for links to previous/next pages.
    $pagination_html = self::extractNodeFromXML($row->body, 'paginationbox');

    if (empty($pagination_html)) {
      syslog(LOG_WARNING, sprintf('Empty pagination data for page %s', $row->p_page_id));
      return;
    }

    $modifiers = 'i';
    $delimiter = '/';
    $pattern = $delimiter . 'ILINK\|(\d+),(?:[,|_]{1}[a-zA-Z0-9_?,]+)?\|' . $delimiter . $modifiers;

    $link_count = preg_match_all($pattern, $pagination_html, $matches);

    if (1 !== $link_count && 2 !== $link_count) {
      syslog(LOG_WARNING, sprintf('Ambiguity encountered whilst migrating a publication page: The pagination data contained %d links for page %s.', $link_count, $row->p_page_id));
    }

    // If this is a child page, set the parent bid of this node.
    // If this is a parent page, set the parent bid on the ILINK'd nodes.
    $map = $this->getMap();
    if (self::isBookParent($row)) {
      // The rows contains a parent book page.
      foreach ($matches[1] as $ilink) {
        self::associateWithParent($ilink, $node, $map);
      }
    }
    else {
      // This row contains a child book page.

    }
  }

  protected static function associateWithParent($ilink, stdClass $node, MigrateMap $map) {
    if ($result = $map->lookupDestinationID(array($ilink))) {
      // We found an already migrated node for a child page.
      $nid = (int) $result['destid1'];
      if ($node->nid !== $nid) {
        $publication_node = node_load($nid);
        $publication_node->book['bid'] = $node->nid;
        node_save($publication_node);
      }
    }
    else {
      // This child page doesn't yet exist, create a stub.
      self::createNodeStub($ilink, array('book' => array('bid' => $node->nid)));
    }
  }

  /**
   * Checks if the row contains a parent book page and sets the bid accordingly.
   *
   * @param \stdClass $row
   */
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