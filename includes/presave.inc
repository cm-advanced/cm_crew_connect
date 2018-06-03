<?

/**
 * Implements hook_node_presave().  
 */
function cm_crew_connect_node_presave($node) {
  //handle presave logic for the crew connect request
  if ($node->type == 'crew_connect_request') {
    //get project id
    $project_nid = 
      cm_crew_connect_get_single_field_value($node,
					     'field_crew_project_id',
					     'target_id');

    //FETCH PROJECT AS IT WILL BE USED IN THE REQUEST TITLE
    $project = $project_nid ? node_load($project_nid) : NULL;


    //WE WILL LOOP THROUGH ALL THE FUNCTION THAT DEFINE OUR HOOK
    $hook_name = "crew_request_presave";
    foreach (module_implements($hook_name) as $module) {
      $function = $module . '_' . $hook_name;
      $function($node, $project, $position);
    } 

    $position = cm_crew_connect_get_position_label($node);

    //SET THE CREW CONNECT REQUEST TITLE WITH THE PROJECT AND POSITION
    $node->title = $project->title . ": " . $position['label'];
    
    //SEE IF WE HAVE A CIVI EVENT
    $event_id = 
      cm_crew_connect_get_single_field_value($node,
					     'field_crew_civievent_id');
    
    if ($event_id) {
      //FIXME, LOOK UP $event_id TO SEE IF IT REALLY EXISTS
    }
    //IF WE DON'T HAVE AN EVENT ID, CREATE ONE
    else {
      civicrm_initialize();

      $event_desc = cm_crew_connect_get_single_field_value($node, 'body');
      $start_date = 
	cm_crew_connect_get_single_field_value($node, 'field_crew_start_date');
      $start_time = 
	cm_crew_connect_get_single_field_value($node, 'field_crew_start_time');
      $hours = 
	cm_crew_connect_get_single_field_value($node, 
					       'field_crew_length_of_time');

      $date = strtotime($start_date);
      $parts = explode(':', $start_time);
      $hour = $parts[0] * 60 * 60;
      $minute = $parts[1] * 60;
      
      $start_ts = $date + $hour + $minute;
      $start = date('Y-m-d H:i:s', $start_ts);
      
      $parts = explode(':', $hours);
      $hour_length = $parts[0] * 60 * 60;
      $minute_length = ($parts[1] == 0) ?  0 : 30*60;
      
      $end = date('Y-m-d H:i:s', $start_ts + $hour_length + $minute_length);

      $event_type_id = variable_get('cm_crew_connect_event_type_id');
      $template_id = variable_get('cm_crew_connect_event_template_id');

      $params = array(
		      'sequential' => 1,
		      'title' => $node->title,
		      'event_full_text' => "",
		      'custom_11' => "1",
		      "start_date" => $start,
		      "end_date" => $end,
		      "is_active" => "1",
		      "default_role_id" => "2",
		      "description" => $event_desc,
		      "event_type_id" => $event_type_id,
		      'template_id' => $template_id,
		      'is_public' => "1",
		      );

      //WE WILL LOOP THROUGH ALL THE FUNCTION THAT DEFINE OUR HOOK
      $hook_name = "event_creation_args";
      foreach (module_implements($hook_name) as $module) {
	$function = $module . '_' . $hook_name;
	$function($params, $node);
      } 

      $result2 = civicrm_api3('Event', 'create', $params);
      $event_id = $result2['id'];

      //set the event to be volunteer enabled.   
      $result3 = civicrm_api3('VolunteerProject', 'create', 
			      array(
				    'sequential' => 1,
				    'id' => $result2['id'],
                                     'title' => $node->title,
                                     ));
				    
      $author_cid = CRM_Core_BAO_UFMatch::getContactID($node->uid);
      //set the creator to be a participant 
      $result_add_creator_as_participant =
	civicrm_api3('Participant', 'create', array(
						    'sequential' => 1,
						    'event_id'=>$result2['id'],
						    'contact_id'=> $author_cid,
						    "role_id" => 3,
						    ));
      
      
      
      $id_to_set = (int) $event_id;
    
      $node->field_crew_civievent_id[LANGUAGE_NONE][0]['value']= $id_to_set;

    }
    $node->field_civicrm_event_link[LANGUAGE_NONE][0]['value'] =
      implode(' -- ', cm_crew_connect_event_links($node));
    $node->field_civicrm_event_link[LANGUAGE_NONE][0]['format'] =
      'filtered_html';
  }
  //handle presave logic for the crew connect application
  else if ($node->type == 'crew_connect_application') {
    civicrm_initialize();

    $participant_id = 	
      cm_crew_connect_get_single_field_value($node, 
					     'field_app_participant_id');

    if ($participant_id) {
      //FIXME, MAYBE WE SHOULD LOOK TO SEE IF THE PARTICIPANT ID ACTUALLY
      //EXISTS
    }
    //WE DON'T HAVE A PARTICPANT ID, THEREFORE WE CREATE THE PARTICIPANT RECORD
    else {
      //GET TEH CREW C0NNECT REQUEST NID OFF OF THE APPLICATION
      $request_nid = $node->request_nid;
      $applicant_uid = $node->applicant_uid;
    
      $node->field_app_crew_connect_node[LANGUAGE_NONE][0]['target_id']=
	$request_nid;
      $node->field_app_producer[LANGUAGE_NONE][0]['target_id'] =
	$applicant_uid;

      $request_node = $request_nid ? node_load($request_nid) : NULL;

      //GET THE CIVICRM EVENT ID OFF THE CREW C0NNECT REQUEST NODE
      $event_id = $request_node ? 
	cm_crew_connect_get_single_field_value($request_node,
					       'field_crew_civievent_id') :
	NULL;

      if ($event_id) {
	$result = civicrm_api3('UFMatch', 'get', 
			       array(
				     'sequential' => 1,
				     'uf_id' => $node->uid,
				     ));
	$cid = (isset($result) && isset($result['values']) && 
		isset($result['values'][0])) ? 
	  $result['values'][0]['contact_id'] : NULL;
	
	if ($cid) {
	  $result = civicrm_api3('Participant', 'create', 
				  array(
					'sequential' => 1,
					'event_id' => $event_id,
					'contact_id' => $cid,
					"role_id" => 2,
					));

	  $participant_id = (isset($result) && isset($result['values']) && 
			     isset($result['values'][0])) ? 
	    $result['values'][0]['id'] : NULL;

	  if ($participant_id) {
	    $node->field_app_participant_id[und][0][value]= $participant_id;
	  }
	}
      }
    }
  }
}

