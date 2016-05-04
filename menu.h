#ifndef MENU_H_
#define MENU_H_

#define ENTER_PROMT         "Enter command: "

#define MENU                "Menu: \n"                                        \
                            "1. Add person\n"                                 \
                            "2. Save\n"                                       \
                            "3. Load\n"                                       \
                            "4. Search\n"                                     \
                            "5. Remove person\n"                              \
                            "6. Show all contacts\n"                          \
                            "7. Clear contacs\n"                              \
                            "8. Lucky search\n"                               \
                            "0. Exit\n"

#define ADD_PERSON          1
#define SAVE                2
#define LOAD                3
#define SEARCH              4
#define REMOVE_PERSON       5
#define SHOW_ALL            6
#define CLEAR               7
#define LUCKY_SEARCH        8
#define EXIT                0




#define SEARCH_MENU_PROMNT  "Search by: \n"
#define SUBMENU             "1. First name\n"                                 \
                            "2. Last name\n"                                  \
                            "3. Age\n"                                        \
                            "4. Phone number\n"


#define FIRST_NAME          1
#define LAST_NAME           2
#define AGE                 3
#define PHONE_NUMBER        4


#define LOGO    "___________ooo__________________________________________oooooooooo\n"                      \
                "________ooooooooo_____________________________________oooooooooooooooo\n"                  \
                "______ooooooooooooo_________________________________oooooooooooooooooooo\n"                \
                "____ooooooooooooooooo_______________oooooooo_____ooooooooooooooooooooooooo\n"              \
                "___ooooooo_____oooooooo________oooooooooooooooooooooooooo_______oooooooooooo\n"            \
                "___¦oooo______oo_ooooooooooooooooooooooooooooooooooooooo_____ooooooooooooooo¦\n"           \
                "__¦ooooooo_ooo_____ooooooooooooooooooooooooooooooooooo¦_____oooooooooooooooooo\n"          \
                "_oooooooooo_____oo__oooooooooooooooooooooooooooooooooo___o_oooooooooooooooooo¦\n"          \
                "_¦ooooooooo__ooo______ooooooooooooooooooooooooooooooo¦_____ooooooooooooooooooo\n"          \
                "_¦ooooooooooo_____oo____ooooooooooooooooooooooooooooo¦_o_o___oooooooooooooooooo\n"         \
                "_oooooooooo____ooo___o___¦oooooooooooooooooooooooooooo_____ooooooooooooooooooo¦\n"         \
                "_¦ooooooooooooo___ooo____oooooooooooooooooooooooooooooo_o__ooooooooooooooooooo¦\n"         \
                "_ooooooooooooooooooo____¦oooooooooooooooooooooooooooooo¦______oooooooooooooooo¦\n"         \
                "__¦oooooooooooooooo__oo_ooo¦_oooooooooooooooooooooooooooo___ooooo_____o____ooo¦\n"         \
                "__oooooooooooooooo______¦oo_ooooooooooooooooooooooo_¦_ooo¦___ooo_ooooo______¦o¦\n"         \
                "___¦ooooooooooooo___oo___ooooooooooooooooooooooooooo_ooooo¦_o__oooo______o___o¦\n"         \
                "___oooo_o__oooo___ooo______ooooooooooooooooooooooooooooooo¦_______o____o____¦o\n"          \
                "____oooo__o_o____oo_____o___¦ooooooooooooooooooooooooooooo____o____ooooo___ooo\n"          \
                "_____oooooo____oo____________oo_ooooooooooooo¦ooooooooooo¦_o______o___ooooooo¦\n"          \
                "______ooo___o_oo_____o____o__ooooooooooooo_o¦_o_ooooooooo____ooooo_____o___oo¦\n"          \
                "_______oo___oo_____o____o___¦ooooooooooooooo¦_oo_oooooo¦_______oooooo_____¦oo\n"           \
                "________ooooo____oo__________¦oooooooooooooo¦¦ooo_oooooo_o_o_______ooooo_ooo\n"            \
                "_________oo____oo____¦_____oo¦o_oooooooooooo¦¦ooo¦ooooo_____oooo_______oooo\n"             \
                "__________oo_ooo____o_____¦oo¦oooooooooooo_o¦ooooo_________o__oooooo_oooo\n"               \
                "___________ooo_____¦¦_____oo¦¦oooooooooooooo_ooooo¦_o__o_o_______ooooooo_o\n"              \
                "____________oo____o____o_¦oo¦¦o_oooooooooooo_ooooo¦_______ooo__o__oooo_oooo\n"             \
                "_____________ooo_¦¦______¦oo¦¦oooooooooooooo_¦ooooo__o______ooo__oooo_ooooo¦\n"            \
                "______________oooo___o___ooo¦¦ooooooooooo_o¦__ooooo¦__ooo____oooooo_ooooooo¦\n"            \
                "________________ooo_____¦ooo_¦ooooooooooooo¦__¦ooooo____ooo__oooo_ooooooooo¦\n"            \
                "_________________oooo___¦ooo__o_ooooooooooo¦___ooooo__o___oooooo_¦ooooooooo¦\n"            \
                "____________________oo___ooo¦_ooooooooooooo_o_____ooo__o____oooo_¦o_ooooooo¦\n"            \
                "_______________________oooooo_oooooooooo_o¦__o___ooooo_____oooo¦_oo¦ooooooo¦\n"            \
                "_______________________oooo¦__oooooooooooo¦______¦oooo¦___¦_ooo¦¦o¦¦ooooooo¦\n"            \
                "______________________¦ooo¦___o__ooooooooo¦___o___ooooo___ooooo¦¦o¦¦oooooooo\n"            \
                "______________________oooo___¦¦ooooooooooo________¦oooo__oooooo_oo¦ooooooo¦\n"             \
                "______________________ooo¦___o¦oooooooooo¦____o____oooo__oooooo¦o¦_ooo¦oooo\n"             \
                "_____________________¦ooo¦__¦o¦oooooooooo¦__o___o__¦oo¦_¦__ooo¦_¦_¦oo¦¦ooo\n"              \
                "_____________________¦ooo___oo¦¦o_ooooo_o¦_________ooo__¦ooooo¦__¦ooo_oo¦\n"               \
                "______________________oo¦___oo¦¦ooooooooo________oooo¦_ooooooo__¦oooo¦oo\n"                \
                "______________________¦o¦__¦oo¦¦ooooooooo____oooooooo_¦__ooooo_¦oooo_¦¦\n"                 \
                "_____________o_________o¦__¦ooo_oooooooo¦______ooo__ooooooooo¦_oooo_¦¦\n"                  \
                "____________ooo_________o__¦ooo_oooooooo¦__o_____oooooooooooo_¦ooo__¦oo¦\n"                \
                "__________ooo_oooo______¦__¦ooo¦oooooooo________¦ooooooooooo___o__ooooo\n"                 \
                "________ooo__o__ooo________¦ooo¦¦o_ooooo________¦__oooooooo¦__ooooooooo\n"                 \
                "_______oo__ooooo__o________¦ooo¦¦oooooo¦________oooooooooooo__oooooooo¦_______oo\n"        \
                "______oo_oooooooo¦_o________ooo¦¦oooo_o¦___o____oooooooooo___¦oo_ooooo______ooo\n"         \
                "____ooo_ooooooooo__oo__oo___oooo_oooooo¦_______¦__ooooooo¦___oo¦¦oooo¦___ooooo\n"          \
                "__ooo_oooooooooo__o_oooo____¦ooo¦oooooo¦_______¦oooooooooo__¦oo_ooooo__oooo\n"             \
                "_ooo_oooooooooo____oooooooo_¦ooo¦¦oooooo_______ooooooooo¦___oo_¦oooo¦_oooooooooo\n"        \
                "oo__oooooooooo_ooo__ooooooo¦¦ooo¦_oooooo¦___o__ooooooooo¦_oo_ooooooooooooooooooo\n"        \
                "o_ooooooooooo_¦ooooo_ooooooo_oooo_¦oooooo______¦oooooooo¦__ooooo oooooooooooooo\n"         \
                "_oooooooooo¦__oooooooooooooo¦ooooo__oooooo_ooooooooooooooooooooooooooooooooooo\n"          \
                "¦oooooooooo__¦oooooooooooooooooooooo_oooooo_ooooooooooooooooooooooooooooooooo_oo\n"        \
                "¦ooooooooo___oooooooooooooooooooooooooo_oo_ooooooooooooooooooooooooooooooooo_ooo\n"


int main_menu();
int search_menu();
/*int sort_menu();*/


#endif /* MENU_H_ */
