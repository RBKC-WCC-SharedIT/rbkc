(function() { 

	var toggleClick,
		headerMob,
		headerDesk,
		stylePDF,
		accordion,
		addViewAllMore,
		addViewAllElsewhere,
		showMore,
		respWrap,
		checkPlaceholder,
		serviceList,
		commsHeight,
		hideLabels;
	
 
 //recreating toggle function
	$.fn.toggleClick = function(){
		var methods = arguments, // store the passed arguments for future reference
			count = methods.length; // cache the number of methods 

		//use return this to maintain jQuery chainability
		return this.each(function(i, item){
			// for each element you bind to
			var index = 0; // create a local counter for that element
			$(item).click(function(){ // bind a click handler to that element
				return methods[index++ % count].apply(this,arguments); // that when called will apply the 'index'th method to that element
				// the index % count means that we constrain our iterator between 0 and (count-1)
			});
		});
	};	 

		
	function headerMob() { // opening menu and search in mobile view  
		$('.openMenu').click(function() {
			$('.search input').fadeOut(0); //hide
			$('.search').slideUp(50).css("width", "0"); //hide
			$('.openSearch').removeClass('active');
			if($('.menu').is(":hidden")){
				$('.menu').css("width", "auto").slideDown(150); //show
				$(this).addClass('active');
			} else {
				$('.menu').slideUp(50).css("width", "0"); //hide
				$(this).removeClass('active');
			}
		});	  
		$('.openSearch').click(function() {
			$('.menu').slideUp(50).css("width", "0"); //hide
			$('.openMenu').removeClass('active');
			if($('.search').is(":hidden")){
				$('.search input').fadeIn(200); 
				$('.search').css("width", "auto").slideDown(200); //show
				$(this).addClass('active');
			} else {
				$('.search input').fadeOut(0); //hide
				$('.search').slideUp(50).css("width", "0"); //hide
				$(this).removeClass('active');
			} 
		});
	} //end headerMob

	function headerDesk() {  // the Service menu button in desktop view  	 
		$('.openServiceMenu').click(function() {
			if($('.serviceMenu').is(":hidden")){
				$('.serviceMenu').slideDown(150);
				$(this).addClass('active');
			} else {
				$('.serviceMenu').slideUp(150);
				$(this).removeClass('active');
			}
		});	  
		$('.serviceMenu-close').click(function() {
			$('.serviceMenu').slideUp(150).addClass('hide');
			$('.openServiceMenu').removeClass('active');
		});	
	} //end headerDesk
	
	function stylePDF() { // styling PDF links with icon 
		
		$('a[href^="IDOC"], a[href$=".pdf"], a[href*="idoc.ashx"], a[href$=".docx"], a[href$=".doc"]').each(function(){  
			
			var linkElement = $(this);
					
			var linkText = linkElement.text();
					
			var	linkHref =  $(this).attr('href');
					
			var linkParent = $(this).parents("li:first, p:first");		
						
			linkParent.addClass("docLink");  // adding a class to the link's parent

			$('<br>').appendTo(linkElement);
								
			// Create the Icon with the duplicated link
			var Icon = 
				$('<a />', {  // creating a div with class of docLink
					'class': 'docLink-icon',
					'href' : linkHref,
					'role' : 'presentation',   //to hide from screen reader
					'tabindex' : "-1", // to hide from screen reader
				}).prependTo(linkParent);
						
		}); // end each function
	} // end stylePDF
	
	 
	function accordion() {	// accordion menu
		$('.accordion').each(function(){   
			$(this).next('ul').addClass('accordionContents'); /* next ul is also hidden using .has-js class in CSS */
		}); // end each
			
		$('.accordion').toggleClick( 
			function() {
			$(this).next('.accordionContents').addClass('show');   
			$(this).addClass('close');
			}, 
			function() {
			$(this).next('.accordionContents').removeClass('show'); 
			$(this).removeClass('close');
			}
		); //end of toggleClick   
	} // end accordion
	
	
	// show/hide right hand column menu
	function addViewAllMore() {
		var childNumber = $('.related-more ul').find('li');
			if (childNumber.length > 3) {			
					$('<p class="viewAll">View all</p>').attr('title', 'View other, related pages').insertAfter('.related-more ul');
			}
	}
	function addViewAllElsewhere() {
		var childNumber = $('.related-elsewhere ul').find('li');
			if (childNumber.length > 3) {			
					$('<p class="viewAll">View all</p>').attr('title', 'View other, related pages').insertAfter('.related-elsewhere ul');
			}
	}
	function showMore() {
		$(this).parent().find('li:gt(2)').slideToggle('150');
				if ($(this).text() === "View all") {
					$(this).text("View less").attr('title', 'View fewer links');/* Toggles the title text  */
				}
				else {
					$(this).text("View all").attr('title', 'View more links');/* Toggles the title text */
					}
	} 	// end show/hide right hand column menu
	
	function LHCtrim() {   // Left hand menu on Publications page - SP October 2014
	
		if($('.internalTOC').length > 0) {  // if statement stops reference error on non-pub pages
			//find the highest level in the menu
			var i=0;
			while ($('.internalTOC .level' + i).length > 0 ) {
				var lvl=i;  //number of levels (will end on highest)
				i++;
			}
		
			//show highest level
			$('.internalTOC .level' + lvl).addClass("showthis");
			
			//and hide all lower levels 
			for (a=0; a<lvl; a++) {
				$('.internalTOC .level' + a).addClass("displayNone");
			}				
			$('.internalTOC ul').slideDown(0);
		}	
	} // end Publications menu
	
	
	// if broswer does not support html5 placeholder, add value to form field
	function checkPlaceholder() {
		if(!Modernizr.input.placeholder){		
		   $('.search_full_text input').val('Enter search terms...');
		   $('.search_full_text input').click(function() {
				function doOnce() {	
					$('.search_full_text input').val("");
					doOnce = function () { alert('hi');};
				}
				doOnce();
		   });
		   
		}	
	} // end check placeholder

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
		$('.local-slider').slick({
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
	
		  
	
		 	

$(document).ready(function() {
  
	headerMob();
	  
	headerDesk();
	  
	stylePDF();
	 
	accordion(); 
	
	addViewAllMore();
	
	addViewAllElsewhere();
	
	$('.viewAll').on("click",showMore);

	LHCtrim();
		
	checkPlaceholder();
	
	serviceList();
	
	commsHeight(); 
	
	try	{
	slickSlider();
	}
	catch(e){
	}
	
  
}); // END DOC READY


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

})(); //end wrapping function