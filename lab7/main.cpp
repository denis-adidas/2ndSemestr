#include <iostream>
#include <stdlib.h>
#include "my_lab.h"

int main() {
    char* str = my_string();
    char* pEnd;
    char* pEnd2;
    long c = strtol(str, &pEnd, 36);
    long d = my_strtol(str, &pEnd2, 36);

    printf("Test0: %d\n", c);
    printf("Test1: %d\n", d);
    return 0;
} //функция анлог strtol
