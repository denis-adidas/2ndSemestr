#include <stdio.h>
#include <stdlib.h>

char* STR = NULL;
int LEN;
/* 1. Обработка файла
 * 2. Считывание все в массивы
 * 3. Сортировка
 * 4. Записать все в структуры
 * 5. Объединить структуры
 */
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
    int n = m2Len(words) - 2;
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
        if (s1[i] != ' ' && s1[i] != '\n') {
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

int len_f(char*  str) {
    for (int i = 0; i < 999; i++) {
        if (str[i] == '\0' || str[i] == '\n') {
            return i + 1;
        }
    }
    return 0;
}

int include(char symb, char* str) {
    int len = len_f(str);
    for (int i = 0; i < len; i++) {
        if (symb == str[i]) {
            return 1;
        }
    }
    return 0;
}

char* my_strtok(char *str, char* d_sym) {
    int len, start = 0;
    if (str == NULL) {
        str = STR;
        len = len_f(str);
        LEN -= len;
        if (LEN <= 0) {
            return NULL;
        }
        str += sizeof(char) *  len;
        int i = 0;
        while (str[i] == '\0' || include(str[i], d_sym)) {
            str += sizeof(char);
            LEN -= 1;
        }
    }
    else {
        LEN = len_f(str);
        int i = 0;
        while (str[i] == '\0' || include(str[i], d_sym)) {
            str += sizeof(char);
            LEN -= 1;
        }
    }
    for (int i = 0; i < LEN; i++) {
        if (include(str[i], d_sym)) {
            while (include(str[i], d_sym)) {
                str[i] = '\0';
                i++;
            }
            break;
        }
    }
    STR = str;
    return str;
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

void sort_l(list_t* l) {
    node_t* left = l->head;
    node_t* right = l->head->next;
    node_t* tmp = (node_t*)malloc(sizeof(node_t*));
    while (left->next) {
        while (right) {
            if ((sLen(left->word)) > sLen(right->word)) {
                tmp->word = left->word;
                left->word = right->word;
                right->word = tmp->word;
            }
            right = right->next;
        }
        left = left->next;
        right = left->next;
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

void add_words(char** source, char** dst) {
    int i = m2Len(source) - 1;
    int j = m2Len(dst);
    if (i > j) {
        resize(dst);
    }
    j = m2Len(dst);
    while (i >= 0) {
        dst[j] = (char*)malloc(sizeof(char*) * sLen(source[i]));
        dst[j] = source[i];
        j++;
        i--;
    }
}

int main() {

    char** words1 = readToMas("/Users/denis_adidas/CLionProjects/untitled/file1.txt");
    char** words2 = readToMas("/Users/denis_adidas/CLionProjects/untitled/file2.txt");
    char** words3 = readToMas("/Users/denis_adidas/CLionProjects/untitled/file3.txt");
    char** words_complete = (char**)malloc(sizeof(char**) * (m2Len(words1) + m2Len(words2) + m2Len(words3)));


    int i = 0;
    list_t l1;   //Первый список
    init(&l1);
    int n = m2Len(words1);
    for (i = 0; i < n; i++) {
        push_back(&l1, words1[i]);
    } //Заполнили первый список словами
//    print(&l1);

    list_t l2; //Второй список
    init(&l2);
    n = m2Len(words2);
//    printf("Test 4: %d \n", n);
    for (i = 0; i < n; i++) {
        push_back(&l2, words2[i]);
    } //Заполнили второй список
//    print(&l2);

    list_t l3; //Третий список
    init(&l3);
    n = m2Len(words3);
    for (i = 0; i < n; i++) {
        push_back(&l3, words3[i]);
    } //Заполнили третий список
//    print(&l3);

    list_t l4;
    init(&l4);

    union_l(&l1, &l4);
    union_l(&l2, &l4);
    union_l(&l3, &l4);

    sort_l(&l4);

    print(&l4);

    destroy(&l1);
    destroy(&l2);
    destroy(&l3);
    destroy(&l4); //освобождение памяти от списков

    free_words(words1);
    free_words(words2);
    free_words(words3);
    return 1;
}