#include "xlinked_list.h"
#include <stddef.h>
#include <stdlib.h>

x_ll_node_t *x_new_ll_node(void *obj) {
  x_ll_node_t *new = malloc(sizeof(x_ll_node_t));

  if (new == NULL) {
    return NULL;
  }

  new->obj = obj;
  new->next = NULL;

  return new;
}

void x_destroy_ll_node(x_ll_node_t *node) {
  if (node == NULL) {
    return;
  }

  free(node);
}

x_linked_list_t *x_new_linked_list() {
  x_linked_list_t *new = malloc(sizeof(x_linked_list_t));

  if (new == NULL) {
    return NULL;
  }

  new->head = NULL;
  new->tail = NULL;
  new->length = 0;

  return new;
}

void *x_pop_linked_list(x_linked_list_t *ll) {
  if (ll == NULL) {
    return NULL;
  }

  if (ll->length == 0 || ll->head == NULL) {
    return NULL;
  }

  void *popped = ll->head->obj;

  x_ll_node_t *next = ll->head->next;

  x_destroy_ll_node(ll->head);

  ll->head = next;
  ll->length--;

  return popped;
}

void x_push_linked_list(x_linked_list_t *ll, void *obj) {
  if (ll == NULL) {
    return;
  }

  if (ll->head == NULL || ll->length == 0) {
    ll->head = x_new_ll_node(obj);
    ll->tail = ll->head;
    ll->length++;
    return;
  }

  x_ll_node_t *new_node = x_new_ll_node(obj);

  ll->tail->next = new_node;

  ll->tail = new_node;
}

void x_delete_from_linked_list(x_linked_list_t *ll, void *obj) {
  if (ll == NULL) {
    return;
  }

  if (ll->length == 0 || ll->head == NULL) {
    return;
  }

  x_ll_node_t *current = ll->head;

  if (current->obj == obj) {
    ll->head = current->next;
    x_destroy_ll_node(current);
    ll->length--;
  }

  while (current != NULL) {
    if (current->next == NULL) {
      break;
    }

    if (current->next->obj == obj) {
      x_ll_node_t *next = current->next->next;

      x_destroy_ll_node(current->next);

      current->next = next;

      ll->length--;

      break;
    }

    current = current->next;
  }
}

void x_insert_into_linked_list(x_linked_list_t *ll, void *obj, size_t idx) {
  if (ll == NULL) {
    return;
  }

  if (idx >= ll->length) {
    return;
  }

  x_ll_node_t *previous = ll->head;

  for (size_t i = 0; i < idx; i++) {
    previous = previous->next;
  }

  x_ll_node_t *new_node = x_new_ll_node(obj);

  if (new_node == NULL) {
    return;
  }

  new_node->next = previous->next;
  previous->next = new_node;

  ll->length++;
}

void x_destroy_linked_list(x_linked_list_t *ll) {
  if (ll == NULL) {
    return;
  }

  if (ll->head == NULL) {
    x_ll_node_t *current = ll->head;
    while (current != NULL) {
      x_ll_node_t *tmp = current->next;

      x_destroy_ll_node(current);

      current = tmp;
    }

    ll->head = NULL;
    ll->tail = NULL;
  }

  free(ll);
}
