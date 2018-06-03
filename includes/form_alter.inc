<?

/**
 * Implements hook_form_alter().
 */
function cm_crew_connect_form_alter(&$form, &$form_state, $form_id) {
  //////////////////////////////////////////////////////////////////////
  //The Crew Connect Request Node Form
  if ($form_id == 'crew_connect_request_node_form') {
    if (isset($form['field_crew_civievent_id'])) {
      unset($form['field_crew_civievent_id']);
    }
    if (isset($form['field_civicrm_event_link'])) {
      unset($form['field_civicrm_event_link']);
    }

    
    $form['#attached']['js'][] =
      array(
	    'data' => drupal_get_path('module', 'cm_crew_connect') .
	    '/cm_crew_connect.js',
	    'type' => 'file',
	    'weight' => -1000,
	    );

    global $user;
    $author_id = $user->uid;

    $nid = (isset($form['nid']['#value'])) ? $form['nid']['#value'] : NULL;    
    $request = NULL;
    // IF WE FOUND A nid ON THE FORM WE ARE EDITING THE REQUEST
    if ($nid) {
      $request = $form['field_crew_project_id'][LANGUAGE_NONE][0]
	['target_id']['#entity'];

      $project_id = 
 	cm_crew_connect_get_single_field_value($request, 
					       'field_crew_project_id',
					       'target_id');
      $form['field_crew_project_id'][LANGUAGE_NONE][0]['target_id']
	['#disabled'] = TRUE;
	  
    }
    // NO NID ON FORM THEREFORE WE ARE CREATING A REQUEST
    else {
      //GET PROJECT FROM URL
      $project_id = isset($_GET['field_crew_project_id']) ? 
	$_GET['field_crew_project_id'] : NULL;
      $pid = filter_input(INPUT_GET, 'field_crew_project_id');

      $project = $project_id ? node_load($project_id) : NULL;

      if ($project) {
	$form['field_crew_project_id'][LANGUAGE_NONE][0]['target_id']
	  ['#default_value'] = $project->title . " (" . $project->nid . ")";
	$form['field_crew_project_id'][LANGUAGE_NONE][0]['target_id']
	  ['#disabled'] = TRUE;

      }
      else if (!user_access("administer crew connect")) {
	//ONLY ADMINS CAN PICK A RANDOM PROJECT
	drupal_set_message("Sorry, we can't do that for you right now",
			   'error');
	drupal_goto("user");
	return;
      }
    }

    //title will be set in presave, just set it to project for now
    if ($project) {
      $form['title'] = array('#type'=>'hidden',
			     '#value'=>$project->title);
    }

    //IF WE ARE CREATING A NEW REQUEST, PREPOPULATE FIELDS
    if (!isset($request) && !$request) {
      $form['field_crew_producer_name'][LANGUAGE_NONE][0]
	['value']['#default_value'] =
      cm_crew_connect_get_display_name($author_id);


      $preset_project = variable_get('cc_project_preset', TRUE); 
      if ($preset_project && $project) {
	
	$field_name = variable_get('cc_project_description_field', '');
	$form['field_crew_public_description'][LANGUAGE_NONE][0]
	  ['value']['#default_value'] = 
	  cm_crew_connect_get_single_field_value($project, $field_name);

	/**
	//DELAYING IMPLEMENTATION OF THIS AS BOTH FIELDS HAVE COMPLICATIONS
	//url fields may actual be Link Fields,whose data is stored in 2 fields
	//language fields maybe taxonomy, does that mean we should make field
	//dropdown instead of plain text? -Mark Libkuman 5/26/2018
	$field_name = variable_get('cc_project_project_url_field', '');

	$field_info = field_info_field($field_name);

	$form['field_crew_public_url'][LANGUAGE_NONE][0]
	  ['value']['#default_value'] = 
	  cm_crew_connect_get_single_field_value($project, $field_name);
	
	$field_name = variable_get('cc_project_language_field', '');

	$field_info = field_info_field($field_name);

	
	$language_tid = 
	  cm_crew_connect_get_single_field_value($project, $field_name, 'tid');
	
	$term = $language_tid ? taxonomy_term_load($language_tid) : NULL;
	
	
	$form['field_crew_language'][LANGUAGE_NONE][0]['value']
	  ['#default_value']= $term ? $term->name : "";
	*/
      }
    }

    $allow_opt_out = variable_get('cc_email_optional', TRUE);
    if (!$allow_opt_out) {
      $form['field_crew_share_email'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['field_crew_share_email'][LANGUAGE_NONE]['#description'] =
	t("Sharing your email is required for this Request");
      $form['field_crew_share_email'][LANGUAGE_NONE][0]['value']
	['#default_value'] = 'yes';
    }
    $default_to_drupal_email = variable_get('cc_email_provide_default', TRUE);
    if ($default_to_drupal_email) {
      global $user;
      $form['field_crew_requesters_pub_email'][LANGUAGE_NONE][0]['value']
	['#default_value'] = $user->mail;
    }
    
    $filter_positions = variable_get('cc_opp_type_position', TRUE);
    if ($filter_positions) {
      $form['crew_connect_filter_positions'] = array('#type'=>'hidden',
						     '#value'=>'yes');

    }

    $default_position =
      $form['field_crew_position_taxonomy'][LANGUAGE_NONE]['#default_value'];

    if (!$default_position) {
      $form['field_crew_position_taxonomy'][LANGUAGE_NONE]['#default_value'] =
	'_none';
    }
    $form['field_crew_position_taxonomy'][LANGUAGE_NONE]['#empty_value'] =
      '_none';
    $form['field_crew_position_taxonomy'][LANGUAGE_NONE]['#empty_option'] =
      '- Select a value -';
   
    //WE WILL LOOP THROUGH ALL THE FUNCTION THAT DEFINE OUR HOOK
    $hook_name = "crew_connect_request_form_alter";
    foreach (module_implements($hook_name) as $module) {
      $function = $module . '_' . $hook_name;
      $function($form, $request, $project, $author_id);
    }
    
    form_set_cache($form['#build_id'], $form, $form_state);
  }

  //////////////////////////////////////////////////////////////////////
  //The Crew Connect Applicant Form
  if ($form_id == 'crew_connect_application_node_form') {
    global $user;
    $title = 'CrewConnectApp-'.$user->uid;
    $form['title'] = array('#type'=>'hidden',
			   '#value'=> $title);

    $nid = (isset($form['nid']['#value'])) ? $form['nid']['#value'] : NULL;

    if ($nid) {
      unset($form['field_app_crew_connect_node']);
      unset($form['field_app_producer']);
    }
    else {
      $request_nid = filter_input(INPUT_GET, 'field_app_crew_connect_node');

      $request = $request_nid ? node_load($request_nid) : NULL;
      if (!isset($request_nid) || !$request_nid || !$request ||
	  $request->type != 'crew_connect_request') {
	drupal_set_message("You must pass in a valid Request ID.", 'error');
	drupal_goto("user/".$author_id."/cm_crew_connect");
	return;
      }
      
      $applicant_uid = filter_input(INPUT_GET, 'field_app_producer');
      
      $applicant = $applicant_uid ? user_load($applicant_uid) : NULL;
      
      if (!isset($applicant_uid) || !$applicant_uid || !$applicant) {
	drupal_set_message("You must pass in a valid Applicant UID", 'error');
	drupal_goto("user/".$user->uid."/cm_crew_connect");
	return;
      }
      
      unset($form['field_app_crew_connect_node']);
      $form['request_nid'] = array('#type' => 'hidden',
				   '#value' => $request_nid);
      unset($form['field_app_producer']);
      $form['applicant_uid'] = array('#type' => 'hidden',
				     '#value' => $applicant_uid);
    }
    //SET SUBMIT BUTTON TEXT
    $form['actions']['submit']['#value'] = t('Sign Up');
    unset($form['actions']['preview']);
    
    global $user;
    $author_id = $user->uid;

    $application = $nid ? node_load($nid) : NULL;

    $allow_opt_out = variable_get('cc_email_optional', TRUE);
    if (!$allow_opt_out) {
      $form['field_app_share_email'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['field_app_share_email'][LANGUAGE_NONE]['#description'] =
	t("Sharing your email is required for this Request");
      $form['field_app_share_email'][LANGUAGE_NONE][0]['value']
	['#default_value'] = 'yes';
    }
    $default_to_drupal_email = variable_get('cc_email_provide_default', TRUE);
    if ($default_to_drupal_email) {
      global $user;
      $form['field_app_apps_public_email'][LANGUAGE_NONE][0]['value']
	['#default_value'] = $user->mail;
    }


    
    //WE WILL LOOP THROUGH ALL THE FUNCTION THAT DEFINE OUR HOOK
    //WE AREN'T USING module_invoke or drupal_alter because we want to
    //alter an array AND pass in the crew application and author uid
    $hook_name = "crew_connect_application_form_alter";
    foreach (module_implements($hook_name) as $module) {
      $function = $module . '_' . $hook_name;
      $function($form, $application, $author_id);
    } 
  }

  //////////////////////////////////////////////////////////////////////
  //The Crew Connect Request "Are you Sure?" Form
  if ($form_id == 'node_delete_confirm' && 
      $form['#node']->type == 'crew_connect_request') {
    $request = $form['#node'];
    
    //FIND A POSITION TO ADD TO MESSAGE PROMPT
    $position = '';
    
    $position_array = cm_crew_connect_get_position_label($request);
    $position = $position_array['label'];
    $text = "<h3>".
      t('Are you sure you want to Cancel this "!position" Crew Request?',
	array('!position' => $position))."</h3>";

    //UPDATE MESSAGE AND BUTTONS
    $form['description']['#markup'] = $text;
    $form['actions']['submit']['#value'] = 'Yes';
    $form['actions']['cancel']['#title'] = 'No';

  }
  //////////////////////////////////////////////////////////////////////
  //The Crew Connect Application "Are you Sure?" Form
  else if ($form_id == 'node_delete_confirm' && 
	   $form['#node']->type == 'crew_connect_application') {
    
    //UPDATE MESSAGE AND BUTTONS
    $form['description']['#markup'] =
      "<h3>".t('Are you sure you want to Cancel this Crew Sign Up?')."</h3>";
    
    $form['actions']['submit']['#value'] = 'Yes';
    $form['actions']['cancel']['#title'] = 'No';

  }

  //////////////////////////////////////////////////////////////////////
  // REQUEST SEARCH FORM FOR PRODUCERS
  // CONVERTS TEXT FIELD TO DROPDOWN FIELD
  // https://www.drupal.org/node/1549250
  else if ($form['#id'] == 'views-exposed-form-crew-connect-search-page') {
    $form['submit']['#value'] = "Search";
    //WE WILL LOOP THROUGH ALL THE FUNCTION THAT DEFINE OUR HOOK
    $hook_name = "crew_connect_search_form_alter";
    foreach (module_implements($hook_name) as $module) {
      $function = $module . '_' . $hook_name;
      $function($form);
    } 
  }    
}
