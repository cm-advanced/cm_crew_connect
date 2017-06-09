<?

/**
 * This module contains functions that will return content to PHP fields in
 * views
 *
 */



/**
 * This will be the form that will be on the Project Alerts View
 */
function cm_crew_connect_project_alert_content($row) {
  $content = 
    drupal_render(drupal_get_form('cm_crew_connect_project_alert_form',
				  $row->nid));
  return $content;
}

function cm_crew_connect_sign_up_to_crew_link($row, $label) {
  global $user;

  $label = $label ? $label : t("More Info");
  //FIXME ADD AS A REAL FORM VARIABLE
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

function cm_crew_connect_add_request_field($row) {
  $project = node_load($row->nid);
  $uid = $project ? "/".$project->uid : "";

  // DESTINATION IS NOT NEEDED IF THERE IS AN INTISTERTIAL FORM
  if (!$uid) {
    return 'N/A';
  }
  //FIXME ADD AS A REAL FORM VARIABLE
  $dashboard = 'user/'.$project->uid.'/cm_crew_connect';
  
  $query_args = array('field_crew_project_id'=>$project->nid,
  	      'destination'=>$dashboard);

  //$query_args = array('field_crew_project_id'=>$project->nid);  

  $link = l(t("Request Crew for your Show"), "node/add/crew-connect-request", 
	    array('query'=>$query_args));

      
  $text = $project->title." ($link)";
  return $text;
}


// http://cm-testing.mnn.openflows.com/node/779714/delete?destination=admin/cm_crew_connect/search
function cm_crew_connect_delete_request_field($row, $view) {

  If ($view->name == 'crew_connect_search' 
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

function cm_crew_connect_cancel_request_field($row) {
  if ($row->nid) {
    $application = cm_crew_connect_get_application_for_request($row->nid);
    if ($application) {
      return "N/A";
    }
  }
  $request = node_load($row->nid);
  $project_nid = 
    cm_crew_connect_get_single_field_value($request, 
					   'field_crew_project_id',
					   'target_id');
  $project = $project_nid ? node_load($project_nid) : NULL;
  
  $link = l("Cancel",
	    "node/".$row->nid."/delete",
	    array('query'=>array('destination' => 
				 "user/".$project->uid."/cm_crew_connect")));
      
  return $link;
}

function cm_crew_connect_edit_request_field($row) {
   if ($row->nid) {
    $application = cm_crew_connect_get_application_for_request($row->nid);
    if ($application) {
      return "N/A";
    }
  }

  $request = node_load($row->nid);
  $project_nid = 
    cm_crew_connect_get_single_field_value($request, 
					   'field_crew_project_id',
					   'target_id');
  $project = $project_nid ? node_load($project_nid) : NULL;
  
  $link = l("Edit", "node/".$row->nid."/edit",
	    array('query'=>array('destination' => 
				 "user/".$project->uid."/cm_crew_connect")));
      
  return $link;
}

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
