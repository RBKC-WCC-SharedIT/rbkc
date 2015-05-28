<?php

/**
 * Common code for migrations.
 *
 * RBKCMigrationCommon
 */

trait RBKCMigrationCommon {
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

      if (is_null($node)) {
        return $ilink[0];
      }

      $nid = $node->nid;

      if ($nid) {
        $data_row = new stdClass();
        $data_row->p_page_id = $page_id;
        $this->map->saveIDMapping($data_row, array($nid), MigrateMap::STATUS_NEEDS_UPDATE, $this->defaultRollbackAction);
      }
    }

    return '/node/' . $nid;
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

    $template = db_select('rbkc_migration_source', 's')
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
}