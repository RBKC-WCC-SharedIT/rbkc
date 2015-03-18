<ul class="iconlinks iconlinks--top-tasks rowexpand">
    <?php foreach ($items as $delta => $item): ?>
      <li class="<?php $numItems = count($items); if ( $numItems === 2 ) { print 'col6'; } elseif ( $numItems === 4 ) { print 'col3'; } else { print 'col4'; } ?>">
        <?php print render($item); ?>
      </li>
    <?php endforeach; ?>
</ul>
