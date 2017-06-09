<?
function cm_crew_connect_page($uid) {
  $output = "";
  $project_block = "";

  cm_crew_connect_override_messages();

  $view = views_get_view('crew_connect_project_alerts');
  $display = $view->execute_display('crew_enabled');
 
  $result = $view->result ? $view->result : array();
  $project_block = "<h2><span style='text-decoration:underline;'><strong>".
    t("Manage Project Crew Requests:")."</span></strong></h2><ul>";

  if ($result) {
    $project_block .= $display['content'];

    $view = views_get_view('crew_connect_crew_requests');
    $display = $view->execute_display('future');
    $result = $view->result ? $view->result : array();
    
    if ($result) {
      $project_block .= $display['content'];
    }
    
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
  else {
    $project_block .=
      "<ul><li>".
      "You need an Active project to Request a Crew, please follow these ".
      "links to sign up for a <a href='http://www.mnn.org/forms/series'>".
      "Series</a> or <a href='http://www.mnn.org/forms/single'>Single</a>.".
      "</li></ul>"; 
  }
  $output .= "<div class='cm-box'>".$project_block."</div>";

  $my_shifts_block = "<h2><strong><span style='text-decoration:underline;'>".
    t("I have signed up to crew on the following shifts:").
    "</span></strong></h2><ul>";
  $view = views_get_view('crew_connect_volunteer_for_a_crew');
  $display = $view->execute_display('block_3');
  $my_shifts_block .= $display['content'];


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

  $volunteer_block ="<h2><strong><span style='text-decoration:underline;'>".
    t("Available Crew Positions:")."</span></strong></h2><ul>";
 
  $view = views_get_view('crew_connect_volunteer_for_a_crew');

  $users = cm_crew_connect_other_crew_producers();
  $mapping = cm_crew_connect_role_position_mapping();
  $positions = cm_crew_connect_role_positions($mapping);

  $view->set_arguments(array($users, $positions));

  $display = $view->execute_display('block');
 
  $result = $view->result ? $view->result : array();

  $volunteer_block .= $display['content'];
  $ouptput .= "</ul><br/>";

  $output .= "<div class='cm-box'>".$volunteer_block."</div>";

  return $output;
}

function cm_crew_connect_search_page() {

  $users = cm_crew_connect_other_crew_producers();
  $mapping = cm_crew_connect_role_position_mapping();
  $positions = cm_crew_connect_role_positions($mapping);
  
  $ret = views_embed_view('crew_connect_search', 'page', $users, $positions);

  cm_crew_connect_override_messages();
  return $ret;
}