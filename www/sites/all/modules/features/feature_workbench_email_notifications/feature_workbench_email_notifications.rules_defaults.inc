<?php
/**
 * @file
 * feature_workbench_email_notifications.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function feature_workbench_email_notifications_default_rules_configuration() {
  $items = array();
  $items['rules_notify_editor_when_page_published'] = entity_import('rules_config', '{ "rules_notify_editor_when_page_published" : {
      "LABEL" : "Notify editor when page published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } },
        { "AND" : [] },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:current-revision-author-mail]",
            "subject" : "Your webpage \\u0027[node:title]\\u0027 has been approved and published.\\r\\n\\r\\n",
            "message" : "Hello\\r\\n\\r\\nThe page you submitted for review, [node:title] ([node:url]) has been approved and published.\\r\\n\\r\\nRegards,\\r\\n\\r\\nWeb Editorial team\\r\\n",
            "from" : "Intrasup@rbkc.gov.uk",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
