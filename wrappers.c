#include "wrappers.h"
#include <stdio.h>
#include "list.h"
#include "phonebook_fio.h"
#include "person.h"
#include "input_error_handlers.h"

extern list_t      *contacts_list;
extern tree_node_t *last_name_tree;
extern tree_node_t *first_name_tree;
extern tree_node_t *age_tree;
extern tree_node_t *phone_number_tree;


void print_list_element(void *data) {
  person_t* person = (person_t*)data;
  printf("  %-21s |  %-21s |  %-21s |  %-21d|\n", person->last_name, person->first_name, person->phone_number, person->age);
}



int add_person() {
  char first_name[DATA_STR_SIZE];
  char last_name[DATA_STR_SIZE];
  char phone_number[DATA_STR_SIZE];
  int age;
  input_last_name(last_name);
  input_first_name(first_name);
  input_phone_number(phone_number);
  printf("Input age: ");
  scanf("%d", &age);
  // add check for number and other
  person_t *person =  person_init(last_name, first_name, phone_number, age);
  list_append(contacts_list, person);
  tree_add_elemnent(&last_name_tree, person, person_cmp_by_last_name);
  tree_add_elemnent(&first_name_tree, person, person_cmp_by_first_name);
  tree_add_elemnent(&phone_number_tree, person, person_cmp_by_phone_number);
  tree_add_elemnent(&age_tree, person, person_cmp_by_age);
  return 0;
}

int save() {
  write_file(contacts_list);
  return 0;
}

int load() {
  read_file(contacts_list);
  return 0;
}

int sort_by_first_name() {
  list_sort(contacts_list, person_cmp_by_first_name);
  return 0;
}

int sort_by_last_name() {
  list_sort(contacts_list, person_cmp_by_last_name);
  return 0;
}

int sort_by_phone_number() {
  list_sort(contacts_list, person_cmp_by_phone_number);
  return 0;
}

int sort_by_age() {
  list_sort(contacts_list, person_cmp_by_age);
  return 0;
}



int search_by_first_name() {
  char tmp_first_name[DATA_STR_SIZE];
  printf("Enter first name of person: ");
  scanf("%s", &tmp_first_name);

  person_t *search_tmp = person_init("", tmp_first_name, "", 0);
  tree_node_t* element = tree_find_element(first_name_tree, search_tmp, person_cmp_by_first_name, print_list_element);
  return 0;
}

int search_by_last_name() {
  char tmp_last_name[DATA_STR_SIZE];
  printf("Enter last name of person: ");
  scanf("%s", &tmp_last_name);

  person_t *search_tmp = person_init(tmp_last_name, "", "", 0);
  tree_node_t* element = tree_find_element(last_name_tree, search_tmp, person_cmp_by_last_name, print_list_element);
  return 0;
}

int search_by_phone_number() {
  char tmp_phone_number[DATA_STR_SIZE];
  printf("Enter phone number of person: ");
  scanf("%s", &tmp_phone_number);

  person_t *search_tmp = person_init("", "", tmp_phone_number, 0);
  tree_node_t* element = tree_find_element(phone_number_tree, search_tmp, person_cmp_by_phone_number, print_list_element);
  return 0;
}

int search_by_age() {
  int tmp_age;
  printf("Enter age of person: ");
  scanf("%u", &tmp_age);

  person_t *search_tmp = person_init("", "", "", tmp_age);
  tree_node_t* element = tree_find_element(age_tree, search_tmp, person_cmp_by_age, print_list_element);
  return 0;
}




int lucky_search() {
  char str[DATA_STR_SIZE];
  printf("Find: ");
  scanf("%s", str);
  list_search(contacts_list, person_lucky_search, print_list_element, str);
  return 0;
}

int remove_person() {
  char first_name[DATA_STR_SIZE];
  char last_name[DATA_STR_SIZE];
  char phone_number[DATA_STR_SIZE];
  int age;
  input_last_name(last_name);
  input_first_name(first_name);
  input_phone_number(phone_number);
  printf("Input age: ");
  scanf("%d", &age);
  person_t *person = person_init(last_name, first_name, phone_number, age);

  tree_remove_element(&first_name_tree, person, person_cmp_by_first_name);
  tree_remove_element(&last_name_tree, person, person_cmp_by_last_name);
  tree_remove_element(&phone_number_tree, person, person_cmp_by_phone_number);
  tree_remove_element(&age_tree, person, person_cmp_by_age);
  void* res = list_remove_element(contacts_list, person, person_cmp);
  if (res) {
    free(res);
  }
  return 0;
}

int show_all() {
  printf("  %-21s |  %-21s |  %-21s |  %-21s|\n", "Last name", "First name", "Phone number", "Age");
  printf("------------------------|------------------------|------------------------|-----------------------|\n");
  list_print(contacts_list, print_list_element);
  printf("===================================================================================================\n");
  return 0;
}

int clean() {
  list_element_t *tmp_element_ptr = contacts_list->head;
  printf("const list size %d\n", contacts_list->size);
  int i;
  int list_size = contacts_list->size;
  for (i = 0; i < list_size; ++i, tmp_element_ptr = contacts_list->head) {
    tree_remove_element(&first_name_tree, tmp_element_ptr->data, person_cmp_by_first_name);
    tree_remove_element(&last_name_tree, tmp_element_ptr->data, person_cmp_by_last_name);
    tree_remove_element(&phone_number_tree, tmp_element_ptr->data, person_cmp_by_phone_number);
    tree_remove_element(&age_tree, tmp_element_ptr->data, person_cmp_by_age);
    void* res = list_remove_element(contacts_list, tmp_element_ptr->data, person_cmp);
    if (res) {
      free(res);
    }
  }

  return 0;
}
