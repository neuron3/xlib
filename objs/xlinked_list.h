#include <stddef.h>

typedef struct XLinkedListNode x_ll_node_t;

typedef struct XLinkedListNode {
  void *obj;
  x_ll_node_t *next;
} x_ll_node_t;

x_ll_node_t *x_new_ll_node(void *obj);

void x_destroy_ll_node(x_ll_node_t *node);

typedef struct XLinkedList x_linked_list_t;

typedef struct XLinkedList {
  size_t length;
  x_ll_node_t *head;
  x_ll_node_t *tail;
} x_linked_list_t;

x_linked_list_t *x_new_linked_list();

void *x_pop_linked_list(x_linked_list_t *ll);

void x_push_linked_list(x_linked_list_t *ll, void *obj);

void x_delete_from_linked_list(x_linked_list_t *ll, void *obj);

void x_insert_into_linked_list(x_linked_list_t *ll, void *obj, size_t idx);

void x_destroy_linked_list(x_linked_list_t *ll);
