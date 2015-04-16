<div class="outerwrap">
  <div class="headerglobal greyblue" role="banner">
    <div class="inner padlr">

      <div class="inner headerglobal__logowrap">
        <a href="<?php print $front_page; ?>" class="inner padlr logo" title="The Royal Borough of Kensington and Chelsea">The Royal Borough of Kensington and Chelsea</a>
      </div><!-- end logo -->

      <button class="headerglobal__open hamburger" id="openMenu" type="button">
        <span class="element-invisible">Open <a href="#nav1">menu below: Services, MyRBKC, Council, Maps</a></span>
      </button>

      <button class="headerglobal__open magnify" id="openSearch" type="button">
        <span class="element-invisible">Open search box below</span>
      </button>

      <nav role="navigation">
        <ul class="headerglobal__nav hide lightlinks" id="nav1">
          <li class="hide800"><a href="http://www.rbkc.gov.uk/services.aspx" title="Council Services">Services</a></li>
          <li class="show800 headerglobal__openservices" id="openServiceMenu">
          <button type="button">Services<span class="element-invisible">Open a <a href="#nav2">full list of services below</a></span></button>
          </li>
          <li><a href="https://www.rbkc.gov.uk/myrbkc/login.aspx" title="MyRBKC">MyRBKC</a></li>
          <li><a href="http://www.rbkc.gov.uk/councilanddemocracy.aspx" title="Council">Council</a></li>
          <li><a href="http://www.rbkc.gov.uk/leisureandlibraries/popularlocalmaps.aspx" title="Maps">Maps</a></li>
        </ul><!-- end menu -->
      </nav>

        <div class="search search--headerglobal hide">
        <?php print render($page['search']); ?>
        </div>
    </div><!-- end inner padlr -->
  </div><!-- end headerGlobal -->

  <?php if (!$is_front): ?>
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
  <?php endif; /* end if is front*/ ?>

  <main role="main">

    <?php if (!$is_front): ?>
    <div class="ribbon">
       <?php if ($breadcrumb): ?>
       <div class="inner breadcrumb lightlinks">
          <ol>
            <li><a href="<?php print $front_page; ?>" title="Home page" >Home page</a></li>
            <li><a href="#" title="#" >Service area link goes here</a></li>
            <li><?php print $title; ?></li>
           </ol>
       </div><!-- end inner breadcrumb-->
       <?php endif; /* end if breadcrumb*/ ?>

      <div class="inner heading group">
           <h1 class='heading__h1 <?php if (strlen($title) > 56) { print "long";} ?>'> <?php print $title; ?> </h1>
      </div>
    </div><!-- end ribbon -->
    <?php endif; /* end if is front*/ ?>
    <div class="middle inner padlr">
      <?php if ($tabs = render($tabs)): ?><div class="tabs"><?php print $tabs; ?></div><?php endif; ?>
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

      <p>&copy; 1998-2015 The Royal Borough of Kensington and Chelsea</p>
    </div><!-- end footerglobal-inner -->
  </div> <!-- end footerglobal -->
  <?php print render($page['govmetric']); ?>
</div><!-- end outerwrap -->

