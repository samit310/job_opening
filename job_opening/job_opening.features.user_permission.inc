<?php
/**
 * @file
 * job_opening.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function job_opening_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer jobopening entities'.
  $permissions['administer jobopening entities'] = array(
    'name' => 'administer jobopening entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'job_opening',
  );

  // Exported permission: 'create jobopening entities'.
  $permissions['create jobopening entities'] = array(
    'name' => 'create jobopening entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'job_opening',
  );

  // Exported permission: 'delete jobopening entities'.
  $permissions['delete jobopening entities'] = array(
    'name' => 'delete jobopening entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'job_opening',
  );

  // Exported permission: 'edit jobopening entities'.
  $permissions['edit jobopening entities'] = array(
    'name' => 'edit jobopening entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'job_opening',
  );

  // Exported permission: 'view jobopening entities'.
  $permissions['view jobopening entities'] = array(
    'name' => 'view jobopening entities',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'job_opening',
  );

  return $permissions;
}
