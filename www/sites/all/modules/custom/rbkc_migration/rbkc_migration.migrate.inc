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
      'RBKCMigrationSourceCSV' => array(
        'class_name' => 'RBKCMigrationSourceCSV',
        'group_name' => 'rbkc',
      ),
      'RBKCMigrationNodeAnswer' => array(
        'class_name' => 'RBKCMigrationNodeAnswer',
        'group_name' => 'rbkc',
      ),
      'RBKCMigrationNodeGuide' => array(
        'class_name' => 'RBKCMigrationNodeGuide',
        'group_name' => 'rbkc',
      ),
      'RBKCMigrationNodePublication' => array(
        'class_name' => 'RBKCMigrationNodePublication',
        'group_name' => 'rbkc',
      ),
      'RBKCMigrationNodeServicehub' => array(
        'class_name' => 'RBKCMigrationNodeServicehub',
        'group_name' => 'rbkc',
      ),
      'RBKCMigrationNodeSubhub' => array(
        'class_name' => 'RBKCMigrationNodeSubhub',
        'group_name' => 'rbkc',
      ),
      'RBKCMigrationNodeTopic' => array(
        'class_name' => 'RBKCMigrationNodeTopic',
        'group_name' => 'rbkc',
      ),
      'RBKCMigrationEntityContactDepartments' => array(
        'class_name' => 'RBKCMigrationEntityContactDepartments',
        'group_name' => 'rbkc',
      ),
    ),
    'destination handlers' => array(
      'MigrateRBKCHandler',
    ),
  );
  return $api;
}