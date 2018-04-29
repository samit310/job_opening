<?php

/**
 * Implements hook_form().
 */
function jobopening_form($form, &$form_state, $jobopening = NULL) {
  $form = array();
  global $user;

  $arg = arg();
  if ((isset($arg[0]) && $arg[0] == 'jobopening-apply') && (isset($arg[2]) && is_numeric($arg[2]))) {
    // only for ctools pop form.
    $job_node = node_load($arg[2]);
    $form_state['node_obj'] = $job_node;
  }

  $form['entity_id'] = array(
    '#title' => t('Job opening node NID'),
    '#type' => 'textfield',
    '#default_value' => isset($jobopening->entity_id) ? $jobopening->entity_id : '',
    '#required' => TRUE,
    '#maxlength' => 255,
  );
  $form['job_opening_node_title'] = array(
    '#title' => t('Job opening node Title'),
    '#type' => 'textfield',
    '#default_value' => isset($jobopening->job_opening_node_title) ? $jobopening->job_opening_node_title : '',
    '#required' => TRUE,
    '#maxlength' => 255,
  );
  $form['applied_by'] = array(
    '#title' => t('Applied by User'),
    '#type' => 'textfield',
    '#default_value' => isset($jobopening->applied_by) ? $jobopening->applied_by : $user->uid,
    '#required' => TRUE,
    '#maxlength' => 255,
  );
  $form['points'] = array(
    '#title' => t('Points assign to user'),
    '#type' => 'textfield',
    '#default_value' => isset($jobopening->points) ? $jobopening->points : 0,
    '#required' => TRUE,
    '#maxlength' => 255,
  );
  field_attach_form('jobopening', $jobopening, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($jobopening->id) ? t('Update') : t('Save'),
    ),
  );
  if (user_access('delete jobopening entities')) {
    $form['actions'][] = array(
      'delete_link' => array(
        '#markup' => isset($jobopening->id) ? l(t('Delete'), 'admin/content/jobopening/manage/' . $jobopening->id . '/delete', array('attributes' => array('id' => array('jobopening-delete-' . $jobopening->id), 'class' => array('button remove')), 'query' => array('destination' => 'admin/content/jobopening'))) : ''
      ),
    );
  }
  return $form;
}

/**
 * Implements hook_form_validate().
 */
function jobopening_form_validate($form, &$form_state) {}

/**
 * Implements hook_form_submit().
 */
function jobopening_form_submit($form, &$form_state) {
  if (preg_match('/admin\/content\/jobopening\/manage\/[0-9]+$/', request_path())) {
    $jobopening = entity_ui_form_submit_build_entity($form, $form_state);
    $jobopening->save();

    drupal_set_message(t('@job_opening_node_title Apply has been saved.', array('@job_opening_node_title' => $jobopening->job_opening_node_title)));
    $form_state['redirect'] = 'admin/content/jobopening';
    $form_state['redirect'] = 'jobopening/' . $jobopening->id;
    return;
  }
  else {
    if (isset($form_state['new_entity_by_user']) && $form_state['new_entity_by_user']) {
      $entity_type = $form_state['entity_type'];

      entity_create($entity_type, $form_state['values'])->save();
    }
    else {
      $entity_type = $form_state['entity_type'];
      $jobopening = $form_state['build_info']['args'][0];
      entity_form_submit_build_entity($entity_type, $jobopening, $form, $form_state);

      $jobopening->save();
    }
  }
}
