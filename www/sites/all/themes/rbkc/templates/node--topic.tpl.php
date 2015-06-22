                <div class="content large-text">
                  <?php
                    hide($content['field_topic_link']);
                    hide($content['deeplink_form']);
                    print render($content);
                  ?>
                </div>
                <div class="blue-border-top row">
                  <div class="topics col8">
                    <?php
                      print render($content['field_topic_link']);
                      print render($content['deeplink_form']);
                    ?>
                  </div><!-- end topics -->
                </div><!-- end row -->
