<?php

/**
 * @file
 * The RBKCMigrationNodePublication migrates all publication pages, this
 * migration is a helper that should be run after to associated child book
 * publication pages with their parent book node.
 */

/**
 * Class RBKCMigrationNodePublicationAssociateChildren
 */
class RBKCMigrationNodePublicationAssociateChildren extends Migration {
  private $children = array();

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->systemOfRecord = migration::DESTINATION;

    $this->description = t('Iterate over publication parent pages and associate their children.');

    $source = drupal_get_path('module', 'rbkc_migration') . '/data/RBKCFullPageTable.csv';
    $columns = array();
    $options = array(
      'enclosure' => '$',
      'delimiter' => ',',
      'header_rows' => 1,
      'embedded_newlines' => TRUE,
    );

    $this->source = new MigrateSourceCSV($source, $columns, $options);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'p_page_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'alias' => 'import'
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $destination = 'publication';
    $this->destination = new MigrateDestinationNode($destination);

    $this->addFieldMapping('nid', 'p_page_id')->sourceMigration('RBKCMigrationNodePublication');
  }

  public function prepareRow($row) {
    $row->template = trim($row->template);

    if ('rf-pub-parent' !== $row->template) {
      return FALSE;
    }

    if (FALSE == parent::prepareRow($row)) {
      return FALSE;
    }

    $this->associateChildren($row);

    return FALSE;
  }

  protected function associateChildren($row) {
    $parent_nid = self::lookupDestinationIDWrapper($row->p_page_id);

    if (FALSE === $parent_nid) {
      return;
    }

    $this->children = array();
    $this->gatherChildren($row->body, $parent_nid);
    reset($this->children);

    foreach (array_keys($this->children) as $child_nid) {
      if ($parent_nid !== $child_nid) {
        self::setParent($child_nid, $parent_nid);
      }
    }

    return;
  }

  protected function gatherChildren($body, $parent_nid) {
    $current_child_count = count($this->children);

    $pagination_html = self::extractNodeFromXML($body, 'paginationbox');

    if (empty($pagination_html)) {
      syslog(LOG_WARNING, 'Empty pagination data for page.');
      return;
    }

    $linked_page_ids = self::extractLinkedPageIDs($pagination_html);

    if (FALSE === $linked_page_ids) {
      return;
    }

    foreach ($linked_page_ids as $page_id) {
      if ($nid = self::lookupDestinationIDWrapper($page_id)) {
        syslog(LOG_WARNING, sprintf('Adding an entry into the children array, key (nid) is %s and page_id is %s', $parent_nid, $page_id));
        $this->children[$nid] = $page_id;
      }
    }

    $updated_child_count = count($this->children);

    if ($updated_child_count !== $current_child_count) {
      $child = end($this->children);

      $body = db_select('rbkc_migration_source', 's')
        ->fields('s', array('body'))
        ->condition('p_page_id', $child)
        ->execute()
        ->fetchField();

      if (FALSE === $body || empty($body)) {
        return;
      }

      return $this->gatherChildren($body, $parent_nid);
    }

    return;
  }

  protected static function extractLinkedPageIDs($html) {
    $modifiers = 'i';
    $delimiter = '/';
    $pattern = $delimiter . 'ILINK\|(\d+),(?:[,|_]{1}[a-zA-Z0-9_?,]+)?\|' . $delimiter . $modifiers;

    $link_count = preg_match_all($pattern, $html, $matches);

    if (1 !== $link_count && 2 !== $link_count) {
      syslog(LOG_WARNING, sprintf('Ambiguity encountered whilst migrating a publication page: The pagination data contained %d links for a page.', $link_count));
      return FALSE;
    }

    return $matches[1];
  }

  protected function lookupDestinationIDWrapper($p_page_id) {
    $migrations = migrate_migrations();
    $publication_migration = $migrations['RBKCMigrationNodePublication'];
    $map = $publication_migration->getMap();
    $result = $map->lookupDestinationID(array($p_page_id));
    if (is_null($result)) {
      syslog(LOG_WARNING, sprintf('Failed to find a destination nid for the ilink: %s whilst associating book children pages.', $p_page_id));
      return FALSE;
    }

    $nid = (int) $result['destid1'];
    return $nid;
  }

  public static function setParent($child_nid, $parent_nid) {
    $node = node_load($child_nid);
    $node->book['bid'] = $parent_nid;
    node_save($node);
  }

  public static function extractNodeFromXML($xml, $node) {
    $content = '';

    if (empty($xml)) {
      return $content;
    }

    try {
      $xml = new SimpleXMLElement($xml);
    }
    catch (Exception $e) {
      syslog(LOG_ERR, sprintf('Failed to load source XML as SimpleXMLElement when looking for %s: %s', $node, $e->getMessage()));
      return $content;
    }

    $content = (string) $xml->content->{$node};
    return $content;
  }
}