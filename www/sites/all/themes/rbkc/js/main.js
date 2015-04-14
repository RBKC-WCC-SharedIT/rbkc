(function($) {

  var headerMob,
      headerDesk,
      stylePDF,
  //  accordion,
      addViewAllMore,
      addViewAllElsewhere,
      showMore,
      checkPlaceholder,
      wrapH2,
      serviceList,
      commsHeight,
      slickSlider,
      moveGovmetric;

  // opening and closing header menus
  function assignOpenMenu( thisButton, thisMenu, otherButton, otherMenu ) {
    $(thisButton).click(function() {
      // test to see if other menu provided (only defined when acting on two mobile menus)
      if (otherButton !== undefined && otherMenu !== undefined) {
        $(otherMenu).addClass('hide'); //hide
        $(otherButton).removeClass('active');
      }
      if($(thisMenu).hasClass('hide')) {
        $(thisMenu).removeClass('hide');
        $(thisButton).addClass('active');
      } else {
        $(thisMenu).addClass('hide');
        $(thisButton).removeClass('active');
      }
      if(thisMenu === '.service-menu') {
          $('.service-menu__close').click(function() {
          $('.service-menu').addClass('hide');
          $('#openServiceMenu').removeClass('active');
        });
      }
    });
  }

  function wrapH2() {
    $('.content h2').each(function() {
      if ($(this).height() > 40) {
        $(this).css("line-height", "2rem");
      }
    });
  }

  function stylePDF() {
    $('a[href^="IDOC"], a[href$=".pdf"], a[href*="idoc.ashx"], a[href$=".docx"], a[href$=".doc"]').each(function(){
      var linkElement = $(this);
      var linkText = linkElement.text();
      var linkHref =  $(this).attr('href');
      var linkParent = $(this).parents("li:first, p:first");
      // adding a class to the link's parent
      linkParent.addClass("docLink");
      $('<br>').appendTo(linkElement);
      // Create the Icon with the duplicated link
      var Icon =
        $('<a />', {
          'class': 'docLink-icon',
          'href' : linkHref,
          // to hide from screen reader
          'role' : 'presentation',
          'tabindex' : "-1"
        }).prependTo(linkParent);
    }); // end each function
  } // end stylePDF


  // where there are more than three items in menu add 'view all'
  function addViewAll() {
    $('.related ul').each(function() {
      var childNumber = $(this).find('li');
      if (childNumber.length > 3) {
        $('<p class="related__viewall">View all</p>').attr('title', 'View other, related pages').insertAfter($(this));
      }
    });
  }

  function showMore() {
    $(this).parent().find('li:gt(2)').slideToggle('150');
        if ($(this).text() === "View all") {
          $(this).text("View less").attr('title', 'View fewer links');/* Toggles the title text  */
        }
        else {
          $(this).text("View all").attr('title', 'View more links');/* Toggles the title text */
          }
  }   // end show/hide right hand column menu

  // if broswer does not support html5 placeholder, add value to form field
  function checkPlaceholder() {
    if(!Modernizr.input.placeholder){
       $('.headerglobal-search_full_text input').val('Enter search terms...');
       $('.headerglobal-search_full_text input').click(function() {
        function doOnce() {
          $('.headerglobal-search_full_text input').val("");
          doOnce = function() {};
        }
        doOnce();
       });
    }
  }

  function serviceList() {
    $('.servicelist-viewall').click(function(e) {
      e.preventDefault();
      if(!$(this).hasClass('viewless')) {
        $('.servicelist-2nd').slideDown(200);
        $('.servicelist-viewall span').text('View fewer services');
        $(this).addClass('viewless');
        }
      else {
        $('.servicelist-2nd').slideUp(200);
        $('.servicelist-viewall span').text('View more services');
        $(this).removeClass('viewless');
      }
    });
  } // end service list


  function commsHeight() {  //make comms panels correct height when no flexbox support
    if  (!$('html').hasClass('flexbox')) {
      var newsBoxHeight = $('.newsbox-news').outerHeight();
      //console.log(newsBoxHeight);
      var imgBoxHeight = $('.newsbox-img').outerHeight();
      var blogBoxHeight = (newsBoxHeight - imgBoxHeight - 30);
      //console.log(blogBoxHeight);
      $('.lblog .newsbox-item ').css('height', blogBoxHeight + "px");
    }
  }

  function slickSlider() {
    $('.local__slider').slick({
      infinite: true,
      speed: 300,
      slidesToShow: 3,
      slidesToScroll: 1,
      autoplay: true,
      autoplaySpeed: 4000,
      responsive: [
        {
          breakpoint: 700,
          settings: {
          slidesToShow: 2,
          swipe: true
          }
        },
        {
          breakpoint: 560,
          settings: {
          slidesToShow: 1,
          swipe: true,

          }
        }
      ]
    });
  } // end slickSlider

  // ensuring govMetric does not obscure footer links at any viewport width
/*  function moveGovmetric() {
    //position of bottom of viewport
    var position =  $(window).scrollTop() + $(window).height();
    var docHeight = $(document).height();
    var footerHeight = $('.footerglobal').outerHeight();
    position >= (docHeight - footerHeight) ? $('govmetric').addClass('special') : $('.govmetric').removeClass('special');
  }*/

  // ensuring govMetric does not obscure footer links at any viewport width
  function moveGovmetric() {
    //position of bottom of viewport
    var position =  $(window).scrollTop() + $(window).height();

    var docHeight = $(document).height();
    var footerHeight = $('.footerglobal').outerHeight();
    if( position >= (docHeight - footerHeight)) {
      $('#govmetric').addClass('special');
    }
    else {
      $('#govmetric').removeClass('special');
    }
  }


$(document).ready(function() {

  // assign click function to open the service menu in mobile
  assignOpenMenu( '#openMenu', '.headerglobal__nav', '#openSearch', '.search' );

  // assign click function to open the search in mobile
  assignOpenMenu( '#openSearch', '.search', '#openMenu', '.headerglobal__nav');

  //assign click function to open the service menu in desktop
  assignOpenMenu( '#openServiceMenu', '.service-menu');

  stylePDF();

  //accordion();

  try {
    addViewAll();
  }
  catch(e){
  }

  $('.related__viewall').on("click", showMore);

  checkPlaceholder();

  wrapH2();

  serviceList();

  commsHeight();

  try {
  slickSlider();
  }
  catch(e){
    // if not on home page then we want to do nothing
  }

  try {
    moveGovmetric();
  }
  catch(e){
  }

}); // END DOC READY

$( window ).scroll(function(){
  try {
    moveGovmetric();
  }
  catch(e){
  }
});

$( window ).resize(function() {
  try {
    setTimeout( moveGovmetric(), 10000);
  }
  catch(e){
  }
});

// script to create scrollbars and shadows on tables from http://www.456bereastreet.com/archive/201309/responsive_scrollable_tables/
// Run on window load instead of on DOM Ready in case images or other scripts affect element widths
$(window).on('load', function() {
    // Check all tables. You may need to be more restrictive.
    $('.content table').each(function() {
        var element = $(this);
        // Create the wrapper element
        var scrollWrapper = $('<div />', {
            'class': 'scrollable',
            'html': '<div />' // The inner div is needed for styling
        }).insertBefore(element);
        // Store a reference to the wrapper element
        element.data('scrollWrapper', scrollWrapper);
        // Move the scrollable element inside the wrapper element
        element.appendTo(scrollWrapper.find('div'));
        // Check if the element is wider than its parent and thus needs to be scrollable
        if (element.outerWidth() > element.parent().outerWidth()) {
            element.data('scrollWrapper').addClass('has-scroll');
        }
        // When the viewport size is changed, check again if the element needs to be scrollable
        $(window).on('resize orientationchange', function() {
            if (element.outerWidth() > element.parent().outerWidth()) {
                element.data('scrollWrapper').addClass('has-scroll');
            } else {
                element.data('scrollWrapper').removeClass('has-scroll');
            }
        });
    });
});  // END WINDOW ON LOAD

})(jQuery); //end wrapping function
