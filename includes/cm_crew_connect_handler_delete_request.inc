<?php

/**
 * @file
 * Definition of cm_crew_connect_handler_delete_request.
 */

/**
 * Called by the "Admin Search" display on the crew_connect_search view
 * to produce a delete link.
 */
class cm_crew_connect_handler_delete_request extends views_handler_field {

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
    $nid = $this->get_value($values, 'nid');

    if ($nid) {
      return 'N/A';
    }

    return l(
      'Delete Request',
      'node/' . $nid . '/delete',
      array(
        'query' => array(
          'destination' => 'admin/cm_crew_connect/search',
        ),
      )
    );
  }
}
