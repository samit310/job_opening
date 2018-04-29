<?php

/**
 * @file
 * File to create custom entity for job opening and Other stuffs.
 */

/**
 * call back for jobopening-apply/%ctools_js/%node
 */
function jobopening_apply_system($js = NULL, $job_opening = NULL) {
  global $user;
  if ($js) { // If JS is enable
    // Incluse Modal form Popup
    ctools_include('jobopening.admin', 'job_opening', 'includes');
    ctools_include('ajax');
    ctools_include('modal');

    if ($job_opening->field_deadline_to_apply[LANGUAGE_NONE][0]['value'] < time()) {
      //Check & restrict if apply date is crodssed.
      $output[] = ajax_command_alert(t("OOPS! Application deadline is crossed."));
    }
    else {
      // if apply date is not crodssed.
      $user_all_ready_applied = _check_user_all_ready_applied($job_opening, $user);

      $form_state = array(
        'title' => t('Apply for ' . $job_opening->title),
        'ajax' => TRUE,
        'entity_type' => 'jobopening'
      );

      if (isset($user_all_ready_applied) && $user_all_ready_applied != NULL) {
        // User already applied for the post

        $jobopening_entity = jobopening_load($user_all_ready_applied);

        $form_state['build_info']['args'] = [$jobopening_entity];
      }
      else {
        // User not applied for the post yet.
        $form_state['new_entity_by_user'] = TRUE;
      }

      $output = ctools_modal_form_wrapper('jobopening_form', $form_state);

      // This means the form has been exectued
      if (!empty($form_state['executed'])) {
        $output = array();
        if(isset($form_state['new_entity_by_user'])){
          $output[] = ajax_command_alert(t('You have successfully applied for @job Job.', array('@job' => $job_opening->title)));
        }
        else{
          $output[] = ajax_command_alert(t('You have successfully Update your applied request for @job Job.', array('@job' => $job_opening->title)));
        }
        // Close the modal
        $output[] = ctools_modal_command_dismiss();
      }
    }
    // Return the ajax instructions to the browser via ajax_render().
    print ajax_render($output);
    drupal_exit();
  }
  else { // If JS IS NOT ENABLE
    return "Javascript required";
  }
}

/**
 * Check current user has applied already or not.
 * @param Obj $job_opening
 * @param Obj $user
 */
function _check_user_all_ready_applied($job_opening, $user) {
  $applied = db_query("SELECT id FROM {job_opening} 
                                  WHERE entity_id = :entity_id AND applied_by = :applied_by LIMIT 1", array(':entity_id' => $job_opening->nid, ':applied_by' => $user->uid))->fetchColumn();
  return $applied;
}
