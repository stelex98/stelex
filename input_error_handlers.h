#ifndef INPUT_ERROR_HANDLER_H_
#define INPUT_ERROR_HANDLER_H_

#include <stdint.h>

int32_t check_for_name(const char *str);
int32_t check_for_phone_number(const char *str);

int32_t input_first_name(char *str);
int32_t input_last_name(char *str);
int32_t input_phone_number(char *str);
int32_t input_age(int32_t *age);


#endif /* INPUT_ERROR_HANDLER_H_ */
