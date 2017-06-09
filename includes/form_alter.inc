<?

/**
 * Implements hook_form_alter().
 */
function cm_crew_connect_form_alter(&$form, &$form_state, $form_id) {
//dpm($form_id, 'form_id');
//dpm($form, 'form');

/*http://cm-testing.mnn.openflows.com/node/add/crew-connect-request?field_crew_project_id=773906&destination=user/207293/cm_crew_connect

http://cm-testing.mnn.openflows.com/node/779616/edit?destination=user/207293/cm_crew_connect
*/
  //The Crew Connect Request Node Form
  if ($form_id == 'crew_connect_request_node_form') {
//dpm($form_state, 'form_state');
    
      drupal_set_message(t("Please make sure you have a Confirmed Reservation for the relevant facility and time prior to asking for a Crew."), 'warning');


      $nid = (isset($form['nid']['#value'])) ? $form['nid']['#value'] :
                NULL;    
      
      // EDITING THE FORM
      if ($nid) {

        $request = 
            $form['field_crew_project_id'][LANGUAGE_NONE][0]
            ['target_id']['#entity'];

        $project_id = 
            cm_crew_connect_get_single_field_value($request, 
                           'field_crew_project_id',
                           'target_id');   
      }
      else {
        
        // NO NID - FIRST TIME THRU - SETUUP PROJECT CONFIRMATION
        $project_id = isset($_GET['field_crew_project_id']) ? 
          $_GET['field_crew_project_id']: NULL;

        if (!isset($project_id) || !$project_id) {
          return;
        }
      }
      
      $project = $project_id ? node_load($project_id) : NULL;            
//dpm($project, 'project');
      
      // create hidden fields
      cm_crew_connect_request_create_hidden_fields_alter_form(
                          $form, 
                          $project);      
   

      //UNSETTING THESE FIELDS AS THE CONDITIONAL TMP VALUES WILL COLLECT 
      //THEM AND THEN IN PRESAVE WE WILL SET THESE FIELDS BASED ON THE TMP 
      //FIELDS. 
      $form['field_crew_location'] = array();
      $form['field_crew_positions'] = array();
      $form['field_which_studio_is_this_in_'] = array();
      
      // THESE VALUES ARE ONLY SET THE FIRST TIME THROUGH
      if (!$nid) {

          // FIXME: for staff and admin this should allow for a search for the
          // producer (similar to what is done in the project)     
          // set the name of the producer based on the author_id of the request
          global $user;
          $author_id = $user->uid;
          $name = cm_crew_connect_get_display_name($author_id); 
          
          
          // SHOULD THIS EMAIL BE UPDATED WHEN THE CIVI ONE IS UPDATED? no, 
          // if the email has already been sent to people, it should not be 
          // updated
          $public_email = cm_crew_connect_get_public_email($author_id); 
          
    /*************************************   
          PHASE 2 INTERSTERTIAL FORM
          $is_project_confirmed = 
            (isset($_GET['project_confirm']) 
            && $_GET['project_confirm'] == 'true')?
            TRUE : FALSE;

          if (!$is_project_confirmed === TRUE) {
            drupal_goto("crew-request-project-confirm/$project_id/$author_id");
            return;
          }    
    *************************************/

 
          // SET DEFAULT VALUES FOR FIELDS - when adding a node
          $form['field_crew_producer_name'][LANGUAGE_NONE][0]
            ['value']['#default_value'] = $name;

          $form['field_crew_public_description'][LANGUAGE_NONE][0]
            ['value']['#default_value'] = 
            cm_crew_connect_get_single_field_value(
                          $project, 
                          'field_description');

          $form['field_crew_public_url'][LANGUAGE_NONE][0]
            ['value']['#default_value'] = 
                      cm_crew_connect_get_single_field_value($project, 
                     'field_project_public_url');

          $language_tid = 
            cm_crew_connect_get_single_field_value($project, 
                     'field_pbcore_languages',
                     'tid');
          $term = $language_tid ? taxonomy_term_load($language_tid) : NULL;
          $form['field_crew_language'][LANGUAGE_NONE][0]
            ['value']['#default_value'] =
                      $term ? $term->name : "";

          $form['field_crew_requesters_pub_email'][LANGUAGE_NONE][0]
            ['value']['#default_value'] = $public_email;      
        
      }
  
  }
/*************************  
 // STUB FOR INTERSTERTIAL FORM
  if($form_id == "views_form_crew_request_project_settings_page_1"){
      // display the confirmation form and setup for creating crew request
      $form['actions']['submit']['#value'] = "Confirm Project Settings";

      $project_id = arg(1);
      $user_id = arg(2);
      $destination = "user/" . $user_id . "/cm_crew_connect";
      $form['#action'] = 
        "/node/add/crew-connect-request?field_request_project=".$project_id .
        "&project_confirm=true&destination=" . $destination;
    
  }
***********************************/

  //The Crew Connect Applicant Form
  if ($form_id == 'crew_connect_application_node_form') {
/*http://cm-testing.mnn.openflows.com/node/add/crew-connect-application?field_app_crew_connect_node=779614&field_app_producer=207293&destination=user/207293/cm_crew_connect  
*/

//dpm($form, 'form');

    $nid = (isset($form['nid']['#value'])) ? $form['nid']['#value'] :
              NULL; 
 
    if (!$nid) {
      
      // FIXME: STAFF NEED TO BE ABLE TO ADD PRODUCER ID AND SET AUTHOR
      $public_email = cm_crew_connect_get_public_email($form['uid']['#value']);
      $form['field_app_apps_public_email'][LANGUAGE_NONE][0]
        ['value']['#default_value'] = $public_email;      
    }
    
    $form['actions']['submit']['#value'] = t('Sign Up');
  }

  if ($form_id == 'node_delete_confirm' && 
      $form['#node']->type == 'crew_connect_request') {
    $nid = arg(1);
    $node = $nid ? node_load($nid) : NULL;
    $type = $node ? substr($node->title, strpos($node->title, ":") + 2) : '';  

    $text = "<h3>".
      t('Are you sure you want to Cancel this "!type" Crew Request?',
	array('!type' => $type))."</h3>";
    
    $form['description']['#markup'] = $text;
    $form['actions']['submit']['#value'] = 'Yes';
    $form['actions']['cancel']['#title'] = 'No';

  }
  else if ($form_id == 'node_delete_confirm' && 
      $form['#node']->type == 'crew_connect_application') {
    $text = "<h3>".
      t('Are you sure you want to Cancel this Crew Sign Up?',
	array('!type' => $type))."</h3>";
    
    $form['description']['#markup'] = $text;
    $form['actions']['submit']['#value'] = 'Yes';
    $form['actions']['cancel']['#title'] = 'No';

  }

  // PRODUCER SEARCHES
  if ($form['#action'] == '/crew-connect/requests-search') {
    $form['title']['#description'] = 
      'This only shows Projects that have active Crew Requests.';
    $form['submit']['#value'] = "Search";
  }

  // ADMIN SEARCHES - CONVERTS TEXT FIELD IN VIEW TO DROPDOWN FIELD
  // https://www.drupal.org/node/1549250
  if ($form['#id'] == 'views-exposed-form-crew-connect-search-page') {
  
    if (isset($form['field_crew_location_value'])) {

        $field_id = 'field_crew_location';
        
        // Build a query to get all node ids having the specified field
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
              ->entityCondition('bundle', 'crew_connect_request')
              ->fieldCondition($field_id, 'value', 'NULL', '!=')            
              ->fieldOrderBy($field_id, 'value', 'ASC');                   
                           
        $results = $query->execute();
      
 
        // Attach the field values to the nodes
        $nodes = $results['node'];
        field_attach_load(
            'node', 
            $nodes, 
            FIELD_LOAD_CURRENT, 
            array(
                'field_id' => $field_id
                  )
            );

        // Add a default so the filter is optional
        $options = array('' => '');


        // Build the options array based on the query results, overwriting 
        // duplicate entries
        foreach($nodes as $nid => $node) {
         
          $value = $node->{$field_id}['und'][0]['value'];
          $options[$value] = $value;      
       }
       
        // Alter the field
        $form[$field_id .'_value']['#type'] = 'select';
        $form[$field_id .'_value']['#options'] = $options;
        $form[$field_id .'_value']['#size'] = 1;
  
    }
     
  }
    
}


function cm_crew_connect_request_create_hidden_fields_alter_form(&$form, $project) {

  $form['field_crew_producer_name'][LANGUAGE_NONE]['#disabled'] = TRUE;
  $form['field_crew_public_description'][LANGUAGE_NONE]['#disabled'] = TRUE;
  $form['field_crew_public_url'][LANGUAGE_NONE]['#disabled'] = TRUE;
  $form['field_crew_language'][LANGUAGE_NONE]['#disabled'] = TRUE;   
  
  if ($project) {
    $form['title'] = array('#type'=>'hidden',
         '#value'=>$project->title);
  }

  $form['field_crew_start_time']['#prefix'] = "<table><tr><td>";
  $form['field_crew_start_time']['#suffix'] = "</td>";
  $form['field_crew_length_of_time']['#prefix'] = "<td>";
  $form['field_crew_length_of_time']['#suffix'] = "</td></tr></table>";
 
  if (!$form['nid']['#value']) {
    $form['actions']['submit']['#value'] = t('Create Crew Request');  
  }
 
}
