#include <iostream>
#include "research_lib.h"
#include "math.h"

int main() {
    int n_copy = 0;
    printf("Enter count of graphs: \n");
    scanf("%d", &n_copy);
    int flags_sum = 0;

    int n = n_copy*(n_copy-1)/2; //ребра

    for (int u = 1; u <= pow(2, n) - 1; u++ ) {

        int* vector = from_number_to_vector(u, n);

//        for (int j = 0; j < n; j++) {
//            printf("%d ", vector[j]);
//        }
//        printf("\n Матрица \n");

        int** matrix2 = make_matrix_from_vector(vector, n_copy);

//        print_matrix(matrix2, n);
//        printf("\n");

        matrix2 = my_square_matrix_pow(matrix2, n_copy, n_copy);

        int j = 0;
        int flag = 1;
        while (j < n_copy) {
            int i = 0;
            while (i < n_copy) {
                if (matrix2[j][i] == 0) {
                    flag = 0;
                    break;
                }
                i++;
            }
            j++;
        }
        flags_sum += flag;
    }

    printf("counts of connected graphs %d \n", flags_sum);

//    int* vector = from_number_to_vector(3, 3);
//
//    int** matrix2 = make_matrix_from_vector(vector, n);
//
//    print_matrix(matrix2, n);
//
//    matrix2 = my_square_matrix_pow(matrix2, n, n);
//
//    int j = 0;
//    int flag = 0;
//    while (j < n) {
//        int i = 0;
//        while (i < n) {
//            if (matrix2[j][i] == 0) {
//                flag = 1;
//                break;
//            }
//            i++;
//        }
//        j++;
//    }
//    if (flag == 1) printf("Graph isn't connected \n");
//    else printf("Graph is connected");
}
/*
 * 1 1 0
Enter numbers of row #2
1 1 1
Enter numbers of row #3
0 1 1

 сделать переборочный алгоритм
 */