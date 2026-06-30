#include "../objs/xlist.h"
#include "../vendor/munit.h"
#include <stdlib.h>

static MunitResult test_new_destroy_list(const MunitParameter params[],
                                         void *data) {
  (void)params;
  (void)data;

  x_list_t *list = x_new_list();
  munit_assert_not_null(list);
  munit_assert_not_null(list->data);
  munit_assert_int(list->length, ==, 0);

  x_destroy_list(list);
  return MUNIT_OK;
}

static MunitResult test_append_pop_list(const MunitParameter params[],
                                        void *data) {
  (void)params;
  (void)data;

  x_list_t *list = x_new_list();

  int *x = malloc(sizeof(int));
  int *y = malloc(sizeof(int));

  x[0] = 6;
  y[0] = 9;

  x_append_to_list(list, x);
  x_append_to_list(list, y);

  int *popped_value = x_pop_from_list(list);
  munit_assert_int(*popped_value, ==, *y);

  popped_value = x_pop_from_list(list);
  munit_assert_int(*popped_value, ==, *x);

  x_destroy_list(list);
  free(x);
  free(y);
  return MUNIT_OK;
}

static MunitResult test_pop_empty_list(const MunitParameter params[],
                                       void *data) {
  (void)params;
  (void)data;

  x_list_t *list = x_new_list();

  void *result = x_pop_from_list(list);
  munit_assert_null(result);

  x_destroy_list(list);
  return MUNIT_OK;
}

static MunitResult test_insert_beginning(const MunitParameter params[],
                                         void *data) {
  (void)params;
  (void)data;

  x_list_t *list = x_new_list();

  int *a = malloc(sizeof(int));
  int *b = malloc(sizeof(int));
  int *c = malloc(sizeof(int));
  *a = 1;
  *b = 2;
  *c = 0;

  x_append_to_list(list, a);
  x_append_to_list(list, b);
  x_insert_into_list(list, c, 0);

  int *val = x_pop_from_list(list);
  munit_assert_int(*val, ==, *b);
  val = x_pop_from_list(list);
  munit_assert_int(*val, ==, *a);
  val = x_pop_from_list(list);
  munit_assert_int(*val, ==, *c);

  x_destroy_list(list);
  free(a);
  free(b);
  free(c);
  return MUNIT_OK;
}

static MunitResult test_insert_middle(const MunitParameter params[],
                                      void *data) {
  (void)params;
  (void)data;

  x_list_t *list = x_new_list();

  int *a = malloc(sizeof(int));
  int *b = malloc(sizeof(int));
  int *c = malloc(sizeof(int));
  *a = 1;
  *b = 3;
  *c = 2;

  x_append_to_list(list, a);
  x_append_to_list(list, b);
  x_insert_into_list(list, c, 1);

  int *val = x_pop_from_list(list);
  munit_assert_int(*val, ==, *b);
  val = x_pop_from_list(list);
  munit_assert_int(*val, ==, *c);
  val = x_pop_from_list(list);
  munit_assert_int(*val, ==, *a);

  x_destroy_list(list);
  free(a);
  free(b);
  free(c);
  return MUNIT_OK;
}

static MunitResult test_insert_out_of_bounds(const MunitParameter params[],
                                             void *data) {
  (void)params;
  (void)data;

  x_list_t *list = x_new_list();

  int *a = malloc(sizeof(int));
  *a = 1;

  x_append_to_list(list, a);

  // Insert at index >= length should be a no-op
  x_insert_into_list(list, a, 5);

  // List should still have 1 element
  int *val = x_pop_from_list(list);
  munit_assert_int(*val, ==, *a);
  munit_assert_null(x_pop_from_list(list));

  x_destroy_list(list);
  free(a);
  return MUNIT_OK;
}

static MunitResult test_delete_element(const MunitParameter params[],
                                       void *data) {
  (void)params;
  (void)data;

  x_list_t *list = x_new_list();

  int *a = malloc(sizeof(int));
  int *b = malloc(sizeof(int));
  int *c = malloc(sizeof(int));
  *a = 1;
  *b = 2;
  *c = 3;

  x_append_to_list(list, a);
  x_append_to_list(list, b);
  x_append_to_list(list, c);

  x_delete_from_list(list, b);

  int *val = x_pop_from_list(list);
  munit_assert_int(*val, ==, *c);
  val = x_pop_from_list(list);
  munit_assert_int(*val, ==, *a);
  munit_assert_null(x_pop_from_list(list));

  x_destroy_list(list);
  free(a);
  free(b);
  free(c);
  return MUNIT_OK;
}

