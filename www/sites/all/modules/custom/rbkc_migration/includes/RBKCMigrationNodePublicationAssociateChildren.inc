<?php

/**
 * Class RBKCMigrationNodePublicationAssociateChildren
 *
 * RBKCMigrationNodePublication migrates all publication pages, this migration
 * is a helper that should be run after to associated child book publication
 * pages with their parent book node.
 */
class RBKCMigrationNodePublicationAssociateChildren extends RBKCBaseMigration {
  use RBKCMigrationCommon;

  private $children = array();

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->systemOfRecord = migration::DESTINATION;

    $this->description = t('Iterate over publication parent pages and associate their children.');
    $this->dependencies = array('RBKCMigrationSourceContentCSV', 'RBKCMigrationSourceDocumentsCSV', 'RBKCMigrationNodePublication');

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

    $weight = 1;
    foreach (array_keys($this->children) as $child_nid) {
      if ($parent_nid !== $child_nid) {
        self::setParent($child_nid, $parent_nid, $weight);
        $weight++;
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
        $this->children[$nid] = $page_id;
      }
    }

    $updated_child_count = count($this->children);

    if ($updated_child_count !== $current_child_count) {
      $child = end($this->children);

      $body = db_select('rbkc_migration_content', 's')
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

  public static function setParent($child_nid, $parent_nid, $weight) {
    $node = node_load($child_nid);
    $node->book['bid'] = $parent_nid;
    $node->book['weight'] = $weight;
    node_save($node);
  }
}