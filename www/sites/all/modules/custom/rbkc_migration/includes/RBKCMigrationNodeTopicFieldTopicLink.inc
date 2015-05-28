<?php

/**
 * Field collection migration for the topic page migration.
 *
 * Class RBKCMigrationNodeTopicFieldTopicLink
 */

class RBKCMigrationNodeTopicFieldTopicLink extends Migration {
  use RBKCMigrationCommon;

  /**
   * Holds the DomCrawler - http://symfony.com/doc/current/components/dom_crawler.html
   * @var null
   */
  private $crawler = NULL;

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->initCrawler();

    $this->description = t('Migrate the internal and external topic links for the topic pages.');
    $this->dependencies = array('RBKCMigrationNodeTopic');

    $source = drupal_get_path('module', 'rbkc_migration') . '/data/RBKCFullPageTable.csv';
    $columns = array();
    $options = array(
      'enclosure' => '$',
      'delimiter' => ',',
      'header_rows' => 1,
      'embedded_newlines' => TRUE,
    );

    $this->source = new MigrateSourceCSV($source, $columns, $options);

    $source_key = array('p_page_id' => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE, 'alias' => 'import'));
    $destination_key = MigrateDestinationNode::getKeySchema();
    $this->map = new MigrateSQLMap($this->machineName, $source_key, $destination_key);

    $this->destination = new MigrateDestinationFieldCollection('field_topic_link', array('host_entity_type' => 'node'));

    $this->addFieldMapping('host_entity_id', 'RBKCMigrationNodeTopic')->sourceMigration('RBKCMigrationNodeTopic');

    // Internal links field_internal_topic_link (entity reference)
    // External links field_external_link (link) and field_external_link_teaser (long text)
    $this->addSimpleMappings(array('field_external_link'));
    $this->addSimpleMappings(array('field_external_link_teaser'));
    $this->addSimpleMappings(array('field_internal_topic_link'));
  }

  protected function initCrawler() {
    $parts = array('lib', 'DomCrawler', 'Crawler.php');
    require_once(drupal_get_path('module', 'rbkc_migration') . DIRECTORY_SEPARATOR . implode(DIRECTORY_SEPARATOR, $parts));
    $this->crawler = new \Symfony\Component\DomCrawler\Crawler();
  }

  public function prepareRow($row) {
    $this->crawler->clear();
    $this->processTopicText($row, $this->crawler);
  }

  protected function processTopicText($row, \Symfony\Component\DomCrawler\Crawler $crawler) {
    $topic_text = self::extractNodeFromXML($row->body, 'topictext');
    $crawler->add($topic_text);

    $count = 0;
    $topics = array();
    foreach ($crawler->filterXPath('//*') as $node) {
      switch ($node->tagName) {
        case 'html':
        case 'body':
          continue;

        case 'h2':
          $count++;
          $topics[$count]['title'] = $node->nodeValue;
          break;

        case 'a':
          $topics[$count]['href'] = $node->getAttribute('href');
          break;

        default:
          $topics[$count]['content'][] = $node->nodeValue;
          break;
      }
    }

    if (empty($topics)) {
      return;
    }

    $internal_link_delta = 0;
    $external_link_delta = 0;
    foreach ($topics as $topic) {
      if (!isset($topic['title']) || !isset($topic['href'])) {
        continue;
      }

      if (FALSE === strpos($topic['href'], 'ILINK')) {
        $row->field_external_link[LANGUAGE_NONE][$external_link_delta]['url'] = $topic['href'];
        $row->field_external_link[LANGUAGE_NONE][$external_link_delta]['title'] = $topic['title'];
        $row->field_external_link_teaser[LANGUAGE_NONE][$external_link_delta]['value'] = implode('', array_values($topic['content']));
        $external_link_delta++;
      }
      else {
        $href = $this->transformSourceLinkTokens($topic['href']);
        $target_id = str_replace('/node/', '', $href);
        $row->field_internal_topic_link[LANGUAGE_NONE][$internal_link_delta]['target_id'] = $target_id;
        $internal_link_delta++;
      }
    }
  }
}