static MunitResult test_delete_first(const MunitParameter params[],
                                     void *data) {
  (void)params;
  (void)data;

  x_list_t *list = x_new_list();

  int *a = malloc(sizeof(int));
  int *b = malloc(sizeof(int));
  *a = 1;
  *b = 2;

  x_append_to_list(list, a);
  x_append_to_list(list, b);

  x_delete_from_list(list, a);

  int *val = x_pop_from_list(list);
  munit_assert_int(*val, ==, *b);
  munit_assert_null(x_pop_from_list(list));

  x_destroy_list(list);
  free(a);
  free(b);
  return MUNIT_OK;
}

static MunitResult test_delete_last(const MunitParameter params[], void *data) {
  (void)params;
  (void)data;

  x_list_t *list = x_new_list();

  int *a = malloc(sizeof(int));
  int *b = malloc(sizeof(int));
  *a = 1;
  *b = 2;

  x_append_to_list(list, a);
  x_append_to_list(list, b);

  x_delete_from_list(list, b);

  int *val = x_pop_from_list(list);
  munit_assert_int(*val, ==, *a);
  munit_assert_null(x_pop_from_list(list));

  x_destroy_list(list);
  free(a);
  free(b);
  return MUNIT_OK;
}

static MunitResult test_delete_not_found(const MunitParameter params[],
                                         void *data) {
  (void)params;
  (void)data;

  x_list_t *list = x_new_list();

  int *a = malloc(sizeof(int));
  int *missing = malloc(sizeof(int));
  *a = 1;
  *missing = 99;

  x_append_to_list(list, a);

  // Deleting an object not in the list should be a no-op
  x_delete_from_list(list, missing);

  int *val = x_pop_from_list(list);
  munit_assert_int(*val, ==, *a);
  munit_assert_null(x_pop_from_list(list));

  x_destroy_list(list);
  free(a);
  free(missing);
  return MUNIT_OK;
}

static MunitResult test_list_growth(const MunitParameter params[], void *data) {
  (void)params;
  (void)data;

  x_list_t *list = x_new_list();
  int count = 64;

  int **vals = malloc(count * sizeof(int *));
  for (int i = 0; i < count; i++) {
    vals[i] = malloc(sizeof(int));
    *vals[i] = i;
    x_append_to_list(list, vals[i]);
  }

  munit_assert_int(list->length, ==, count);

  // Pop all items in reverse order
  for (int i = count - 1; i >= 0; i--) {
    int *val = x_pop_from_list(list);
    munit_assert_int(*val, ==, i);
  }

  munit_assert_int(list->length, ==, 0);

  x_destroy_list(list);
  for (int i = 0; i < count; i++) {
    free(vals[i]);
  }
  free(vals);
  return MUNIT_OK;
}

static MunitResult test_null_handling(const MunitParameter params[],
                                      void *data) {
  (void)params;
  (void)data;

  // These should all be safe no-ops
  x_append_to_list(NULL, NULL);
  x_append_to_list(NULL, &data);
  x_pop_from_list(NULL);
  x_insert_into_list(NULL, &data, 0);
  x_delete_from_list(NULL, &data);
  x_destroy_list(NULL);

  return MUNIT_OK;
}

static MunitTest testsXLists[] = {
    {"/new-destroy", test_new_destroy_list, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {"/append-pop", test_append_pop_list, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {"/pop-empty", test_pop_empty_list, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {"/insert-beginning", test_insert_beginning, NULL, NULL,
     MUNIT_TEST_OPTION_NONE, NULL},
    {"/insert-middle", test_insert_middle, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {"/insert-out-of-bounds", test_insert_out_of_bounds, NULL, NULL,
     MUNIT_TEST_OPTION_NONE, NULL},
    {"/delete-element", test_delete_element, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {"/delete-first", test_delete_first, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {"/delete-last", test_delete_last, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {"/delete-not-found", test_delete_not_found, NULL, NULL,
     MUNIT_TEST_OPTION_NONE, NULL},
    {"/growth", test_list_growth, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/null-handling", test_null_handling, NULL, NULL, MUNIT_TEST_OPTION_NONE,
     NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

static MunitSuite suiteXLists = {"/xlist", testsXLists, NULL, 0,
                                 MUNIT_SUITE_OPTION_NONE};

int main(int argc, char *argv[]) {
  return munit_suite_main(&suiteXLists, NULL, argc, argv);
}
