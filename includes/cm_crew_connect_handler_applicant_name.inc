<?php

/**
 * @file
 * Definition of cm_crew_connect_handler_applicant_name.
 */

/**
 * Called by the "Future Crew Requests" display of the
 * crew_connect_crew_requests view to produce an applicant name.
 */
class cm_crew_connect_handler_applicant_name extends views_handler_field {

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
    $nid = $this->get_value($values, 'nid');

    if (isset($nid)) {
      $application = cm_crew_connect_get_application_for_request($nid);

      if (isset($application)) {
        return cm_crew_connect_get_display_name($application->uid);
      }
    }

    return '';
  }
}
