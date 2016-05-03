<div class="outerwrap">
  <div class="headerglobal greyblue" role="banner">
    <div class="inner padlr">

      <div class="inner headerglobal__logowrap">
        <a href="<?php print $front_page; ?>" class="padlr logo" title="The Royal Borough of Kensington and Chelsea">The Royal Borough of Kensington and Chelsea</a>
      </div><!-- end logo -->

      <button class="headerglobal__open hamburger" id="openMenu" type="button"><span class="element-invisible">Open menu</span></button>
      <span class="element-invisible"><a href="#nav1">Skip to menu: Services, MyRBKC, Council, Maps</a></span>

      <button class="headerglobal__open magnify" id="openSearch" type="button"><span class="element-invisible">Open search</span></button>
      <span class="element-invisible"><a href="#search">Skip to search box</a></span>

      <nav role="navigation">
        <ul class="headerglobal__nav hide lightlinks" id="nav1">
          <li class="hide800"><a href="<?php print $front_page; ?>#services" title="Council Services">Services</a></li>
          <li class="show800 headerglobal__openservices" id="openServiceMenu">
          <button type="button">Services</button>
          <span class="element-invisible">See a <a href="#nav2">full list of services below</a></span>
          </li>
          <li><a href="https://www.rbkc.gov.uk/myrbkc/login.aspx" title="MyRBKC">MyRBKC</a></li>
          <li><?php print l('Council', 'node/2479'); ?></li>
          <li><?php print l('Maps', 'node/76'); ?></li>
        </ul><!-- end menu -->
      </nav>

      <?php print render($page['search']); ?>

    </div><!-- end inner padlr -->
  </div><!-- end headerGlobal -->

  <div class="service-menu hide lightlinks blueblack" role="navigation">
    <div class="inner padlr">
      <nav role="navigation">
        <?php print render($page['servicedropdown']); ?>
      </nav>

      <div class="service-menu__close">
        <p><button type="button">Close menu</button></p>
      </div>
    </div><!-- end inner padlr -->
  </div><!-- end serviceMenu -->

  <main role="main">

    <div class="ribbon">
       <?php if ($breadcrumb): ?>
       <div class="inner breadcrumb lightlinks">
          <ol>
            <li><a href="<?php print $front_page; ?>" title="Home page" >Home page</a></li>
            <?php if (isset($service_area_link)): ?>
            <li><?php print $service_area_link; ?></li>
            <?php endif; ?>
            <?php if (!empty($title)): ?>
            <li><?php print $title; ?></li>
            <?php endif; ?>
           </ol>
       </div><!-- end inner breadcrumb-->
       <?php endif; /* end if breadcrumb*/ ?>

      <div class="inner heading group">
           <h1 class='heading__h1 <?php if (strlen($title) > 80) { print "long";} ?>'> <?php print $title; ?> </h1>
      </div>
    </div><!-- end ribbon -->

    <?php if ($tabs = render($tabs)): ?>
      <div class="drupal-tabs">
        <div class="tabs"><?php print $tabs; ?></div>
      </div>
    <?php endif; ?>

    <div class="middle inner padlr group">
      <?php print render($page['help']); ?>
      <?php print render($page['content']); ?>
    </div><!-- end middle inner -->

  </main>

  <div class="footerglobal deepblue" role="contentinfo">
    <div class="inner">
      <p class="footerglobal__address">Town Hall, Hornton Street, W8 7NX</p>

      <p class="lightlinks">
        <a class="footerglobal__contact" href="tel://020-7361-3000">Call on 020 7361 3000</a>
        <a class="footerglobal__contact" href="https://www.eforms.rbkc.gov.uk/default.aspx/RenderForm/?F.Name=FoXT6rvnp4J">Email us</a>
      </p>

      <?php print render($page['footerlinks']); ?>

      <ul class="footerglobal__social">
        <li><a href="http://uk.sitestat.com/rbkc/rbkc/s?Twitter&amp;ns_type=clickout" class="wtbird" title="Twitter">Twitter</a></li>
        <li><a href="http://uk.sitestat.com/rbkc/rbkc/s?Facebook&amp;ns_type=clickout" class="wficon" title="Facebook">Facebook</a></li>
        <li><a href="http://uk.sitestat.com/rbkc/rbkc/s?Youtube&amp;ns_type=clickout" class="wytube" title="YouTube">YouTube</a></li>
      </ul>

      <p>&copy; 1998-<?php print rbkc_sitewide_getcopyrightyear()?> The Royal Borough of Kensington and Chelsea</p>
    </div><!-- end footerglobal-inner -->
  </div> <!-- end footerglobal -->
  <?php print render($page['govmetric']); ?>
</div><!-- end outerwrap -->
