<?php

/**
 * @file
 * Definition of cm_crew_connect_handler_signup_to_crew.
 */

/**
 * Field that is called by the "Page" display of crew_connect_search
 * for "Sign up to Crew" link.
 */
class cm_crew_connect_handler_signup_to_crew extends views_handler_field {

  /**
   * Add some required fields needed on render().
   */
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
  }

  /**
   * Loads additional fields.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Default options form.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Creates the form item for the options added.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  /**
   * Renders the field handler.
   */
  function render($values) {
    global $user;

    $uid = $user->uid;
    $nid = $this->get_value($values, 'nid');

    $label = t('More Info');
    $dashboard = 'user/' . $uid . '/cm_crew_connect';

    return l($label, 
	    'node/add/crew-connect-application',
	    array(
        'query' => array(
          'field_app_crew_connect_node' => $nid,
          'field_app_producer' => $uid,
          'destination' => $dashboard, 
        )
      )
	  );
  }
}
