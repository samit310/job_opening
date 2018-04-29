<?php
/**
 * @file
 * job_opening.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function job_opening_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function job_opening_node_info() {
  $items = array(
    'job_opening' => array(
      'name' => t('Job Opening'),
      'base' => 'node_content',
      'description' => t('Job Opening Content type.'),
      'has_title' => '1',
      'title_label' => t('Job Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
