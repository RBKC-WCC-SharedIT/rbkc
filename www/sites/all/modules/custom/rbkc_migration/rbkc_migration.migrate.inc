<?php

/**
 * @file
 *
 * Define migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function rbkc_migration_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'rbkc' => array(
        'title' => t('rbkc'),
        'default_format' => 'filtered_html',
      ),
    ),
    'migrations' => array(
      'RBKCMigrationSourceDocumentsCSV' => array(
        'class_name' => 'RBKCMigrationSourceDocumentsCSV',
        'group_name' => 'rbkc',
      ),
      'RBKCMigrationSourceContentCSV' => array(
        'class_name' => 'RBKCMigrationSourceContentCSV',
        'group_name' => 'rbkc',
      ),
      'RBKCMigrationNodeAnswer' => array(
        'class_name' => 'RBKCMigrationNodeAnswer',
        'group_name' => 'rbkc',
      ),
      'RBKCMigrationNodePublication' => array(
        'class_name' => 'RBKCMigrationNodePublication',
        'group_name' => 'rbkc',
      ),
      'RBKCMigrationNodePublicationAssociateChildren' => array(
        'class_name' => 'RBKCMigrationNodePublicationAssociateChildren',
        'group_name' => 'rbkc',
      ),
      'RBKCMigrationNodeTopic' => array(
        'class_name' => 'RBKCMigrationNodeTopic',
        'group_name' => 'rbkc',
      ),
      'RBKCMigrationNodeTopicFieldTopicLink' => array(
        'class_name' => 'RBKCMigrationNodeTopicFieldTopicLink',
        'group_name' => 'rbkc',
      ),
      'RBKCMigrationArchivedPressReleases' => array(
        'class_name' => 'RBKCMigrationArchivedPressReleases',
        'group_name' => 'rbkc',
      ),
    ),
    'destination handlers' => array(
      'MigrateRBKCHandler',
    ),
  );
  return $api;
}