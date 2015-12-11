jQuery(document).ready(function ($) {

	$('#toggle_link_final').click(function(e) {
		
		$('#content_difference').hide();
		$('#content_new').show();
		e.preventDefault();
	});

	$('#toggle_link_finalwithmarkup').click(function(e) {
		$('#content_difference').show();
		$('#content_new').hide();
		e.preventDefault();
	});

});
