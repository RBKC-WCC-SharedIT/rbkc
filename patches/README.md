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

PATCH: wysiwyg_tools_plus-tab_builder_js--find_nested_children.patch
PROBLEM: The module only searches direct (first level) children for the designated
accordion header, which means the module doesn't work when we wrap contents in p tags
SOLUTION: Alter the jQuery to use 'find' function rather than 'children' to search
nested elements for the designated header.
RELATED ISSUES: N/A
TESTING STEPS: Create an accordion and check that the header link works properly.
NOTES: N/A

################################################################################