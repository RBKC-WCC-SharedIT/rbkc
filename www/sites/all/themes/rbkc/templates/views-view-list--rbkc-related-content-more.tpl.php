<?php print $list_type_prefix; ?>
<?php $count = 0; ?>
<?php foreach ($rows as $id => $row): ?>
  <?php $count++; ?>
  <li class="<?php print $classes_array[$id]; ?><?php print (($count >= 4) ? ' hide' : ''); ?>"><?php print $row; ?></li>
<?php endforeach; ?>
<?php print $list_type_suffix; ?>