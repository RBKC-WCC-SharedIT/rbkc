<ul class="iconlinks iconlinks--top-tasks rowexpand">
    <?php foreach ($items as $delta => $item): ?>
    <h2><?php print render($item); ?></h2>
    <?php endforeach; ?>
</ul>