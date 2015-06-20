<?php

/**
 * Class RBKCMigrationArchivedPressReleases
 *
 * Import archived press releases from CSV to Drupal press release nodes.
 */

class RBKCMigrationArchivedPressReleases extends Migration {
  use RBKCMigrationHandleRedirect;

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import archived press releases from CSV source to Drupal press release nodes.');

    $source = drupal_get_path('module', 'rbkc_migration') . DIRECTORY_SEPARATOR . 'data' . DIRECTORY_SEPARATOR . 'RBKCArchivedPressReleases' . '.csv';

    $columns = array();
    $options = array(
      'enclosure' => '"',
      'delimiter' => ',',
      'header_rows' => 1,
      'embedded_newlines' => TRUE,
    );
    $this->source = new MigrateSourceCSV($source, $columns, $options);

    $destination = 'press_release';
    $this->destination = new MigrateDestinationNode($destination);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'releaseid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'alias' => 'import'
        )
      ),

      MigrateDestinationNode::getKeySchema()
    );

    $this->addFieldMapping('created', 'prdate')->callbacks(array(self, 'callbackTransformCreatedDate'));
    $this->addFieldMapping('title', 'shorttitle')->callbacks('strip_tags', array(self, 'massageSourceData'));
    $this->addFieldMapping('field_short_title', 'shorttitle')->callbacks('strip_tags', array(self, 'massageSourceData'));
    $this->addFieldMapping('field_short_title:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('body', 'prcopy')->callbacks(array(self, 'massageSourceData'));
    $this->addFieldMapping('body:summary', 'shortdescription')->callbacks(array(self, 'massageSourceData'));
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('body:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('metatag_keywords', 'metatag_keywords');
    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('field_archived')->defaultValue(1);
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('pathauto')->defaultValue(1);
    $this->addUnmigratedSources(array('noteslabel', 'notestextcopy', 'photolabel', 'phototextcopy'));
  }

  public function prepareRow($row) {
    if (FALSE == parent::prepareRow($row)) {
      return FALSE;
    }

    $metatag_keywords = array();
    for ($i = 1; $i <= 5; $i++) {
      $property_name = 'keyword' . $i;
      if ('NULL' !== $row->{$property_name}) {
        $metatag_keywords[] = self::massageSourceData(trim($row->{$property_name}));
      }
    }

    $metatag_keywords_string = implode(',', $metatag_keywords);
    $metatag_keywords_string = rtrim($metatag_keywords_string, ',');
    $row->metatag_keywords = $metatag_keywords_string;

    $row->path = 'pressrelease/pressreleasepage.aspx';
    $row->path_query = array('query' => array('id' => $row->releaseid));
    return TRUE;
  }

  public function complete($entity, stdClass $row) {
      self::handleRedirect($entity, $row);
  }

  protected static function callbackTransformCreatedDate($date) {
    $date = mb_convert_encoding($date, 'UTF-8', 'ASCII');

    try {
      switch (strlen($date)) {
        case 19:
          $date_time = DateTime::createFromFormat('d/m/Y H:i:s', $date);
          break;

        default:
          $date_time = DateTime::createFromFormat('d/m/Y', $date);
          break;
      }

      $timestamp = $date_time->format('U');

    }
    catch (Exception $e) {
      $timestamp = time();
    }

    return $timestamp;
  }

  protected static function massageSourceData($string) {
    $string = htmlspecialchars_decode($string, ENT_QUOTES);
    $string = mb_convert_encoding($string, 'UTF-8', 'Windows-1252');
    return $string;
  }

  public static function handleRedirect($entity, stdClass $row) {
    if (!empty($row->path)) {
      $redirect = new stdClass();
      $url = $row->path;

      redirect_object_prepare($redirect, array(
        'source' => $url,
        'source_options' => isset($row->path_query) ? $row->path_query : array(),
        'redirect' => 'node/' . $entity->nid,
        'redirect_options' => array(),
        'language' => LANGUAGE_NONE,
      ));

      redirect_save($redirect);
    }
  }
}