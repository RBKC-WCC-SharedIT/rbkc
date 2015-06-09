<?php

function rbkc_migration_drush_command() {
  $items['rbkc-split-csvs'] = array(
    'description' => 'Split source RBKC CSV files into separate files by template type.',
  );

  return $items;
}

function drush_rbkc_migration_rbkc_split_csvs() {
  $path = drupal_get_path('module', 'rbkc_migration') . DIRECTORY_SEPARATOR . 'data' . DIRECTORY_SEPARATOR . 'RBKCFullPageTable.csv';

  $columns = array();
  $options = array(
    'enclosure' => '$',
    'delimiter' => ',',
    'header_rows' => 1,
    'embedded_newlines' => TRUE,
  );

  $csv = new MigrateSourceCSV($path, $columns, $options);
  $csv->performRewind();
  $row_count = 0;
  $file_count = 0;

  while ($row = $csv->getNextRow()) {
    switch ($row->template) {
      case 'rf-answer-planning':
      case 'rf-answer-generic':
      case 'rf-answer-parking':
      case 'rf-plain-content':
        $handle = rbkc_migration_establish_handle($csv, 'answer');
        break;

      case 'rf-pub-parent':
      case 'rf-pub-child':
        $handle = rbkc_migration_establish_handle($csv, 'publication');
        break;

      case 'rf-topic-planning':
        $handle = rbkc_migration_establish_handle($csv, 'topic');
        break;

      default:
        continue 2;
    }

    if ($handle) {
      fputcsv($handle, (array) $row, ',', '$');
      $row_count++;
    }
  }

  foreach ($csv->handles as $handle) {
    fclose($handle);
    $file_count++;
  }

  print sprintf('Successfully generated %d files with a total of %d rows.', $file_count, $row_count) . PHP_EOL;
}

function rbkc_migration_establish_handle(MigrateSourceCSV $csv, $type) {
  if (!isset($csv->handles[$type])) {
    $path = drupal_get_path('module', 'rbkc_migration') . DIRECTORY_SEPARATOR . 'data' . DIRECTORY_SEPARATOR . 'RBKCSource' . ucfirst($type) . '.csv';
    $csv->handles[$type] = fopen($path, 'w');
    fputcsv($csv->handles[$type], (array) $csv->fields(), ',', '$');
  }

  return $csv->handles[$type];
}