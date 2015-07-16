(function($) {

  var Sitewide = {

    settings: {
      //number of items displayed by default in 'more in...' related menu
      numRelated: 3,
      //number of items displayed by default in a sub hub topic
      numSubHubTopics: 3,
      //html for simple 'view all' link
      paraViewAll: '<p class="view-all" title="View other, related pages"><span>View all</span></p>'
    },

    init: function() {
      $.fn.extend(this.displayViewAll);
      this.updateDisplay();
      this.legacyIESupport();
      this.bindUIActions();
    },

    runOnResize: function() {

    },

    runOnOnload: function() {

    },

    bindUIActions: function() {
      // assign click function to open the service menu in mobile
      this.openClose( '#openMenu', '.headerglobal__nav', '#openSearch', '.search' );
      // assign click function to open the search in mobile
      this.openClose( '#openSearch', '.search', '#openMenu', '.headerglobal__nav');
      //assign click function to open the service menu in desktop
      this.openClose( '#openServiceMenu', '.service-menu');

      $('.service-menu__close').on("click", function() {
        $('.service-menu').addClass('hide');
        $('#openServiceMenu').removeClass('active');
      });

      $('.view-all').on("click", this.showMore);
    },

    updateDisplay: function() {
      this.wrapH2();
      this.moveGovmetric();
      //$('.related ul').displayViewAll(this.settings.numRelated, 'li', this.settings.paraViewAll);
      //$('.sub-hub-topic ul').displayViewAll(this.settings.numSubHubTopics, 'li', this.settings.paraViewAll);
      //$('.servicelist__wrap ul').displayViewAll(1, 'ul');
    },

    legacyIESupport: function() {
      // for IE8 support
      this.checkPlaceholder();
      // for IE8 and IE9 support
      this.commsHeight();
    },

     // higher order function to test if there are more items than we want to show by default
    // (extra items are pre-hidden with css but we need to know if they exist we we can add 'view all')
    itemsHidden: function (numDefault, elems) {
      var childNumber = $(this).find(elems);
      var hidden = childNumber.length > numDefault ? true : false;
      return hidden;
    },

    // where there are more than n elements in menu display 'view all'
    displayViewAll: function(num, elems, viewAllElem) {
      $(this).each(function() {
        var existing = $(this).find($('viewall'));
        // if viewall element exists but is hidden, unhide it
        if (existing) {
          existing.removeClass('hide');
        }
        // else insert it
        else {
          if (itemsHidden(num, elems)) {
            viewAllElem.insertAfter($(this));
          }
        }
      });
    },

    showMore: function() {

      var elem = $(this);
      elem.parent().find('li:gt(2)').slideToggle('150');

      if (elem.text() === "View all") {
        elem.find('span').text("View less").attr('title', 'View fewer links').addClass('open');
      }
      else {
        elem.find('span').text("View all").attr('title', 'View more links').removeClass('open');
      }
    },

    openClose: function(thisButton, thisMenu, otherButton, otherMenu) {
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
      });
    },

    wrapH2: function() {
      $('.content h2').each(function() {
        if ($(this).height() > 40) {
          $(this).css("line-height", "2rem");
        }
      });
    },

    moveGovmetric: function() {
      //position of bottom of viewport
      var position =  $(window).scrollTop() + $(window).height();
      var docHeight = $(document).height();
      var footerHeight = $('.footerglobal').outerHeight();
      position >= (docHeight - footerHeight) ? $('#govmetric').addClass('special') : $('#govmetric').removeClass('special');
    },

    commsHeight: function() {
      //make comms panels correct height when no flexbox support
      if  (!$('html').hasClass('flexbox')) {
        var newsBoxHeight = $('.comms__news').outerHeight();
        //console.log(newsBoxHeight);
        var imgBoxHeight = $('.comms__img').outerHeight();
        var blogBoxHeight = (newsBoxHeight - imgBoxHeight - 30);
        //console.log(blogBoxHeight);
        $('.comms__feature .comms__item').css('height', blogBoxHeight + "px");
      }
    },

    stylePDF: function() {
      $('a[href^="IDOC"], a[href$=".pdf"], a[href*="idoc.ashx"], a[href$=".docx"], a[href$=".doc"]').each(function(){
        if (!$(this).parents('.context-file_with_size').length) {
          var linkElement = $(this);
          var linkText = linkElement.text();
          var linkHref =  $(this).attr('href');
          var linkParent = $(this).parents("li:first, p:first");
          linkParent.addClass("docLink");
          $('<br>').appendTo(linkElement);
          // Create the Icon with the duplicated link
          var Icon =
            $('<a />', {
              'class': 'docLink-icon',
              'href' : linkHref,
              //to hide extra link from screen reader
              'role' : 'presentation',
              'tabindex' : "-1"
            }).prependTo(linkParent);
        }
      });
    },

    slickSlider: function() {
      if ($('.local__slider').length) {
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
                swipe: true
              }
            }
          ]
        });
      }
    }

  }


$(document).ready(function() {

  Sitewide.init();

});


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
            scrollWrapper.before('<p class="scroll-indicator">Scroll</p>');
        }
        // When the viewport size is changed, check again if the element needs to be scrollable
        $(window).on('resize orientationchange', function() {
            if (element.outerWidth() > element.parent().outerWidth()) {
                element.data('scrollWrapper').addClass('has-scroll');
            } else {
                element.data('scrollWrapper').removeClass('has-scroll');
                $('.scroll-indicator').remove();
            }
        });
    });
});  // END WINDOW ON LOAD

//end wrapping function
})(jQuery);
