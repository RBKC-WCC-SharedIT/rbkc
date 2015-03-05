  <?php $menu_lists = array_chunk($items, 3); foreach ($menu_lists as $delta => $list): ?>
    <ul class="secondary-topics row">
      <?php foreach ($list as $delta => $item): ?>
        <li class="col4"><?php print render($item); ?></li>
      <?php endforeach; ?>
    </ul>
  <?php endforeach; ?>
