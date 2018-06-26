<?php

/**
 * This is not a real drupal hook but instead is called from both the 
 * hook_node_update() and the hook_node_insert() hooks implmented by this 
 * module. See cm_crew_connect_node_insert() and cm_crew_connect_node_update() 
 * below.
 *
 */
function cm_crew_connect_node_postsave(&$node) {
  if ($node->type == 'crew_connect_request') {
    //get project id
    $project_nid = 
      cm_crew_connect_get_single_field_value($node,
					     'field_crew_project_id',
					     'target_id');
    
    //FETCH PROJECT AS IT WILL BE USED IN THE REQUEST TITLE
    $project = $project_nid ? node_load($project_nid) : NULL;
    
    $preset_project = variable_get('cc_project_preset', TRUE); 
    if ($preset_project && $project) {
      $field_name = 'field_crew_public_description';
      $description = cm_crew_connect_get_single_field_value($node,
							    $field_name);
      if ($description) {

	$field_name = variable_get('cc_project_description_field', '');
	$field = &$project->{$field_name}; 
	$field[LANGUAGE_NONE][0]['value'] = $description;
	field_attach_update('node', $project);
      }	
    }
  }
  else if ($node->type == 'crew_connect_application') {
    //setting session variable so we have it to override status message later
    $_SESSION['cm_crew_connect_new_application'] = $node;

    $request_nid = 
      cm_crew_connect_get_single_field_value($node, 
					     'field_app_crew_connect_node',
					     'target_id');
 
    //resave Crew Connect Request node so computed field can be set
    $request = node_load($request_nid);
    if ($request) {
      $links = cm_crew_connect_event_links($request);
      $request->field_civicrm_event_link[LANGUAGE_NONE][0]['value'] =
	implode(' -- ', $links);
      field_attach_update('node', $request);
    }

  }
}

/**
 * Implements hook_node_update().
 *
 * This is the hook after an existing node is saved to the db.
 * It will call cm_crew_connect_post_save function.
 *  
 */
function cm_crew_connect_node_update($node) {
  $_SESSION['cm_crew_connect_deleting_application'] = FALSE;
  $_SESSION['cm_crew_connect_request_nid'] = $node->nid;
  cm_crew_connect_node_postsave($node);
}

/**
 * Implements hook_node_inser().
 *
 * This is the hook after an existing node is inserteed into the db. 
 * It will call the cm_crew_connect_post_save function.
 * function
 *  
 */
function cm_crew_connect_node_insert($node) {
  $_SESSION['cm_crew_connect_deleting_application'] = FALSE;
  $_SESSION['cm_crew_connect_request_nid'] = $node->nid;
  cm_crew_connect_node_postsave($node);
}

/**
 * Implements hook_node_inser().
 *
 * This is the hook after an existing node is inserteed into the db. 
 * It will call the cm_crew_connect_post_save function.
 * function
 *  
 */
function cm_crew_connect_node_delete($node) {
  $_SESSION['cm_crew_connect_deleting_application'] = TRUE;
  $_SESSION['cm_crew_connect_request_nid'] = $node->nid;
  cm_crew_connect_node_postsave($node);
}

