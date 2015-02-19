              <div class="middle inner padlr">
                <div class="row">
                  <div class="col8">
                    <div class="toc contrast group">
                     <h2 class="toc__header ">Contents</h2>
                      <ol class="toc__numlist floatleft">
                        <li class="active"><span>Planning advice</span></li>
                        <li><a href="#">Permitted development</a></li>
                        <li><a href="#">Submitting your application</a></li>
                      </ol>
                      <ol class="toc__numlist floatright"  start="4">
                        <li><a href="#">Considering an application</a></li>
                        <li><a href="#">When a decision is made</a></li>
                        <li><a href="#">Application forms</a></li>
                      </ol>
                    </div>

                    <div class="content group">
                      <?php
                        print render($content);
                      ?>
                    </div><!-- end content -->

                    <div class="contrast pag">
                      <a class="pag__next-name" href="#">
                        <span>Permitted development</span>
                      </a>
                    </div><!-- end pagination -->
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
