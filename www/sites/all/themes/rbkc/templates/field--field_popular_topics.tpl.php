<?php $columns = array_chunk($items, 3); ?>
<?php foreach ($columns as $column): ?>
  <ul class="secondary-topics row">
    <?php foreach ($column as $delta => $item): ?>
      <li class="col4">
        <?php
          // I couldn't find configuration to remove the links.
          if (isset($item['links'])) {
            unset($item['links']);
          }
          print render($item);
        ?>
      </li>
    <?php endforeach; ?>
  </ul>
<?php endforeach; ?>