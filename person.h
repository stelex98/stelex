#ifndef PERSON_H_
#define PERSON_H_

#define DATA_STR_SIZE 20

typedef struct person_t {
  char last_name[DATA_STR_SIZE];
  char first_name[DATA_STR_SIZE];
  char phone_number[DATA_STR_SIZE];
  int  age;
} person_t;


int person_cmp_by_first_name(void *person1, void *person2);
int person_cmp_by_last_name(void *person1, void *person2);
int person_cmp_by_phone_number(void *person1, void *person2);
int person_cmp_by_age(void *person1, void *person2);
int person_lucky_search(void *data, char *str);

person_t* person_init(char *last_name, char *first_name, char *phone_number,  int age);
person_t* person_set_last_name(person_t* person, char *last_name);
person_t* person_set_first_name(person_t* person, char *last_name);
person_t* person_set_phone_number(person_t* person, char *last_name);
person_t* person_set_age(person_t* person, int age);
int person_cmp(void *person1, void *peroson2);
void person_free(person_t *person);



#endif /* PERSON_H_ */
