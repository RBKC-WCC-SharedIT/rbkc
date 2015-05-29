<?php

/**
 * Class RBKCMigrationNodeTopicFieldTopicLink
 *
 * Field collection migration for the topic page migration, this is the second
 * half of the two pass migration for topic pages.
 */

class RBKCMigrationNodeTopicFieldTopicLink extends RBKCBaseNodeMigration {
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
    $this->dependencies = array('RBKCMigrationSourceContentCSV', 'RBKCMigrationSourceDocumentsCSV', 'RBKCMigrationNodeTopic');

    $source = drupal_get_path('module', 'rbkc_migration') . DIRECTORY_SEPARATOR . 'data' . DIRECTORY_SEPARATOR . 'RBKCSource' . 'Topic' . '.csv';
    $columns = array();
    $options = array(
      'enclosure' => '$',
      'delimiter' => ',',
      'header_rows' => 1,
      'embedded_newlines' => TRUE,
    );
    $this->source = new MigrateSourceCSV($source, $columns, $options);

    $this->destination = new RBKCMigrateDestinationFieldCollection('field_topic_link', array('host_entity_type' => 'node'));

    $this->addFieldMapping('host_entity_id', 'p_page_id')->sourceMigration('RBKCMigrationNodeTopic');
    $this->addSimpleMappings(array('field_collections'));
  }

  /**
   * Initialise the DomCrawler.
   */
  protected function initCrawler() {
    $parts = array('lib', 'DomCrawler', 'Crawler.php');
    require_once(drupal_get_path('module', 'rbkc_migration') . DIRECTORY_SEPARATOR . implode(DIRECTORY_SEPARATOR, $parts));
    $this->crawler = new \Symfony\Component\DomCrawler\Crawler();
  }

  public function prepareRow($row) {
    if (FALSE == parent::prepareRow($row)) {
      return FALSE;
    }

    $this->crawler->clear();
    $this->processTopicText($row, $this->crawler);

    if (empty($row->field_collections)) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Process the blob of HTML that is H2's, links and content and transform it
   * into internal entity reference links or external links (with a teaser) all
   * in a field collection for good measure.
   *
   * Using DomCrawler here as it makes more effort to the parse the input than
   * SimpleXMLElement does.
   *
   * @param \stdClass $row
   * @param \Symfony\Component\DomCrawler\Crawler $crawler
   */
  protected function processTopicText(stdClass $row, \Symfony\Component\DomCrawler\Crawler $crawler) {
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

    $delta = 0;
    foreach ($topics as $topic) {
      if (!isset($topic['title']) || !isset($topic['href'])) {
        continue;
      }

      if (FALSE === strpos($topic['href'], 'ILINK')) {
        if (!is_string($topic['href'])) {
          continue;
        }

        $row->field_collections[$delta]['field_external_link'][LANGUAGE_NONE][0]['url'] = $topic['href'];
        $row->field_collections[$delta]['field_external_link'][LANGUAGE_NONE][0]['title'] = $topic['title'];

        $row->field_collections[$delta]['field_external_link_teaser'][LANGUAGE_NONE][0]['value'] = implode('', array_values($topic['content']));
        $delta++;
      }
      else {
        $href = $this->transformSourceLinkTokens($topic['href']);

        if (FALSE !== strpos($href, 'ILINK')) {
          continue;
        }

        $target_id = str_replace('/node/', '', $href);

        if (!$target_id) {
          continue;
        }

        $row->field_collections[$delta]['field_internal_topic_link'][LANGUAGE_NONE][0]['target_id'] = $target_id;
        $delta++;
      }
    }
  }
}