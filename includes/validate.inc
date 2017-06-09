<?
define ("CM_CREW_CONNECT_PROJECT_GROUP_MEMBERS_VIEW", 'project_group_members');
    
/**
 * Implements hook_node_validate().
 */
function cm_crew_connect_node_validate($node) {
  //handle validate logic for the crew connect request
  if ($node->type == 'crew_connect_request') {
    
/************* FIXME - make sure that the user is a member of the producers
// may not be a need for this if we check roles and then just use the logged in
// user for non-staff/admin

    // MAKE SURE THE AUTHOR OF THE NODE IS A MEMBER OF THE PROJECT'S GROUP
    $author_id = $node->uid ? $node->uid : NULL;
    
    // get the project_id (which is also the og_membership_users.gid)
    $group_id = filter_input(INPUT_GET, 'field_crew_project_id');
    if ($group_id) {

      $members = array();

      $view_members = 
          views_get_view(CM_CREW_CONNECT_PROJECT_GROUP_MEMBERS_VIEW);          
      if (!$view_members) {
        drupal_set_message("Error Code 23289: Missing view:".
                           CM_CREW_CONNECT_PROJECT_GROUP_MEMBERS_VIEW, 'error');
      return $members;
      }
      $view_members->set_arguments(array($group_id));
      $view_members->execute();
      $results = $view_members->result;

     
      $i=0;
      foreach ($results as $members){        
        if ($author_id == $members->uid) {
          $is_producer = TRUE;
        } 
      }
    }
    else {
      //return;   // no associate producers so this is the right producer
    }
    
    if (!$is_producer) {
        $msg = "Error in cm_crew_connect_node_validate: " . 
                "Producer is not associated with this Project's Group";
        drupal_set_message($msg, 'error');                
    }
****************************/    

  }
  //handle validate logic for the crew connect application
  else if ($node->type == 'crew_connect_application') {

  }

}
