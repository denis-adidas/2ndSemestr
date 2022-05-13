#include <iostream>
#include "research_lib.h"
#include "math.h"

int main() {
    int n = 0;
    printf("Enter count of graphs: \n");
    scanf("%d", &n);
    int** matrix = (int**)malloc(sizeof(int**) * (n) + 1);
    char* str;

    printf("Enter numbers of row #1\n");
    matrix[0] = (int*)malloc(sizeof(int*) + 1);
    getchar();
    str = my_string();
    int* mas_float = masFloat(str);
    matrix[0] = mas_float;
    for (int i = 1; i < n; i++) {
        printf("Enter numbers of row #%d\n", i + 1);
        matrix[i] = (int*)malloc(sizeof(int*) + 1);
        str = my_string();
        mas_float = masFloat(str);
        matrix[i] = mas_float;
        free(str);
    }
    int j = 0;
    int ctrl_flag_row = 0;
    int max_sum_in_row = 0;
    int* ctrl_flag_clm = (int*)calloc(n, sizeof(int));
    while (j < n) {
        int i = 0;
        float sum_str = 0;
        while (i < n) {
            sum_str += matrix[j][i];
//            printf("test 0: %d \n", matrix[j][i]);
            ctrl_flag_clm[i] += matrix[j][i];

            i++;
        }
        if (sum_str > (int)(n/2))
            ctrl_flag_row++;
        j++;
    }
//    printf("test1 %d\n", ctrl_flag_row);
    int graph_ctrl_flag = 0;
    for (int i = 0; i < n; i++) {
//        printf("test3 %d\n", ctrl_flag_clm[i]);
        if (ctrl_flag_row >= (int)(n/2) && ctrl_flag_clm[i] >= (int)(n/2)) graph_ctrl_flag = 1;
        else {
            graph_ctrl_flag = 0;
            break;
        }
    }
    if (graph_ctrl_flag > 0) printf("Graph is connected\n");
    else printf("Graph is not connected\n");
}
/*
 * 1 1 0
Enter numbers of row #2
1 1 1
Enter numbers of row #3
0 1 1

 сделать переборочный алгоритм
 */