#include "person.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


person_t* person_init(char *last_name, char *first_name, char *phone_number, int age) {
  person_t *person = calloc(1, sizeof(person_t));
  strncpy(person->last_name, last_name, DATA_STR_SIZE);
  strncpy(person->first_name, first_name, DATA_STR_SIZE);
  strncpy(person->phone_number, phone_number, DATA_STR_SIZE);
  person->age = age;
  return person;
}


int person_cmp_by_first_name(void *person1, void *person2) {
  person_t *p1 = (person_t*)person1;
  person_t *p2 = (person_t*)person2;

  if (strncmp(p1->first_name, p2->first_name, DATA_STR_SIZE) > 0) {
    return 1;
  } else if (strncmp(p1->first_name, p2->first_name, DATA_STR_SIZE) < 0) {
    return -1;
  } else {
    return 0;
  }
}

int person_cmp_by_last_name(void *person1, void *person2) {
  person_t *p1 = (person_t*)person1;
  person_t *p2 = (person_t*)person2;

  if (strncmp(p1->last_name, p2->last_name, DATA_STR_SIZE) > 0) {
    return 1;
  } else if (strncmp(p1->last_name, p2->last_name, DATA_STR_SIZE) < 0) {
    return -1;
  } else {
    return 0;
  }
}

int person_cmp_by_phone_number(void *person1, void *person2) {
  person_t *p1 = (person_t*)person1;
  person_t *p2 = (person_t*)person2;

  if (strncmp(p1->phone_number, p2->phone_number, DATA_STR_SIZE) > 0) {
    return 1;
  } else if (strncmp(p1->phone_number, p2->phone_number, DATA_STR_SIZE) < 0) {
    return -1;
  } else {
    return 0;
  }
}

int person_cmp_by_age(void *person1, void *person2) {
  person_t *p1 = (person_t*)person1;
  person_t *p2 = (person_t*)person2;


  if ((p1->age - p2->age) > 0) {
    return 1;
  } else if ((p1->age - p2->age) < 0) {
    return -1;
  } else {
    return 0;
  }
}

int person_lucky_search(void *data, char *str) {
  person_t *person = (person_t*)data;
  unsigned int str_len = strnlen(str, DATA_STR_SIZE);
  if (strstr(person->first_name, str)) {
    return 1;
  }
  if (strstr(person->last_name, str)) {
    return 1;
  }
  if (strstr(person->phone_number, str)) {
    return 1;
  }
  char age_str[DATA_STR_SIZE];
  sprintf(age_str, "%d", person->age);
  if (strstr(age_str, str)) {
    return 1;
  }
  return 0;
}



person_t* person_set_last_name(person_t* person, char *last_name) {
  strncpy(person->last_name, last_name, DATA_STR_SIZE);
  return person;
}

person_t* person_set_first_name(person_t* person, char *first_name) {
  strncpy(person->first_name, first_name, DATA_STR_SIZE);
  return person;
}

person_t* person_set_phone_number(person_t* person, char *phone_number) {
  strncpy(person->phone_number, phone_number, DATA_STR_SIZE);
  return person;
}

person_t* person_set_age(person_t* person, int age) {
  person->age = age;
  return person;
}

int person_cmp(void *person1, void *peroson2) {
  int res = memcmp(person1, peroson2, sizeof(person_t));
  return res;
}


void person_free(person_t *person) {
  free(person);
}
