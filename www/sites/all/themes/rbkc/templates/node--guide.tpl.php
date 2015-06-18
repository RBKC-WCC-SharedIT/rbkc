                <div class="row">
                  <div class="col8">
                    <div class="toc contrast group">
                     <h2 class="toc__header ">Contents</h2>
                      <?php print render($content['book_menu']); ?>
                    </div>

                    <div class="content group">
                      <?php print render($content['body']); ?>
                    </div><!-- end content -->

                    <?php
                      print render($content['book_navigation']);
                      print render($content['deeplink_form']);
                    ?>
                  </div><!--end col 8-->

                  <div class="col4"  role="complementary">
                     <?php if (isset($content['rbkc_related_content']['also_in']['#markup'])): ?>
                    <div class="bordered related">
                      <!-- sibling menu -->
                      <div class="related__elsewhere">
                        <?php print render($content['rbkc_related_content']['also_in']); ?>
                      </div><!-- end related-elsewhere -->
                    </div><!-- end bordered related -->
                    <?php endif; ?>
                  </div><!-- end col4 -->
                </div><!-- end row -->
