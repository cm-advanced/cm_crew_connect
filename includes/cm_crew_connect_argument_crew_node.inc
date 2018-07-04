<?php

/**
 * @file
 * Contains the Crew Node argument default plugin.
 */

/**
 * Default argument plugin to filter on current Crew Node.
 *
 * @ingroup views_argument_default_plugins
 */
class cm_crew_connect_argument_crew_node extends views_plugin_argument_default {
  function get_argument() {
    return filter_input(INPUT_GET, 'field_app_crew_connect_node');
  }
}
