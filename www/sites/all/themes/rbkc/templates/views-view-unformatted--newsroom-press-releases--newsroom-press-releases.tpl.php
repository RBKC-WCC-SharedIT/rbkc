<?php $numItems = count($rows); $columns = array_chunk($rows, ceil($numItems / 2));?>
<?php foreach ($columns as $column): ?>
<div class="press-releases__column content">
  <?php foreach ($column as $delta => $item): ?>
    <p<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
      <?php print $item; ?>
    </p>
  <?php endforeach; ?>
</div>
<?php endforeach; ?>