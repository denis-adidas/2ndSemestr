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

int charToNum(char symb) {
    if (symb >= '0' && symb <= '9') {
        return int(symb - '0');
    }
    if (symb >= 'a' && symb <= 'z') {
        return int(10 + symb - 'a');
    }
    if (symb >= 'A' && symb <= 'Z') {
        return int(10 + symb - 'A');
    }
    return -1;


}

char* my_string() {
    int str_idx = 0, len_str = 20;
    char* str = (char*) malloc(sizeof(char) * len_str);
    if (str == NULL) exit(-1);
    char a = ' ';
    while ((a = getchar()) !='\n') {
        if (str_idx >= len_str) {
            char* str_temp = (char*)(realloc(str, len_str *= 2));
            if (str_temp == NULL) {
                free(str);
                exit(-1);
            }
            str = str_temp;
        }
        str[str_idx++] = a;
    }
    return &str[0];
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

char* fromIntToChar(int num) {
    int lenstr = 20;
    char* str = (char*)malloc(sizeof(int) * lenstr);
    int i = 0;
    while (num > 0) {
        if (i == lenstr) {
            resize(str);
        }
        str[i] = num % 10 + '0';
        i++;
        num /= 10;
    }
    char* str_temp = (char*)malloc(sizeof(int) * strlen(str) + 2);
    i = strlen(str) - 1;
    for (int j = 0; j < strlen(str); j++) {
        str_temp[j] = str[i];
        i--;
    }
    free(str);
    return str_temp;
}
long fromCharToLong(char i, int ss, int count) {
    int result = 0;
    int ch = charToNum(i);
    if ((ch <= ss) && (ch >= 0)) {
        result += ch * my_pow(ss, count);
    }
    else {
        result = -1;
    }
    return result;
}


long my_strtol(char* str, char** pEnd, int ss) {
    int count = strlen(str);
    int result = 0;
    int i = 0;
    int flag = 0;
    if ((str[0] == '0') && (str[1] == 'x')) {
        count = strlen(str);
        for (i = 2; i < count; i++) {
            if (fromCharToLong(str[i], 16, count - i - 1) != -1) {
                result += fromCharToLong(str[i], ss, count - i - 1);
            }
            else {
                result = 0;
                *pEnd = &str[i];
                flag = 1;
                break;
            }
        }
        str = fromIntToChar(result);
    }

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
    } //если 10-я
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
    } //проверка после ошибки

    if (str[0] != '-') return result;
    else return -result;
}

//0x32432 - 16-й
//0235252 - 8-й