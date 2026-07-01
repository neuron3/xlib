#pragma once

#include "xlist.h"
#include <stddef.h>

typedef struct XStack x_stack_t;

typedef struct XStack {
  x_list_t *data;
} x_stack_t;

x_stack_t *x_new_stack();

void *x_pop_stack(x_stack_t *stack);

void x_push_stack(x_stack_t *stack, void *obj);

size_t x_get_length_stack(x_stack_t *stack);

void x_destroy_stack(x_stack_t *stack);
