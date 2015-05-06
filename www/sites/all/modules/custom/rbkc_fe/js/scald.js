(function($, Drupal) {
  /**
   * Override default atom theme function.
   */
  Drupal.theme.scaldEmbed = function(atom, context, options) {
    context = context ? context : Drupal.settings.dnd.contextDefault;
    var classname = 'image-cap dnd-atom-wrapper';
    classname += ' type-' + atom.meta.type;
    classname += ' context-' + context;
    if (atom.meta.align && atom.meta.align != 'none') {
      classname += ' atom-align-' + atom.meta.align;
      classname += ' float' + atom.meta.align;
    }

    var output = '<div class="' + classname + '"><div class="dnd-drop-wrapper image-cap__pic">' + atom.contexts[context] + '</div>';
    if (atom.meta.legend) {
      output += '<div class="image-cap__text dnd-legend-wrapper">' + atom.meta.legend + '</div>';
    }
    output += '</div>';

    // If there are options, update the SAS representation.
    if (options) {
      output = output.replace(/<!-- scald=\d+(.+?) -->/, '<!-- scald=' + atom.sid + ':' + context + ' ' + JSON.stringify(options) + ' -->');
    }

    return output;
  };

}) (jQuery, Drupal);  