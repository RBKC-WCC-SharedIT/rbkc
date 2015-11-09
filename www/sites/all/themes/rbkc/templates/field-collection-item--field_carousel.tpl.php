<?php

/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
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
$internalID = $content['field_internal_carousel_link']['#items'][0]['target_id'];
$nicePath = drupal_get_path_alias('node/'.$internalID);
$internalURL = url($nicePath,array('absolute'=>TRUE));
$internalRender = $content['field_internal_carousel_link'];
$externalURL = $content['field_external_carousel_url']['#items'][0]['url'];
$externalH2 = $content['field_external_carousel_url']['#items'][0]['title'];
$externalTeaser = $content['field_external_carousel_teaser'];
?>

<div class="top-news__item">
  <a href="<?php
              if (empty($externalURL)) {
                print $internalURL;
              }
              else {
                print $externalURL;
              }
            ?>">
    <div class="top-news__img">
      <?php print render($content['field_carousel_image']);?>
    </div>
    <div class="top-news__text">
      <?php print render($internalRender);?>
      <?php if (!empty($externalH2)): ?>
        <h2><?php print $externalH2 ?></h2>
      <?php endif; ?>
      <?php if (!empty($externalTeaser)): ?>
        <p><?php print render($externalTeaser);?></p>
      <?php endif; ?>
    </div>
  </a>
</div>
