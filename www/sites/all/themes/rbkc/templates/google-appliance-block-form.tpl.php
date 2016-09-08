<div id ="search" class="search <?php $is_front ? print 'search--hp' : print 'search--headerglobal hide' ?>">
  <label>Search</label>
  <?php if (variable_get('rbkc_funnelback_active', false)) {
    print rbkc_funnelback_form();
  } else {
    print $block_search_form_complete;
  } ?>
</div>
