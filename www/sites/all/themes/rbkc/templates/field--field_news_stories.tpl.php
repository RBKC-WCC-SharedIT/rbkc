
<ul class="hub-feature col6">
    <?php foreach ($items as $delta => $item): ?>
    <li class="bordered">
      <img width="91" alt="The Royal Borough of Kensington and Chelsea" src="../images/hub-featured1.jpg" height="94"/>
      <div class="hub-feature__text">
        <?php print render($item); ?>
      </div>
    </li>
    <?php endforeach; ?>
</ul>