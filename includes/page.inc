<?php
/**
 * @file page.inc
 * Defines the Crew Connect User tab as well as the search page
 */

/**
 * Called by menu hook user/%/cm_crew_connect, appears as a user tab
 * The page is made of the following Blocks (some won't display if empty)
 * 1. My Projects - includes links to create a Crew Request
 * 2. Applications from other users for my future Crew Requests
 * 3. Applications from other users for my past Crew Requests
 * 4. My Applications for Future Crew Requests
 * 5. My Applications for Past Crew Requests
 * 6. Crew Requests that are available for me to submit an Application
 */
function cm_crew_connect_page($uid) {
  $output = "";
  $project_block = "";

  //will over ride all drupal status messages to make more sense for the
  //crew connect workflow
  cm_crew_connect_override_messages();

  $view = views_get_view('crew_connect_project_alerts');
  $display = $view->execute_display('crew_enabled');
 
  $result = $view->result ? $view->result : array();
  $project_block = "<h2><span style='text-decoration:underline;'><strong>".
    t("Manage Project Crew Requests:")."</span></strong></h2><ul>";

  //if we find projects for the user, display them with links
  if ($result) {
    $project_block .= $display['content'];

    //look for applications for future crew requests from the user's project
    $view = views_get_view('crew_connect_crew_requests');
    $display = $view->execute_display('future');
    $result = $view->result ? $view->result : array();
    
    if ($result) {
      $project_block .= $display['content'];
    }
    
    //look for applications for past crew requests from the user's project
    $view = views_get_view('crew_connect_crew_requests');
    $display = $view->execute_display('past');
    $result = $view->result ? $view->result : array();
    
    if ($result) {
      $has_results = TRUE;
      $options = array('handle' => "<b>".t("Past Crew Requests")."</b>",
		       'content' => $display['content'], 
		       'collapsed' => TRUE);
      $project_block .= theme('ctools_collapsible',$options).
	"</ul>"."<br/><br/>";
    }
  }
  //user has no projects
  else {
    $project_block .=
      "<ul><li>".
      "You need an Active project to Request a Crew, please follow these ".
      "links to sign up for a <a href='http://www.mnn.org/forms/series'>".
      "Series</a> or <a href='http://www.mnn.org/forms/single'>Single</a>.".
      "</li></ul>"; 
  }
  $output .= "<div class='cm-box'>".$project_block."</div>";

  //Block For Applications that the user has submitted for future Crew Requests
  $my_shifts_block = "<h2><strong><span style='text-decoration:underline;'>".
    t("I have signed up to crew on the following shifts:").
    "</span></strong></h2><ul>";
  $view = views_get_view('crew_connect_volunteer_for_a_crew');
  $display = $view->execute_display('block_3');
  $my_shifts_block .= $display['content'];

  //Block for Applications that the user has submitted for past Crew Requests
  $view = views_get_view('crew_connect_volunteer_for_a_crew');
  $display = $view->execute_display('block_4');
 
  $result = $view->result ? $view->result : array();

  if ($result) {
    $has_results = TRUE;
    $options = array('handle' => "<b>Past Crew Positions</b>",
		     'content' => $display['content'], 
		     'collapsed' => TRUE);
    $my_shifts_block .= theme('ctools_collapsible',$options)."</ul><br/><br/>";

  }

  $output .= "<div class='cm-box'>".$my_shifts_block."</div>";

  //Block for future Crew Requests that the user can apply for
  $volunteer_block ="<h2><strong><span style='text-decoration:underline;'>".
    t("Available Crew Positions:")."</span></strong></h2><ul>";
 
  $view = views_get_view('crew_connect_volunteer_for_a_crew');

  $user_arg = cm_crew_connect_other_crew_producers();
  $opp_type_arg = cm_crew_connect_get_default_opp_type_arg();
  $position_arg = cm_crew_connect_get_default_position_arg();

  $user_arg = $user_arg ? $user_arg : 0;
  //WE WILL LOOP THROUGH ALL THE FUNCTION THAT DEFINE OUR HOOK
  //WE AREN'T USING module_invoke or drupal_alter because we want to
  //alter an array AND pass in the $user_arg and $position_arg and $opp_type
  //arrays
  $hook_name = "crew_connect_available_positions";
  foreach (module_implements($hook_name) as $module) {
    $function = $module . '_' . $hook_name;
    $function($user_arg, $position_arg);
  }

  //WE WILL LOOP THROUGH ALL THE FUNCTION THAT DEFINE OUR HOOK
  //WE AREN'T USING module_invoke or drupal_alter because we want to
  //alter an array AND pass in the $user_arg and $opp_type
  //arrays
  $hook_name = "crew_connect_available_opportunity_types";
  foreach (module_implements($hook_name) as $module) {
    $function = $module . '_' . $hook_name;
    $function($user_arg,$opp_type);
  }

  $opp_type_arg = $opp_type_arg ? $opp_type_arg : -1;
  $position_arg = $position_arg ? $position_arg : -1;
  //FIRE THE VIEW WITH OUR ARGUMENTS
  $view->set_arguments(array($user_arg, $position_arg, $opp_type_arg));
  $display = $view->execute_display('block');
  $result = $view->result ? $view->result : array();
  $volunteer_block .= $display['content'];
  $ouptput .= "</ul><br/>";
  $output .= "<div class='cm-box'>".$volunteer_block."</div>";

  return $output;
}

/**
 * Page simply fires a view allowing crew request searches, the code 
 * gets the correct arguments so only available crew requests show up to 
 * regular users
 */
function cm_crew_connect_search_page() {
  //will over ride all drupal status messages to make more sense for the
  //crew connect workflow
  cm_crew_connect_override_messages();

  //get default arguments for the views, then allow a hook to override 
  $user_arg = cm_crew_connect_other_crew_producers();
  $position_arg = cm_crew_connect_get_default_position_arg();
  $opp_type_arg = cm_crew_connect_get_default_opp_type_arg();
  
  //WE WILL LOOP THROUGH ALL THE FUNCTION THAT DEFINE OUR HOOK
  //We aren't using module_invoke or drupal_alter because we want to
  //alter an array AND pass in the $user_arg and $position_arg arrays
  $hook_name = "crew_connect_available_positions";
  foreach (module_implements($hook_name) as $module) {
    $function = $module . '_' . $hook_name;
    $function($user_arg, $position_arg);
  } 

  //WE WILL LOOP THROUGH ALL THE FUNCTION THAT DEFINE OUR HOOK
  //WE AREN'T USING module_invoke or drupal_alter because we want to
  //alter an array AND pass in the $user_arg and $opp_type
  //arrays
  $hook_name = "crew_connect_available_opportunity_types";
  foreach (module_implements($hook_name) as $module) {
    $function = $module . '_' . $hook_name;
    $function($user_arg,$opp_type);
  }

  $opp_type_arg = $opp_type_arg ? $opp_type_arg : -1;
  $position_arg = $position_arg ? $position_arg : -1;


  $ret =
    views_embed_view('crew_connect_search', 'page', $user_arg, $position_arg,
		     $opp_type_arg);

  return $ret;
}