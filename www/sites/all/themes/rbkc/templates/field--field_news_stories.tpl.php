<ul class="hub-feature col6">
    <?php foreach ($items as $delta => $item): ?>
      <li class="bordered">
        <?php print render($item); ?>
      </li>
    <?php endforeach; ?>
</ul>
