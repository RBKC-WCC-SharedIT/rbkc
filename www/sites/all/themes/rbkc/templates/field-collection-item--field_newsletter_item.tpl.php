<?php

/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.g
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */

$title = $content['field_external_link']['#items'][0]['title'];
$url = $content['field_external_link']['#items'][0]['url'];
$backgroundURL = file_create_url($content['field_background_image']['#items'][0]['uri']);
$style = "background-image:url(".$backgroundURL."); background-size: cover";
$description = $content['field_description']['#items'][0]['safe_value'];
?>

<li class="col4">
  <a class="newsletters__link" href="<?php print $url; ?>">
 <div class="newsletters__caption">
  <?php print $title; ?>
  <p class="newsletters__description small-text"><?php print $description; ?></p>
 </div>

    <div class="image" style="<?php print $style; ?>"></div>

    </a>
   </a>
</li>
