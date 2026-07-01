#include "xqueue.h"
#include <stddef.h>
#include <stdlib.h>

x_queue_t *x_new_queue() {
  x_queue_t *new = malloc(sizeof(x_queue_t));

  if (new == NULL) {
    return NULL;
  }

  new->data = x_new_linked_list();

  if (new->data == NULL) {
    free(new);
    return NULL;
  }

  return new;
}

void x_enqueue_queue(x_queue_t *queue, void *obj) {
  if (queue == NULL) {
    return;
  }

  x_push_linked_list(queue->data, obj);
}

void *x_dequeue_queue(x_queue_t *queue) {
  if (queue == NULL) {
    return NULL;
  }

  void *popped = x_pop_linked_list(queue->data);

  return popped;
}

size_t x_get_length_queue(x_queue_t *queue) {
  if (queue == NULL) {
    return 0;
  }

  if (queue->data == NULL) {
    return 0;
  }

  return queue->data->length;
}

void x_destroy_queue(x_queue_t *queue) {
  if (queue == NULL) {
    return;
  }

  x_destroy_linked_list(queue->data);

  free(queue);
}
