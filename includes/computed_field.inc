<?
/*
function computed_field_field_civicrm_event_link_display($field, $entity_field_item, $entity_lang, $langcode) {
 dsm($field, 'field');
dsm($entity_field_item, 'item');
dsm($entity, 'ent');  
  return l('hi mom', '');
  }*/

function computed_field_field_civicrm_event_link_compute(&$entity_field, 
							 $entity_type, 
							 $entity, $field, 
							 $instance, 
							 $langcode, $items) {

  //SEE IF WE HAVE A CIVI EVENT
  $event_id = 
    cm_crew_connect_get_single_field_value($entity,
					   'field_crew_civievent_id');
  $link = '';
  if ($event_id) {
    $deleting_application =  $_SESSION['cm_crew_connect_deleting_application'];

    $_SESSION['cm_crew_connect_deleting_application'] = FALSE;
    if (!$deleting_application) {

      //find applicant node 
      $view = views_get_view('crew_connect_application_for_request');
      $view->set_arguments(array($entity->nid));
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
    }

    //if it exists, find particpant id and contact id, and build link
    if ($participant_id) {
      $result = civicrm_api3('Participant', 'get', array(
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
	
	//contact/view/participant?reset=1&action=update&id=44639&cid=24432&context=search&compContext=participant&key=df0c891182920977f805756b43ddd75a_158 [^]

      $link = l(t("Manage CiviCRM Event"),
		  'civicrm/contact/view/participant',array('query'=>$query));
      }

		  
    }
    //link will be as it was
    else {
      $query = array('id'=>$event_id,
		   'action'=>'update',
		   'reset'=>1);

      $link = l(t("Manage CiviCRM Event"), 
		'civicrm/event/manage/settings', array('query'=>$query));
    }
    
		
  

  }
  $entity_field[0]['value'] = $link;
  return $link;
}