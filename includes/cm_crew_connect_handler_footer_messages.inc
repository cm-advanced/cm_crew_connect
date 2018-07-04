<?php

/**
 * @file
 * Definition of cm_crew_connect_handler_footer_messages.
 */

/**
 *  Header that is called by the "Admin Search" display of crew_connect_search.
 */
class cm_crew_connect_handler_footer_messages extends views_handler_area {

  /**
   * Renders the field handler.
   */
  function render($empty = FALSE) {
    return cm_crew_connect_override_messages();
  }
}
