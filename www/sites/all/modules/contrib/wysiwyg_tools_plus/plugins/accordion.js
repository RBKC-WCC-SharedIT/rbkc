(function ($) {
	Drupal.wysiwyg.plugins.accordion = {
	  invoke: function(data,settings,instanceId) {
      Drupal.wysiwyg.instances[instanceId].insert('<div class="ready-accordion">' + data.content + '</div>');
		},
	}
}(jQuery));