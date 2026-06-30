#include "xlist.h"
#include <stddef.h>
#include <stdlib.h>

x_list_t *x_new_list() {
  x_list_t *new = malloc(sizeof(x_list_t));

  if (new == NULL) {
    return NULL;
  }

  new->cap = 32; // Default capacity for a list

  new->length = 0;

  new->data = malloc(new->cap * sizeof(void *));

  return new;
}

void x_append_to_list(x_list_t *list, void *obj) {
  if (list == NULL || obj == NULL) {
    return;
  }

  if (list->data == NULL) {
    return;
  }

  if (list->length >= list->cap) {
    list->cap *= 2;
    void **tmp = realloc(list->data, list->cap * sizeof(void *));

    if (tmp == NULL) {
      list->cap /= 2;
      return;
    }

    list->data = tmp;
  }

  list->data[list->length] = obj;
  list->length++;
}

void *x_pop_from_list(x_list_t *list) {
  if (list == NULL) {
    return NULL;
  }

  if (list->data == NULL || list->length < 1) {
    return NULL;
  }

  list->length--;
  void *popped_value = list->data[list->length];

  return popped_value;
}

void x_insert_into_list(x_list_t *list, void *obj, size_t idx) {
  if (list == NULL || obj == NULL) {
    return;
  }

  if (list->data == NULL) {
    return;
  }

  if (idx >= list->length) {
    return;
  }

  if (list->length >= list->cap) {
    list->cap *= 2;
    void **tmp = realloc(list->data, list->cap * sizeof(void *));

    if (tmp == NULL) {
      list->cap /= 2;
      return;
    }

    list->data = tmp;
  }

  void **start = list->data + list->length;
  void **end = list->data + idx;

  while (start >= end) {
    *start = *(start - 1);
    start--;
  }

  list->data[idx] = obj;
  list->length++;
}

int x_find_obj_in_list(x_list_t *list, void *obj) {
  if (list == NULL || obj == NULL) {
    return -1;
  }

  for (int idx = 0; idx < list->length; idx++) {
    if (list->data[(size_t)idx] == obj) {
      return idx;
    }
  }

  return -1;
}

void x_delete_from_list(x_list_t *list, void *obj) {
  if (list == NULL || obj == NULL) {
    return;
  }

  if (list->data == NULL || list->length < 1) {
    return;
  }

  int idx = x_find_obj_in_list(list, obj);
  
  if (idx < 0) {
    return;
  }

  for (size_t i = (size_t)idx; i < list->length; i++) {
    list->data[i] = list->data[i + 1];
  }

  list->length--;
}

void x_destroy_list(x_list_t *list) {
  if (list == NULL)
    return;

  if (list->data != NULL) {
    free(list->data);
  }

  free(list);
}
