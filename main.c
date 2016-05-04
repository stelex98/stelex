#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "tree.h"
#include "list.h"

list_t      *contacts_list;
tree_node_t *last_name_tree;
tree_node_t *first_name_tree;
tree_node_t *age_tree;
tree_node_t *phone_number_tree;

int main(int argc, char const *argv[]) {
  contacts_list = list_init();

  main_menu();

  contacts_list = list_destroy(contacts_list);
  return 0;
}
