#ifndef TREE_H_
#define TREE_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef void (*print_data_fptr)(void *);
typedef int (*cmp_data_ptr)(void *data1, void *data2);

typedef struct tree_node_t
{
  struct tree_node_t *left_node;
  struct tree_node_t *right_node;
  list_t             *data;
  char               filed;
} tree_node_t;



tree_node_t* tree_add_elemnent(tree_node_t **tree, void *data, cmp_data_ptr cmp);
void tree_remove_element(tree_node_t **tree, void *data, cmp_data_ptr cmp);
tree_node_t* tree_find_element(tree_node_t *tree, void *data, cmp_data_ptr cmp, print_data_fptr print_data);
void tree_print(tree_node_t *tree, print_data_fptr print_data);

#endif /* TREE_H_ */
