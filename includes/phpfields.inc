<?php

/**
 * This module contains functions that will return content to PHP fields in
 * views
 *
 */

/**
 * PHP field that is called by the "Page" display of crew_connect_search for
 * the Global PHP field "Sign up to Crew"
 */
function cm_crew_connect_sign_up_to_crew_link($row, $label) {
  global $user;

  $label = $label ? $label : t("More Info");
  $dashboard = 'user/'.$user->uid.'/cm_crew_connect';

  $link = l($label, 
	    "node/add/crew-connect-application",
	    array('query' => 
		  array('field_app_crew_connect_node'=>$row->nid,
			'field_app_producer'=>$user->uid,
			'destination'=>$dashboard, 
			)
		  )
	    );

  return $link;
}

/**
 * Called by the "My Projects" display on the crew_connect_project_alerts view
 * for the Global PHP Field. This provides the link to "Add a Crew Request"
 * for a particuler project
 */
function cm_crew_connect_add_request_field($row) {
  global $user;
  $project = node_load($row->nid);
  $uid = $project ? "/".$project->uid : "";

  $dashboard = 'user/'.$user->uid.'/cm_crew_connect';
  
  $query_args = array('field_crew_project_id'=>$project->nid,
		      'destination'=>$dashboard);

  $link = l(t("Request Crew for your Show"), "node/add/crew-connect-request", 
	    array('query'=>$query_args));

      
  $text = $project->title." ($link)";
  return $text;
}

/**
 * Called by the "Admin Search" display on the crew_connect_search view for
 * the Global PHP field "Delete Request"
 */
function cm_crew_connect_delete_request_field($row, $view) {
  if ($view->name == 'crew_connect_search' 
      && $view->current_display == 'page_1') {

      if ($row->nid_1) {
        return "N/A";
      }
      
      $link = l("Delete Request",
          "node/".$row->nid."/delete",
          array('query'=>array('destination' => 
             "admin/cm_crew_connect/search")));
       
      return $link;   
      
  }
}
/**
 * Called by the "Future Crew Requests (incl cancel link)" display of the
 * crew_connect_crew_requests view for the Global PHP Field "Cancel"
 */
function cm_crew_connect_cancel_request_field($row) {
  global $user;
  if ($row->nid) {
    $application = cm_crew_connect_get_application_for_request($row->nid);
    if ($application) {
      return "N/A";
    }
  }
  $link = l("Cancel",
	    "node/".$row->nid."/delete",
	    array('query'=>array('destination' => 
				 "user/".$user->uid."/cm_crew_connect")));
      
  return $link;
}

/**
 * Called by the "Future Crew Requests" display of the 
 * crew_connect_crew_requests view for the Global PHP Field "Edit"
 */
function cm_crew_connect_edit_request_field($row) {
  global $user;
   if ($row->nid) {
    $application = cm_crew_connect_get_application_for_request($row->nid);
    if ($application) {
      return "N/A";
    }
  }
  
  $link = l("Edit", "node/".$row->nid."/edit",
	    array('query'=>array('destination' => 
				 "user/".$user->uid."/cm_crew_connect")));
      
  return $link;
}
/**
 * Called by the "Future Crew Requests" display of the 
 * crew_connect_crew_requests view for the Global PHP Field "Applicant Name"
 */
function cm_crew_connect_applicant_name($row) {
  if ($row->nid) {
    $application = cm_crew_connect_get_application_for_request($row->nid);

    if ($application) {
      $applicant_name = cm_crew_connect_get_display_name($application->uid);
      return $applicant_name;
    }
  }

  return '';
}

/**
 * PHP Header that is called by the "Page" display of crew_connect_search for
 * the Global PHP Header
 */
function cm_crew_connect_search_page_header() {
  $ret = "";
  $path = "admin/cm_crew_connect/search";

  if ($router_item = menu_get_item($path)) {
    if ($router_item['access']) {
      // The user has access to the page in $path.
      $ret = l("Admin Search", $path);
    }
    $ret = "<h2><strong>$ret</strong></h2>";
  }
  return $ret;
}
