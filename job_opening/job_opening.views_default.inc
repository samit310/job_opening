<?php
/**
 * @file
 * job_opening.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function job_opening_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'job_report';
  $view->description = 'Report for job Appliers';
  $view->tag = 'default';
  $view->base_table = 'job_opening';
  $view->human_name = 'Job report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Job report';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_pivot';
  $handler->display->display_options['style_options']['columns'] = array(
    'applied_by' => 'applied_by',
    'name' => 'name',
    'job_opening_node_title' => 'job_opening_node_title',
    'points' => 'points',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'applied_by' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
      'pivot_row_aggregate' => '0',
      'pivot_row_aggregate_label' => '',
      'pivot_col_aggregate' => '0',
      'pivot_col_aggregate_label' => '',
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
      'pivot_row_aggregate' => '0',
      'pivot_row_aggregate_label' => '',
      'pivot_col_aggregate' => '0',
      'pivot_col_aggregate_label' => '',
    ),
    'job_opening_node_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
      'pivot_row_aggregate' => '0',
      'pivot_row_aggregate_label' => '',
      'pivot_col_aggregate' => '0',
      'pivot_col_aggregate_label' => '',
    ),
    'points' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'pivot_row_extra' => 0,
      'pivot_row_aggregate' => 'sum',
      'pivot_row_aggregate_label' => 'Total',
      'pivot_col_aggregate' => '0',
      'pivot_col_aggregate_label' => '',
    ),
  );
  $handler->display->display_options['style_options']['pivot_col'] = 'job_opening_node_title';
  $handler->display->display_options['style_options']['pivot_row'] = 'name';
  $handler->display->display_options['style_options']['pivot_mode_multi_values'] = '0';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Apply for Jobs: Relationships with user */
  $handler->display->display_options['relationships']['job_opening']['id'] = 'job_opening';
  $handler->display->display_options['relationships']['job_opening']['table'] = 'job_opening';
  $handler->display->display_options['relationships']['job_opening']['field'] = 'job_opening';
  $handler->display->display_options['relationships']['job_opening']['required'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'job_opening';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Apply for Jobs: Job_opening_node_title */
  $handler->display->display_options['fields']['job_opening_node_title']['id'] = 'job_opening_node_title';
  $handler->display->display_options['fields']['job_opening_node_title']['table'] = 'job_opening';
  $handler->display->display_options['fields']['job_opening_node_title']['field'] = 'job_opening_node_title';
  $handler->display->display_options['fields']['job_opening_node_title']['label'] = 'Title';
  /* Field: Apply for Jobs: Points */
  $handler->display->display_options['fields']['points']['id'] = 'points';
  $handler->display->display_options['fields']['points']['table'] = 'job_opening';
  $handler->display->display_options['fields']['points']['field'] = 'points';
  $handler->display->display_options['fields']['points']['label'] = '';
  $handler->display->display_options['fields']['points']['element_label_colon'] = FALSE;

  /* Display: Job Report */
  $handler = $view->new_display('page', 'Job Report', 'page');
  $handler->display->display_options['display_description'] = 'Job Report';
  $handler->display->display_options['path'] = 'job-report';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Job Report';
  $handler->display->display_options['menu']['description'] = 'Job Report';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['job_report'] = $view;

  return $export;
}
