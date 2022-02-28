//
// Created by Денис Адидас on 2/18/22.
//

#include <algorithm>
#include <math.h>
#include "my_lab.h"

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
long my_strtol(char* str, char** pEnd, int ss) {
    int count = strlen(str);
    int result = 0;
    int i = 0;
    if (str[0] = '-') i = 1;
    for (i; i < count; i++) {
        int exam_l = (int)(str[i] - 'A');
        int exam_n = (int)(str[i] - '0');

        if ((isSymb(str[i])) && (exam_l < ss) && (exam_l >= 0)) {
            result += (((int)(str[i] - 'A')) + 10) * pow(ss, count - i - 1);
        }
        else if ((isNumber(str[i])) && (exam_n < ss) && (exam_n >= 0)) {
            result += ((int)(str[i]) - '0') * pow(ss, count - i - 1);
        }
        else {
            *pEnd = &str[i];
            printf("Error: symbol not belong notation \n");
            return 0;
        }
    }
    if (str[0] != '-') return result;
    else return -result;
}
