              <div class="middle inner padlr">
                <div class="row">
                  <div class="col8">
                    <div class="toc contrast group">
                     <h2 class="toc__header ">Contents</h2>
                      <?php print render($content['book_menu']); ?>
                    </div>

                    <div class="content group">
                      <?php
                        print render($content['body']);
                      ?>
                    </div><!-- end content -->

                    <?php print render($content['book_navigation']); ?>
                  </div><!--end col 8-->

                  <div class="col4"  role="complementary">
                    <div class="bordered related">
                      <!-- child menu -->
                      <div class="related__more">
                        <h2 class="related__header">More in <?php print $title ?></h2>

                        <ul class="chevronlist">
                          <li><a href="#">Home page</a></li>
                          <li><a href="#">New Page</a></li>
                          <li><a href="#">Heritage and conservation</a></li>
                          <li class="hide"><a href="#">Newsroom</a></li>
                          <li class="hide"><a href="#">Guide Page</a></li>
                          <li class="hide"><a href="#">New menu test</a></li>
                          <li class="hide"><a href="#">forms</a></li>
                          <li class="hide"><a href="#">Planning Policy</a></li>
                        </ul>
                      </div><!-- end related-more -->

                      <!-- sibling menu -->
                      <div class="related__elsewhere">
                        <h2 class="related__header">Also in Related Topic</h2>

                        <ul class="chevronlist">
                          <li><a href="#">Home page</a></li>
                          <li><a href="#">New Page</a></li>
                          <li><a href="#">Heritage and conservation</a></li>
                          <li class="hide"><a href="#">Newsroom</a></li>
                          <li class="hide"><a href="#">Guide Page</a></li>
                          <li class="hide"><a href="#">New menu test</a></li>
                          <li class="hide"><a href="#">forms</a></li>
                          <li class="hide"><a href="#">Planning Policy</a></li>
                        </ul>
                      </div><!-- end related-elsewhere -->
                    </div><!-- end bordered related -->
                  </div><!-- end col4 -->
                </div><!-- end row -->
              </div><!-- end middle innerpadded -->
