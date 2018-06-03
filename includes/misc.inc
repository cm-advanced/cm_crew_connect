<?

/**
 * function called from admin/crew_connect/positions
 * returns json with available postions
 */
function cm_crew_connect_positions_for_opp_type_json() {
  $opp_type_tid = filter_input(INPUT_GET, 'opp_type');
  $ret = array();
  if ($opp_type_tid) {
    $var_name = 'cc_opp_type_position_'. $opp_type_tid;

    $values = variable_get($var_name, array());   
    foreach($values as $tid) {
      $term = taxonomy_term_load($tid);
      $ret[] = array('id' => $term->tid, 'label' => $term->name);
    }
    return $ret;
  }
  return array();
}

/**
 * File will return the label for the Position on the Crew Connect
 * It will look at both the current field for position, as well as the 
 * legacy
 */
function cm_crew_connect_get_position_label(&$request) {
  $position = array();
  
  //DOES THE NEW POSITION FIELD EXIST?
  $position_field = field_info_instance('node','field_crew_position_taxonomy',
					 'crew_connect_request');
  if ($position_field) {
    $tid =
      cm_crew_connect_get_single_field_value($request,
					     'field_crew_position_taxonomy',
					     'tid');
    
    $term = $tid ? taxonomy_term_load($tid) : NULL;
    $position['id'] = $tid;
    $position['label'] = $term ? $term->name : '';
  }
  //ELSE, DOES THE LEGACY POSITION FIELD EXIST
  else {
    $position_field = field_info_instance('node', 'field_crew_positions',
					  'crew_connect_request');
    if ($position_field) {
      $value =
	cm_crew_connect_get_single_field_value($request,
					       'field_crew_positions',
					       'value');
      $position_field = field_info_field('field_crew_positions');   
      $allowed_values = list_allowed_values($position_field);
      
      $position['id'] = $value;
      $position['label'] =
	$allowed_values[$value] ? $allowed_values[$value] : '';

    }
  }
   
  return $position;
}

/**                                                                            
 * Helper function to get a single value off of a entity  
*/
function cm_crew_connect_get_single_field_value($entity, $field_name,
						$index = 'value') {
  if (isset($entity->{$field_name})) {
    $field = $entity->{$field_name};
    if (isset($field[LANGUAGE_NONE]) &&
        isset($field[LANGUAGE_NONE][0]) &&
        isset($field[LANGUAGE_NONE][0][$index])) {
      return $field[LANGUAGE_NONE][0][$index];
    }
  }
  return NULL;
}

/**                                                         
 * Checks if the current user has a role
 *  
 * @param array $roles
 *
 * @return bool
 */ 
function cm_crew_connect_user_has_role($roles = array()) {
  global $user;
  foreach ($roles as $role) { 

    if (in_array($role, $user->roles)) {
      return TRUE;
    }
  }
  return FALSE;
}           
/**
 * Function will return all the possible Position names on a Crew Request
 *
 * @return $positions - '+' deliminated string of position tid's or values
 */
function cm_crew_connect_get_default_position_arg() {
  $position_arg = '';
  $filter_by_role = variable_get('cc_default_position_filter', FALSE);
  global $user;
  $roles = $user->roles;
  //DOES THE NEW POSITION FIELD EXIST?
  $position_field = field_info_instance('node','field_crew_position_taxonomy',
					 'crew_connect_request');
  if ($position_field) {
    //get all taxonomy terms
    $v = taxonomy_vocabulary_machine_name_load('crew_connect_position');
    $terms = taxonomy_get_tree($v->vid);
    $is_first = TRUE;
    foreach ($terms as $term) {
      //if filtering by position/role
      if ($filter_by_role) {
	$var = 'cc_position_role_' . $term->tid;
	$role_mapping = variable_get($var, array());
	$allowed = FALSE;
	foreach($role_mapping as $qualifying_role) {
	  if (isset($roles[$qualifying_role])) {
	    $allowed = TRUE;
	    break;
	  }
	}
	if (!$allowed) {
	  //we did not find an applicable qualifying role
	  continue;
	}
      }

      if (!$is_first) {
	$position_arg .= "+";
      }
      else {
	$is_first = FALSE;
      }
      $position_arg .= $term->tid;
    }
  }
  //ELSE, DOES THE LEGACY POSITION FIELD EXIST
  else {
    $position_field = field_info_instance('node', 'field_crew_positions',
					  'crew_connect_request');
    if ($position_field) {
      $position_field = field_info_field('field_crew_positions');   
      $allowed_values = list_allowed_values($position_field);

      $is_first = TRUE;
      foreach($allowed_values as $value => $label) {
	if (!$value) {
	  continue;
	}
	if (!$is_first) {
	  $position_arg .= "+";
	}
	else {
	  $is_first = FALSE;
	}
	$position_arg .= $value;
      }
    }
  }
  return $position_arg;
}

/**
 * Function will return all the possible Opportunity Types on a Crew Request
 *
 * @return $positions - '+' deliminated string of position tid's or values
 */
