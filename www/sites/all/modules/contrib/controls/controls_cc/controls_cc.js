(function($) {

Drupal.controlsCC = Drupal.controlsCC || {};
Drupal.controlsCC.behaviors = Drupal.controlsCC.behaviors || {};

/**
 * Core behavior for Controls Create Content.
 */
Drupal.behaviors.controlsCC = {
  attach: function (context, settings) {
    var $controlsCC = $('#controls-cc:not(.controls-cc-processed)', context);
    
    if (!$controlsCC.length) {
      // Doesn't exist on the page
      return;
    }
    
    $controlsCC
      .each(function(){
        $('body', context).append($controlsCC);
        Drupal.controlsCC.attachBehaviors(context, settings, $controlsCC);
      });
  }
};

/**
 * Attach behaviors.
 */
Drupal.controlsCC.attachBehaviors = function (context, settings, $controlsCC) {
  $controlsCC.addClass('controls-cc-processed');
  $.each(Drupal.controlsCC.behaviors, function() {
    this(context, settings, $controlsCC);
  });
};

})(jQuery);
