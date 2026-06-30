#include <stddef.h>
typedef struct XHeap x_heap_t;

typedef struct XHeap {
  size_t length;
  size_t cap;
  void **data;
} x_heap_t;

x_heap_t *x_new_heap();

x_heap_t *x_append_to_heap(x_heap_t *heap, void *value);

void **x_children_heap(x_heap_t *heap, void *value);

void **x_parent_heap(x_heap_t *heap, void *value);

x_heap_t *x_heapify_up(x_heap_t *heap, void *value);

x_heap_t *x_heapify_down(x_heap_t *heap, void *value);

x_heap_t *x_delete_heap_value(x_heap_t *heap, void *value);

void x_destroy_heap(x_heap_t *heap);
