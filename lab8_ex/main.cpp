#include <iostream>
#include <cstdio>
#include "my_lib.h"


int main() {
    int n = 0;
    printf("Enter count of rows: \n");
    scanf("%d", &n);
    float** matrix = (float**)malloc(sizeof(float**) * (n) + 1);
    char* str;

    printf("Enter numbers of row #0\n");
    matrix[0] = (float*)malloc(sizeof(float*) + 1);
    getchar();
    str = my_string();
    float* mas_float = masFloat(str);
    matrix[0] = mas_float;
    for (int i = 1; i < n; i++) {
        printf("Enter numbers of row #%d\n", i + 1);
        matrix[i] = (float*)malloc(sizeof(float*) + 1);
        str = my_string();
        mas_float = masFloat(str);
        matrix[i] = mas_float;
        free(str);
    }

    int count = 0;
    int min_v = 0;
    for (int i = 0; i < n; i++) {
        min_v = min(matrix[i]);
        int j = n-1;
        count = 0;
        while (j > i) {
            if (matrix[j][min_v] <= matrix[i][min_v]) count++;
            j--;
        }
        j = i;
        while (j > 0)  {
            if (matrix[j][min_v] <= matrix[i][min_v]) count++;
            j--;
        }
        if (count == n - 1) {
            printf("Saddle point: Column: %d, Row: %d \n", min_v + 1, i + 1);
        }
    }
}

/* test's
 * 242.234 2342.12 865.3453 342.54
 * 25223.54 43534 3463.234 32346.654 353 65474.454 5464.9878 234.534 235.643 876.234 235576
 */
/* 5 6 4 5 - седловой элемент
 * -2 5 3 7
 * 8 7 -2 6
 *
 * 2 3 5 2
 * 2 4 6 2
 * -2 7 2 0
 */