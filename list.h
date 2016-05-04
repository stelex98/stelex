#ifndef LIST_H_
#define LIST_H_

#include<stddef.h>

typedef void (*print_data_fptr)(void *);
typedef int (*search_data_fptr)(void *, char *);
typedef int (*cmp_data_fptr)(void *, void *);

typedef struct list_element_t {
  struct list_element_t *left;
  struct list_element_t *right;
  void                  *data;
} list_element_t;


typedef struct list_t {
  list_element_t     *head;
  list_element_t     *tail;
  unsigned long      size;
} list_t;


list_t* list_init();
int list_append(list_t *list, void *data);
void *list_remove_element(list_t *list, void *element, cmp_data_fptr cmp);
void *list_at(list_t *list, int pos);
int list_print(list_t *list, print_data_fptr print_data);
int list_sort(list_t  *list, cmp_data_fptr cmp);
int list_search(list_t *list, search_data_fptr serch, print_data_fptr print_data, char *str);
list_t* list_destroy(list_t* list);



#endif  /* LIST_H_ */
