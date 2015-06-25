(function($) {

  function addClassCarosel() {
    if (Modernizr.mq('only screen and (min-width: 700px)')) {
      $('#latestNews ul').first().addClass('deskView');
      $('.pager').find('li.rslides_here').removeClass('rslides_here');
      $('.pager').find('li:eq(0)').addClass('rslides_here');
    } else if (Modernizr.mq('only screen and (max-width: 699px)'))  {
      $('#latestNews ul:eq(0) li').removeAttr('style id');
      $('#pressReleases .sectionContent, #pressReleases ul').removeAttr('style');
    }
    // if no support for media queries
    else {
      $('#latestNews ul').first().addClass('deskView');
      $('.pager').find('li.rslides_here').removeClass('rslides_here');
      $('.pager').find('li:eq(0)').addClass('rslides_here');
    }
  }

  function showCapProj() {
    if (Modernizr.mq('only screen and (max-width: 699px)')) {
      if ($('.showMoreCapProjects').length > 0) {
        // stuff
        $('.showMoreCapProjects a').text("+");
      }
      $('#capital_projects .fixedItem, #capital_projects .sectionContent').hide();
      if (!($('.showMoreCapProjects').length > 0)) {
        // it does not exists
        $('#capital_projects').append('<span class="showMoreCapProjects"><a href="#" title="View the council\'s current capital projects.">+</a></span>');
        $('.showMoreCapProjects a').on("click", function (e) {
          if ($(this).text() === "+") {
            $(this).text("\u2013").attr('title', 'Hide the council\'s current capital projects.');
            /* Toggles the title text  */
          }
          else {
            $(this).text("+").attr('title', 'View the council\'s current capital projects.');
            /* Toggles the title text */
          }
          $('#capital_projects .fixedItem, #capital_projects .sectionContent').toggle();
          e.stopPropagation();
          return false;
        })
      }


    } else {
      $('.showMoreCapProjects  ').remove();
      $('#capital_projects .fixedItem, #capital_projects .sectionContent').show();
    }

  }
  function showNewsletters() {

    if (Modernizr.mq('only screen and (max-width: 699px)')) {
      if ($('.showMoreNewsletters').length > 0) {
        // stuff
        $('.showMoreNewsletters a').text("+");
      }
      $('#newsletters .fixedItem, #newsletters .sectionContent').hide();
      if (!($('.showMoreNewsletters').length > 0)) {
        // it does not exists
        $('#newsletters').append('<span class="showMoreNewsletters"><a href="#" title="View newsletters.">+</a></span>');
        $('.showMoreNewsletters a').on("click", function (e) {
          if ($(this).text() === "+") {
            $(this).text("\u2013").attr('title', 'Hide newsletters.');
            /* Toggles the title text  */
          }
          else {
            $(this).text("+").attr('title', 'View newsletters.');
            /* Toggles the title text */
          }
          $('#newsletters .fixedItem, #newsletters .sectionContent').toggle();
          e.stopPropagation();
          return false;
        })
      }


    } else {
      $('.showMoreNewsletters').remove();
      $('#newsletters .fixedItem, #newsletters .sectionContent').show();
    }
  }

  function latestNewsH() {
    if (Modernizr.mq('only screen and (min-width: 700px)')) {
      var pagerH = $('.pager').outerHeight();

      var caroH = $('#latestNews .sectionContent').first().outerHeight();

      var widgetH = pagerH + caroH - 32;

      var fixedItemH = $('#pressReleases .fixedItem').outerHeight();

      var PRlistH = widgetH - fixedItemH - "1";

      //$('#pressReleases ul').height(PRlistH);
      $('#pressReleases .sectionContent').css({
        "height": widgetH
      });
    }
  }

  function projectsHeight() {
    if (Modernizr.mq('only screen and (min-width: 700px)')) {

      var sectionH = $('#capital_projects .sectionContent').outerHeight();

      var fixedItemH = $('#capital_projects .fixedItem').outerHeight();

      var introH = $('#capital_projects .intro').outerHeight();

      var listH = sectionH - (fixedItemH + introH);

      $('#capital_projects ul').css({
        "height": listH
      });

    }
  }


  /*function hideLatestNewsImages (){
   $('.latestNewsHideImages a').click(function(){
   if ($(this).text() === "hide images") {
   $(this).text("show images").attr('title', 'Hide images.');
   *//* Toggles the title text  *//*
   }
   else {
   $(this).text("hide images").attr('title', 'View images.');
   *//* Toggles the title text *//*
   }
   $('.latestNewsIntro img').toggle(500);
   return false;
   })
   }*/

  function showCarousel() {

    if (Modernizr.mq('only screen and (min-width: 700px)')) {
      /*$('.latestNewsIntro img').show();*/

      $("#latestNews .deskView").responsiveSlides({
        auto: true, // Boolean: Animate automatically, true or false
        speed: 750, // Integer: Speed of the transition, in milliseconds
        timeout: 4500, // Integer: Time between slide transitions, in milliseconds
        pager: true, // Boolean: Show pager, true or false
        nav: true, // Boolean: Show navigation, true or false
        random: false, // Boolean: Randomize the order of the slides, true or false
        pause: true, // Boolean: Pause on hover, true or false
        pauseControls: true, // Boolean: Pause when hovering controls, true or false
        prevText: "&lt;", // String: Text for the "previous" button
        nextText: "&gt;", // String: Text for the "next" button
        maxwidth: "", // Integer: Max-width of the slideshow, in pixels
        navContainer: "#latestNews .pager", // Selector: Where controls should be appended to, default is after the 'ul'
        manualControls: "", // Selector: Declare custom pager navigation
        namespace: "rslides" // String: Change the default namespace used
        /*before: function(){}, Function: Before callback */
        /*after: function(){}  Function: After callback*/
      });
      $('.rslides_tabs:gt(0),.prev:gt(0),.next:gt(0)').remove();
    }

  }


  $(document).ready(function () {

    addClassCarosel();
    showCarousel();
    showCapProj();
    latestNewsH();
    projectsHeight();
    showNewsletters();

    setTimeout(function() {
      latestNewsH();
    }, 1500);

    // carousel in IE
    $(".lt-ie9 #latestNews .deskView").responsiveSlides({
      auto: false, // Boolean: Animate automatically, true or false
      speed: 750, // Integer: Speed of the transition, in milliseconds
      timeout: 5000, // Integer: Time between slide transitions, in milliseconds
      pager: true, // Boolean: Show pager, true or false
      nav: true, // Boolean: Show navigation, true or false
      random: false, // Boolean: Randomize the order of the slides, true or false
      pause: true, // Boolean: Pause on hover, true or false
      pauseControls: true, // Boolean: Pause when hovering controls, true or false
      prevText: "&lt;", // String: Text for the "previous" button
      nextText: "&gt;", // String: Text for the "next" button
      maxwidth: "", // Integer: Max-width of the slideshow, in pixels
      navContainer: "#latestNews .pager", // Selector: Where controls should be appended to, default is after the 'ul'
      manualControls: "", // Selector: Declare custom pager navigation
      namespace: "rslides" // String: Change the default namespace used
      /*before: function(){}, Function: Before callback */
      /*after: function(){}  Function: After callback*/
    });

  }); // end doc ready




  $(window).resize(function () {
    var CaroselId;
    clearTimeout(CaroselId);
    CaroselId = setTimeout(addClassCarosel, 500);
    var resizeId;
    clearTimeout(resizeId);
    resizeId = setTimeout(showCarousel, 500);
    var heightId;
    clearTimeout(heightId);
    heightId = setTimeout(latestNewsH, 500);
    var capHeightId;
    clearTimeout(capHeightId);
    capHeightId = setTimeout(projectsHeight, 500)
    var capProjHide;
    clearTimeout(capProjHide);
    resizeId = setTimeout(showCapProj, 500);
    var newslettersHide;
    clearTimeout(newslettersHide);
    resizeId = setTimeout(showNewsletters, 500);
  });

})(jQuery);