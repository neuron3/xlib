#pragma once

#include "xlinked_list.h"
#include <stddef.h>

typedef struct XQueue x_queue_t;

typedef struct XQueue {
  x_linked_list_t *data;
} x_queue_t;

x_queue_t *x_new_queue();

void x_enqueue_queue(x_queue_t *queue, void *obj);

void *x_dequeue_queue(x_queue_t *queue);

size_t x_get_length_queue(x_queue_t *queue);

void x_destroy_queue(x_queue_t *queue);
