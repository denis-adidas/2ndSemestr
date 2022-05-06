//
// Created by Денис Адидас on 4/14/22.
//

#ifndef LAB10_LAB10_LIB_H
#define LAB10_LAB10_LIB_H

void* resize(void* mas);
int mas_len(char** mas);
char** readToMas(char* path);
char** readToMas2(char* path);
void copy_word(char* dst , char* src , int start , int end);
int isSymb(char symb);
int isFunction(char* str);

#endif //LAB10_LAB10_LIB_H
