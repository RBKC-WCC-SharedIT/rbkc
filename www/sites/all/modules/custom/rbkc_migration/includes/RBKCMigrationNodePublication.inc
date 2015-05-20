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
  }
}