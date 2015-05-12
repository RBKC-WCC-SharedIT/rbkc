<?php
/**
 * @file
 * Leaflet theme implementation for Scald Map.
 *
 * - $vars['context']: scald context
 * - $vars['id']: atom entity id
 * - $vars['zoomlevel']: map zoom level, override if you want,
 *       integer between 0 and 18, default 8
 */
?>
<iframe width="540" height="400" frameborder="0" style="border:0"
        src="/scald/mapleaflet/render/<?php print $vars['id'] . '/' . $vars['zoomlevel']; ?>"></iframe>
