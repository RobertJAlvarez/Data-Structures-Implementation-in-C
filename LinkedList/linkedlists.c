#include <stdio.h>
#include <stdlib.h>
#include "linkedlists.h"
#include "linkedlists.h"

static void error_no_mem(void)
{
  fprintf(stderr, "Error: no memory left.\n");
  exit(1);
}

list_t *create_list(void)
{
  list_t *list;

  list = (list_t *) malloc(sizeof(list_t));
  if (list == NULL) error_no_mem();

  list->head = NULL;
  list->tail = NULL;

  return list;
}

void delete_list(
  list_t *list,
  void (*delete_data)(void *, void *),
  void *data)
{
  node_t *curr, *next;

  for (curr = list->head; curr != NULL; curr = next) {
    next = curr->next;
    delete_data(curr->data, data);
    free(curr);
  }

  free(list);
}

int is_empty_list(list_t *list)
{
  return (list->head == NULL);
}

size_t length_list(list_t *list)
{
  size_t i;
  node_t *curr;

  for (i=0, curr=list->head;
       curr!=NULL;
       curr=curr->next) {
    i++;
  }

  return i;
}

void iterate_over_list(
  list_t *list,
  void (*operation)(void *, void *),
  void *data)
{
  node_t *curr;

  for (curr=list->head;
       curr!=NULL;
       curr=curr->next) {
    operation(curr->data, data);
  }
}

void *search_list(
  list_t *list,
  void *elem,
  int (*compare_elements)(void *, void *, void *),
  void *data)
{
  node_t *curr;

  for (curr=list->head;
       curr!=NULL;
       curr=curr->next) {
    if (compare_elements(elem, curr->data, data) == 0)
      return curr->data;
  }

  return NULL;
}

void *get_ith_element_of_list(list_t *list, size_t i)
{
  size_t k;
  node_t *curr;

  for (k=0, curr=list->head;
       curr!=NULL;
       k++, curr=curr->next) {
    if (k == i)
      return curr->data;
  }

  return NULL;
}

void prepend_to_list(
  list_t *list,
  void *elem,
  void *(*copy_element)(void *, void *),
  void *data)
{
  node_t *new_node;

  new_node = (node_t *) malloc(sizeof(node_t));
  if (new_node == NULL) error_no_mem();

  new_node->data = copy_element(elem, data);
  new_node->prev = NULL;
  new_node->next = list->head;

  if (list->head != NULL) {
    list->head->prev = new_node;
  }
  list->head = new_node;
  if (list->tail == NULL) {
    list->tail = new_node;
  }
}

void append_to_list(
  list_t *list,
  void *elem,
  void *(*copy_element)(void *, void *),
  void *data)
{
  node_t *new_node;

  new_node = (node_t *) malloc(sizeof(node_t));
  if (new_node == NULL) error_no_mem();

  new_node->data = copy_element(elem, data);

  new_node->prev = list->tail;
  new_node->next = NULL;
  
  if (list->tail != NULL) {
    list->tail->next = new_node;
  }
  list->tail = new_node;
  if (list->head == NULL) {
    list->head = new_node;
  }
}

