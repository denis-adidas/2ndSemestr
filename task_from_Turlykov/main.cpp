#include <iostream>
#include "research_lib.h"

int main() {
    int n = 0;
    printf("Enter count of graphs: \n");
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
    int j = 0;
    int ctrl_flag_row = 0;
    int max_sum_in_row = 0;
    int* ctrl_flag_clm = (int*)malloc(sizeof(int) * 4);
    while (j < n) {
        int i = 0;
        float sum_str = 0;
        while (i < n) {
            sum_str += matrix[j][i];
            ctrl_flag_clm[i] += matrix[j][i];
            i++;
        }
        if (sum_str > 2)
            ctrl_flag_row++;
        j++;
    }
//    printf("test1 %d\n", ctrl_flag_row);
    int graph_ctrl_flag = 0;
    for (int i = 0; i < n; i++) {
//        printf("test3 %d\n", ctrl_flag_clm[i]);
        if (ctrl_flag_row >= 2 && ctrl_flag_clm[i] >= 2) graph_ctrl_flag = 1;
        else {
            graph_ctrl_flag = 0;
            break;
        }
    }
    if (graph_ctrl_flag > 0) printf("Graph is connected\n");
    else printf("Graph is not connected\n");
}
