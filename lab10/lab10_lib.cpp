//
// Created by Денис Адидас on 4/14/22.
//

#include "lab10_lib.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void* resize(void* mas) {
    int mas_len = 20;
    void* mas_temp = realloc(mas, mas_len *= 2);
    if (mas_temp == NULL) {
        free(mas);
        exit(-1);
    }
    mas = mas_temp;
    free(mas_temp);
}

int mas_len(char** words) {
    int i = 0;
    while (words[i] != NULL) {
        i++;
    }
    return i;
}

char** readToMas(char* path) {
    FILE *f;
    f = fopen(path, "r");
    if (f == NULL) {
        printf("File %s couldn't be opened! \n", path);
    }
    else {
        printf("File %s was opened correctly \n", path);
    }

    int str_idx = 0, len_str = 20;
    //Подготовка к обработке
    char* str = (char*)malloc(sizeof(char) * len_str);
    if (str == NULL) {
        exit(-1);
    }
    char c = ' ';
    while (((c = fgetc(f)) != EOF)) {
        if (str_idx >= len_str) {
            char* str_temp = (char*)(realloc(str, len_str *= 2));
            if (str_temp == NULL) {
                free(str);
                exit(-1);
            }
            str = str_temp;
        }
        str[str_idx++] = c;
    }
    char* pstr;
    int i = 0;
    char** mas_words = (char**)malloc(sizeof(char**) * 50);
    pstr = strtok(str, " ()");
    while (pstr != NULL) {
        pstr = strtok(NULL, " < > () \n");
        if (i > (mas_len(mas_words))) resize(mas_words);
        mas_words[i] = pstr;
        i++;
    }
    return mas_words;
}

void copy_word(char* dst , char* src , int start , int end) {
    int j = 0, k = 0;
    for ( j = start ; j < end ; j++) {
        dst[k] = src[j];
        k++;
    }
    dst[k] = 0;
}

int isSymb(char symb) {
    if (symb >= 'a' && symb <= 'z') {
        return 1;
    }
    if (symb == ' ')
        return 1;
    return -1;


}

int isFunction(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if ((isSymb(str[i]) == -1) || (strlen(str) <= 3) ) return -1;
        i++;
    }
    return 1;
}

void mas_words(char *s1, char **words) {
    int i = 0, in_word = 0;
    int start_w = 0, end_w = 0;
    int word_count = 0;
    while (s1[i] != 0) {
        if (s1[i] != ' ') {
            if (in_word == 0) start_w = i;
            in_word = 1;
        }
        else {
            if (in_word == 1) {
                end_w = i;
                words[word_count] = (char*)malloc(end_w - start_w + 2);
                copy_word(words[word_count], s1, start_w, end_w);
                word_count++;
            }
            in_word = 0;
        }
        i++;
    }
    if (in_word == 1) {
        end_w = i;
        words[word_count] = (char*)malloc(end_w - start_w + 2);
        copy_word(words[word_count], s1, start_w, end_w);
        word_count++;
    }
}

char** readToMas2(char* path) {
    FILE *f;
    f = fopen(path, "r");
    if (f == NULL) {
        printf("File %s couldn't be opened! \n", path);
    }
    else {
        printf("File %s was opened correctly \n", path);
    }

    int str_idx = 0, len_str = 20;
    //Подготовка к обработке
    char* str = (char*)malloc(sizeof(char) * len_str);
    if (str == NULL) {
        exit(-1);
    }
    char** words = (char**)malloc(sizeof(char**) * len_str);

    char c = ' ';
    while (((c = fgetc(f)) != EOF)) {
        if (str_idx >= len_str) {
            char* str_temp = (char*)realloc(str, len_str *= 2);
            if (str_temp == NULL) {
                free(str);
                exit(-1);
            }
            str = str_temp;
        }
        str[str_idx++] = c;
    }
    mas_words(str, words);
    fclose(f);
    return words;
}

