<?php

/**
 * Just forwards to the main settings page
 */
function cm_crew_connect_settings_home() {
  drupal_goto('admin/config/cm_crew_connect/settings');
  return;
}

/**
 * Setting Form for the Crew Connect Module
 */
function cm_crew_connect_settings_form($form, &$form_state) {
  $form['before'] =
    array(
	  '#type' => 'fieldset',
	  '#title' =>
	  "Initial Permission Config for Module, Content Types, and Fields",
	  '#weight' => -20,
	  '#collapsible' => TRUE,
          '#collapsed' => TRUE,

  );

  $text = cm_crew_connect_permission_help_text();

  $form['before']['permission_help'] = array('#markup' => $text);

    
  $form['civicrm_fieldset'] =
    array(
	  '#type' => 'fieldset',
	  '#title' => "CiviCRM ID's",
	  '#weight' => -10,
	  '#description' =>
	  t("The ID's of the template and event type used when we create " .
	    "the Civicrm Event."),
  );

  $form['civicrm_fieldset']['cm_crew_connect_event_template_id'] =
    array(
	  '#type' => 'textfield',
	  '#title' => t('CiviCRM Event Template ID'),
	  '#default_value' =>
	  variable_get('cm_crew_connect_event_template_id', ''),
	  '#attributes' => array(
				 ' type' => 'number', 
				 ),
	  '#required' => TRUE,
	  '#description' =>
	  t('Enter the ID of the CiviCRM Event Template'),
	  );

  $form['civicrm_fieldset']['cm_crew_connect_event_type_id'] =
    array(
	  '#type' => 'textfield',
	  '#title' => t('CiviCRM Event Type ID'),
	  '#required' => TRUE,
	  '#default_value' =>
	  variable_get('cm_crew_connect_event_type_id', ''),
	  '#attributes' => array(
				 ' type' => 'number', 
				 ),
	  '#description' =>
	  t('Enter the ID of the CiviCRM Event Type'),
	  );
  
  $form['mapping_fieldset'] =
    array(
	  '#type' => 'fieldset',
	  '#weight' => -9,
	  '#title' => t("Position/Opportunity Type Mapping"),
	  '#description' => "<i>".
	  t("Mapping the Position/Opportunity Type vocabularies against roles".
	    " and each other.") . "</i>",
	  );

  $default_value = variable_get('cc_default_position_filter', FALSE);
  $form['mapping_fieldset']['cc_default_position_filter'] =
    array(
	  '#type' => 'checkbox',
	  '#default_value' => $default_value,
	  '#prefix' => "<br/>",
	  '#weight' => 0,
	  '#title' =>
	  t('Filter Crew Requests from Producers by Position and Role.'.
	    "(Note: Don't check if you are providing a custom filter)")

	  );
  
  $default_value = variable_get('cc_default_opp_type_filter', FALSE);
  $form['mapping_fieldset']['cc_default_opp_type_filter'] =
    array(
	  '#type' => 'checkbox',
	  '#default_value' => $default_value,
	  '#title' =>
	  t('Filter Crew Requests from Producers by Opportunity Type and '.
	    "Role. (Note: Don't check if you are providing a custom filter)")
	  );

  $roles = user_roles();

  $default_position_roles = array();
  
  $position_vocab =
    taxonomy_vocabulary_machine_name_load('crew_connect_position');

  $opp_type_vocab =
    taxonomy_vocabulary_machine_name_load('crew_connect_opportunity_type');
  
  $opp_type_terms = $opp_type_vocab ?
    taxonomy_get_tree($opp_type_vocab->vid) : array();

  if ($position_vocab) {
    $position_terms = taxonomy_get_tree($position_vocab->vid);
    $form['mapping_fieldset']['position_role'] =
      array(
	    '#type' => 'fieldset',
	    '#title' => t("Position Vocabulary Role Mapping"),
	    '#description' => "<i>".
	    t("Mapping the Position vocabularies against roles. ") .
	    l("See/Edit Terms",
	      "admin/structure/taxonomy/crew_connect_position")."</i>",
	    );

    foreach ($position_terms as $position) {
      $var_name = 'cc_position_role_'. $position->tid;
      $default_value = variable_get($var_name, array());
      $form['mapping_fieldset']['position_role'][$var_name]  =
	array(
	      '#type' => 'select',
	      '#multiple' => TRUE,
	      '#title' => t('Roles for: @position', array('@position' =>
							  $position->name)),
	      '#required' => FALSE,
	      '#options' => $roles,
	      '#default_value' => $default_value,
	      );
    }
  }
  
  if ($opp_type_vocab) {
    $opp_type_terms = taxonomy_get_tree($opp_type_vocab->vid);
    $form['mapping_fieldset']['opp_type_role'] =
      array(
	    '#type' => 'fieldset',
	    '#title' => t("Opportunity Type Vocabulary Role Mapping"),
	    '#description' => "<i>".
	    t("Mapping the Position vocabularies against roles. ") .
	    l("See/Edit Terms",
	      "admin/structure/taxonomy/crew_connect_opportunity_type")."</i>",
	    );
    
    foreach ($opp_type_terms as $opp_type) {
      $var_name = 'cc_opp_type_role_'. $opp_type->tid;
      $default_value = variable_get($var_name, array());

      $form['mapping_fieldset']['opp_type_role'][$var_name]  =
	array(
	      '#type' => 'select',
	      '#multiple' => TRUE,
	      '#title' => t('Roles for: @opp_type', array('@opp_type' =>
							  $opp_type->name)),
	      '#required' => FALSE,
	      '#options' => $roles,
	      '#default_value' => $default_value,
	      );
    }
  }

  if ($opp_type_vocab && $position_vocab) {
    $form['mapping_fieldset']['opp_type_position'] =
      array(
	    '#type' => 'fieldset',
	    '#title' => t("Opportunity Type Position Mapping"),
	    '#description' => "<i>".
	    t("Mapping the Position vocabularies against roles. ") .
	    l("See/Edit Terms",
	      "admin/structure/taxonomy/crew_connect_opportunity_type")."</i>",
	    );
    $default_value = variable_get('cc_opp_type_position', FALSE);
    $form['mapping_fieldset']['opp_type_position']['cc_opp_type_position'] =
      array(
	    '#type' => 'checkbox',
	    '#default_value' => $default_value,
	    '#prefix' => "<br/>",
	    '#title' => t("Limit Position by Volunteer Opportunity Type")
	    );
    
    $options = array();
    foreach($position_terms as $term) {
      $options[$term->tid] = $term->name;
    }
    foreach ($opp_type_terms as $opp_type) {
      $var_name = 'cc_opp_type_position_'. $opp_type->tid;
      $default_value = variable_get($var_name, array());
      
      $form['mapping_fieldset']['opp_type_position'][$var_name]
	= array(
		'#type' => 'select',
		'#multiple' => TRUE,
		'#title' =>t('Positions available for Opportunity type: ' .
			     '@opp_type',
			     array('@opp_type' => $opp_type->name)),
		'#required' => FALSE,
		'#options' => $options,
		'#default_value' => $default_value,
		);
    }
  }
  $form['project_fieldset'] =
    array(
	  '#type' => 'fieldset',
	  	  '#weight' => -5,
	  '#title' => t("Project Settings"),
	  );

  $default_value = variable_get('cc_project_preset', FALSE);
  $form['project_fieldset']['cc_project_preset'] =
    array(
	  '#type' => 'checkbox',
	  '#default_value' => $default_value,
	  '#prefix' => "<br/>",
	  '#title' => t("Preset Project fields from Project on Request Form")
	  );
	
  $default_value = variable_get('cc_project_update', FALSE);
  $form['project_fieldset']['cc_project_update'] =
    array(
	  '#type' => 'checkbox',
	  '#default_value' => $default_value,
	  '#prefix' => "<br/>",
	  '#title' => t("Update Project from fields on Request Form")
	  );

  $fields_info = field_info_instances('node', 'cm_project');
  $project_fields = array(0=>'<Select>');
  foreach ($fields_info as $field_name => $value) {
    $project_fields[$field_name] = $field_name;
  }
  asort($project_fields);

  $default_value = variable_get('cc_project_description_field', '');
  $form['project_fieldset']['cc_project_description_field']
    = array(
	    '#type' => 'select',
	    '#title' =>t('Which field on project is the description?'),
	    '#required' => FALSE,
	    '#options' => $project_fields,
	    '#default_value' => $default_value,
	    );

  $default_value = variable_get('cc_project_project_url_field', '');
  $form['project_fieldset']['cc_project_project_url_field']
    = array(
	    '#type' => 'select',
	    '#title' =>t('Which field on project is the Project URL?'),
	    '#required' => FALSE,
	    '#options' => $project_fields,
	    '#default_value' => $default_value,
	    '#disabled' => TRUE,
	    '#description' => 'Currently not implemented',
	    );
  

  $default_value = variable_get('cc_project_language_field', '');
  $form['project_fieldset']['cc_project_language_field']
    = array(
	    '#type' => 'select',
	    '#title' =>t('Which field on project is the language?'),
	    '#required' => FALSE,
	    '#options' => $project_fields,
	    '#default_value' => $default_value,
	    '#disabled' => TRUE,
	    '#description' => 'Currently not implemented',

	    );

  $form['email_fieldset'] =
    array(
	  '#type' => 'fieldset',
	  '#weight' => -4,
	  '#title' => t("Email Settings"),
	  );

  $default_value = variable_get('cc_email_optional', FALSE);
  $form['email_fieldset']['cc_email_optional'] =
    array(
	  '#type' => 'checkbox',
	  '#default_value' => $default_value,
	  '#prefix' => "<br/>",
	  '#title' => t("Allow producer to opt out of public email.")
	  );

  $default_value = variable_get('cc_email_provide_default', FALSE);
  $form['email_fieldset']['cc_email_provide_default'] =
    array(
	  '#type' => 'checkbox',
	  '#default_value' => $default_value,
	  '#prefix' => "<br/>",
	  '#title' =>
	  t("Default Email associated with Drupal Account in email field.")
	  );

  return system_settings_form($form);
}

