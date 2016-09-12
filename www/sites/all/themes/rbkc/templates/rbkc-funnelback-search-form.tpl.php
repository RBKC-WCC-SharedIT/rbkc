<div id ="search" class="search <?php $is_front ? print 'search--hp' : print 'search--headerglobal hide' ?>">
  <div class="search__wrap">
    <?php print render($form['keywords']); ?>
  </div>
  <?php print render($form['submit']); ?>
  <?php print drupal_render_children($form); ?>
</div>
  