function cm_crew_connect_get_default_opp_type_arg() {
  $opp_type_arg = '';
  $filter_by_role = variable_get('cc_default_opp_type_filter', FALSE);
  global $user;
  $roles = $user->roles;
  //DOES THE NEW OPP_TYPE FIELD EXIST?
  $opp_type_field = field_info_instance('node','field_crew_opportunity_type',
					 'crew_connect_request');
  if ($opp_type_field) {
    //get all taxonomy terms
    $v =taxonomy_vocabulary_machine_name_load('crew_connect_opportunity_type');
    $terms = taxonomy_get_tree($v->vid);
    $is_first = TRUE;
    foreach ($terms as $term) {
      //if filtering by opp_type/role
      if ($filter_by_role) {
	$var = 'cc_opp_type_role_' . $term->tid;
	$role_mapping = variable_get($var, array());
	$allowed = FALSE;
	foreach($role_mapping as $qualifying_role) {
	  if (isset($roles[$qualifying_role])) {
	    $allowed = TRUE;
	    break;
	  }
	}
	if (!$allowed) {
	  //we did not find an applicable qualifying role
	  continue;
	}
      }

      if (!$is_first) {
	$opp_type_arg .= "+";
      }
      else {
	$is_first = FALSE;
      }
      $opp_type_arg .= $term->tid;
    }
  }
  return $opp_type_arg;
}

/**
 * Finds all authors of Crew Requests other than the logged in user
 */
function cm_crew_connect_other_crew_producers() {
  global $user;
  $sql = "SELECT distinct uid FROM node WHERE type = 'crew_connect_request'";
  $results = db_query($sql);

  $users =  "";
  $is_first = TRUE;
  while ($result = $results->fetchObject()) {
    if ($user->uid == $result->uid) {
      continue;
    }
    if (!$is_first) {
      $users .= "+";
    }
    else {
      $is_first = FALSE;
    }
    $users .= $result->uid;
  }
  return $users;
}

/**
 * Function gets the set of current drupal status messages and updates them
 * so that the status messages make more sense for crew connect
 */
function cm_crew_connect_override_messages() {
  $messages = drupal_get_messages();
  foreach($messages as $type=>$type_msgs) {
    foreach ($type_msgs as $message) {
      if (strpos($message, 'Crew Connect Request') &&
	  strpos($message, 'has been deleted') ) {
	$message = t("You have successfully cancelled your Crew Request.");

      }
      else if (strpos($message, 'Crew Connect Application') &&
	       strpos($message, 'has been deleted') ) {
	$message = t("You have successfully cancelled your Crew Sign Up.");
      }
      else if (strpos($message, 'Crew Connect Application') &&
	  strpos($message, 'has been created') ) {
	$node = $_SESSION['cm_crew_connect_new_application'];
	$_SESSION['cm_crew_connect_new_application'] = NULL;
	
	$req = 
	  cm_crew_connect_get_single_field_value($node, 
						 'field_app_crew_connect_node',
						 'target_id');

	$req = $req ? node_load($req) : NULL;

	$project_nid = $req ? 
	  cm_crew_connect_get_single_field_value($req,
						 'field_crew_project_id',
						 'target_id') : NULL;

	$project_title = $project_nid ? node_load($project_nid)->title : "";
	
	$date = $req ? 
	  cm_crew_connect_get_single_field_value($req,
						 'field_crew_start_date') 
	  : NULL;
	$date = date('m/d/Y', strtotime($date));

	$message = 
	  t("You have successfully signed up to crew for !proj on !date.",
	    array('!proj'=>$project_title, '!date'=>$date));

      }

      drupal_set_message($message, $type);
    }
  }
}

/**
 * Function returns an Application node for a nid of a Crew Request node
 */
function cm_crew_connect_get_application_for_request($nid) {
  $sql =
    "SELECT entity_id FROM {field_data_field_app_crew_connect_node}         
     WHERE field_app_crew_connect_node_target_id = :nid";
  $results = db_query($sql, array(':nid' => $nid));
  $result = $results->fetchObject();
  if ($result->entity_id) {
    $application = node_load($result->entity_id);
    return $application;
  }
  return NULL;
}

/**
 * Function returns the link to the associated civi event, either the event
 * or the participant record
 */
function cm_crew_connect_event_links($request) {
  //SEE IF WE HAVE A CIVI EVENT
  $event_id = 
    cm_crew_connect_get_single_field_value($request,
					   'field_crew_civievent_id');
  $link = '';
  if ($event_id) {
    //find applicant node 
    $view = views_get_view('crew_connect_application_for_request');
    $view->set_arguments(array($request->nid));
    $view->execute();
    
    $results = $view->result;;
    
    if ($results) {
      $result = array_pop($results);
      $nid = $result->nid;
    }
    else {
      $nid = $_SESSION['cm_crew_connect_request_nid'];
    }
    $_SESSION['cm_crew_connect_request_nid'] = NULL;
    
    if ($nid) {
      $applicant = node_load($nid);
      
      if ($applicant) {
	$participant_id = 
	  cm_crew_connect_get_single_field_value($applicant,
						 'field_app_participant_id');
	
      }
    }

    $query = array('id'=>$event_id,
		   'action'=>'update',
		   'reset'=>1);
    
    $links = array();
    $links[] = l(t("Manage CiviCRM Event"), 
		 'civicrm/event/manage/settings', array('query'=>$query));

    //if it exists, find particpant id and contact id, and build link
    if ($participant_id) {
      $result = civicrm_api3('Participant', 'get',
			     array(
				   'sequential' => 1,
				   'id' => $participant_id,
				   ));
      if ($result && isset($result['values']) && $result['values'] &&
	  isset($result['values'][0]) && $result['values'][0]) {
	$contact_id = $result['values'][0]['contact_id'];
	$query = array(
		       'reset' => 1,
		       'action' => 'update',
		       'id' => $participant_id, 
		       'cid' => $contact_id,
		     );

	$links[] =
	  l(t("Manage Participant Record"),
	    'civicrm/contact/view/participant',array('query'=>$query));

      }
    }
  }
  return $links;
}