#include "input_error_handlers.h"

#include <ctype.h>
#include <string.h>
#include <stdio.h>

int32_t check_for_name(const char *str) {
  int i = 0;
  if (!str) {
    return 1;
  }
  int str_len = strlen(str);
  for (i = 0; i < str_len; i++) {
    if (!isalpha(str[i])) {
      return 1;
    }
  }
  return 0;
}


int32_t check_for_phone_number(const char *str) {
  int i = 0;
  if (!str) {
    printf("--->%c<---\n", str[i]);
    return 1;
  }
  int str_len = strlen(str);
  if ((str[i] != '+') && !isdigit(str[i])) {
    printf("-->%c<--\n", str[i]);
    return 1;
  }
  for (i = 1; i < str_len ; i++) {
    if ((str[i] == '\n') || (str[i] == '\0')) {
      break;
    }
    if (!isdigit(str[i])) {
      printf("->%c<-\n", str[i]);
      return 1;
    }
  }
  return 0;
}


int32_t check_for_age(const char *str) {
  int i = 0;
  if (!str) {
    return 1;
  }
  int str_len = strlen(str);
  for (i = 0; i < str_len; i++) {
    if (!isdigit(str[i])) {
      return 1;
    }
  }
  return 0;
}


int32_t input_first_name(char *str) {
  do {
    printf("Input first name: ");
    scanf("%s", str);
  } while(check_for_name(str));
}

int32_t input_last_name(char *str) {
  do {
    printf("Input last name: ");
    scanf("%s", str);
  } while(check_for_name(str));
}

int32_t input_phone_number(char *str) {
  do {
    printf("Input phone number: ");
    scanf("%s", str);
  } while(check_for_phone_number(str));
}

int32_t input_age(int32_t *age) {
  char str[20];
  do {
    printf("Input age: ");
    scanf("%s", str);
  } while(check_for_age(str));
  // *age = atoi(str);
}
