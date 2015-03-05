<?php

/**
 * @file
 * Default theme implementation to navigate books.
 *
 * Presented under nodes that are a part of book outlines.
 *
 * Available variables:
 * - $tree: The immediate children of the current node rendered as an unordered
 *   list.
 * - $current_depth: Depth of the current node within the book outline. Provided
 *   for context.
 * - $prev_url: URL to the previous node.
 * - $prev_title: Title of the previous node.
 * - $parent_url: URL to the parent node.
 * - $parent_title: Title of the parent node. Not printed by default. Provided
 *   as an option.
 * - $next_url: URL to the next node.
 * - $next_title: Title of the next node.
 * - $has_links: Flags TRUE whenever the previous, parent or next data has a
 *   value.
 * - $book_id: The book ID of the current outline being viewed. Same as the node
 *   ID containing the entire outline. Provided for context.
 * - $book_url: The book/node URL of the current outline being viewed. Provided
 *   as an option. Not used by default.
 * - $book_title: The book/node title of the current outline being viewed.
 *   Provided as an option. Not used by default.
 *
 * @see template_preprocess_book_navigation()
 *
 * @ingroup themeable
 */
?>
<?php if ($tree || $has_links): ?>
  <div class="contrast pag">
    <?php if ($has_links): ?>
      <?php if ($prev_url): ?>
        <a class="pag__prev-name" href="<?php print $prev_url; ?>"><span><?php print $prev_title; ?></span></a>
      <?php endif; ?>
      <div class="pag-divider"></div>
      <?php if ($next_url): ?>
        <a href="" class="page-next" title="<?php print t('Go to next page'); ?>"></a>
        <a class="pag__next-name" href="<?php print $next_url; ?>"><span><?php print $next_title; ?></span></a>
      <?php endif; ?>
    <?php endif; ?>
  </div>
<?php endif; ?>