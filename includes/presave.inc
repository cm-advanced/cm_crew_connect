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
    
    //get teh civi template id from the field_tmp_crew_location field
    $event_template_id = 
      cm_crew_connect_get_single_field_value($node,
					     'field_tmp_crew_location',
					     'value');
 //   dsm("starting");

    ////////////////////////////////////////////////////////////////////
    //LOCATION
    //FETCH CURRENT LOCATION
    $location = 
      cm_crew_connect_get_single_field_value($node,
					     'field_crew_location',
					     'value');

    $location_field = field_info_field('field_tmp_crew_location');   
    $allowed_values = list_allowed_values($location_field);

    //CHECK FOR TMP LOCATION FIELDS
    $tmp_location = 
      cm_crew_connect_get_single_field_value($node,
					     'field_tmp_crew_location',
					     'value');
    $location = $tmp_location ? $allowed_values[$tmp_location] : $location;
    
    $node->field_crew_location[LANGUAGE_NONE][0]['value'] = $location;
    ///////////////////////////////////////////////////////////////////////
    //POSITION

    //FETCH CURRENT POSITION
    $position = 
      cm_crew_connect_get_single_field_value($node,
					     'field_crew_positions',
					     'value');

    //CHECK FOR TMP POSITION FIELD
    $index = count($allowed_values);
    $new_position = '';

    //THIS A HACK, I BUILD FIELD NAMES BY GOING OFF THE REVERSE ORDER OF 
    //LOCATION FIELD
    foreach ($allowed_values as $k=>$v) {
      if ($k == $tmp_location) {
	$field_name = 'field_tmp'.$index.'_crew_position';
	$new_position = 
	  cm_crew_connect_get_single_field_value($node,$field_name,'value');
	break;
      }
      $index --;
	    
    }

    $position = $new_position ? $new_position : $position;

    $node->field_crew_positions[LANGUAGE_NONE][0]['value'] = $position;


    //FETCH THE POSITION FIELD AS IT WILL BE USED IN THE REQUEST TITLE
    $positions_field = field_info_field('field_crew_positions');   
    $allowed_values = list_allowed_values($positions_field);
     
    //SET THE CREW CONNECT REQUEST TITLE WITH THE PROJECT AND POSITION
    $node->title = $project->title . ": " . $allowed_values[$position];

    ///////////////////////////////////////////////////////////////////////
    //STUDIO

    //GET CURRENT WHICH STUDIO 
    $studio = 
      cm_crew_connect_get_single_field_value($node,
                                             'field_which_studio_is_this_in',
                                             'value');

    //CHECK FOR TMP STUDIO FIELDS
    $field_name = 'field_tmp'.$index.'_which_studio';

    $new_studio = 
      cm_crew_connect_get_single_field_value($node,$field_name,'value');

    $studio = $new_studio ? $new_studio : $studio;
    
    $node->field_which_studio_is_this_in_[LANGUAGE_NONE][0]['value'] = $studio;
   
    //SEE IF WE HAVE A CIVI EVENT
    $event_id = 
      cm_crew_connect_get_single_field_value($node,
					     'field_crew_civievent_id');

    
    if ($event_id) {
      //FIXME, WE SHOULD DECIDE IF WE WANT TO LOOK UP EVENT TO CONFIRM THAT
      //IT REALLY EXISTS
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
   //   dsm("before event created");
      $result2 = civicrm_api3('Event', 'create', 
			      array(
				    'sequential' => 1,
				    'title' => $node->title,
				    'event_full_text' => "",
				    'custom_11' => "1",
				    "start_date" => $start,
				    "end_date" => $end,
				    "is_active" => "1",
				    //  "loc_block_id" => "4",
				    "default_role_id" => "2",
				    "description" => $event_desc,
		 				    "event_type_id" => "170",
				     'template_id' => $event_template_id,
				    'is_public' => "1",
				    ));
      $event_id = $result2['id'];
//dsm("event created");
      //set the event to be volunteer enabled.   
      $result3 = civicrm_api3('VolunteerProject', 'create', 
			      array(
				    'sequential' => 1,
				  //  'entity_table' => "civicrm_event",
				    'id' => $result2['id'],
                                     'title' => $node->title,
                                     ));
				    
           $author_cid = CRM_Core_BAO_UFMatch::getContactID($node->uid);
      //set the creator to be a participant 
      	  $result_add_creator_as_participant = civicrm_api3('Participant', 'create', 
				  array(
					'sequential' => 1,
					'event_id' => $result2['id'],
					'contact_id' => $author_cid,
					"role_id" => 3,
					));

      
      
      $id_to_set = (int) $event_id;
    
      $node->field_crew_civievent_id[LANGUAGE_NONE][0]['value']= $id_to_set;
    }
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
      $request_nid = 
	cm_crew_connect_get_single_field_value($node,
					       'field_app_crew_connect_node',
					       'target_id');

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

