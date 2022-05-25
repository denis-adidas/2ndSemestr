//
// Created by Денис Адидас on 3/13/22.
//


#ifndef my_lib
#define my_lib
void ltoae(long num, char str[]);
long my_strtol(char* str, char** pEnd, int ss);
char* my_string();
void* resize(void* mas);
int* masFloat(char* str);
int mas_len(float* mas);
int my_pow(int ss, int count);
int min(float* mas);
int** my_square_matrix_pow(int** matrix, int size, int grade);
int **matrix_mylti(int **matrix, int size);
int** make_matrix_from_vector(int* vector, int size);
void print_matrix(int** matrix, int size);
int* from_number_to_vector(int n, int degree);
#endif
