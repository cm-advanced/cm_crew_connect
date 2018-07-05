<?php
/**
 * Implements rules import and config api 
 */
function cm_crew_connect_default_rules_configuration() {

  $configs = array();
// each rule gets added to the config array 
// exactly as output from rules export 
// and enclosed in '  '   
//$configs["rulename"] = 'rules export';
// $items['rules_approve_content'] = entity_import('rules_config', '{
$configs["rules_crew_conn_email_confirm_request_active"] = '{ "rules_crew_conn_email_confirm_request_active" : {
    "LABEL" : "crew_conn_email_confirm_request_active",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "crew connect", "email" ],
    "REQUIRES" : [ "rules" ],
    "ON" : [ "node_insert" ],
    "IF" : [
      { "node_is_of_type" : {
          "node" : [ "node" ],
          "type" : { "value" : { "crew_connect_request" : "crew_connect_request" } }
        }
      }
    ],
    "DO" : [
      { "mail" : {
          "to" : [ "node:author:mail" ],
          "subject" : "Crew Request Position Submitted ",
          "message" : "Dear [node:field-crew-producer-name],\r\n \r\nThis email confirms the following crew request:\r\n \r\nDate: [node:field_crew_start_date]\r\nStart Time: [node:field_crew_start_time] \r\nShift Length: [node:field_crew_length_of_time] hours\r\nLocation: [node:field-crew-location]\r\nPosition: [node:field-crew-positions]\r\nDetails:\r\n[node:body]\r\n\r\nEmail address: [node:field_crew_requesters_pub_email]\r\n\r\nPlease confirm that you have a facility reservation for this crew request.\r\n \r\nIf you need to cancel your Application please contact us as far in advance as possible.\r\n \r\nYou will be notified at this email address when a Certified Producer has signed up to fulfill this request.\r\n  \r\nThank you.\r\n",
          "language" : [ "" ]
        }
      }
    ]
  }
}';


$configs["rules_crew_conn_e_request_updated"] = '{ "rules_crew_conn_e_request_updated" : {
    "LABEL" : "crew_conn_email_confirm_request_updated",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "crew connect", "email" ],
    "REQUIRES" : [ "rules" ],
    "ON" : [ "node_update" ],
    "IF" : [
      { "node_is_of_type" : {
          "node" : [ "node" ],
          "type" : { "value" : { "crew_connect_request" : "crew_connect_request" } }
        }
      }
    ],
    "DO" : [
      { "mail" : {
          "to" : [ "node:author:mail" ],
          "subject" : "Crew Request Position Updated",
          "message" : "Dear [node:field-crew-producer-name],\r\n\r\nThis email confirms that your crew request has been modified:\r\n \r\nDate: [node:field_crew_start_date]\r\nStart Time: [node:field_crew_start_time] \r\nShift Length: [node:field_crew_length_of_time]  hours\r\nLocation: [node:field-crew-location]\r\nPosition: [node:field-crew-positions]\r\nDetails:\r\n[node:body]\r\n\r\nEmail address: [node:field_crew_requesters_pub_email]\r\n\r\nPlease confirm that you have a facility reservation for this crew request.\r\n \r\nIf you need to change this request or it was made in error, please click here to modify or cancel it.\r\n \r\nYou will be notified at this email address when an Certified Producer has signed up to fulfill this request.\r\nThank you\r\n",
          "language" : [ "" ]
        }
      }
    ]
  }
}';


//$configs['rulename'] = 'rules export';


// $configs[] = '{ "rules_crew_conn_email_requestauthor_app_submit" : {
//     "LABEL" : "crew_conn_email_requestauthor_app_submit",
//     "PLUGIN" : "reaction rule",
//     "ACTIVE" : false,
//     "TAGS" : [ "crew connect", "email" ],
//     "REQUIRES" : [ "rules", "php" ],
//     "ON" : [ "node_insert" ],
//     "IF" : [
//       { "node_is_of_type" : {
//           "node" : [ "node" ],
//           "type" : { "value" : { "crew_connect_application" : "crew_connect_application" } }
//         }
//       }
//     ],
//     "DO" : [
//       { "entity_fetch" : {
//           "USING" : { "type" : "node", "id" : [ "node:field-app-crew-connect-node:nid" ] },
//           "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "request node" } }
//         }
//       },
//       { "entity_fetch" : {
//           "USING" : { "type" : "user", "id" : [ "entity-fetched:author:uid" ] },
//           "PROVIDE" : { "entity_fetched" : { "user_fetched" : "Fetched user" } }
//         }
//       },
//       { "mail" : {
//           "to" : [ "user-fetched:mail" ],
//           "subject" : "Someone has applied to your Crew Connect Request",
//           "message" : "\u003C?php\r\ncivicrm_initialize();\r\n\t$volunteer_cid = CRM_Core_BAO_UFMatch::getContactID($node-\u003Euid);\r\n\r\n\t$volunteer_name = civicrm_api3(\u0027Contact\u0027, \u0027get\u0027, \r\n\t\t\t       array(\r\n\t\t\t\t     \u0027sequential\u0027 =\u003E 1,\r\n\t\t\t\t     \u0027id\u0027 =\u003E $volunteer_cid,\r\n                                     \u0027return\u0027 =\u003E \u0022display_name\u0022,\r\n\t\t\t\t     ));\r\n\r\necho \u0022This email confirms that \u0022. $volunteer_name[\u0027values\u0027][0][\u0027display_name\u0027]. \u0022 signed up for the following crew assignment for \u0022.$entity_fetched-\u003Etitle;\r\necho \u0022\\r\\n\u0022;\r\necho \u0022\\r\\n\u0022;\r\n$date = date_create($entity_fetched-\u003Efield_crew_start_date[\u0027und\u0027][0][\u0027value\u0027]);\r\necho \u0022Date: \u0022.date_format($date, \u0027m\/d\/Y\u0027);\r\n?\u003E\r\n\r\nStart Time: [entity-fetched:field_crew_start_time] \r\nShift Length: [entity-fetched:field_crew_length_of_time] hours\r\nLocation: [entity-fetched:field-crew-location]\r\nPosition: [entity-fetched:field-crew-positions]\r\nDetails:\r\n[entity-fetched:body]\r\n\u003C?php\r\n\/\/echo \u0022test \\r\u0022;\r\n\/\/echo print_r($entity_fetched-\u003Enid);\r\n\/\/echo $entity_fetched-\u003Efield_crew_share_email[\u0027und\u0027][0][\u0027value\u0027];\r\nif ($node-\u003Efield_app_share_email [\u0027und\u0027][0][\u0027value\u0027] == \u0022yes\u0022){\r\n\/\/echo  \u0022Contact Email: \u0022.$entity_fetched-\u003Efield_crew_requesters_pub_email[\u0027und\u0027][0][\u0027value\u0027];\r\necho \u0022Contact Email: \u0022.$node-\u003Efield_app_apps_public_email[\u0027und\u0027][0][\u0027value\u0027];\r\necho \u0022 \\r\\n\u0022;\r\n}\r\n\r\n \r\necho \u0022 If there is an email address provided above, \u0022.$volunteer_name[\u0027values\u0027][0][\u0027display_name\u0027].\u0022  is open to being contacted via email with questions about this crew assignment.\u0022;\r\n?\u003E\r\n \r\nThank you",
//           "language" : [ "" ]
//         }
//       }
//     ]
//   }
// }';


foreach ($configs as $key => $config) {
    $results[$key] = rules_import($config);
  }  
//$configs = rules_import($configs);
  return $results;
}

