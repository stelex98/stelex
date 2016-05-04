#include "list.h"
#include <stdlib.h>
#include <stdio.h>

list_t* list_init() {
  list_t* list = calloc(1, sizeof(list_t));
  if (!list) {
    printf("error\n");
    exit(1);
  }
  list->head = list->tail = NULL;
  return list;
}

int list_append(list_t *list, void *data) {
  list_element_t* element = calloc(1, sizeof(list_element_t));
  element->right = NULL;
  element->left = list->tail;
  element->data = data;
  if (list->size) {
    list->tail->right = element;
    list->tail = element;
  } else {
    list->tail = element;
    list->head = element;
  }
  list->size++;
  return 0;
}

void *list_at(list_t *list, int pos) {
  void *result = NULL;
  int position = pos - 1;
  unsigned int i;
  list_element_t *tmp_element_ptr = list->head;
  for (i = 0; i < list->size; ++i, tmp_element_ptr = tmp_element_ptr->right) {
    if (i == position) {
      result = tmp_element_ptr->data;
      break;
    }
  }
  return result;
}

void* list_remove_element(list_t *list, void *element, cmp_data_fptr cmp) {
  unsigned int i;
  void *removed_item = NULL;
  if (list->size == 0) {
    return 0;
  }
  list_element_t *tmp_element_ptr = list->head;
  if (!cmp(list->head->data, element)) {
    list->head = list->head->right;
    removed_item = tmp_element_ptr->data;
    free(tmp_element_ptr);
    list->size--;
    return removed_item;
  } else {
    tmp_element_ptr = tmp_element_ptr->right;
  }
  for (i = 1; i < list->size - 1; ++i, tmp_element_ptr = tmp_element_ptr->right) {
    if (!cmp(tmp_element_ptr->data, element)) {
      tmp_element_ptr->left->right = tmp_element_ptr->right;
      tmp_element_ptr->right->left = tmp_element_ptr->left;
      removed_item = tmp_element_ptr->data;
      free(tmp_element_ptr);
      list->size--;
      return removed_item;
    }
  }
  tmp_element_ptr = list->tail;
  if (!cmp(list->tail->data, element)) {
    list->tail = list->tail->left;
    removed_item = tmp_element_ptr->data;
    free(tmp_element_ptr);
    list->size--;
    return removed_item;
  }
  return removed_item;
}

int list_print(list_t *list, print_data_fptr print_data) {
  unsigned int i;
  list_element_t *tmp_element_ptr = list->head;
  for (i = 0; i < list->size; ++i, tmp_element_ptr = tmp_element_ptr->right) {
    print_data(tmp_element_ptr->data);
  }
}

list_t* list_destroy(list_t *list) {
  unsigned int i;
  list_element_t *tmp_element_ptr = list->head;
  for (i = 0; i < list->size; ++i, tmp_element_ptr = list->head) {
    list->head = tmp_element_ptr->right;
    free(tmp_element_ptr);
    list->size--;
  }
}

int list_sort(list_t *list, cmp_data_fptr cmp) {
  unsigned int i;
  list_element_t *tmp_i_ptr = list->head;
  for (i = 0; i < list->size; i++, tmp_i_ptr = tmp_i_ptr->right) {
    unsigned int j;
    list_element_t *tmp_j_ptr = tmp_i_ptr->right;
    for (j = i+1; j < list->size; j++, tmp_j_ptr = tmp_j_ptr->right) {
      if (0 < cmp(tmp_i_ptr->data, tmp_j_ptr->data)) {
        void *tmp_data = tmp_i_ptr->data;
        tmp_i_ptr->data = tmp_j_ptr->data;
        tmp_j_ptr->data = tmp_data;
      }
    }
  }
}

int list_search(list_t *list, search_data_fptr search, print_data_fptr print_data, char *str) {
  unsigned int i;
  list_element_t *tmp_element_ptr = list->head;
  for (i = 0; i < list->size; ++i, tmp_element_ptr = tmp_element_ptr->right) {
    if (search(tmp_element_ptr->data, str))
      print_data(tmp_element_ptr->data);
  }
}
