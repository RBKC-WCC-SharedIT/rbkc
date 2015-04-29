                <div class="row">
                  <div class="col3">
                    <div class="contrast toc">
                      <h2 class="toc__header">Contents</h2>
                        <?php print render($content['book_menu']); ?>
                      </div><!-- end toc -->
                  </div><!--end col 3-->
                  <div class="col9">
                    <div class="content">
                      <?php
                      // Render the body field.
                      print render($content['body']);
                      // Hide the book navigation as we're displaying that later.
                      hide($content['book_navigation']);
                      // Render the rest of the node, including links added by various modules.
                      print render($content);
                      ?>
                    </div><!-- end content -->
                    <?php print render($content['book_navigation']); ?>
                  </div><!--end col 9-->
                </div><!-- end row -->
