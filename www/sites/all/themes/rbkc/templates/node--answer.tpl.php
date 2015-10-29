                <div class="row">
                  <div class="col8">
                    <div class="content">
                      <?php
                        //var_dump($content); die();
                        hide($content['field_contact_department']);
                        hide($content['deeplink_form']);
                        hide($content['rbkc_related_content']);
                        hide($content['sharethis']);
                        hide($content['field_tag']);
                        print render($content);
                       ?>

                    </div>
                    <div class="content group">
                      <?php print render($content['field_tag']); ?>
                      <p class="print-page"><strong>Print page: </strong><?php print print_insert_link(); ?> / <?php print print_pdf_insert_link(); ?></p>
                      <?php
                        print render($content['deeplink_form']);
                      ?>
                    </div>
                  </div><!-- end col8 -->

                  <div class="col4"  role="complementary">
                    <?php if ((isset($content['rbkc_related_content']['more_in']['#markup']) && !empty($content['rbkc_related_content']['more_in']['#markup'])) || isset($content['rbkc_related_content']['also_in']['#markup'])): ?>
                    <div class="bordered related">
                      <!-- child menu -->
                      <?php if (isset($content['rbkc_related_content']['more_in']['#markup']) && !empty($content['rbkc_related_content']['more_in']['#markup'])): ?>
                      <div class="related__more">
                        <h2 class="related__header">More in <?php print $title ?></h2>
                        <?php print render($content['rbkc_related_content']['more_in']); ?>
                      </div><!-- end related-more -->
                      <?php endif; ?>

                      <?php if (isset($content['rbkc_related_content']['also_in']['#markup'])): ?>
                      <!-- sibling menu -->
                      <div class="related__elsewhere">
                        <?php print render($content['rbkc_related_content']['also_in']); ?>
                      </div><!-- end related-elsewhere -->
                      <?php endif; ?>
                    </div><!-- end bordered related -->
                    <?php endif; ?>

                    <?php print render($content['field_contact_department']); ?>

                    <!--<div id="webchatplanning">
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
                    </div>-->
                  </div><!-- end col4 -->
                </div><!-- end row -->
