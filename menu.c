#include "menu.h"
#include "wrappers.h"
#include "list.h"
#include "phonebook_fio.h"
#include <stdlib.h>
#include <stdio.h>

extern list_t *contacts_list;

/*int sort_menu() {
  int command = 0;
  puts(SORT_MENU_PROMT SUBMENU);
  printf(ENTER_PROMT);
  scanf("%d", &command);
  switch (command) {
    case FIRST_NAME:
      printf("First name\n");
      sort_by_first_name();
      break;
    case LAST_NAME:
      printf("Last name\n");
      sort_by_last_name();
      break;
    case AGE:
      printf("Age\n");
      sort_by_age();
      break;
    case PHONE_NUMBER:
      printf("Phone number\n");
      sort_by_phone_number();
      break;
    default:
    printf("Error. Wrong command. Try again\n");
  }

}*/

int search_menu() {
  int command = 0;
  puts(SEARCH_MENU_PROMNT SUBMENU);
  printf(ENTER_PROMT);
  scanf("%d", &command);
  switch (command) {
    case FIRST_NAME:
      printf("First name\n");
      search_by_first_name();
      break;
    case LAST_NAME:
      printf("Last name\n");
      search_by_last_name();
      break;
    case AGE:
      printf("Age\n");
      search_by_age();
      break;
    case PHONE_NUMBER:
      printf("Phone number\n");
      search_by_phone_number();
      break;
    default:
    printf("Error. Wrong command. Try again\n");
  }
}


int main_menu() {
  int command = 0;
  puts(LOGO);
  while (1) {
    puts(MENU);
    printf(ENTER_PROMT);
    scanf("%d", &command); // check
    switch (command) {
      case ADD_PERSON:
        add_person();
        break;
      /*case SORT_PERSON:
        sort_menu();
        break;*/
      case SAVE:
        save();
        break;
      case LOAD:
        load();
        break;
     case SEARCH:
        search_menu();
        break;
      case REMOVE_PERSON:
        remove_person();
        break;
      case SHOW_ALL:
        show_all();
        break;
      case CLEAR:
        clean();
        break;
      case LUCKY_SEARCH:
        lucky_search();
        break;
      case EXIT:
        exit(1);
        break;
      default:
      printf("Error. Wrong command. Try again\n");
    }
  }
}
