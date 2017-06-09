<?
/**
 *
 */
function cm_crew_connect_project_alert_form($form, &$form_state,
					    $project_nid) {
  $form = array();

  $needs = array('yes'=>'Yes', 'no'=>'No', 'not_applicable'=>'N/A');

  $form['cm_crew_connect_project_nid'] =
    array(
	  '#type' => 'hidden',
	  '#value'=> $project_nid,
	  );

  $project = node_load($project_nid);
  $title = $project ? $project->title : "";

  $label = t("Do you need a Crew For !title?", array('!title'=>$title));

  $form['cm_crew_connect_project_needs'] =
    array(
	  '#type' => 'select',
	  '#options'=> $needs,
	  '#required' => TRUE,
	  '#prefix'=> "<table><tr><td>$label</td><td>",
	  '#suffix'=>"</td>",
	  );
  
  $form['cm_crew_connect_project_alert_submit'] =
    array(
	  '#type' => 'submit',
	  '#value'=> t("Update"),
	  '#prefix' => "<td>",
	  '#suffix' => "</tr></table>",
	  );
  return $form;
}

function cm_crew_connect_project_alert_form_submit($form, &$form_state) {
  $project_nid = $form['cm_crew_connect_project_nid']['#value'];

  $needed = $form['cm_crew_connect_project_needs']['#value'];

  $project = node_load($project_nid);
  $project->field_is_crew_needed[LANGUAGE_NONE][0]['value'] = $needed;
  node_save($project);

  //FIXME ADD AS A REAL FORM VARIABLE
  $dashboard = variable_get('cm_crew_connect_dashboard_page', 'user');
  $dashboard .= $project ? "/".$project->uid : "";
  $dashboard_query_args = array();

  $submit_request_page = "node/add/crew-connect-request";
  $submit_query_args = array('field_crew_project_id'=>$project->nid,
			     'destination'=>$dashboard);

  switch ($needed) {
  case 'yes':
    $destination = $submit_request_page;
    $query_args = $submit_query_args;
    break;
  case 'no':
    $destination = $dashboard;
    $query_args = $dashboard_query_args;
    break;
  case 'not_applicable':
    $destination = $dashboard;
    $query_args = $dashboard_query_args;
    break;
  }
  drupal_goto($destination, array('query'=>$query_args));
  return;
}
