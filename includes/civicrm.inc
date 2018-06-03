<?
/**
  * Get the the display name of the contact of the contact
  */
function cm_crew_connect_get_display_name($uid) {

  $cid = cm_crew_connect_get_cid($uid);

  if ($cid) {
    civicrm_initialize();
    
    $result = civicrm_api3('Contact', 'get', array(
						   'sequential' => 1,
						   'id' => $cid,
						   ));

    $display_name = (isset($result) && isset($result['values']) && 
		     isset($result['values'][0])) ? 
      $result['values'][0]['display_name'] : NULL;
      
    return $display_name;
  }
  return "";
}

/**
  * Get the the email address of the contact for a location type
  */
function cm_crew_connect_get_email_for_location_type($uid, $location_type_id) {
  $cid = cm_crew_connect_get_cid($uid);
  if ($cid) {
    $params = array(
		    'sequential' => 1,
		    'contact_id' => $cid,
		    'location_type_id' => $location_type_id,
		    );
    $result = civicrm_api3('Email', 'get', $params);               

    $public_email = (isset($result) && isset($result['values'][0])) ? 
      $result['values'][0]['email'] : NULL;      
    return $public_email;
  }
  return "";  
  
}

/**
  * Get the cid for a givin Drupal uid
  */
function cm_crew_connect_get_cid($uid) {
  civicrm_initialize();
  $result = civicrm_api3('UFMatch', 'get', array(
						 'sequential' => 1,
						 'uf_id' => $uid,
						 ));

  $cid = (isset($result) && isset($result['values']) && 
	  isset($result['values'][0])) ? $result['values'][0]['contact_id'] :
    NULL; 

  return $cid;  
}
