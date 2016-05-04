#include "phonebook_fio.h"
#include "person.h"

#define FILE_NAME "gen_phonebook.txt"


extern list_t      *contacts_list;
extern tree_node_t *last_name_tree;
extern tree_node_t *first_name_tree;
extern tree_node_t *age_tree;
extern tree_node_t *phone_number_tree;


int read_file(list_t *list) {
  FILE *file;
  file = fopen(FILE_NAME, "r");

  fseek(file, 0, SEEK_END);
  unsigned long len = (unsigned long)ftell(file);
  if (len > 0) {
    rewind(file);
  } else {
    fclose(file);
    return 0;
  }

  while (!feof(file)) {
    char last_name[DATA_STR_SIZE];
    char first_name[DATA_STR_SIZE];
    char phone_number[DATA_STR_SIZE];
    int  age;
    fscanf(file, "%21s %21s %21s %21d\n", last_name, first_name, phone_number, &age);
    person_t *person = person_init(last_name, first_name, phone_number, age);
    list_append(list, person);
    tree_add_elemnent(&last_name_tree, person, person_cmp_by_last_name);
    tree_add_elemnent(&first_name_tree, person, person_cmp_by_first_name);
    tree_add_elemnent(&phone_number_tree, person, person_cmp_by_phone_number);
    tree_add_elemnent(&age_tree, person, person_cmp_by_age);
  }

  fclose(file);
}

int write_file(list_t *list) {
  unsigned int i;
  FILE *file;
  file = fopen(FILE_NAME, "w");
  // error check

  for (i = 0; i < list->size; i++) {
    person_t *person = list_at(list, i+1);
    fprintf(file, "%-21s %-21s %-21s %-21d\n", person->last_name, person->first_name, person->phone_number, person->age);
  }
  fclose(file);
  return 0;
}
