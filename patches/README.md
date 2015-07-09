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

################################################################################

PATCH: wysiwyg_tools_plus-accordion_js-add_p_tags_remove_whitespace
PROBLEM: When applied the accordion strips p tags from content and inserts a non-breaking
space before text.  This means that block elements can't be inserted into the accordion.
SOLUTION: Alter the JavaScript to wrap contents in p tags and remove non-breaking space.
RELATED ISSUES: wysiwyg_tools_plus-tab_builder_js--target_header_links_properly.patch
TESTING STEPS: Create an accordion, see that there is no non-breaking space
inserted into the body of the accordion, check that content is wrapped in p tags
and check that you can add carriage returns/block elements in WYWIWYG area that don't
break the accordion body.
NOTES: N/A

################################################################################

PATCH: panels-preview_open_new_tab-2319517.patch
PROBLEM: Panels preview is displayed in the administration theme so does not
give the editor a clear indication of the what the page will look like if they
save it.
SOLUTION: Applied a modified version of the patch at
https://www.drupal.org/node/2319517, the modification being to make the preview
open in a new browser tab.
RELATED ISSUES: N/A
TESTING STEPS: Make an edit to a panel, click update and preview, click on the
Preview available here link, observe a new browser tab is opened and the edited
version of the page is displayed.
NOTES: N/A

################################################################################
