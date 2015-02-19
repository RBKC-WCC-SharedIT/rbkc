              <div class="middle inner padlr">
                <div class="row">
                  <div class="col8">
                    <div class="content">
                      <?php
                        print render($content);
                      ?>
                    </div>
                  </div> <!-- end col8 -->

                  <div class="col4"  role="complementary">
                    <div class="bordered related">
                      <!-- child menu -->
                      <div class="related__more">
                        <h2 class="related__header">More in <?php print $title ?></h2>

                        <ul class="chevronlist">
                          <li class="level0"><a href="/planningandbuildingcontrol/homepage.aspx">Home page</a></li>
                          <li class="level0"><a href="/planningandbuildingcontrol/newpage.aspx">New Page</a></li>
                          <li class="level0"><a href="/planningandbuildingcontrol/heritageandconservation.aspx">Heritage and conservation</a></li>
                          <li class="hide level0"><a href="/planningandbuildingcontrol/newsroom.aspx">Newsroom</a></li>
                          <li class="hide level0"><a href="/planningandbuildingcontrol/guidepage.aspx">Guide Page</a></li>
                          <li class="hide level0"><a href="/planningandbuildingcontrol/newmenutest.aspx">New menu test</a></li>
                          <li class="hide level0"><a href="/planningandbuildingcontrol/forms.aspx">forms</a></li>
                          <li class="hide level0"><a href="/planningandbuildingcontrol/planningpolicy.aspx">Planning Policy</a></li>
                        </ul>
                      </div><!-- end related-more -->

                      <!-- sibling menu -->
                      <div class="related__elsewhere">
                        <h2 class="related__header">Also in Related Topic</h2>

                        <ul class="chevronlist">
                          <li class="level0"><a href="/planningandbuildingcontrol/homepage.aspx">Home page</a></li>
                          <li class="level0"><a href="/planningandbuildingcontrol/newpage.aspx">New Page</a></li>
                          <li class="level0"><a href="/planningandbuildingcontrol/heritageandconservation.aspx">Heritage and conservation</a></li>
                          <li class="hide level0"><a href="/planningandbuildingcontrol/newsroom.aspx">Newsroom</a></li>
                          <li class="hide level0"><a href="/planningandbuildingcontrol/guidepage.aspx">Guide Page</a></li>
                          <li class="hide level0"><a href="/planningandbuildingcontrol/newmenutest.aspx">New menu test</a></li>
                          <li class="hide level0"><a href="/planningandbuildingcontrol/forms.aspx">forms</a></li>
                          <li class="hide level0"><a href="/planningandbuildingcontrol/planningpolicy.aspx">Planning Policy</a></li>
                        </ul>
                      </div><!-- end related-elsewhere -->
                    </div><!-- end bordered related -->

                    <a class="contact-team" href="#">Contact the team</a>

                    <div id="webchatplanning">
                      <script type="text/javascript">
                        var m3_u = "http://rbkc.logo-net.co.uk/Delivery/DBURL.php";
                        var strPURL = parent.document.URL;
                        strPURL = strPURL.replace(/&/g, "^");
                        strPURL = strPURL.toLowerCase();
                        strPURL = strPURL.replace(/script/g, "HACK");
                        strPURL = strPURL.replace(/</g, "HACKONE");
                        strPURL = strPURL.replace(/>/g, "HACKTWO");
                        strPURL = strPURL.replace(/%3c/g, "HACKONE");
                        strPURL = strPURL.replace(/%3e/g, "HACKTWO");
                        var T = new Date();
                        var cMS = T.getTime();
                        document.write("<scr" + "ipt type='text/javascript' src='" + m3_u);
                        document.write("?SDTID=167");
                        document.write('&PURL=' + strPURL);
                        document.write('&CMS=' + cMS);
                        document.write("'></scr" + "ipt>");
                      </script>
                    </div>
                  </div><!-- end col4 -->
                </div><!-- end row -->
              </div><!-- end middle inner -->

