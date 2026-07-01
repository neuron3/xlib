#include "xstack.h"
#include "xlist.h"
#include <stdlib.h>

x_stack_t *x_new_stack() {
  x_stack_t *new = malloc(sizeof(x_stack_t));

  if (new == NULL) {
    return NULL;
  }

  new->data = x_new_list();

  if (new->data == NULL) {
    free(new);
    return NULL;
  }

  return new;
}

void *x_pop_stack(x_stack_t *stack) {

  if (stack == NULL) {
    return NULL;
  }

  void *popped_value = x_pop_from_list(stack->data);

  return popped_value;
}

void x_push_stack(x_stack_t *stack, void *obj) {
  if (stack == NULL) {
    return;
  }

  x_append_to_list(stack->data, obj);
}

size_t x_get_length_stack(x_stack_t *stack) {
  if (stack == NULL) {
    return 0;
  }

  if (stack->data == NULL) {
    return 0;
  }

  return stack->data->length;
}

void x_destroy_stack(x_stack_t *stack) {
  if (stack == NULL) {
    return;
  }

  if (stack->data != NULL) {
    x_destroy_list(stack->data);
  }

  free(stack);
}
