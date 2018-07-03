<?php

/**
 * @file
 * Definition of cm_crew_connect_handler_add_request.
 */

/**
 * Called by the "My Projects" display on the crew_connect_project_alerts
 * view. This provides the link to "Add a Crew Request" for a particuler
 * project.
 */
class cm_crew_connect_handler_add_request extends views_handler_field {

  /**
   * Add some required fields needed on render().
   */
  function construct() {
    parent::construct();
  }

  /**
   * Loads additional fields.
   */
  function query() {}

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
    $title = $this->get_value($values, 'title');

    $dashboard = 'user/' . $uid . '/cm_crew_connect';

    $query_args = array(
      'field_crew_project_id' => $nid,
      'destination' => $dashboard,
    );

    $link = l(
      t('Request Crew for your Show'),
      'node/add/crew-connect-request', 
      array(
        'query' => $query_args,
      )
    );

    return $title . " ($link)";
  }
}
