#pragma once

#include <stddef.h>

typedef struct XList x_list_t;

typedef struct XList {
  size_t cap;
  size_t length;
  void **data;
} x_list_t;

x_list_t *x_new_list();

void x_append_to_list(x_list_t *list, void *obj);

void *x_pop_from_list(x_list_t *list);

void x_insert_into_list(x_list_t *list, void *obj, size_t idx);

void x_delete_from_list(x_list_t *list, void *obj);

void x_destroy_list(x_list_t *list);
