#include <iostream>
#include <stdlib.h>
#include "my_lab.h"

/*  Написать аналог функции strtol
 *  1. Подсчитать
 *
 *
*/
int main() {
        int str_idx = 0, len_str = 20;
        char* str = (char*) malloc(sizeof(char) * len_str);
        if (str == NULL) exit(-1);
        char a = ' ';
        while ((a = getchar()) !='\n') {
        if (str_idx >= len_str) {
            char* str_temp = (char*)(realloc(str, len_str *= 2));
            if (str_temp == NULL) {
                free(str);
                exit(-1);
                }
            str = str_temp;
            }
        str[str_idx++] = a;
        }
        char* pEnd;
        char* pEnd2;
       long c = strtol(str, &pEnd, 36);
       long d = my_strtol(str, &pEnd2, 36);

        printf("Test0: %d\n", c);
        printf("Test1: %d\n", d);
        return 0;

} //функция анлог strtol
