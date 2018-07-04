<?php

/**
 * @file
 * Definition of cm_crew_connect_handler_header_search_link.
 */

/**
 *  Header that is called by the "Page" display of crew_connect_search.
 */
class cm_crew_connect_handler_header_search_link extends views_handler_area {

  /**
   * Renders the field handler.
   */
  function render($empty = FALSE) {
    $ret = '';
    $path = 'admin/cm_crew_connect/search';

    if ($router_item = menu_get_item($path)) {
      // The user has access to the page in $path.
      if (isset($router_item['access'])) {
        $ret = '<h2><strong>' . l('Admin Search', $path) . '</strong></h2>';
      }
    }

    return $ret;
  }
}
