<?php

/**
 * @file
 *
 * Migrate answer pages.
 */
class RBKCBaseNodeMigration extends Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

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

    $this->addSimpleMappings(array(
      'title',
      'changed',
      'promote',
      'sticky',
      'revision',
      'log',
      'language',
      'tnid',
      'translate',
      'is_new',
      'path',
      'comment'
    ));

    $this->addFieldMapping('uid')->defaultValue(1);
  }

  public function prepareRow($row) {
    $row->body_html = self::extractNodeFromXML($row->body, 'content');
    $row->body_html = $this->transformSourceLinkTokens($row->body_html);
    return TRUE;
  }

  public function complete($entity, stdClass $row) {
    $this->handleRedirect($entity, $row);
  }

  /**
   * Find and replace occurrences of ILINK's in the source data.
   *
   * Regular expression pattern should match the following strings capturing
   * only the link id (the integer after the first pipe) but matching everything
   * up to the final pipe:
   *
   * ILINK|18052,|
   * ILINK|16495,,WWI_website|
   * ILINK|17933,_blank|
   * ILINK|7271,,space|
   * ILINK|7462,,fridges|
   * ILINK|16377,,online_rewals|
   * ILINK|16444,,Oxford_reference_online|
   * ILINK|16414,,Library_of_the_month|
   * ILINK|10106,,almostcompletedHLTAwhatnext?|
   * ILINK|9219,_blank,Whousesservice|
   *
   * @param $html
   * @return mixed
   */
  protected function transformSourceLinkTokens($html) {
    $modifiers = 'i';
    $delimiter = '/';
    $pattern = $delimiter . 'ILINK\|(\d+),(?:[,|_]{1}[a-zA-Z0-9_?,]+)?\|' . $delimiter . $modifiers;
    $result = preg_replace_callback($pattern, array($this, 'generateNodeLinkFromSourceLinkToken'), $html);

    if (is_null($result)) {
      syslog(LOG_WARNING, 'An error occurred whilst attempting to transform a legacy internal link.');
      return $html;
    }

    return $result;
  }

  protected function generateNodeLinkFromSourceLinkToken(array $ilink) {
    $page_id = (int) $ilink[1];

    $nid = db_select('migrate_map_rbkcmigrationnodeanswer', 'm')
      ->fields('m', array('destid1'))
      ->condition('sourceid1', $page_id)
      ->execute()
      ->fetchField();


    if (FALSE === $nid) {
      if (FALSE === method_exists($this, 'createNodeStub')) {
        syslog(LOG_WARNING, 'Missing a createNodeStub method.');
        return $ilink[0];
      }

      $node = $this->createNodeStub($page_id);
      $nid = $node->nid;

      if ($nid) {
        $data_row = new stdClass();
        $data_row->p_page_id = $page_id;
        $this->map->saveIDMapping($data_row, array($nid), MigrateMap::STATUS_NEEDS_UPDATE, $this->defaultRollbackAction);
      }
    }

    return '/node/' . $nid;
  }

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

      redirect_save($redirect);
    }
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

  protected static function resolveTermMapping($key) {
    $mappings = array(
      'parkingtransportandstreets' => 'Parking, transports and streets',
      'binsandrecycling' => 'Bins and recycling',
      'planningandbuildingcontrol' => 'Planning and building control',
      'planningandconservation' => 'Planning and building control',
      'libraries' => 'Libraries',
      'libraryservices' => 'Libraries',
      'counciltax' => 'Council tax',
      'birthsdeathsmarriages' => 'Births, deaths and marriages',
      'childrenandeducation' => 'Children and education',
      'leisureandlibraries' => 'Leisure and culture',
      'housing' => 'Housing',
      'housingbeta' => 'Housing',
      'jobs' => 'Jobs',
      'healthandsocialcare' => 'Health and social care',
      'environmentandtransport' => 'Licensing',
      'businessandenterprise' => 'Business and enterprise',
      'environment' => 'Environment',
      'adviceandbensinformation' => 'Advice and benefits',
      'adviceandbenefits' => 'Advice and benefits',
      'community' => 'Community and local life',
      'newsroom-beta' => 'Newsroom',
      'councilanddemocracy' => 'Council',
      'council' => 'Council',
      'educationandlearning' => 'Education and learning',
      'cpdforschools' => 'CPD for schools',
      'voluntaryandpartnerships' => 'Voluntary and partnerships',
      'familyinformationservice' => 'Family information service',
      'teamkensingtonandchelsea' => 'Team Kensington and Chelsea',
      'streamingtest' => 'Streaming test',
    );

    return array_key_exists($key, $mappings) ? $mappings[$key] : $key;
  }
}
