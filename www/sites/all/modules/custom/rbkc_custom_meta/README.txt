Summary
=======

This module adds custom meta tags, primarily to be consumed by our search engine.
Currently, it only adds one tag:

    <meta name="search-category" content="..." />


Instructions for using this module
==================================

1. Copy this module into the sites/all/modules/custom directory.

2. In the rbkc_custom_meta.install file, within rbkc_custom_meta_install(), ensure that the "administrator" role ID is correct for your site, in the user_role_change_permissions() function call.

3. If you want every page on the site to have the same category, put the following into the rbkc_custom_meta_install() function, and replace "Category name" with the correct one for your site:

	// use a custom category for search
	variable_set('rbkc_custom_meta_use_sitewide_category', 1);

	// set the search category for all pages on this site
	variable_set('rbkc_custom_meta_sitewide_category', 'Category name');

4. The settings above can be changed in the Admin UI at /admin/structure/site_category.

5. Enable the module via a hook_update in the relevant deploy module.

That's it.

