#include "tree.h"

tree_node_t* tree_add_elemnent(tree_node_t **tree, void *data, cmp_data_ptr cmp) {
  if (!*tree) {
    (*tree) = (tree_node_t*)calloc(1, sizeof(tree_node_t));
    if (!*tree) {
      printf("error\n");
      exit(1);
    }
    (*tree)->left_node = (*tree)->right_node = NULL;
    (*tree)->data = list_init();
    list_append((*tree)->data, data);
  } else {
    int cmp_result = cmp((*tree)->data->head->data, data);
    if (cmp_result > 0) {
      tree_add_elemnent(&(*tree)->right_node, data, cmp);
    } else if (cmp_result < 0) {
      tree_add_elemnent(&(*tree)->left_node, data, cmp);
    } else {
      list_append((*tree)->data, data);
    }
  }
}



void tree_remove_element(tree_node_t **tree, void *data, cmp_data_ptr cmp) {
  if (!(*tree)) {
    return;
  }
  int cmp_result = cmp((*tree)->data->head->data, data);
  if (cmp_result > 0) {
    tree_remove_element(&(*tree)->right_node, data, cmp);
  } else if (cmp_result < 0) {
    tree_remove_element(&(*tree)->left_node, data, cmp);
  } else {
    list_remove_element((*tree)->data, data, cmp);
    if ((*tree)->data->size == 0) {
      tree_node_t *left = (*tree)->left_node;
      tree_node_t *right = (*tree)->right_node;
      list_destroy((*tree)->data);
      free(*tree);
      (*tree) = right;
      while (*tree) {
        tree = &(*tree)->left_node;
      }
      (*tree) = left;
    }
  }
}

tree_node_t* tree_find_element(tree_node_t *tree, void *data, cmp_data_ptr cmp, print_data_fptr print_data) {
  if (tree) {
    int cmp_result = cmp(tree->data->head->data, data);
    if (cmp_result > 0) {
      tree_find_element(tree->right_node, data, cmp, print_data);
    } else if (cmp_result < 0) {
      tree_find_element(tree->left_node, data, cmp, print_data);
    } else {
      list_print(tree->data, print_data);
    }
  }
}

void tree_print(tree_node_t *tree, print_data_fptr print_data) {
  if (tree) {
    list_print(tree->data, print_data);
    tree_print(tree->right_node, print_data);
    tree_print(tree->left_node, print_data);
  }
}
