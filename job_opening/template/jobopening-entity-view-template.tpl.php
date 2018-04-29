<?php
$content = $element->content;
?>

<div class="<?php print $classes; ?>">
  <h2><?php print $content['#element']->job_opening_node_title; ?>: <?php print $content['#element']->entity_id; ?></h2>
  <p class="meta">
      <?php print $content['#element']->entity_id; ?><br />
  </p>
</div>
