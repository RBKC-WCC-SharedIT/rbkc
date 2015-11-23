    <div class="row top-news large-text ">
      <div class="col12 top-news__slider">

        <?php print render($content['field_carousel']); ?>

      </div>
    </div>

    <div class="press-releases row newsroom-section">
      <h2>Press releases</h2>
      <div class="press-releases__feed">

         <?php print views_embed_view("newsroom_press_releases", 'newsroom_press_releases'); ?>
      </div>
      <div class="action linkheader">
        <?php print render($content['field_search_newsroom_action']); ?>
      </div>
    </div>

    <div class="row blue-border-top newsroom-section">
      <h2>Newsletters</h2>
      <p class="large-text"><?php print render($content['field_newsletters_intro']); ?></p>
    </div>
    <div class="newsletters group">
      <?php print render($content['field_newsletters']); ?>
    </div>

    <div class=" blue-border-top social-media newsroom-section group">
      <h2>Social media</h2>

        <?php print views_embed_view("tweets", 'newsroom_tweets'); ?>

        <div class="action special">
          <span class="find-us">Find us:</span>
          <a href="https://twitter.com/RBKC" target="_blank">
            <span class="wtbird"></span>
            <span class="social-media__link">Twitter</span>
          </a>
          <a href="https://www.facebook.com/RoyalBorough/" target="_blank">
            <span class="wficon"></span>
            <span class="social-media__link">Facebook</span>
          </a>
          <a href="https://www.youtube.com/user/kensingtonandchelsea" target="_blank">
            <span class="wytube"></span>
            <span class="social-media__link">YouTube</span>
          </a>
        </div>
    </div>

    <div class=" blue-border-top newsroom-section row capital-projects ">
      <h2>Council capital projects</h2>

      <div class="content">
      <p class="large-text"><?php print render($content['field_capital_projects_intro']); ?></p>
        <?php print views_embed_view("new_newsroom_capital_projects", 'newsroom_capital_projects_block'); ?>

      </div>
      <div class="action linkheader"><?php print render($content['field_view_all_capital_projects']); ?></div>
    </div>

    <div class=" blue-border-top newsroom-section row royal-borough">
      <h2>Royal Borough newspaper</h2>
      <p class="large-text"><?php print render($content['field_royal_borough_intro']); ?></p>
      <div class="action linkheader"><?php print render($content['field_read_latest_edition_rb']); ?></div>
    </div>

    <div class=" blue-border-top newsroom-section row contact-us">
      <h2>Contact us</h2>

      <p class="large-text"><strong>Tel:</strong> <a href="tel://020-7361-2826/">020 73612826</a></p>
      <p class="large-text"><strong>Email:</strong> <a href="mailto:pressbox@rbkc.gov.uk">pressbox@rbkc.gov.uk</a></p>

    </div>








