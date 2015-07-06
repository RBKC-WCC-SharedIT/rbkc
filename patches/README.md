# scald_module_dndck4.patch
### Version
7.x-1.x-dev @ 2015-May-07
### Problem
Scald only supports CKeditor standalone and not the WYSIWYG API version when using
dnd.
### Solution
This patch integrates dndck4 via a plugin for WYSIWYG.

################################################################################

PATCH: wysiwyg_tools_plus-tab_builder_js--target_header_links_properly.patch
PROBLEM: Prevents any link in the accordion body from being pulled up into
the accordion head. This is because in line 43 of tab-builder.js in
wysiwyg_tools_plus the script pulls out any child <a> elements and inserts them
before the accordion body, when it should be targeting the head link
specifically. ALSO: The module only searches direct (first level) children for the designated
accordion header, which means the module doesn't work when we wrap contents in p tags.

SOLUTION: A header-link-specific selector in the Jquery and alter code to use 'find'
function rather than 'children' to search nested elements for the designated header.
RELATED ISSUES:  wysiwyg_tools_plus-accordion_js--wrap_contents_in_p_tags.patch
TESTING STEPS: Create an accordion with a anchor link, ensure it is not pulled
 into the accordion head. Check that the header link works properly.
NOTES: N/A

