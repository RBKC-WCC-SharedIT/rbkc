<ul class="iconlinks iconlinks--top-tasks rowexpand">
    <?php foreach ($items as $delta => $item): ?>
    <li class="col4"><?php print render($item); ?></li>
    <?php endforeach; ?>
</ul>