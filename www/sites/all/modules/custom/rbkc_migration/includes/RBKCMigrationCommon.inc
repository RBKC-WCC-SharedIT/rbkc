<?php

/**
 * RBKCMigrationCommon
 */

trait RBKCMigrationCommon {
  public static function extractNodeFromXML($xml, $node) {
    $content = '';

    if (empty($xml)) {
      return $content;
    }

    try {
      $xml = new SimpleXMLElement($xml);
    }
    catch (Exception $e) {
      syslog(LOG_WARNING, sprintf('Failed to load source XML as SimpleXMLElement when looking for %s: %s', $node, $e->getMessage()));
      return $content;
    }

    $content = (string) $xml->content->{$node};
    return $content;
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
  protected function transformSourceLinkTokens($html, $path = TRUE) {
    $modifiers = 'i';
    $delimiter = '/';
    $pattern = $delimiter . 'ILINK\|(\d+),([_a-zA-Z]*)(?:,)*([a-zA-Z0-9\?]*)\|' . $delimiter . $modifiers;

    if ($path) {
      $result = preg_replace_callback($pattern, array($this, 'generateNodeLinkFromSourceLinkToken'), $html);
    }
    else {
      $result = preg_replace_callback($pattern, array($this, 'generateNidFromSourceLinkToken'), $html);
    }

    if (is_null($result)) {
      syslog(LOG_WARNING, 'An error occurred whilst attempting to transform a legacy internal link.');
      return $html;
    }

    return $result;
  }

  /**
   * Transform instances of some class names in incoming content.
   *
   * @param $html
   * @return mixed
   */
  protected function transformClasses($html) {
    $search = array('noticeMessage', 'policyInfo', 'warningRed', 'warningYellow');
    $replace = array('notice-message', 'policy-info', 'warning-red', 'warning-yellow');

    $html = str_replace($search, $replace, $html);

    return $html;
  }

  /**
   * Find and replace occurrences of IDOC's in the source data.
   *
   * Regular expression pattern should match the following strings capturing
   * only the document gui (the string that looks like a hash) but matching
   * everything up to the final pipe:
   *
   * IDOC|{336da895-43dc-44d5-ad00-7f5867dfa87a},-1,33|
   *
   * @param $html
   * @return mixed
   */
  protected function transformSourceDocumentTokens($html) {
    $modifiers = 'i';
    $delimiter = '/';
    $pattern = $delimiter . '(?:IDOC\|{){1}([0-9a-zA-Z-]+)(?:}[,0-9-]+\|){1}' . $delimiter . $modifiers;
    $result = preg_replace_callback($pattern, array($this, 'generateDocumentLinkFromSourceDocumentToken'), $html);

    if (is_null($result)) {
      syslog(LOG_WARNING, 'An error occurred whilst attempting to transform a legacy internal link.');
      return $html;
    }

    return $result;
  }

  /**
   * Given an ILINK (integer), look up the destination id from available
   * migrations.
   *
   * @param array $ilink
   * @return string
   */
  protected function generateNodeLinkFromSourceLinkToken(array $ilink) {
    $result = $this->generateNidFromSourceLinkToken($ilink);

    if (FALSE !== strpos($result, 'ILINK')) {
      return $result;
    }

    $anchor = '';
    if (!empty($ilink[3])) {
      $anchor = '#' . $ilink[3];
      return $anchor;
    }

    return '/node/' . $result;
  }

  protected function generateNidFromSourceLinkToken(array $ilink) {
    $source_id = (int) $ilink[1];

    $migrations = array('RBKCMigrationNodeAnswer', 'RBKCMigrationNodePublication', 'RBKCMigrationNodeTopic');

    $destination_nid = $this->handleSourceMigration($migrations, $source_id);

    if (FALSE === $destination_nid || is_null($destination_nid)) {
      if (FALSE === method_exists($this, 'createNodeStub')) {
        return $ilink[0];
      }

      $node = $this->createNodeStub($source_id);

      if (is_null($node)) {
        return $ilink[0];
      }

      $destination_nid = $node->nid;

      if ($destination_nid) {
        $data_row = new stdClass();
        $data_row->p_page_id = $source_id;
        $this->map->saveIDMapping($data_row, array($destination_nid), MigrateMap::STATUS_NEEDS_UPDATE, $this->defaultRollbackAction);
      }
    }

    return $destination_nid;
  }

  protected function createNodeStub($source_id, array $properties = NULL) {
    $node_type = self::templateLookUp($source_id);

    if (is_null($node_type)) {
      return NULL;
    }

    $node = new stdClass();
    $node->title = t('Stub for @id', array('@id' => $source_id));
    if (self::contentTypeHasBody($node_type)) {
      $node->body[LANGUAGE_NONE][0]['value'] = t('Stub body');
    }
    $node->language = LANGUAGE_NONE;
    $node->type = $node_type;
    $node->uid = 1;
    $node->status = 0;

    if (!is_null($properties)) {
      foreach ($properties as $key => $value) {
        $node->{$key} = $value;
      }
    }

    node_save($node);
    return $node;
  }

  protected static function contentTypeHasBody($type) {
    return (is_null(field_info_instance('node', 'body', $type))) ? FALSE : TRUE;
  }

  protected static function templateLookUp($page_id) {
    $page_id = (int) $page_id;

    $template = db_select('rbkc_migration_content', 's')
      ->fields('s', array('template'))
      ->condition('p_page_id', $page_id)
      ->execute()
      ->fetchField();

    if (FALSE === $template) {
      syslog(LOG_WARNING, sprintf('No row in the source data for p_page_id = %d', $page_id));
      return NULL;
    }

    syslog(LOG_DEBUG, sprintf('Looking up template for %s', $template));
    return self::resolveTemplateMapping($template);
  }

  protected static function resolveTermMapping($key) {
    $mappings = array(
      'parkingtransportandstreets' => 'Parking, transport and streets',
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

  protected static function resolveTemplateMapping($key) {
    switch ($key) {
      case 'rf-answer-planning':
      case 'rf-answer-generic':
      case 'rf-plain-content':
      case 'rf-answer-parking':
        return 'answer';
        break;

      case 'rf-pub-child':
      case 'rf-pub-parent':
        return 'publication';
        break;

      case 'rf-topic-planning':
        return 'topic';
        break;

      default:
        return NULL;
    }
  }

  protected static function callbackResolveServiceHubTerm($path) {
    if (!$path) {
      return array();
    }

    if (FALSE === strpos($path, '/')) {
      return array();
    }

    $parts = explode('/', $path);
    array_pop($parts);

    $vocabulary_name = 'service_hub';
    $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_name);
    if (FALSE === $vocabulary) {
      return array();
    }

    return self::recurseServiceHubTerms($parts, $vocabulary);
  }

  protected static function recurseServiceHubTerms(array $parts, stdClass $vocabulary, stdClass $parent = NULL) {
    $part = array_shift($parts);

    $term_name = static::resolveTermMapping($part);

    $terms = taxonomy_get_term_by_name($term_name, $vocabulary->machine_name);
    if (count($terms)) {
      $term = array_shift($terms);
    }

    if (!isset($term) && !is_object($term)) {
      $term = new stdClass();
      $term->vid = $vocabulary->vid;
      $term->name = $term_name;
      if (!is_null($parent)) {
        $term->parent = $parent->tid;
      }
      taxonomy_term_save($term);
    }

    if (count($parts)) {
      return self::recurseServiceHubTerms($parts, $vocabulary, $term);
    }

    return $term->name;
  }

  protected function generateDocumentLinkFromSourceDocumentToken(array $idoc) {
    $path_to_idocs = '/wamdocs/';
    $gui = $idoc[1];

    $filename = db_select('rbkc_migration_documents', 'd')
      ->fields('d', array('filename'))
      ->condition('gui', $gui)
      ->execute()
      ->fetchField();

    if (FALSE === $filename) {
      syslog(LOG_WARNING, sprintf('Unable to retrieve a row for a gui of %s.', $gui));
      return $idoc[0];
    }

    return $path_to_idocs . rawurlencode($filename);
  }
}
