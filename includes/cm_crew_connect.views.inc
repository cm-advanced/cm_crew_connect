<?php

function cm_crew_connect_views_default_views() {

  //FOR EACH VIEW, COPY EXPORT CODE THEN ADD IT TO THIS ARRAY
  $views = array();

  //////////////////////////////////////////////////////////////
  //ADDING VIEW: crew_connect_app_header
  // Add view to list of views to provide.
  $view = new view();
  $view->name = 'crew_connect_app_header';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Crew Connect Application Header';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Crew Sign Up';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'use crew connect';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
								      'field_crew_producer_name' => 'field_crew_producer_name',
								      'picture' => 'picture',
								      'title_1' => 'title_1',
								      'field_crew_public_url' => 'field_crew_public_url',
								      'field_crew_start_date' => 'field_crew_start_date',
								      'field_crew_length_of_time' => 'field_crew_length_of_time',
								      'field_crew_start_time' => 'field_crew_start_time',
								      'field_crew_position_taxonomy' => 'field_crew_position_taxonomy',
								      'field_crew_opportunity_type' => 'field_crew_opportunity_type',
								      );
  $handler->display->display_options['row_options']['separator'] = '<br />';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_crew_project_id_target_id']['id'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['relationships']['field_crew_project_id_target_id']['table'] = 'field_data_field_crew_project_id';
  $handler->display->display_options['relationships']['field_crew_project_id_target_id']['field'] = 'field_crew_project_id_target_id';
  /* Field: Content: Producer's Name */
  $handler->display->display_options['fields']['field_crew_producer_name']['id'] = 'field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['table'] = 'field_data_field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['field'] = 'field_crew_producer_name';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Project Name';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Project Description */
  $handler->display->display_options['fields']['field_crew_public_description']['id'] = 'field_crew_public_description';
  $handler->display->display_options['fields']['field_crew_public_description']['table'] = 'field_data_field_crew_public_description';
  $handler->display->display_options['fields']['field_crew_public_description']['field'] = 'field_crew_public_description';
  $handler->display->display_options['fields']['field_crew_public_description']['label'] = '';
  $handler->display->display_options['fields']['field_crew_public_description']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_crew_public_description']['alter']['text'] = 'Project Description: [field_crew_public_description-value]';
  $handler->display->display_options['fields']['field_crew_public_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crew_public_description']['hide_empty'] = TRUE;
  /* Field: Content: Project Website */
  $handler->display->display_options['fields']['field_crew_public_url']['id'] = 'field_crew_public_url';
  $handler->display->display_options['fields']['field_crew_public_url']['table'] = 'field_data_field_crew_public_url';
  $handler->display->display_options['fields']['field_crew_public_url']['field'] = 'field_crew_public_url';
  $handler->display->display_options['fields']['field_crew_public_url']['hide_empty'] = TRUE;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_crew_start_date']['id'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['field'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_crew_start_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_crew_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crew_start_date']['settings'] = array(
											    'format_type' => 'date_long_day_and_month_only',
											    'fromto' => 'both',
											    'multiple_number' => '',
											    'multiple_from' => '',
											    'multiple_to' => '',
											    'show_repeat_rule' => 'show',
											    );
  /* Field: Content: Length of Time In Hours */
  $handler->display->display_options['fields']['field_crew_length_of_time']['id'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['table'] = 'field_data_field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['field'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['label'] = '';
  $handler->display->display_options['fields']['field_crew_length_of_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_crew_length_of_time']['element_label_colon'] = FALSE;
  /* Field: Content: Start Time */
  $handler->display->display_options['fields']['field_crew_start_time']['id'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['table'] = 'field_data_field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['field'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['label'] = 'Date/Time';
  $handler->display->display_options['fields']['field_crew_start_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_crew_start_time']['alter']['text'] = '[field_crew_start_date] - [field_crew_start_time] - [field_crew_length_of_time] hour(s)';
  /* Field: Content: Crew Position */
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['id'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['field'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Volunteer Opportunity Type */
  $handler->display->display_options['fields']['field_crew_opportunity_type']['id'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['table'] = 'field_data_field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['field'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['label'] = 'Opportunity Type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = 'Crew Shift Info: [body] ';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['settings'] = array(
									   'trim_length' => '500',
									   );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = ' return  filter_input(INPUT_GET, \'field_app_crew_connect_node\');

';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'crew_connect_request' => 'crew_connect_request',
									 );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'app_header_block');

  $views[$view->name] = $view;
  //FINISHED ADDING VIEW
  ///////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////
  //ADDING VIEW: crew_connect_search
  // Add view to list of views to provide.
  $view = new view();
  $view->name = 'crew_connect_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Crew Connect Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Crew Connect Search';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'use crew connect';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
									 'title' => 'title',
									 'edit_node' => 'edit_node',
									 'field_crew_producer_name' => 'field_crew_producer_name',
									 'uid' => 'uid',
									 'title_1' => 'title_1',
									 'field_crew_start_date' => 'field_crew_start_date',
									 'field_crew_start_time' => 'field_crew_start_time',
									 'field_crew_length_of_time' => 'field_crew_length_of_time',
									 'field_crew_opportunity_type' => 'field_crew_opportunity_type',
									 'field_crew_position_taxonomy' => 'field_crew_position_taxonomy',
									 'body' => 'body',
									 'nid' => 'nid',
									 'nid_1' => 'nid_1',
									 'php' => 'php',
									 'field_civicrm_event_link' => 'field_civicrm_event_link',
									 'field_app_producer' => 'field_app_producer',
									 'field_app_status' => 'field_app_status',
									 'field_app_producer_1' => 'field_app_producer_1',
									 'field_app_producer_2' => 'field_app_producer_2',
									 );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
								      'title' => array(
										       'sortable' => 0,
										       'default_sort_order' => 'asc',
										       'align' => '',
										       'separator' => '',
										       'empty_column' => 0,
										       ),
								      'edit_node' => array(
											   'align' => '',
											   'separator' => '',
											   'empty_column' => 0,
											   ),
								      'field_crew_producer_name' => array(
													  'sortable' => 1,
													  'default_sort_order' => 'asc',
													  'align' => '',
													  'separator' => '',
													  'empty_column' => 0,
													  ),
								      'uid' => array(
										     'align' => '',
										     'separator' => '',
										     'empty_column' => 0,
										     ),
								      'title_1' => array(
											 'sortable' => 1,
											 'default_sort_order' => 'asc',
											 'align' => '',
											 'separator' => '',
											 'empty_column' => 0,
											 ),
								      'field_crew_start_date' => array(
												       'sortable' => 1,
												       'default_sort_order' => 'asc',
												       'align' => '',
												       'separator' => '',
												       'empty_column' => 0,
												       ),
								      'field_crew_start_time' => array(
												       'sortable' => 1,
												       'default_sort_order' => 'asc',
												       'align' => '',
												       'separator' => '',
												       'empty_column' => 0,
												       ),
								      'field_crew_length_of_time' => array(
													   'sortable' => 1,
													   'default_sort_order' => 'asc',
													   'align' => '',
													   'separator' => '',
													   'empty_column' => 0,
													   ),
								      'field_crew_opportunity_type' => array(
													     'sortable' => 1,
													     'default_sort_order' => 'asc',
													     'align' => '',
													     'separator' => '',
													     'empty_column' => 0,
													     ),
								      'field_crew_position_taxonomy' => array(
													      'sortable' => 1,
													      'default_sort_order' => 'asc',
													      'align' => '',
													      'separator' => '',
													      'empty_column' => 0,
													      ),
								      'body' => array(
										      'sortable' => 0,
										      'default_sort_order' => 'asc',
										      'align' => '',
										      'separator' => '',
										      'empty_column' => 0,
										      ),
								      'nid' => array(
										     'sortable' => 0,
										     'default_sort_order' => 'asc',
										     'align' => '',
										     'separator' => '',
										     'empty_column' => 0,
										     ),
								      'nid_1' => array(
										       'sortable' => 0,
										       'default_sort_order' => 'asc',
										       'align' => '',
										       'separator' => '',
										       'empty_column' => 0,
										       ),
								      'php' => array(
										     'align' => '',
										     'separator' => '',
										     'empty_column' => 0,
										     ),
								      'field_civicrm_event_link' => array(
													  'sortable' => 0,
													  'default_sort_order' => 'asc',
													  'align' => '',
													  'separator' => '',
													  'empty_column' => 0,
													  ),
								      'field_app_producer' => array(
												    'sortable' => 0,
												    'default_sort_order' => 'asc',
												    'align' => '',
												    'separator' => '',
												    'empty_column' => 0,
												    ),
								      'field_app_status' => array(
												  'sortable' => 0,
												  'default_sort_order' => 'asc',
												  'align' => '',
												  'separator' => '',
												  'empty_column' => 0,
												  ),
								      'field_app_producer_1' => array(
												      'sortable' => 0,
												      'default_sort_order' => 'asc',
												      'align' => '',
												      'separator' => '',
												      'empty_column' => 0,
												      ),
								      'field_app_producer_2' => array(
												      'sortable' => 0,
												      'default_sort_order' => 'asc',
												      'align' => '',
												      'separator' => '',
												      'empty_column' => 0,
												      ),
								      );
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<?php print cm_crew_connect_search_page_header() ;?></p>
';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_crew_project_id_target_id']['id'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['relationships']['field_crew_project_id_target_id']['table'] = 'field_data_field_crew_project_id';
  $handler->display->display_options['relationships']['field_crew_project_id_target_id']['field'] = 'field_crew_project_id_target_id';
  /* Relationship: Referencing: Crew Connect Application */
  $handler->display->display_options['relationships']['reverse_field_app_crew_connect_node_node']['id'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['relationships']['reverse_field_app_crew_connect_node_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_app_crew_connect_node_node']['field'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['relationships']['reverse_field_app_crew_connect_node_node']['ui_name'] = 'Referencing: Crew Connect Application';
  $handler->display->display_options['relationships']['reverse_field_app_crew_connect_node_node']['label'] = 'Referencing: Crew Connect Application';
  /* Field: Content: Producer's Name */
  $handler->display->display_options['fields']['field_crew_producer_name']['id'] = 'field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['table'] = 'field_data_field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['field'] = 'field_crew_producer_name';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Project Name';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_crew_start_date']['id'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['field'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_crew_start_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_crew_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crew_start_date']['settings'] = array(
											    'format_type' => 'month_day',
											    'fromto' => 'both',
											    'multiple_number' => '',
											    'multiple_from' => '',
											    'multiple_to' => '',
											    'show_repeat_rule' => 'show',
											    );
  /* Field: Content: Start Time */
  $handler->display->display_options['fields']['field_crew_start_time']['id'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['table'] = 'field_data_field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['field'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_crew_start_time']['alter']['text'] = '[field_crew_start_date] - [field_crew_start_time]';
  /* Field: Content: Crew Position */
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['id'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['field'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Relevant Crew Information';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
									   'trim_length' => '250',
									   );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'View Crew Details';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
print cm_crew_connect_sign_up_to_crew_link($row, \'Vew Crew Details\');
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Sign Up to Crew';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print cm_crew_connect_sign_up_to_crew_link($row);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: CiviCRM Event Link */
  $handler->display->display_options['fields']['field_civicrm_event_link']['id'] = 'field_civicrm_event_link';
  $handler->display->display_options['fields']['field_civicrm_event_link']['table'] = 'field_data_field_civicrm_event_link';
  $handler->display->display_options['fields']['field_civicrm_event_link']['field'] = 'field_civicrm_event_link';
  $handler->display->display_options['fields']['field_civicrm_event_link']['label'] = 'Manage';
  /* Sort criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['sorts']['field_crew_start_date_value']['id'] = 'field_crew_start_date_value';
  $handler->display->display_options['sorts']['field_crew_start_date_value']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['sorts']['field_crew_start_date_value']['field'] = 'field_crew_start_date_value';
  /* Sort criterion: Content: Start Time (field_crew_start_time) */
  $handler->display->display_options['sorts']['field_crew_start_time_value']['id'] = 'field_crew_start_time_value';
  $handler->display->display_options['sorts']['field_crew_start_time_value']['table'] = 'field_data_field_crew_start_time';
  $handler->display->display_options['sorts']['field_crew_start_time_value']['field'] = 'field_crew_start_time_value';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'crew_connect_request' => 'crew_connect_request',
									 );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['filters']['nid']['operator'] = 'empty';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  /* Filter criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['id'] = 'field_crew_start_date_value_1';
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['field'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['operator'] = '>=';
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['default_date'] = 'now';
  /* Filter criterion: Content: Status (field_crew_status) */
  $handler->display->display_options['filters']['field_crew_status_value']['id'] = 'field_crew_status_value';
  $handler->display->display_options['filters']['field_crew_status_value']['table'] = 'field_data_field_crew_status';
  $handler->display->display_options['filters']['field_crew_status_value']['field'] = 'field_crew_status_value';
  $handler->display->display_options['filters']['field_crew_status_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_crew_status_value']['value'] = array(
											    'cancelled' => 'cancelled',
											    );
  $handler->display->display_options['filters']['field_crew_status_value']['group'] = 1;
  /* Filter criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['filters']['field_crew_start_date_value']['id'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['filters']['field_crew_start_date_value']['field'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_crew_start_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['operator_id'] = 'field_crew_start_date_value_op';
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['operator'] = 'field_crew_start_date_value_op';
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['identifier'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['remember_roles'] = array(
														   2 => '2',
														   3 => 0,
														   1 => 0,
														   44 => 0,
														   8 => 0,
														   14 => 0,
														   10 => 0,
														   6 => 0,
														   11 => 0,
														   4 => 0,
														   16 => 0,
														   17 => 0,
														   20 => 0,
														   22 => 0,
														   23 => 0,
														   25 => 0,
														   39 => 0,
														   28 => 0,
														   29 => 0,
														   45 => 0,
														   26 => 0,
														   37 => 0,
														   33 => 0,
														   34 => 0,
														   35 => 0,
														   46 => 0,
														   36 => 0,
														   43 => 0,
														   32 => 0,
														   );
  $handler->display->display_options['filters']['field_crew_start_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_crew_start_date_value']['year_range'] = '-0:+1';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Project Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
											     2 => '2',
											     3 => 0,
											     1 => 0,
											     44 => 0,
											     8 => 0,
											     14 => 0,
											     10 => 0,
											     6 => 0,
											     11 => 0,
											     4 => 0,
											     16 => 0,
											     17 => 0,
											     20 => 0,
											     22 => 0,
											     23 => 0,
											     25 => 0,
											     39 => 0,
											     28 => 0,
											     29 => 0,
											     45 => 0,
											     26 => 0,
											     37 => 0,
											     33 => 0,
											     34 => 0,
											     35 => 0,
											     46 => 0,
											     36 => 0,
											     43 => 0,
											     32 => 0,
											     );
  /* Filter criterion: Content: Producer&#039;s Name (field_crew_producer_name) */
  $handler->display->display_options['filters']['field_crew_producer_name_value']['id'] = 'field_crew_producer_name_value';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['table'] = 'field_data_field_crew_producer_name';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['field'] = 'field_crew_producer_name_value';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['operator_id'] = 'field_crew_producer_name_value_op';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['label'] = 'Producer\'s Name';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['operator'] = 'field_crew_producer_name_value_op';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['identifier'] = 'field_crew_producer_name_value';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['remember_roles'] = array(
														      2 => '2',
														      3 => 0,
														      1 => 0,
														      44 => 0,
														      8 => 0,
														      14 => 0,
														      10 => 0,
														      6 => 0,
														      11 => 0,
														      4 => 0,
														      16 => 0,
														      17 => 0,
														      20 => 0,
														      22 => 0,
														      23 => 0,
														      25 => 0,
														      39 => 0,
														      28 => 0,
														      29 => 0,
														      45 => 0,
														      26 => 0,
														      37 => 0,
														      33 => 0,
														      34 => 0,
														      35 => 0,
														      46 => 0,
														      36 => 0,
														      43 => 0,
														      32 => 0,
														      );
  /* Filter criterion: Content: Crew Position (field_crew_position_taxonomy) */
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['id'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['field'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['value'] = '';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['operator_id'] = 'field_crew_position_taxonomy_tid_op';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['label'] = 'Crew Position';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['operator'] = 'field_crew_position_taxonomy_tid_op';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['identifier'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['remember_roles'] = array(
															2 => '2',
															3 => 0,
															1 => 0,
															44 => 0,
															8 => 0,
															14 => 0,
															10 => 0,
															6 => 0,
															11 => 0,
															4 => 0,
															51 => 0,
															16 => 0,
															49 => 0,
															17 => 0,
															20 => 0,
															50 => 0,
															48 => 0,
															39 => 0,
															28 => 0,
															29 => 0,
															45 => 0,
															37 => 0,
															34 => 0,
															35 => 0,
															46 => 0,
															43 => 0,
															47 => 0,
															32 => 0,
															52 => 0,
															);
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['vocabulary'] = 'crew_connect_position';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Either you do not have the appropriate Certification, or their are currently no opportunities for this position.';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_crew_project_id_target_id']['id'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['relationships']['field_crew_project_id_target_id']['table'] = 'field_data_field_crew_project_id';
  $handler->display->display_options['relationships']['field_crew_project_id_target_id']['field'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Producer's Name */
  $handler->display->display_options['fields']['field_crew_producer_name']['id'] = 'field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['table'] = 'field_data_field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['field'] = 'field_crew_producer_name';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Project Name';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_crew_start_date']['id'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['field'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_crew_start_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_crew_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crew_start_date']['settings'] = array(
											    'format_type' => 'month_day',
											    'fromto' => 'both',
											    'multiple_number' => '',
											    'multiple_from' => '',
											    'multiple_to' => '',
											    'show_repeat_rule' => 'show',
											    );
  /* Field: Content: Start Time */
  $handler->display->display_options['fields']['field_crew_start_time']['id'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['table'] = 'field_data_field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['field'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_crew_start_time']['alter']['text'] = '[field_crew_start_date] - [field_crew_start_time]';
  /* Field: Content: Length of Time In Hours */
  $handler->display->display_options['fields']['field_crew_length_of_time']['id'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['table'] = 'field_data_field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['field'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['label'] = 'Length In Hours';
  /* Field: Content: Volunteer Opportunity Type */
  $handler->display->display_options['fields']['field_crew_opportunity_type']['id'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['table'] = 'field_data_field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['field'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['label'] = 'Opportunity Type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Crew Position */
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['id'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['field'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Relevant Crew Information';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
									   'trim_length' => '250',
									   );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Sign Up to Crew';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print cm_crew_connect_sign_up_to_crew_link($row);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Crew Position (field_crew_position_taxonomy) */
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['id'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['field'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Volunteer Opportunity Type (field_crew_opportunity_type) */
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['id'] = 'field_crew_opportunity_type_tid';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['table'] = 'field_data_field_crew_opportunity_type';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['field'] = 'field_crew_opportunity_type_tid';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'crew_connect_request' => 'crew_connect_request',
									 );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['id'] = 'field_crew_start_date_value_1';
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['field'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['operator'] = '>=';
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['default_date'] = 'now';
  /* Filter criterion: Content: Status (field_crew_status) */
  $handler->display->display_options['filters']['field_crew_status_value']['id'] = 'field_crew_status_value';
  $handler->display->display_options['filters']['field_crew_status_value']['table'] = 'field_data_field_crew_status';
  $handler->display->display_options['filters']['field_crew_status_value']['field'] = 'field_crew_status_value';
  $handler->display->display_options['filters']['field_crew_status_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_crew_status_value']['value'] = array(
											    'cancelled' => 'cancelled',
											    );
  $handler->display->display_options['filters']['field_crew_status_value']['group'] = 1;
  /* Filter criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['filters']['field_crew_start_date_value']['id'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['filters']['field_crew_start_date_value']['field'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_crew_start_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['operator_id'] = 'field_crew_start_date_value_op';
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['operator'] = 'field_crew_start_date_value_op';
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['identifier'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['remember_roles'] = array(
														   2 => '2',
														   1 => 0,
														   3 => 0,
														   27 => 0,
														   7 => 0,
														   16 => 0,
														   14 => 0,
														   26 => 0,
														   11 => 0,
														   12 => 0,
														   6 => 0,
														   13 => 0,
														   33 => 0,
														   4 => 0,
														   30 => 0,
														   28 => 0,
														   32 => 0,
														   18 => 0,
														   22 => 0,
														   20 => 0,
														   25 => 0,
														   23 => 0,
														   31 => 0,
														   15 => 0,
														   34 => 0,
														   17 => 0,
														   21 => 0,
														   19 => 0,
														   35 => 0,
														   49 => 0,
														   44 => 0,
														   37 => 0,
														   43 => 0,
														   36 => 0,
														   57 => 0,
														   47 => 0,
														   56 => 0,
														   40 => 0,
														   50 => 0,
														   46 => 0,
														   39 => 0,
														   38 => 0,
														   41 => 0,
														   45 => 0,
														   42 => 0,
														   51 => 0,
														   48 => 0,
														   52 => 0,
														   55 => 0,
														   53 => 0,
														   54 => 0,
														   );
  $handler->display->display_options['filters']['field_crew_start_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_crew_start_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_crew_start_date_value']['year_range'] = '-0:+1';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Project Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
											     2 => '2',
											     3 => 0,
											     1 => 0,
											     44 => 0,
											     8 => 0,
											     14 => 0,
											     10 => 0,
											     6 => 0,
											     11 => 0,
											     4 => 0,
											     51 => 0,
											     16 => 0,
											     49 => 0,
											     17 => 0,
											     20 => 0,
											     50 => 0,
											     48 => 0,
											     39 => 0,
											     28 => 0,
											     29 => 0,
											     45 => 0,
											     37 => 0,
											     34 => 0,
											     35 => 0,
											     46 => 0,
											     43 => 0,
											     47 => 0,
											     32 => 0,
											     52 => 0,
											     );
  /* Filter criterion: Content: Producer&#039;s Name (field_crew_producer_name) */
  $handler->display->display_options['filters']['field_crew_producer_name_value']['id'] = 'field_crew_producer_name_value';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['table'] = 'field_data_field_crew_producer_name';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['field'] = 'field_crew_producer_name_value';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_producer_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['operator_id'] = 'field_crew_producer_name_value_op';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['label'] = 'Producer\'s Name';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['operator'] = 'field_crew_producer_name_value_op';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['identifier'] = 'field_crew_producer_name_value';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['remember_roles'] = array(
														      2 => '2',
														      3 => 0,
														      1 => 0,
														      44 => 0,
														      8 => 0,
														      14 => 0,
														      10 => 0,
														      6 => 0,
														      11 => 0,
														      4 => 0,
														      16 => 0,
														      17 => 0,
														      20 => 0,
														      22 => 0,
														      23 => 0,
														      25 => 0,
														      39 => 0,
														      28 => 0,
														      29 => 0,
														      45 => 0,
														      26 => 0,
														      37 => 0,
														      33 => 0,
														      34 => 0,
														      35 => 0,
														      46 => 0,
														      36 => 0,
														      43 => 0,
														      32 => 0,
														      );
  /* Filter criterion: Content: Crew Position (field_crew_position_taxonomy) */
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['id'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['field'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['operator_id'] = 'field_crew_position_taxonomy_tid_op';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['label'] = 'Crew Position';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['operator'] = 'field_crew_position_taxonomy_tid_op';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['identifier'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['remember_roles'] = array(
															2 => '2',
															3 => 0,
															1 => 0,
															44 => 0,
															8 => 0,
															14 => 0,
															10 => 0,
															6 => 0,
															11 => 0,
															4 => 0,
															51 => 0,
															16 => 0,
															49 => 0,
															17 => 0,
															20 => 0,
															50 => 0,
															48 => 0,
															39 => 0,
															28 => 0,
															29 => 0,
															45 => 0,
															37 => 0,
															34 => 0,
															35 => 0,
															46 => 0,
															43 => 0,
															47 => 0,
															32 => 0,
															52 => 0,
															);
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['vocabulary'] = 'crew_connect_position';
  /* Filter criterion: Content: CiviCRM Event Link (field_civicrm_event_link) */
  $handler->display->display_options['filters']['field_civicrm_event_link_value']['id'] = 'field_civicrm_event_link_value';
  $handler->display->display_options['filters']['field_civicrm_event_link_value']['table'] = 'field_data_field_civicrm_event_link';
  $handler->display->display_options['filters']['field_civicrm_event_link_value']['field'] = 'field_civicrm_event_link_value';
  $handler->display->display_options['filters']['field_civicrm_event_link_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_civicrm_event_link_value']['value'] = 'participant';
  $handler->display->display_options['filters']['field_civicrm_event_link_value']['group'] = 1;
  $handler->display->display_options['path'] = 'crew-connect/requests-search/raw';

  /* Display: Admin Search */
  $handler = $view->new_display('page', 'Admin Search', 'page_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer crew connect';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '250';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['empty'] = TRUE;
  $handler->display->display_options['footer']['php']['php_output'] = ' <?php 
cm_crew_connect_override_messages();
?>
';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Crew Request';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Field: Content: Producer's Name */
  $handler->display->display_options['fields']['field_crew_producer_name']['id'] = 'field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['table'] = 'field_data_field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['field'] = 'field_crew_producer_name';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Project Name';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_crew_start_date']['id'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['field'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_crew_start_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_crew_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crew_start_date']['settings'] = array(
											    'format_type' => 'month_day',
											    'fromto' => 'both',
											    'multiple_number' => '',
											    'multiple_from' => '',
											    'multiple_to' => '',
											    'show_repeat_rule' => 'show',
											    );
  /* Field: Content: Start Time */
  $handler->display->display_options['fields']['field_crew_start_time']['id'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['table'] = 'field_data_field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['field'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_crew_start_time']['alter']['text'] = '[field_crew_start_date] - [field_crew_start_time]';
  /* Field: Content: Length of Time In Hours */
  $handler->display->display_options['fields']['field_crew_length_of_time']['id'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['table'] = 'field_data_field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['field'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['label'] = 'Length';
  /* Field: Content: Volunteer Opportunity Type */
  $handler->display->display_options['fields']['field_crew_opportunity_type']['id'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['table'] = 'field_data_field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['field'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Crew Position */
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['id'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['field'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Relevant Crew Information';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
									   'trim_length' => '250',
									   );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Delete Request';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print cm_crew_connect_delete_request_field($row, $view);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: CiviCRM Event Link */
  $handler->display->display_options['fields']['field_civicrm_event_link']['id'] = 'field_civicrm_event_link';
  $handler->display->display_options['fields']['field_civicrm_event_link']['table'] = 'field_data_field_civicrm_event_link';
  $handler->display->display_options['fields']['field_civicrm_event_link']['field'] = 'field_civicrm_event_link';
  $handler->display->display_options['fields']['field_civicrm_event_link']['label'] = 'Manage';
  /* Field: Content: Producer */
  $handler->display->display_options['fields']['field_app_producer']['id'] = 'field_app_producer';
  $handler->display->display_options['fields']['field_app_producer']['table'] = 'field_data_field_app_producer';
  $handler->display->display_options['fields']['field_app_producer']['field'] = 'field_app_producer';
  $handler->display->display_options['fields']['field_app_producer']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['field_app_producer']['label'] = '';
  $handler->display->display_options['fields']['field_app_producer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_app_producer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_app_producer']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_app_producer']['settings'] = array(
											 'link' => 0,
											 );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_app_status']['id'] = 'field_app_status';
  $handler->display->display_options['fields']['field_app_status']['table'] = 'field_data_field_app_status';
  $handler->display->display_options['fields']['field_app_status']['field'] = 'field_app_status';
  $handler->display->display_options['fields']['field_app_status']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['field_app_status']['label'] = 'Applicant Status';
  $handler->display->display_options['fields']['field_app_status']['empty'] = 'Open';
  /* Field: Content: Producer */
  $handler->display->display_options['fields']['field_app_producer_1']['id'] = 'field_app_producer_1';
  $handler->display->display_options['fields']['field_app_producer_1']['table'] = 'field_data_field_app_producer';
  $handler->display->display_options['fields']['field_app_producer_1']['field'] = 'field_app_producer';
  $handler->display->display_options['fields']['field_app_producer_1']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['field_app_producer_1']['label'] = 'Applicant';
  $handler->display->display_options['fields']['field_app_producer_1']['alter']['text'] = '[field_app_producer] ';
  $handler->display->display_options['fields']['field_app_producer_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_app_producer_1']['alter']['path'] = 'user/[field_app_producer]/cm_crew_connect';
  $handler->display->display_options['fields']['field_app_producer_1']['settings'] = array(
											   'link' => 0,
											   );
  /* Field: Content: Producer */
  $handler->display->display_options['fields']['field_app_producer_2']['id'] = 'field_app_producer_2';
  $handler->display->display_options['fields']['field_app_producer_2']['table'] = 'field_data_field_app_producer';
  $handler->display->display_options['fields']['field_app_producer_2']['field'] = 'field_app_producer';
  $handler->display->display_options['fields']['field_app_producer_2']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['field_app_producer_2']['label'] = 'Delete Applicant';
  $handler->display->display_options['fields']['field_app_producer_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_app_producer_2']['alter']['text'] = 'Delete Applicant';
  $handler->display->display_options['fields']['field_app_producer_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_app_producer_2']['alter']['path'] = 'node/[nid_1]/delete?destination=admin/cm_crew_connect/search';
  $handler->display->display_options['fields']['field_app_producer_2']['settings'] = array(
											   'link' => 0,
											   );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['sorts']['field_crew_start_date_value']['id'] = 'field_crew_start_date_value';
  $handler->display->display_options['sorts']['field_crew_start_date_value']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['sorts']['field_crew_start_date_value']['field'] = 'field_crew_start_date_value';
  $handler->display->display_options['sorts']['field_crew_start_date_value']['order'] = 'DESC';
  /* Sort criterion: Content: Start Time (field_crew_start_time) */
  $handler->display->display_options['sorts']['field_crew_start_time_value']['id'] = 'field_crew_start_time_value';
  $handler->display->display_options['sorts']['field_crew_start_time_value']['table'] = 'field_data_field_crew_start_time';
  $handler->display->display_options['sorts']['field_crew_start_time_value']['field'] = 'field_crew_start_time_value';
  $handler->display->display_options['sorts']['field_crew_start_time_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'crew_connect_request' => 'crew_connect_request',
									 );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['filters']['field_crew_start_date_value']['id'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['filters']['field_crew_start_date_value']['field'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_crew_start_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['operator_id'] = 'field_crew_start_date_value_op';
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['operator'] = 'field_crew_start_date_value_op';
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['identifier'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['remember_roles'] = array(
														   2 => '2',
														   3 => 0,
														   1 => 0,
														   44 => 0,
														   8 => 0,
														   14 => 0,
														   10 => 0,
														   6 => 0,
														   11 => 0,
														   4 => 0,
														   16 => 0,
														   17 => 0,
														   20 => 0,
														   22 => 0,
														   23 => 0,
														   25 => 0,
														   39 => 0,
														   28 => 0,
														   29 => 0,
														   45 => 0,
														   26 => 0,
														   37 => 0,
														   33 => 0,
														   34 => 0,
														   35 => 0,
														   46 => 0,
														   36 => 0,
														   43 => 0,
														   32 => 0,
														   );
  $handler->display->display_options['filters']['field_crew_start_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_crew_start_date_value']['year_range'] = '-0:+1';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Project Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
											     2 => '2',
											     3 => 0,
											     1 => 0,
											     44 => 0,
											     8 => 0,
											     14 => 0,
											     10 => 0,
											     6 => 0,
											     11 => 0,
											     4 => 0,
											     16 => 0,
											     17 => 0,
											     20 => 0,
											     22 => 0,
											     23 => 0,
											     25 => 0,
											     39 => 0,
											     28 => 0,
											     29 => 0,
											     45 => 0,
											     26 => 0,
											     37 => 0,
											     33 => 0,
											     34 => 0,
											     35 => 0,
											     46 => 0,
											     36 => 0,
											     43 => 0,
											     32 => 0,
											     );
  /* Filter criterion: Content: Status (field_crew_status) */
  $handler->display->display_options['filters']['field_crew_status_value']['id'] = 'field_crew_status_value';
  $handler->display->display_options['filters']['field_crew_status_value']['table'] = 'field_data_field_crew_status';
  $handler->display->display_options['filters']['field_crew_status_value']['field'] = 'field_crew_status_value';
  $handler->display->display_options['filters']['field_crew_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_status_value']['expose']['operator_id'] = 'field_crew_status_value_op';
  $handler->display->display_options['filters']['field_crew_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_crew_status_value']['expose']['operator'] = 'field_crew_status_value_op';
  $handler->display->display_options['filters']['field_crew_status_value']['expose']['identifier'] = 'field_crew_status_value';
  $handler->display->display_options['filters']['field_crew_status_value']['expose']['remember_roles'] = array(
													       2 => '2',
													       3 => 0,
													       1 => 0,
													       44 => 0,
													       8 => 0,
													       14 => 0,
													       10 => 0,
													       6 => 0,
													       11 => 0,
													       4 => 0,
													       16 => 0,
													       17 => 0,
													       20 => 0,
													       22 => 0,
													       23 => 0,
													       25 => 0,
													       39 => 0,
													       28 => 0,
													       29 => 0,
													       45 => 0,
													       26 => 0,
													       37 => 0,
													       33 => 0,
													       34 => 0,
													       35 => 0,
													       46 => 0,
													       36 => 0,
													       43 => 0,
													       32 => 0,
													       );
  /* Filter criterion: Content: Producer&#039;s Name (field_crew_producer_name) */
  $handler->display->display_options['filters']['field_crew_producer_name_value']['id'] = 'field_crew_producer_name_value';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['table'] = 'field_data_field_crew_producer_name';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['field'] = 'field_crew_producer_name_value';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_producer_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['operator_id'] = 'field_crew_producer_name_value_op';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['label'] = 'Producer\'s Name';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['operator'] = 'field_crew_producer_name_value_op';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['identifier'] = 'field_crew_producer_name_value';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['remember_roles'] = array(
														      2 => '2',
														      3 => 0,
														      1 => 0,
														      44 => 0,
														      8 => 0,
														      14 => 0,
														      10 => 0,
														      6 => 0,
														      11 => 0,
														      4 => 0,
														      16 => 0,
														      17 => 0,
														      20 => 0,
														      22 => 0,
														      23 => 0,
														      25 => 0,
														      39 => 0,
														      28 => 0,
														      29 => 0,
														      45 => 0,
														      26 => 0,
														      37 => 0,
														      33 => 0,
														      34 => 0,
														      35 => 0,
														      46 => 0,
														      36 => 0,
														      43 => 0,
														      32 => 0,
														      );
  /* Filter criterion: Content: Crew Position (field_crew_position_taxonomy) */
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['id'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['field'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['operator_id'] = 'field_crew_position_taxonomy_tid_op';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['label'] = 'Crew Position';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['operator'] = 'field_crew_position_taxonomy_tid_op';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['identifier'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['remember_roles'] = array(
															2 => '2',
															3 => 0,
															1 => 0,
															44 => 0,
															8 => 0,
															14 => 0,
															10 => 0,
															6 => 0,
															11 => 0,
															4 => 0,
															51 => 0,
															16 => 0,
															49 => 0,
															17 => 0,
															20 => 0,
															50 => 0,
															48 => 0,
															39 => 0,
															28 => 0,
															29 => 0,
															45 => 0,
															37 => 0,
															34 => 0,
															35 => 0,
															46 => 0,
															43 => 0,
															47 => 0,
															32 => 0,
															52 => 0,
															);
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['vocabulary'] = 'crew_connect_position';
  $handler->display->display_options['path'] = 'admin/cm_crew_connect/search';

  /* Display: Admin Search (incl Signup) */
  $handler = $view->new_display('page', 'Admin Search (incl Signup)', 'page_2');
  $handler->display->display_options['display_description'] = 'signup to crew and edit crew request for staff';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer crew connect';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['empty'] = TRUE;
  $handler->display->display_options['footer']['php']['php_output'] = ' <?php 
cm_crew_connect_override_messages();
?>
';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Producer's Name */
  $handler->display->display_options['fields']['field_crew_producer_name']['id'] = 'field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['table'] = 'field_data_field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['field'] = 'field_crew_producer_name';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Project Name';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_crew_start_date']['id'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['field'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_crew_start_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_crew_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_crew_start_date']['settings'] = array(
											    'format_type' => 'month_day',
											    'fromto' => 'both',
											    'multiple_number' => '',
											    'multiple_from' => '',
											    'multiple_to' => '',
											    'show_repeat_rule' => 'show',
											    );
  /* Field: Content: Start Time */
  $handler->display->display_options['fields']['field_crew_start_time']['id'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['table'] = 'field_data_field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['field'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_crew_start_time']['alter']['text'] = '[field_crew_start_date] - [field_crew_start_time]';
  /* Field: Content: Length of Time In Hours */
  $handler->display->display_options['fields']['field_crew_length_of_time']['id'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['table'] = 'field_data_field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['field'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['label'] = 'Length';
  /* Field: Content: Crew Position */
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['id'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['field'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Relevant Crew Information';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
									   'trim_length' => '250',
									   );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Sign Up to Crew';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print cm_crew_connect_sign_up_to_crew_link($row);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit Crew Request';
  /* Field: Content: CiviCRM Event Link */
  $handler->display->display_options['fields']['field_civicrm_event_link']['id'] = 'field_civicrm_event_link';
  $handler->display->display_options['fields']['field_civicrm_event_link']['table'] = 'field_data_field_civicrm_event_link';
  $handler->display->display_options['fields']['field_civicrm_event_link']['field'] = 'field_civicrm_event_link';
  $handler->display->display_options['fields']['field_civicrm_event_link']['label'] = 'Manage';
  /* Field: Content: Producer */
  $handler->display->display_options['fields']['field_app_producer']['id'] = 'field_app_producer';
  $handler->display->display_options['fields']['field_app_producer']['table'] = 'field_data_field_app_producer';
  $handler->display->display_options['fields']['field_app_producer']['field'] = 'field_app_producer';
  $handler->display->display_options['fields']['field_app_producer']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['field_app_producer']['label'] = '';
  $handler->display->display_options['fields']['field_app_producer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_app_producer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_app_producer']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_app_producer']['settings'] = array(
											 'link' => 0,
											 );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_app_status']['id'] = 'field_app_status';
  $handler->display->display_options['fields']['field_app_status']['table'] = 'field_data_field_app_status';
  $handler->display->display_options['fields']['field_app_status']['field'] = 'field_app_status';
  $handler->display->display_options['fields']['field_app_status']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['field_app_status']['label'] = 'Applicant Status';
  $handler->display->display_options['fields']['field_app_status']['empty'] = 'Open';
  /* Field: Content: Producer */
  $handler->display->display_options['fields']['field_app_producer_1']['id'] = 'field_app_producer_1';
  $handler->display->display_options['fields']['field_app_producer_1']['table'] = 'field_data_field_app_producer';
  $handler->display->display_options['fields']['field_app_producer_1']['field'] = 'field_app_producer';
  $handler->display->display_options['fields']['field_app_producer_1']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['field_app_producer_1']['label'] = 'Volunteer';
  $handler->display->display_options['fields']['field_app_producer_1']['alter']['text'] = '[field_app_producer] ';
  $handler->display->display_options['fields']['field_app_producer_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_app_producer_1']['alter']['path'] = 'user/[field_app_producer]/cm_crew_connect';
  $handler->display->display_options['fields']['field_app_producer_1']['settings'] = array(
											   'link' => 0,
											   );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Content: Producer */
  $handler->display->display_options['fields']['field_app_producer_2']['id'] = 'field_app_producer_2';
  $handler->display->display_options['fields']['field_app_producer_2']['table'] = 'field_data_field_app_producer';
  $handler->display->display_options['fields']['field_app_producer_2']['field'] = 'field_app_producer';
  $handler->display->display_options['fields']['field_app_producer_2']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['field_app_producer_2']['label'] = 'Delete Applicant';
  $handler->display->display_options['fields']['field_app_producer_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_app_producer_2']['alter']['text'] = 'Delete Applicant';
  $handler->display->display_options['fields']['field_app_producer_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_app_producer_2']['alter']['path'] = 'node/[nid_1]/delete?destination=admin/cm_crew_connect/search';
  $handler->display->display_options['fields']['field_app_producer_2']['settings'] = array(
											   'link' => 0,
											   );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['sorts']['field_crew_start_date_value']['id'] = 'field_crew_start_date_value';
  $handler->display->display_options['sorts']['field_crew_start_date_value']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['sorts']['field_crew_start_date_value']['field'] = 'field_crew_start_date_value';
  $handler->display->display_options['sorts']['field_crew_start_date_value']['order'] = 'DESC';
  /* Sort criterion: Content: Start Time (field_crew_start_time) */
  $handler->display->display_options['sorts']['field_crew_start_time_value']['id'] = 'field_crew_start_time_value';
  $handler->display->display_options['sorts']['field_crew_start_time_value']['table'] = 'field_data_field_crew_start_time';
  $handler->display->display_options['sorts']['field_crew_start_time_value']['field'] = 'field_crew_start_time_value';
  $handler->display->display_options['sorts']['field_crew_start_time_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'crew_connect_request' => 'crew_connect_request',
									 );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['filters']['field_crew_start_date_value']['id'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['filters']['field_crew_start_date_value']['field'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_crew_start_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_start_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['operator_id'] = 'field_crew_start_date_value_op';
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['operator'] = 'field_crew_start_date_value_op';
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['identifier'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['expose']['remember_roles'] = array(
														   2 => '2',
														   3 => 0,
														   1 => 0,
														   44 => 0,
														   8 => 0,
														   14 => 0,
														   10 => 0,
														   6 => 0,
														   11 => 0,
														   4 => 0,
														   16 => 0,
														   17 => 0,
														   20 => 0,
														   22 => 0,
														   23 => 0,
														   25 => 0,
														   39 => 0,
														   28 => 0,
														   29 => 0,
														   45 => 0,
														   26 => 0,
														   37 => 0,
														   33 => 0,
														   34 => 0,
														   35 => 0,
														   46 => 0,
														   36 => 0,
														   43 => 0,
														   32 => 0,
														   );
  $handler->display->display_options['filters']['field_crew_start_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_crew_start_date_value']['year_range'] = '-0:+1';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Project Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
											     2 => '2',
											     3 => 0,
											     1 => 0,
											     44 => 0,
											     8 => 0,
											     14 => 0,
											     10 => 0,
											     6 => 0,
											     11 => 0,
											     4 => 0,
											     16 => 0,
											     17 => 0,
											     20 => 0,
											     22 => 0,
											     23 => 0,
											     25 => 0,
											     39 => 0,
											     28 => 0,
											     29 => 0,
											     45 => 0,
											     26 => 0,
											     37 => 0,
											     33 => 0,
											     34 => 0,
											     35 => 0,
											     46 => 0,
											     36 => 0,
											     43 => 0,
											     32 => 0,
											     );
  /* Filter criterion: Content: Status (field_crew_status) */
  $handler->display->display_options['filters']['field_crew_status_value']['id'] = 'field_crew_status_value';
  $handler->display->display_options['filters']['field_crew_status_value']['table'] = 'field_data_field_crew_status';
  $handler->display->display_options['filters']['field_crew_status_value']['field'] = 'field_crew_status_value';
  $handler->display->display_options['filters']['field_crew_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_status_value']['expose']['operator_id'] = 'field_crew_status_value_op';
  $handler->display->display_options['filters']['field_crew_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_crew_status_value']['expose']['operator'] = 'field_crew_status_value_op';
  $handler->display->display_options['filters']['field_crew_status_value']['expose']['identifier'] = 'field_crew_status_value';
  $handler->display->display_options['filters']['field_crew_status_value']['expose']['remember_roles'] = array(
													       2 => '2',
													       3 => 0,
													       1 => 0,
													       44 => 0,
													       8 => 0,
													       14 => 0,
													       10 => 0,
													       6 => 0,
													       11 => 0,
													       4 => 0,
													       16 => 0,
													       17 => 0,
													       20 => 0,
													       22 => 0,
													       23 => 0,
													       25 => 0,
													       39 => 0,
													       28 => 0,
													       29 => 0,
													       45 => 0,
													       26 => 0,
													       37 => 0,
													       33 => 0,
													       34 => 0,
													       35 => 0,
													       46 => 0,
													       36 => 0,
													       43 => 0,
													       32 => 0,
													       );
  /* Filter criterion: Content: Producer&#039;s Name (field_crew_producer_name) */
  $handler->display->display_options['filters']['field_crew_producer_name_value']['id'] = 'field_crew_producer_name_value';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['table'] = 'field_data_field_crew_producer_name';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['field'] = 'field_crew_producer_name_value';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['operator_id'] = 'field_crew_producer_name_value_op';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['label'] = 'Producer\'s Name';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['operator'] = 'field_crew_producer_name_value_op';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['identifier'] = 'field_crew_producer_name_value';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['remember_roles'] = array(
														      2 => '2',
														      3 => 0,
														      1 => 0,
														      44 => 0,
														      8 => 0,
														      14 => 0,
														      10 => 0,
														      6 => 0,
														      11 => 0,
														      4 => 0,
														      16 => 0,
														      17 => 0,
														      20 => 0,
														      22 => 0,
														      23 => 0,
														      25 => 0,
														      39 => 0,
														      28 => 0,
														      29 => 0,
														      45 => 0,
														      26 => 0,
														      37 => 0,
														      33 => 0,
														      34 => 0,
														      35 => 0,
														      46 => 0,
														      36 => 0,
														      43 => 0,
														      32 => 0,
														      );
  /* Filter criterion: Content: Crew Position (field_crew_position_taxonomy) */
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['id'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['field'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['operator_id'] = 'field_crew_position_taxonomy_tid_op';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['label'] = 'Crew Position';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['operator'] = 'field_crew_position_taxonomy_tid_op';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['identifier'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['remember_roles'] = array(
															2 => '2',
															3 => 0,
															1 => 0,
															44 => 0,
															8 => 0,
															14 => 0,
															10 => 0,
															6 => 0,
															11 => 0,
															4 => 0,
															51 => 0,
															16 => 0,
															49 => 0,
															17 => 0,
															20 => 0,
															50 => 0,
															48 => 0,
															39 => 0,
															28 => 0,
															29 => 0,
															45 => 0,
															37 => 0,
															34 => 0,
															35 => 0,
															46 => 0,
															43 => 0,
															47 => 0,
															32 => 0,
															52 => 0,
															);
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['vocabulary'] = 'crew_connect_position';
  $handler->display->display_options['path'] = 'admin/cm_crew_connect/search_clone';

  $views[$view->name] = $view;
  //FINISHED ADDING VIEW
  ///////////////////////////////////////////////////////////////


  //////////////////////////////////////////////////////////////
  //ADDING VIEW: crew_connect_application_for_request
  // Add view to list of views to provide.
  $view = new view();
  $view->name = 'crew_connect_application_for_request';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Crew Connect: Application For Request';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'use crew connect';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Participant ID */
  $handler->display->display_options['fields']['field_app_participant_id']['id'] = 'field_app_participant_id';
  $handler->display->display_options['fields']['field_app_participant_id']['table'] = 'field_data_field_app_participant_id';
  $handler->display->display_options['fields']['field_app_participant_id']['field'] = 'field_app_participant_id';
  $handler->display->display_options['fields']['field_app_participant_id']['label'] = '';
  $handler->display->display_options['fields']['field_app_participant_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_app_participant_id']['settings'] = array(
											       'thousand_separator' => '',
											       'prefix_suffix' => 1,
											       );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Crew Connect Node (field_app_crew_connect_node) */
  $handler->display->display_options['arguments']['field_app_crew_connect_node_target_id']['id'] = 'field_app_crew_connect_node_target_id';
  $handler->display->display_options['arguments']['field_app_crew_connect_node_target_id']['table'] = 'field_data_field_app_crew_connect_node';
  $handler->display->display_options['arguments']['field_app_crew_connect_node_target_id']['field'] = 'field_app_crew_connect_node_target_id';
  $handler->display->display_options['arguments']['field_app_crew_connect_node_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_app_crew_connect_node_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_app_crew_connect_node_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_app_crew_connect_node_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_app_crew_connect_node_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'crew_connect_application' => 'crew_connect_application',
									 );
  $handler->display->display_options['filters']['type']['group'] = 1;

  $views[$view->name] = $view;
  //FINISHED ADDING VIEW
  ///////////////////////////////////////////////////////////////


  //////////////////////////////////////////////////////////////
  //ADDING VIEW: crew_connect_crew_requests
  // Add view to list of views to provide.
  $view = new view();
  $view->name = 'crew_connect_crew_requests';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Crew Connect: Crew Requests by Producer';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'field-group-fieldset';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'use crew connect';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
									 'nid' => 'nid',
									 'title' => 'title',
									 'field_crew_producer_name' => 'field_crew_producer_name',
									 'field_crew_start_date' => 'field_crew_start_date',
									 'field_crew_start_time' => 'field_crew_start_time',
									 'field_crew_length_of_time' => 'field_crew_length_of_time',
									 'field_crew_opportunity_type' => 'field_crew_opportunity_type',
									 'field_crew_position_taxonomy' => 'field_crew_position_taxonomy',
									 'php' => 'php',
									 );
  $handler->display->display_options['style_options']['default'] = 'field_crew_start_date';
  $handler->display->display_options['style_options']['info'] = array(
								      'nid' => array(
										     'sortable' => 0,
										     'default_sort_order' => 'asc',
										     'align' => '',
										     'separator' => '',
										     'empty_column' => 0,
										     ),
								      'title' => array(
										       'sortable' => 1,
										       'default_sort_order' => 'asc',
										       'align' => '',
										       'separator' => '',
										       'empty_column' => 0,
										       ),
								      'field_crew_producer_name' => array(
													  'sortable' => 1,
													  'default_sort_order' => 'asc',
													  'align' => '',
													  'separator' => '',
													  'empty_column' => 0,
													  ),
								      'field_crew_start_date' => array(
												       'sortable' => 1,
												       'default_sort_order' => 'asc',
												       'align' => '',
												       'separator' => '',
												       'empty_column' => 0,
												       ),
								      'field_crew_start_time' => array(
												       'sortable' => 1,
												       'default_sort_order' => 'asc',
												       'align' => '',
												       'separator' => '',
												       'empty_column' => 0,
												       ),
								      'field_crew_length_of_time' => array(
													   'sortable' => 1,
													   'default_sort_order' => 'asc',
													   'align' => '',
													   'separator' => '',
													   'empty_column' => 0,
													   ),
								      'field_crew_opportunity_type' => array(
													     'sortable' => 1,
													     'default_sort_order' => 'asc',
													     'align' => '',
													     'separator' => '',
													     'empty_column' => 0,
													     ),
								      'field_crew_position_taxonomy' => array(
													      'sortable' => 1,
													      'default_sort_order' => 'asc',
													      'align' => '',
													      'separator' => '',
													      'empty_column' => 0,
													      ),
								      'php' => array(
										     'align' => '',
										     'separator' => '',
										     'empty_column' => 0,
										     ),
								      );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3><strong>My Future Project Crew Requests:</strong></h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Project ID */
  $handler->display->display_options['fields']['field_crew_project_id']['id'] = 'field_crew_project_id';
  $handler->display->display_options['fields']['field_crew_project_id']['table'] = 'field_data_field_crew_project_id';
  $handler->display->display_options['fields']['field_crew_project_id']['field'] = 'field_crew_project_id';
  $handler->display->display_options['fields']['field_crew_project_id']['label'] = 'Project';
  $handler->display->display_options['fields']['field_crew_project_id']['settings'] = array(
											    'link' => 0,
											    );
  /* Field: Content: Crew Position */
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['id'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['field'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_crew_status']['id'] = 'field_crew_status';
  $handler->display->display_options['fields']['field_crew_status']['table'] = 'field_data_field_crew_status';
  $handler->display->display_options['fields']['field_crew_status']['field'] = 'field_crew_status';
  $handler->display->display_options['fields']['field_crew_status']['label'] = 'Request Status';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_app_status']['id'] = 'field_app_status';
  $handler->display->display_options['fields']['field_app_status']['table'] = 'field_data_field_app_status';
  $handler->display->display_options['fields']['field_app_status']['field'] = 'field_app_status';
  $handler->display->display_options['fields']['field_app_status']['label'] = 'Application Status';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Apply For Shift';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Apply For Shift';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/add/crew-connect-application?field_app_crew_connect_node=[nid]&field_app_producer=[uid]';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'crew_connect_request' => 'crew_connect_request',
									 );

  /* Display: Future Crew Requests */
  $handler = $view->new_display('block', 'Future Crew Requests', 'future');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Crew Request';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Producer's Name */
  $handler->display->display_options['fields']['field_crew_producer_name']['id'] = 'field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['table'] = 'field_data_field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['field'] = 'field_crew_producer_name';
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_crew_start_date']['id'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['field'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_crew_start_date']['settings'] = array(
											    'format_type' => 'short',
											    'fromto' => 'both',
											    'multiple_number' => '',
											    'multiple_from' => '',
											    'multiple_to' => '',
											    'show_repeat_rule' => 'show',
											    );
  /* Field: Content: Start Time */
  $handler->display->display_options['fields']['field_crew_start_time']['id'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['table'] = 'field_data_field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['field'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['label'] = 'Time';
  /* Field: Content: Length of Time In Hours */
  $handler->display->display_options['fields']['field_crew_length_of_time']['id'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['table'] = 'field_data_field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['field'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['label'] = 'Length of Shift';
  $handler->display->display_options['fields']['field_crew_length_of_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_crew_length_of_time']['alter']['text'] = '[field_crew_length_of_time]  hours';
  /* Field: Content: Volunteer Opportunity Type */
  $handler->display->display_options['fields']['field_crew_opportunity_type']['id'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['table'] = 'field_data_field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['field'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['label'] = 'Opportunity Type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Crew Position */
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['id'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['field'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Edit';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
 print cm_crew_connect_edit_request_field($row);
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Applicant Name';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print cm_crew_connect_applicant_name($row);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'crew_connect_request' => 'crew_connect_request',
									 );
  /* Filter criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['filters']['field_crew_start_date_value']['id'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['filters']['field_crew_start_date_value']['field'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_crew_start_date_value']['default_date'] = 'now';

  /* Display: Past Crew Requests */
  $handler = $view->new_display('block', 'Past Crew Requests', 'past');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Crew Request';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Producer's Name */
  $handler->display->display_options['fields']['field_crew_producer_name']['id'] = 'field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['table'] = 'field_data_field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['field'] = 'field_crew_producer_name';
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_crew_start_date']['id'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['field'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_crew_start_date']['settings'] = array(
											    'format_type' => 'short',
											    'fromto' => 'both',
											    'multiple_number' => '',
											    'multiple_from' => '',
											    'multiple_to' => '',
											    'show_repeat_rule' => 'show',
											    );
  /* Field: Content: Start Time */
  $handler->display->display_options['fields']['field_crew_start_time']['id'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['table'] = 'field_data_field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['field'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['label'] = 'Time';
  /* Field: Content: Length of Time In Hours */
  $handler->display->display_options['fields']['field_crew_length_of_time']['id'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['table'] = 'field_data_field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['field'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['label'] = 'Length of Shift';
  $handler->display->display_options['fields']['field_crew_length_of_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_crew_length_of_time']['alter']['text'] = '[field_crew_length_of_time]  hours';
  /* Field: Content: Volunteer Opportunity Type */
  $handler->display->display_options['fields']['field_crew_opportunity_type']['id'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['table'] = 'field_data_field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['field'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['label'] = 'Opportunity Type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Crew Position */
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['id'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['field'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Applicant Name';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print cm_crew_connect_applicant_name($row);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'crew_connect_request' => 'crew_connect_request',
									 );
  /* Filter criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['filters']['field_crew_start_date_value']['id'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['filters']['field_crew_start_date_value']['field'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_crew_start_date_value']['default_date'] = 'now';

  /* Display: Future Crew Requests (incl cancel link) */
  $handler = $view->new_display('block', 'Future Crew Requests (incl cancel link)', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Crew Request';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Producer's Name */
  $handler->display->display_options['fields']['field_crew_producer_name']['id'] = 'field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['table'] = 'field_data_field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['field'] = 'field_crew_producer_name';
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_crew_start_date']['id'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['field'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_crew_start_date']['settings'] = array(
											    'format_type' => 'short',
											    'fromto' => 'both',
											    'multiple_number' => '',
											    'multiple_from' => '',
											    'multiple_to' => '',
											    'show_repeat_rule' => 'show',
											    );
  /* Field: Content: Start Time */
  $handler->display->display_options['fields']['field_crew_start_time']['id'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['table'] = 'field_data_field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['field'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['label'] = 'Time';
  /* Field: Content: Length of Time In Hours */
  $handler->display->display_options['fields']['field_crew_length_of_time']['id'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['table'] = 'field_data_field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['field'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['label'] = 'Length of Shift';
  $handler->display->display_options['fields']['field_crew_length_of_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_crew_length_of_time']['alter']['text'] = '[field_crew_length_of_time]  hours';
  /* Field: Content: Volunteer Opportunity Type */
  $handler->display->display_options['fields']['field_crew_opportunity_type']['id'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['table'] = 'field_data_field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['field'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['label'] = 'Opportunity Type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Crew Position */
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['id'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['field'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Edit';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
 print cm_crew_connect_edit_request_field($row);
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Cancel';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
print cm_crew_connect_cancel_request_field($row);
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Applicant Name';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print cm_crew_connect_applicant_name($row);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'crew_connect_request' => 'crew_connect_request',
									 );
  /* Filter criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['filters']['field_crew_start_date_value']['id'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['filters']['field_crew_start_date_value']['field'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_crew_start_date_value']['default_date'] = 'now';

  $views[$view->name] = $view;
  //FINISHED ADDING VIEW
  ///////////////////////////////////////////////////////////////


  //////////////////////////////////////////////////////////////
  //ADDING VIEW: crew_connect_project_alerts
  // Add view to list of views to provide.
  $view = new view();
  $view->name = 'crew_connect_project_alerts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Crew Connect: Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Crew Connect: Project Alerts';
  $handler->display->display_options['css_class'] = 'field-group-fieldset';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'use crew connect';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
									 'title' => 'title',
									 'nid' => 'nid',
									 'field_is_crew_needed' => 'field_is_crew_needed',
									 );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
								      'title' => array(
										       'sortable' => 0,
										       'default_sort_order' => 'asc',
										       'align' => '',
										       'separator' => '',
										       'empty_column' => 0,
										       ),
								      'nid' => array(
										     'sortable' => 0,
										     'default_sort_order' => 'asc',
										     'align' => '',
										     'separator' => '',
										     'empty_column' => 0,
										     ),
								      'field_is_crew_needed' => array(
												      'sortable' => 0,
												      'default_sort_order' => 'asc',
												      'align' => '',
												      'separator' => '',
												      'empty_column' => 0,
												      ),
								      );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'node/[nid]';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'cm_project' => 'cm_project',
									 );

  /* Display: My Projects */
  $handler = $view->new_display('block', 'My Projects', 'crew_enabled');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3><strong>My Projects:</strong></h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'node/[nid]';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print cm_crew_connect_add_request_field($row);

?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'cm_project' => 'cm_project',
									 );
  /* Filter criterion: Content: Active (group_group) */
  $handler->display->display_options['filters']['group_group_value']['id'] = 'group_group_value';
  $handler->display->display_options['filters']['group_group_value']['table'] = 'field_data_group_group';
  $handler->display->display_options['filters']['group_group_value']['field'] = 'group_group_value';
  $handler->display->display_options['filters']['group_group_value']['value'] = array(
										      1 => '1',
										      );

  
  $views[$view->name] = $view;
  //FINISHED ADDING VIEW
  ///////////////////////////////////////////////////////////////


  //////////////////////////////////////////////////////////////
  //ADDING VIEW: crew_connect_resave_requests
  // Add view to list of views to provide.
  $view = new view();
  $view->name = 'crew_connect_resave_requests';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Crew Connect: Resave Requests';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Crew Connect: Resave Requests';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer crew connect';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
												  'action::node_save_action' => array(
																      'selected' => 1,
																      'postpone_processing' => 0,
																      'skip_confirmation' => 0,
																      'override_label' => 0,
																      'label' => '',
																      ),
												  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'crew_connect_request' => 'crew_connect_request',
									 );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/crew-connect-resave-requests';

  
  $views[$view->name] = $view;
  //FINISHED ADDING VIEW
  ///////////////////////////////////////////////////////////////


  //////////////////////////////////////////////////////////////
  //ADDING VIEW: crew_connect_volunteer_for_a_crew
  // Add view to list of views to provide.
  $view = new view();
  $view->name = 'crew_connect_volunteer_for_a_crew';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Crew Connect: Volunteer For a Crew';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'field-group-fieldset';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'use crew connect';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
									 'nid' => 'nid',
									 'uid' => 'uid',
									 'title' => 'title',
									 'field_crew_producer_name' => 'field_crew_producer_name',
									 'picture' => 'picture',
									 'field_crew_start_date' => 'field_crew_start_date',
									 'field_crew_start_time' => 'field_crew_start_time',
									 'field_crew_length_of_time' => 'field_crew_length_of_time',
									 'field_crew_position_taxonomy' => 'field_crew_position_taxonomy',
									 'php' => 'php',
									 'field_crew_opportunity_type' => 'field_crew_opportunity_type',
									 );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
								      'nid' => array(
										     'sortable' => 0,
										     'default_sort_order' => 'asc',
										     'align' => '',
										     'separator' => '',
										     'empty_column' => 0,
										     ),
								      'uid' => array(
										     'align' => '',
										     'separator' => '',
										     'empty_column' => 0,
										     ),
								      'title' => array(
										       'sortable' => 1,
										       'default_sort_order' => 'asc',
										       'align' => '',
										       'separator' => '',
										       'empty_column' => 0,
										       ),
								      'field_crew_producer_name' => array(
													  'sortable' => 1,
													  'default_sort_order' => 'asc',
													  'align' => '',
													  'separator' => '',
													  'empty_column' => 0,
													  ),
								      'picture' => array(
											 'sortable' => 0,
											 'default_sort_order' => 'asc',
											 'align' => '',
											 'separator' => '',
											 'empty_column' => 0,
											 ),
								      'field_crew_start_date' => array(
												       'sortable' => 1,
												       'default_sort_order' => 'asc',
												       'align' => '',
												       'separator' => '',
												       'empty_column' => 0,
												       ),
								      'field_crew_start_time' => array(
												       'sortable' => 1,
												       'default_sort_order' => 'asc',
												       'align' => '',
												       'separator' => '',
												       'empty_column' => 0,
												       ),
								      'field_crew_length_of_time' => array(
													   'sortable' => 1,
													   'default_sort_order' => 'asc',
													   'align' => '',
													   'separator' => '',
													   'empty_column' => 0,
													   ),
								      'field_crew_position_taxonomy' => array(
													      'sortable' => 1,
													      'default_sort_order' => 'asc',
													      'align' => '',
													      'separator' => '',
													      'empty_column' => 0,
													      ),
								      'php' => array(
										     'align' => '',
										     'separator' => '',
										     'empty_column' => 0,
										     ),
								      'field_crew_opportunity_type' => array(
													     'sortable' => 1,
													     'default_sort_order' => 'asc',
													     'align' => '',
													     'separator' => '',
													     'empty_column' => 0,
													     ),
								      );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Either you do not have the appropriate Certification, or their are currently no opportunities for this position.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_crew_project_id_target_id']['id'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['relationships']['field_crew_project_id_target_id']['table'] = 'field_data_field_crew_project_id';
  $handler->display->display_options['relationships']['field_crew_project_id_target_id']['field'] = 'field_crew_project_id_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_app_crew_connect_node_node']['id'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['relationships']['reverse_field_app_crew_connect_node_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_app_crew_connect_node_node']['field'] = 'reverse_field_app_crew_connect_node_node';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Project */
  $handler->display->display_options['fields']['field_crew_project_id']['id'] = 'field_crew_project_id';
  $handler->display->display_options['fields']['field_crew_project_id']['table'] = 'field_data_field_crew_project_id';
  $handler->display->display_options['fields']['field_crew_project_id']['field'] = 'field_crew_project_id';
  $handler->display->display_options['fields']['field_crew_project_id']['settings'] = array(
											    'link' => 0,
											    );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_crew_status']['id'] = 'field_crew_status';
  $handler->display->display_options['fields']['field_crew_status']['table'] = 'field_data_field_crew_status';
  $handler->display->display_options['fields']['field_crew_status']['field'] = 'field_crew_status';
  $handler->display->display_options['fields']['field_crew_status']['label'] = 'Request Status';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_app_status']['id'] = 'field_app_status';
  $handler->display->display_options['fields']['field_app_status']['table'] = 'field_data_field_app_status';
  $handler->display->display_options['fields']['field_app_status']['field'] = 'field_app_status';
  $handler->display->display_options['fields']['field_app_status']['label'] = 'Application Status';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Apply For Shift';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Apply For Shift';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/add/crew-connect-application?field_app_crew_connect_node=[nid]&field_app_producer=[uid]';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'crew_connect_request' => 'crew_connect_request',
									 );

  /* Display: Available Crew Requests */
  $handler = $view->new_display('block', 'Available Crew Requests', 'block');
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/crew-connect/requests-search">See All Available Crew Positions</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Either you do not have the appropriate Certification, or their are currently no opportunities for this position.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_crew_project_id_target_id']['id'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['relationships']['field_crew_project_id_target_id']['table'] = 'field_data_field_crew_project_id';
  $handler->display->display_options['relationships']['field_crew_project_id_target_id']['field'] = 'field_crew_project_id_target_id';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Project Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Producer's Name */
  $handler->display->display_options['fields']['field_crew_producer_name']['id'] = 'field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['table'] = 'field_data_field_crew_producer_name';
  $handler->display->display_options['fields']['field_crew_producer_name']['field'] = 'field_crew_producer_name';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_crew_start_date']['id'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['field'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['label'] = 'Date';
  $handler->display->display_options['fields']['field_crew_start_date']['settings'] = array(
											    'format_type' => 'short',
											    'fromto' => 'both',
											    'multiple_number' => '',
											    'multiple_from' => '',
											    'multiple_to' => '',
											    'show_repeat_rule' => 'show',
											    );
  /* Field: Content: Start Time */
  $handler->display->display_options['fields']['field_crew_start_time']['id'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['table'] = 'field_data_field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['field'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['label'] = 'Time';
  /* Field: Content: Length of Time In Hours */
  $handler->display->display_options['fields']['field_crew_length_of_time']['id'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['table'] = 'field_data_field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['field'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['label'] = 'Length of Shift';
  $handler->display->display_options['fields']['field_crew_length_of_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_crew_length_of_time']['alter']['text'] = '[field_crew_length_of_time]  hours';
  /* Field: Content: Volunteer Opportunity Type */
  $handler->display->display_options['fields']['field_crew_opportunity_type']['id'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['table'] = 'field_data_field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['field'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['label'] = 'Opportunity Type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Crew Position */
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['id'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['field'] = 'field_crew_position_taxonomy';
  $handler->display->display_options['fields']['field_crew_position_taxonomy']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'More Info';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
 print cm_crew_connect_sign_up_to_crew_link($row);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['sorts']['field_crew_start_date_value']['id'] = 'field_crew_start_date_value';
  $handler->display->display_options['sorts']['field_crew_start_date_value']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['sorts']['field_crew_start_date_value']['field'] = 'field_crew_start_date_value';
  /* Sort criterion: Content: Start Time (field_crew_start_time) */
  $handler->display->display_options['sorts']['field_crew_start_time_value']['id'] = 'field_crew_start_time_value';
  $handler->display->display_options['sorts']['field_crew_start_time_value']['table'] = 'field_data_field_crew_start_time';
  $handler->display->display_options['sorts']['field_crew_start_time_value']['field'] = 'field_crew_start_time_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Crew Position (field_crew_position_taxonomy) */
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['id'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['field'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_crew_position_taxonomy_tid']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Volunteer Opportunity Type (field_crew_opportunity_type) */
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['id'] = 'field_crew_opportunity_type_tid';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['table'] = 'field_data_field_crew_opportunity_type';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['field'] = 'field_crew_opportunity_type_tid';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_crew_opportunity_type_tid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'crew_connect_request' => 'crew_connect_request',
									 );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['filters']['field_crew_start_date_value']['id'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['filters']['field_crew_start_date_value']['field'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_crew_start_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_start_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Status (field_crew_status) */
  $handler->display->display_options['filters']['field_crew_status_value']['id'] = 'field_crew_status_value';
  $handler->display->display_options['filters']['field_crew_status_value']['table'] = 'field_data_field_crew_status';
  $handler->display->display_options['filters']['field_crew_status_value']['field'] = 'field_crew_status_value';
  $handler->display->display_options['filters']['field_crew_status_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_crew_status_value']['value'] = array(
											    'cancelled' => 'cancelled',
											    );
  $handler->display->display_options['filters']['field_crew_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_status_value']['expose']['operator_id'] = 'field_crew_status_value_op';
  $handler->display->display_options['filters']['field_crew_status_value']['expose']['label'] = 'Status (field_crew_status)';
  $handler->display->display_options['filters']['field_crew_status_value']['expose']['operator'] = 'field_crew_status_value_op';
  $handler->display->display_options['filters']['field_crew_status_value']['expose']['identifier'] = 'field_crew_status_value';
  /* Filter criterion: Content: CiviCRM Event Link (field_civicrm_event_link) */
  $handler->display->display_options['filters']['field_civicrm_event_link_value']['id'] = 'field_civicrm_event_link_value';
  $handler->display->display_options['filters']['field_civicrm_event_link_value']['table'] = 'field_data_field_civicrm_event_link';
  $handler->display->display_options['filters']['field_civicrm_event_link_value']['field'] = 'field_civicrm_event_link_value';
  $handler->display->display_options['filters']['field_civicrm_event_link_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_civicrm_event_link_value']['value'] = 'participant';
  $handler->display->display_options['filters']['field_civicrm_event_link_value']['group'] = 1;
  /* Filter criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['id'] = 'field_crew_start_date_value_1';
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['field'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['operator'] = 'between';
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['expose']['operator_id'] = 'field_crew_start_date_value_1_op';
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['expose']['operator'] = 'field_crew_start_date_value_1_op';
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['expose']['identifier'] = 'field_crew_start_date_value_1';
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['expose']['remember_roles'] = array(
														     2 => '2',
														     1 => 0,
														     3 => 0,
														     27 => 0,
														     7 => 0,
														     16 => 0,
														     14 => 0,
														     26 => 0,
														     11 => 0,
														     12 => 0,
														     6 => 0,
														     13 => 0,
														     33 => 0,
														     4 => 0,
														     30 => 0,
														     28 => 0,
														     32 => 0,
														     18 => 0,
														     22 => 0,
														     20 => 0,
														     25 => 0,
														     23 => 0,
														     31 => 0,
														     15 => 0,
														     34 => 0,
														     17 => 0,
														     21 => 0,
														     19 => 0,
														     35 => 0,
														     49 => 0,
														     44 => 0,
														     37 => 0,
														     43 => 0,
														     36 => 0,
														     57 => 0,
														     47 => 0,
														     56 => 0,
														     40 => 0,
														     50 => 0,
														     46 => 0,
														     39 => 0,
														     38 => 0,
														     41 => 0,
														     45 => 0,
														     42 => 0,
														     51 => 0,
														     48 => 0,
														     52 => 0,
														     55 => 0,
														     53 => 0,
														     54 => 0,
														     );
  $handler->display->display_options['filters']['field_crew_start_date_value_1']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_crew_project_id_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Project Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
											     2 => '2',
											     3 => 0,
											     1 => 0,
											     44 => 0,
											     8 => 0,
											     14 => 0,
											     10 => 0,
											     6 => 0,
											     11 => 0,
											     4 => 0,
											     51 => 0,
											     16 => 0,
											     49 => 0,
											     17 => 0,
											     20 => 0,
											     50 => 0,
											     48 => 0,
											     39 => 0,
											     28 => 0,
											     29 => 0,
											     45 => 0,
											     37 => 0,
											     34 => 0,
											     35 => 0,
											     46 => 0,
											     43 => 0,
											     47 => 0,
											     32 => 0,
											     52 => 0,
											     );
  /* Filter criterion: Content: Producer&#039;s Name (field_crew_producer_name) */
  $handler->display->display_options['filters']['field_crew_producer_name_value']['id'] = 'field_crew_producer_name_value';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['table'] = 'field_data_field_crew_producer_name';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['field'] = 'field_crew_producer_name_value';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_producer_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['operator_id'] = 'field_crew_producer_name_value_op';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['label'] = 'Producer\'s Name';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['operator'] = 'field_crew_producer_name_value_op';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['identifier'] = 'field_crew_producer_name_value';
  $handler->display->display_options['filters']['field_crew_producer_name_value']['expose']['remember_roles'] = array(
														      2 => '2',
														      3 => 0,
														      1 => 0,
														      44 => 0,
														      8 => 0,
														      14 => 0,
														      10 => 0,
														      6 => 0,
														      11 => 0,
														      4 => 0,
														      51 => 0,
														      16 => 0,
														      49 => 0,
														      17 => 0,
														      20 => 0,
														      50 => 0,
														      48 => 0,
														      39 => 0,
														      28 => 0,
														      29 => 0,
														      45 => 0,
														      37 => 0,
														      34 => 0,
														      35 => 0,
														      46 => 0,
														      43 => 0,
														      47 => 0,
														      32 => 0,
														      52 => 0,
														      );
  /* Filter criterion: Content: Crew Position (field_crew_position_taxonomy) */
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['id'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['table'] = 'field_data_field_crew_position_taxonomy';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['field'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['operator_id'] = 'field_crew_position_taxonomy_tid_op';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['label'] = 'Crew Position';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['operator'] = 'field_crew_position_taxonomy_tid_op';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['identifier'] = 'field_crew_position_taxonomy_tid';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['expose']['remember_roles'] = array(
															2 => '2',
															3 => 0,
															1 => 0,
															44 => 0,
															8 => 0,
															14 => 0,
															10 => 0,
															6 => 0,
															11 => 0,
															4 => 0,
															51 => 0,
															16 => 0,
															49 => 0,
															17 => 0,
															20 => 0,
															50 => 0,
															48 => 0,
															39 => 0,
															28 => 0,
															29 => 0,
															45 => 0,
															37 => 0,
															34 => 0,
															35 => 0,
															46 => 0,
															43 => 0,
															47 => 0,
															32 => 0,
															52 => 0,
															);
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_crew_position_taxonomy_tid']['vocabulary'] = 'crew_connect_position';

  /* Display: My Upcoming Crew Events */
  $handler = $view->new_display('block', 'My Upcoming Crew Events', 'block_3');
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You have no upcoming shifts.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Content: Producer */
  $handler->display->display_options['fields']['field_app_producer']['id'] = 'field_app_producer';
  $handler->display->display_options['fields']['field_app_producer']['table'] = 'field_data_field_app_producer';
  $handler->display->display_options['fields']['field_app_producer']['field'] = 'field_app_producer';
  $handler->display->display_options['fields']['field_app_producer']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['field_app_producer']['label'] = '';
  $handler->display->display_options['fields']['field_app_producer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_app_producer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_app_producer']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_app_producer']['settings'] = array(
											 'link' => 0,
											 );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Volunteer Opportunity Type */
  $handler->display->display_options['fields']['field_crew_opportunity_type']['id'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['table'] = 'field_data_field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['field'] = 'field_crew_opportunity_type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['label'] = 'Opportunity Type';
  $handler->display->display_options['fields']['field_crew_opportunity_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_crew_start_date']['id'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['field'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['settings'] = array(
											    'format_type' => 'short',
											    'fromto' => 'both',
											    'multiple_number' => '',
											    'multiple_from' => '',
											    'multiple_to' => '',
											    'show_repeat_rule' => 'show',
											    );
  /* Field: Content: Start Time */
  $handler->display->display_options['fields']['field_crew_start_time']['id'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['table'] = 'field_data_field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['field'] = 'field_crew_start_time';
  /* Field: Content: Length of Time In Hours */
  $handler->display->display_options['fields']['field_crew_length_of_time']['id'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['table'] = 'field_data_field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['field'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['label'] = 'Length of Shift';
  $handler->display->display_options['fields']['field_crew_length_of_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_crew_length_of_time']['alter']['text'] = '[field_crew_length_of_time]  hours';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_app_status']['id'] = 'field_app_status';
  $handler->display->display_options['fields']['field_app_status']['table'] = 'field_data_field_app_status';
  $handler->display->display_options['fields']['field_app_status']['field'] = 'field_app_status';
  $handler->display->display_options['fields']['field_app_status']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['field_app_status']['label'] = 'Application Status';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Producer (field_app_producer) */
  $handler->display->display_options['arguments']['field_app_producer_target_id']['id'] = 'field_app_producer_target_id';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['table'] = 'field_data_field_app_producer';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['field'] = 'field_app_producer_target_id';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['field_app_producer_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'crew_connect_request' => 'crew_connect_request',
									 );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['filters']['nid']['operator'] = 'not empty';
  /* Filter criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['filters']['field_crew_start_date_value']['id'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['filters']['field_crew_start_date_value']['field'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_crew_start_date_value']['default_date'] = 'now';

  /* Display: My Past Crew Events */
  $handler = $view->new_display('block', 'My Past Crew Events', 'block_4');
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Content: Producer */
  $handler->display->display_options['fields']['field_app_producer']['id'] = 'field_app_producer';
  $handler->display->display_options['fields']['field_app_producer']['table'] = 'field_data_field_app_producer';
  $handler->display->display_options['fields']['field_app_producer']['field'] = 'field_app_producer';
  $handler->display->display_options['fields']['field_app_producer']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['field_app_producer']['label'] = '';
  $handler->display->display_options['fields']['field_app_producer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_app_producer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_app_producer']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_app_producer']['settings'] = array(
											 'link' => 0,
											 );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Cew Request';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Start Date */
  $handler->display->display_options['fields']['field_crew_start_date']['id'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['field'] = 'field_crew_start_date';
  $handler->display->display_options['fields']['field_crew_start_date']['settings'] = array(
											    'format_type' => 'short',
											    'fromto' => 'both',
											    'multiple_number' => '',
											    'multiple_from' => '',
											    'multiple_to' => '',
											    'show_repeat_rule' => 'show',
											    );
  /* Field: Content: Start Time */
  $handler->display->display_options['fields']['field_crew_start_time']['id'] = 'field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['table'] = 'field_data_field_crew_start_time';
  $handler->display->display_options['fields']['field_crew_start_time']['field'] = 'field_crew_start_time';
  /* Field: Content: Length of Time In Hours */
  $handler->display->display_options['fields']['field_crew_length_of_time']['id'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['table'] = 'field_data_field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['field'] = 'field_crew_length_of_time';
  $handler->display->display_options['fields']['field_crew_length_of_time']['label'] = 'Length of Shift';
  $handler->display->display_options['fields']['field_crew_length_of_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_crew_length_of_time']['alter']['text'] = '[field_crew_length_of_time]  hours';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_app_status']['id'] = 'field_app_status';
  $handler->display->display_options['fields']['field_app_status']['table'] = 'field_data_field_app_status';
  $handler->display->display_options['fields']['field_app_status']['field'] = 'field_app_status';
  $handler->display->display_options['fields']['field_app_status']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['fields']['field_app_status']['label'] = 'Application Status';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Producer (field_app_producer) */
  $handler->display->display_options['arguments']['field_app_producer_target_id']['id'] = 'field_app_producer_target_id';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['table'] = 'field_data_field_app_producer';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['field'] = 'field_app_producer_target_id';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['field_app_producer_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_app_producer_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
									 'crew_connect_request' => 'crew_connect_request',
									 );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'reverse_field_app_crew_connect_node_node';
  $handler->display->display_options['filters']['nid']['operator'] = 'not empty';
  /* Filter criterion: Content: Start Date (field_crew_start_date) */
  $handler->display->display_options['filters']['field_crew_start_date_value']['id'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['table'] = 'field_data_field_crew_start_date';
  $handler->display->display_options['filters']['field_crew_start_date_value']['field'] = 'field_crew_start_date_value';
  $handler->display->display_options['filters']['field_crew_start_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_crew_start_date_value']['default_date'] = 'now';

  $views[$view->name] = $view;
  //FINISHED ADDING VIEW
  ///////////////////////////////////////////////////////////////

  // ...Repeat all of the above for each view the module should provide.

  // At the end, return array of default views.
  return $views;

}