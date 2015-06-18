<?php
/**
 * @file
 * Layout template for Planer three region layout.
 *
 * Regions:
 * - first
 * - second
 * - third
 */
?>
<?php if (isset($content['first'])) {print $content['first'];} ?>
<?php if (isset($content['second'])) {print $content['second'];} ?>
<?php if (isset($content['third'])) {print $content['third'];} ?>