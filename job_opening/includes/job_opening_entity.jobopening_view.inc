<?php

/**
 * View for /jobopening/<jobopening_id> page.
 */
function jobopening_view_entity($entity, $view_mode = 'full') {
  $entity_type = $entity->entityType();
  $entity_id = entity_id($entity_type, $entity);

  // Remove previously built content, if exists
  $entity->content = array();

  $entity->title = filter_xss($entity->job_opening_node_title) . ' ' . filter_xss($entity->entity_id);

  // Build the fields content
  field_attach_prepare_view($entity_type, array($entity_id => $entity), $view_mode);
  entity_prepare_view($entity_type, array($entity_id => $entity));

  $entity->content += field_attach_view($entity_type, $entity, $view_mode);

  $entity->content += array(
    '#theme' => 'jobopening_entity_view',
    '#element' => $entity,
    '#view_mode' => $view_mode,
    '#language' => LANGUAGE_NONE,
  );
  return $entity->content;
}
