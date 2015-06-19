<div class="outerwrap">
  <div class="headerglobal headerglobal--hp greyblue" role="banner">
    <div class="inner padlr">

      <div class="inner headerglobal__logowrap">
        <a href="<?php print $front_page; ?>" class="inner padlr logo" title="The Royal Borough of Kensington and Chelsea">The Royal Borough of Kensington and Chelsea</a>
      </div><!-- end logo -->

      <button class="headerglobal__open hamburger" id="openMenu" type="button"><span class="element-invisible">Open menu</span></button>
      <span class="element-invisible"><a href="#nav1">Skip to menu: Services, MyRBKC, Council, Maps</a></span>

      <button class="headerglobal__open magnify active" id="openSearch" type="button"><span class="element-invisible">Open search</span></button>
      <span class="element-invisible"><a href="#search">Skip to search box</a></span>

      <nav role="navigation">
        <ul class="headerglobal__nav hide lightlinks" id="nav1">
          <li class="hide800"><a href="#services" title="Council Services">Services</a></li>
          <li class="show800 headerglobal__openservices" id="openServiceMenu">
          <button type="button">Services</button>
          <span class="element-invisible">See a <a href="#nav2">full list of services below</a>
          </li>
          <li><a href="https://www.rbkc.gov.uk/myrbkc/login.aspx" title="MyRBKC">MyRBKC</a></li>
          <li><a href="http://www.rbkc.gov.uk/councilanddemocracy.aspx" title="Council">Council</a></li>
          <li><a href="http://www.rbkc.gov.uk/leisureandlibraries/popularlocalmaps.aspx" title="Maps">Maps</a></li>
        </ul><!-- end menu -->
      </nav>
    </div>
  </div>

    <main>
      <div class="ribbon--hp"></div>
      <div class="inner group">
        <h1 class="heading__h1 heading__h1--hp">Welcome to the Royal Borough</h1>
        <?php print render($page['search']); ?>
      </div>
      <?php print render($page['content']); ?>
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


<script type="text/javascript">
 //<!-- Begin Sitestat4 Loadingtime1 code -->
ns_loadingtime1=(new Date()).getTime();
//<!-- End Sitestat4 Loadingtime1 code -->
</script>
<!-- Begin Sitestat4 code -->
<script type="text/javascript">

<!--
function sitestat(ns_l){ns_l+='&amp;ns__t='+(new Date()).getTime();ns_pixelUrl=ns_l;
ns_0=document.referrer;
ns_0=(ns_0.lastIndexOf('/')==ns_0.length-1)?ns_0.substring(ns_0.lastIndexOf('/'),0):ns_0;
if(ns_0.length>0)ns_l+='&amp;ns_referrer='+escape(ns_0);
if(document.images){ns_1=new Image();ns_1.src=ns_l;}else
document.write('<img src="'+ns_l+'" width="1" height="1" alt="" />');}
sitestat("http://uk.sitestat.com/rbkc/rbkc/s?home.page" );
//-->
</script>

<div><img src="http://uk.sitestat.com/rbkc/rbkc/s?home.page" width="1" height="1" alt="" /></div>

<!-- End Sitestat4 code -->
<!-- Begin Sitestat4 Technical code --><script type="text/javascript" src="/js/rbkc/sitestat.js"></script>
<!-- End Sitestat4 Technical code -->
<!-- Begin Sitestat4 Loadingtime2 code -->
<script type="text/javascript">ns_loadingtime2=(new Date()).getTime();</script>
<!-- End Sitestat4 Loadingtime2 code -->
