//
// Created by Денис Адидас on 3/13/22.
//

#include <iostream>
#include <stdlib.h>
#include "my_lib.h"

int main() {
    char* str = my_string();
    char* pEnd;
    char* pEnd2;
    long c = strtol(str, &pEnd, 17);
    long d = my_strtol(str, &pEnd2, 17);

    printf("Test0: %d\n", c);
    printf("Test1: %d\n", d);
    return 0;
} //функция анлог strtol