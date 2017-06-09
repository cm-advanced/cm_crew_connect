<?

/**
 * This is not a real drupal hook but instead is called from both the 
 * hook_node_update() and the hook_node_insert() hooks implmented by this 
 * module. See cm_crew_connect_node_insert() and cm_crew_connect_node_update() 
 * below.
 *
 */
function cm_crew_connect_node_postsave(&$node) {
  if ($node->type == 'crew_connect_request') {

  }
  else if ($node->type == 'crew_connect_application') {
    //setting session variable so we have it to override status message later
    $_SESSION['cm_crew_connect_new_application'] = $node;

    $request_nid = 
      cm_crew_connect_get_single_field_value($node, 
					     'field_app_crew_connect_node',
					     'target_id');
 

    $request = node_load($request_nid);
    if ($request) {
      node_save($request);
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

