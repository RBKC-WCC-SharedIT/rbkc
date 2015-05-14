<?php print $wrapper_prefix; ?>
<?php if (!empty($title)) : ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php print $list_type_prefix; ?>
<?php $count = 0; ?>
<?php foreach ($rows as $id => $row): ?>
  <?php $count++; ?>
  <li class="<?php print $classes_array[$id]; ?><?php print (($count >= 4) ? ' hide' : ''); ?>"><?php print $row; ?></li>
<?php endforeach; ?>
<?php print $list_type_suffix; ?>
<?php print $wrapper_suffix; ?>
