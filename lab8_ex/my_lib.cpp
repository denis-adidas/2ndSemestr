//
// Created by Денис Адидас on 3/13/22.
//

#include <algorithm>
#include <math.h>
#include "my_lib.h"

void ltoae(long num, char str[]) {
    int i = 0, flag = 0;
    if (num < 0) {
        flag = 1;
        num = abs(num);
        i = 1;
        str[0] = '-';
    }
    while (num != 0) {
        int d = 0;
        d = num % 11;
        num /= 11;
//            printf("Test: %d \n", num);
        if (d == 10) {
            str[i] = 'A';
        }
        else {
            str[i] = '0'+d;
        }
        i++;
    }
    if (flag == 1) {
        std::reverse(&str[1], &str[i]);
    }
    else {
        std::reverse(&str[0], &str[i]);
    }

}
int my_pow(int ss, int count) {
    int a = 1;
    while (count != 0) {
        a *= ss;
        count -= 1;
    }
    return a;
}
int isSymb(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return 1;
    }
    else {
        return 0;
    }
}
int isNumber(char ch) {
    if ((ch >= '0') && (ch <= '9')) return 1;
    else return 0;
}
int isSmallLetter(char ch) {
    if ((ch >= 'a') && (ch <= 'z')) return 1;
    else return 0;
}

char* my_string() {
    int str_idx = 0, len_str = 20;
    char* str = (char*)malloc(sizeof(char) * len_str);
    if (str == NULL) exit(-1);
    char a = ' ';
    while ((a = getchar()) != '\n') {
        if (str_idx >= len_str) {
            char* str_temp = (char*)(realloc(str, len_str *= 2));
            if (str_temp == NULL) {
                free(str);
                exit(-1);
            }
            str = str_temp;
            free(str_temp);
        }
        str[str_idx++] = a;
    }
    return &str[0];
}
long fromCharToLong(char i, int ss, int count) {
    int exam_l = (int)(i - 'A');
    int exam_n = (int)(i - '0');
    int exam_sl = (int)(i - 'a');
    int result = 0;
    if ((isSymb(i)) && (exam_l < ss) && (exam_l >= 0)) {
        result += (exam_l + 10) * my_pow(ss, count);
    }
    else if ((isNumber(i)) && (exam_n < ss) && (exam_n >= 0)) {
        result += exam_n * my_pow(ss, count);
    }
    else if ((isSmallLetter(i)) && (exam_sl < ss) && (exam_sl >= 0)) {
        result += (exam_sl + 10) * my_pow(ss, count);
    }
    else {
        result = -1;
    }
    return result;
}
long my_strtol(char* str, char** pEnd, int ss) {
    int count = strlen(str);
    int result = 0;
    int i = 0, c = 0;
    int flag = 0;
    if (str[0] == '-') i = 1;
    for (i ; i < count; i++) {
        if (fromCharToLong(str[i], ss, count - i - 1) != -1) {
            result += fromCharToLong(str[i], ss, count - i - 1);
        }
        else {
            result = 0;
            *pEnd = &str[i];
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        count = i;
        if (str[0] == '-') i = 1;
        else i = 0;
        for (i ; i < count; i++) {
            if (fromCharToLong(str[i], ss, count - i - 1) != -1) {
                result += fromCharToLong(str[i], ss, count - i - 1);
            }
            else {
                *pEnd = &str[i];
                break;
            }
        }
    }

    if (str[0] != '-') return result;
    else return -result;
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

int mas_len(float* mas) {
    int i = 0;
    while (mas[i] != NULL) {
        i++;
    }
    return i;
}

float* masFloat(char* str) {
    int  mas_len = 20;
    float *mas_float = (float *) malloc(sizeof(float) * mas_len);
    char *pch;
//    printf("test00 %c \n", str[0]);
    pch = strtok(str, " ");
    int i = 0;
    while (pch != NULL) {
//        printf("pch %s\n", pch);
        mas_float[i] = atof(pch);
//        printf("pch2 %f\n", mas_float[i]);
        pch = strtok(NULL, " ");
        if (i > mas_len) resize(mas_float);
        i++;
    }
    free(pch);
    return mas_float;
}

int min(float* mas) {
    int i = 0;
    float min = mas[0];
    int min_i = 0;
    while (mas[i] != NULL) {
        if (mas[i] < min) min_i = i;
        i++;
    }
    return min_i;
}