/**
 * Function returns help text for setting permissions
 */
function cm_crew_connect_permission_help_text() {
  
  $text = "The first step is setting node and field permissions. There are two
   levels of permissions, one for roles that can admin crew connect, and then 
   roles for people to use crew connect. Permissions must be set for the two 
   content types, 'Crew Connect Request' and 'Crew Connect Application as well
   as two admin only fields, field_crew_status and field_crew_civievent_id";
  
  $text .= "<br/>";
  $text .= "<h2>1. Node Permissions</h2>";
  $text .= l("admin/people/permissions", "admin/people/permissions");
  $text .= "<ul><li><b>Crew Connect Admins</b><br/>";
  $text .= "<i>Permission Section Name:</i> node";
  $text .= "<br/><ul><li>";
  $text .= "Crew Connect Application: Create new content";
  $text .= "<br/><li>";
  $text .= "Crew Connect Application: Edit own content";
  $text .= "<br/><li>";  
  $text .= "Crew Connect Application: Edit any content";
  $text .= "<br/><li>";  
  $text .= "Crew Connect Application: Delete own content";
  $text .= "<br/><li>";  
  $text .= "Crew Connect Application: Delete any content";
  $text .= "<br/><li>";  
  $text .= "Crew Connect Request: Create new content";
  $text .= "<br/><li>";
  $text .= "Crew Connect Request: Edit own content";
  $text .= "<br/><li>";  
  $text .= "Crew Connect Request: Edit any content";
  $text .= "<br/><li>";  
  $text .= "Crew Connect Request: Delete own content";
  $text .= "<br/><li>";  
  $text .= "Crew Connect Request: Delete any content";
  $text .= "<br/></ul>";
  
  $text .= "<i>Permission Module Section Name:</i> cm_crew_connect";
  $text .= "<br/><ul><li>";
  $text .= "Crew Connect Tab On User Page";
  $text .= "<br/><li>";  
  $text .= "Administer Crew Connect";
  $text .= "<br/></ul>";
  $text .= "<br/>";


  $text .= "</li><li><b>Crew Connect Users</b><br/>";
  $text .= "<i>Permission Section Name:</i> node";
  $text .= "<br/><ul><li>";
  $text .= "Crew Connect Application: Create new content";
  $text .= "<br/><li>";
  $text .= "Crew Connect Request: Create new content";
  $text .= "<br/><li>";
  $text .= "Crew Connect Request: Edit own content";
  $text .= "</ul>";
  $text .= "<i>Permission Section Name:</i> cm_crew_connect";
  $text .= "<br/><ul><li>";
  $text .= "Crew Connect Tab On User Page";
  $text .= "<br/></ul></li></ul>";

  $text .= "<h2>2. Field Permissions</h2>";
  $text .= "<ul><li><b>CiviCRM Event ID</b><br/>";
  $text .= l("admin/structure/types/manage/crew-connect-request/fields/" .
	     "field_crew_civievent_id",
	     "admin/structure/types/manage/crew-connect-request/fields/" .
	     "field_crew_civievent_id");
  $text .= "<br/>";
  $text .= "<i>Admin Roles Only:</i>";
  $text .= "<br/><ul><li>";
  $text .= "View own value for field Event ID";
  $text .= "<br/><li>";
  $text .= "View anyone's value for field Event ID";
  $text .= "<br/></ul>";
  $text .= "</li><li><b>Crew Status</b><br/>";
  $text .= l("admin/structure/types/manage/crew-connect-request/fields/".
	     "field_crew_status",
	     "admin/structure/types/manage/crew-connect-request/fields/" .
	     "field_crew_status");
  $text .= "<br/>";
  $text .= "<i>Crew Connect Admin Roles Only:</i>";
  $text .= "<br/><ul><li>";
  $text .= "View own value for field Status";
  $text .= "<br/><li>";
  $text .= "View anyone's value for field Status";
  $text .= "<br/></ul></li></ul>";
  return $text;
}