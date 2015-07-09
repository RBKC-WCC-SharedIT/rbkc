# scald_module_dndck4.patch
### Version
7.x-1.x-dev @ 2015-May-07
### Problem
Scald only supports CKeditor standalone and not the WYSIWYG API version when using
dnd.
### Solution
This patch integrates dndck4 via a plugin for WYSIWYG.

################################################################################

PATCH: wysiwyg_tools_plus-tab_builder_js--anchor_links_in_accordion_body.patch
PROBLEM: Prevents anchor links in the accordion body from being pulled up into
the accordion head. This is because in line 43 of tab-builder.js in
wysiwyg_tools_plus the script pulls out any child <a> elements and inserts them
before the accordion body, when it should be targeting the head link
specifically.
SOLUTION: A change to the selector in the JavaScript.
RELATED ISSUES: N/A
TESTING STEPS: Create an accordion with a anchor link, ensure it is not pulled
 into the accordion head.
NOTES: N/A

################################################################################

PATCH: wysiwyg_tools_plus-accordion_js--remove_non_breaking_space_in_accordion_body.patch
PROBLEM: There is a non-breaking space that is inserted into the body of every
accordion.
SOLUTION: Alter the JavaScript to remove the non-breaking space.
RELATED ISSUES: N/A
TESTING STEPS: Create an accordion, see that there is no non-breaking space
inserted into the body of the accordion.
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
