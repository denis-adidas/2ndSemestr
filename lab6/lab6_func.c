//
// Created by Денис Адидас on 4/12/22.
//

#include "lab6_func.h"
#include <stdio.h>
#include <stdlib.h>

int sLen(char* string){
    int g = 0;
    for (int i = 0; string[i] != '\0'; i++){
        g++;
    }
    return (g);
}

int m2Len(char** words) {
    int i = 0;
    while (words[i] != NULL) {
        i++;
    }
    return i;
}

void swap(char **s1, char **s2) {
    char * tmp = * s1 ;
    *s1 = *s2 ;
    *s2 = tmp ;
}

void sort(char **words) {
    int i = 0, j = 0, min_idx = 0;
    int n = m2Len(words);
    for (i = 0; i < n; i++) {
        min_idx = i;
        for (j = i; j < n; j++) {
            if (sLen(words[j]) < sLen(words[min_idx])) min_idx = j;
        }
        swap(&words[i], &words[min_idx]);
    }
}


void copy_word(char* dst , char* src , int start , int end) {
    int j = 0, k = 0;
    for ( j = start ; j < end ; j++) {
        dst[k] = src[j];
        k++;
    }
    dst[k] = 0;
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


//Все, что связанно со списками
struct node_s;

typedef struct {
    struct node_s* next;
    struct node_s* prev;
    char* word;
} node_t;

typedef struct {
    node_t* head;
    node_t* tail;
    size_t size;
}list_t;

void init(list_t* l) {
    l->head = NULL;
    l->head = NULL;
    l->size = 0;
}

void destroy(list_t* l) {
    if (l->head != NULL) {
        node_t *cur = l->head;
        node_t *prev = NULL;
        while (cur != NULL) {
            prev = cur;
            cur = cur->next;
            free(prev);
        }
    }
}

void push_back(list_t* l, char* str) {
    node_t *n, *cur;
    n = (node_t*)malloc(sizeof(node_t));
    n->word = str; n->next = NULL;
    if (l->head == NULL) {
        n->prev = NULL;
        l->head = n;
    }
    else {
        cur = l->head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = n;
        n->prev = cur;
    }
    l->size++;
}

void print(list_t* l) {
    node_t *cur = l->head ;
    while (cur != NULL ) {
        printf("%s ", cur->word);
        cur = cur->next;
    }
    printf("\n");
}

void union_l(list_t* l1, list_t* l4) {
    node_t* cur = l1->head;
    while (cur != NULL) {
        push_back(l4, cur->word);
        cur = cur->next;
    }
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
    char** words = (char**)malloc(sizeof(char**) * len_str);

    char c = ' ';
    while (((c = fgetc(f)) != EOF)) {
        if (str_idx >= len_str) {
            char* str_temp = realloc(str, len_str *= 2);
            if (str_temp == NULL) {
                free(str);
                exit(-1);
            }
            str = str_temp;
        }
        str[str_idx++] = c;
    }
    mas_words(str, words);
    sort(words);
    fclose(f);
    return words;
}
void free_words(char** words) {
    int i = 0;
    while (words[i] != NULL) {
        free(words[i]);
        i++;
    }
    free(words);
}
