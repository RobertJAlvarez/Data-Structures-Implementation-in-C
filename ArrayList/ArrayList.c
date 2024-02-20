#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"

#define MIN_ELEM ((size_t)4)

static int error_no_mem(void) {
  fprintf(stderr, "Error: no memory left.\n");
  return 1;
}

static int __AL_double_size(ArrayList_t *AL) {
  void *p;

  if (AL == NULL) return 1;

  p = realloc(AL->array, sizeof(void *) * AL->__size * 2);
  if (p == NULL) return error_no_mem();

  AL->__size *= 2;
  AL->array = p;

  return 0;
}

static int __AL_half_size(ArrayList_t *AL) {
  void *p;

  if (AL == NULL) return 1;

  if (AL->__size <= MIN_ELEM) return 0;

  p = realloc(AL->array, (sizeof(void *) * AL->__size) / 2);
  if (p == NULL) return 1;

  AL->__size /= 2;
  AL->array = p;

  return 0;
}

ArrayList_t *AL_init(void) {
  ArrayList_t *AL;

  if ((AL = (ArrayList_t *)malloc(sizeof(ArrayList_t))) == NULL) error_no_mem();

  // Start array with size of 4
  AL->array = malloc(MIN_ELEM * sizeof(void *));
  AL->__size = MIN_ELEM;
  AL->len = 0;

  return AL;
}

int AL_free(ArrayList_t *AL, int (*delete_data)(void *data)) {
  if (AL == NULL) return 0;

  for (size_t i = 0; i < AL->len; i++) {
    if (delete_data(AL->array[i])) return 1;
  }

  free(AL->array);
  free(AL);

  return 0;
}

void AL_print(ArrayList_t *AL, void (*print_data)(void *data)) {
  if (AL == NULL) return;

  for (size_t i = 0; i < AL->len; i++) print_data(AL->array[i]);
}

void *AL_get_at(ArrayList_t *AL, size_t i) {
  if (AL == NULL) return NULL;
  if (i >= AL->len) return NULL;

  return AL->array[i];
}

int AL_set_at(ArrayList_t *AL, size_t i, void *elem,
              void *(*copy_data)(void *data), int (*delete_data)(void *data)) {
  if (AL == NULL) return 1;
  if (i >= AL->len) return 1;

  if (delete_data(AL->array[i])) return 1;
  AL->array[i] = copy_data(elem);

  return 0;
}

int AL_insert_first(ArrayList_t *AL, void *elem,
                    void *(*copy_data)(void *data)) {
  if (AL == NULL) return 1;
  // If size == len then double array size
  if (AL->__size == AL->len) {
    // If doubling array size fail, return 1
    if (__AL_double_size(AL) == 1) return 1;
  }

  for (size_t i = AL->len; i > 0; i--) AL->array[i] = AL->array[i - 1];

  AL->array[0] = copy_data(elem);
  AL->len++;

  return 0;
}

int AL_delete_first(ArrayList_t *AL, int (*delete_data)(void *data)) {
  if (AL == NULL) return 1;

  if (delete_data(AL->array[0])) return 1;
  AL->len--;

  for (size_t i = 0; i < AL->len; i++) AL->array[i] = AL->array[i + 1];

  if (AL->len * 4 <= AL->__size) __AL_half_size(AL);

  return 0;
}

int AL_insert_last(ArrayList_t *AL, void *elem,
                   void *(*copy_data)(void *data)) {
  if (AL == NULL) return 1;
  if (AL->len == AL->__size) {
    if (__AL_double_size(AL) == 1) return 1;
  }

  AL->array[AL->len] = copy_data(elem);
  AL->len++;

  return 0;
}

int AL_delete_last(ArrayList_t *AL, int (*delete_data)(void *data)) {
  if (AL == NULL) return 1;
  if (AL->len == 0) return 0;

  if (delete_data(AL->array[AL->len - 1])) return 1;
  AL->len--;

  if (AL->len * 4 <= AL->__size) __AL_half_size(AL);

  return 0;
}

int AL_insert_at(ArrayList_t *AL, size_t i, void *elem,
                 void *(*copy_data)(void *data)) {
  if (AL == NULL) return 1;
  if (i >= AL->len) return AL_insert_last(AL, elem, copy_data);

  // Double size array size if needed
  if (AL->len == AL->__size) {
    if (__AL_double_size(AL) == 1) return 1;
  }

  for (size_t k = AL->len; k > i; k--) AL->array[k] = AL->array[k - 1];

  AL->array[i] = copy_data(elem);
  AL->len++;

  return 0;
}

int AL_delete_at(ArrayList_t *AL, size_t i, int (*delete_data)(void *)) {
  size_t k;

  if (AL == NULL) return 1;
  if (i >= AL->len) return 1;

  if (delete_data(AL->array[i]) != 0) return 1;

  for (k = i + 1; k < AL->len; k++) AL->array[k - 1] = AL->array[k];

  AL->len--;

  return 0;
}
