#include <iostream>
#include <string.h>
#include "my_lib.h"


int main() {
    int mas_len = 20;
    char *str = my_string();
    float *mas_float = (float *) malloc(sizeof(float) * mas_len);
    char *pch;
    pch = strtok(str, " ");
    int i = 0;
    while (pch != NULL) {
        mas_float[i] = atof(pch);
        pch = strtok(NULL, " ");
        if (i > mas_len) resize(mas_float);
        i++;
    }
    int count = 0, min = i;
    for (int j = 1; j < i; j++) {
        if (((mas_float[j] > mas_float[j - 1]) && (mas_float[j] > mas_float[j + 1])) || ((mas_float[j] < mas_float[j - 1]) && (mas_float[j] < mas_float[j + 1]))) {
            if ((count <= min) && (count != 0)) min = count;
            count = 0;
        }
        else{
            count++;
        }
    }
    printf("Result: %d\n", min);
    free(mas_float);
    free(str);
    return 0;
}

/* test's
 * 242.234 2342.12 865.3453 342.54
 * 25223.54 43534 3463.234 32346.654 353 65474.454 5464.9878 234.534 235.643 876.234 235576
 */