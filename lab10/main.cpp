#include "lab10_lib.h"
#include <stdio.h>
#include "string.h"



int main() {
    char** main_code = readToMas("/Users/denis_adidas/CLionProjects/lab10/code.txt");
    char** time_lib = readToMas("/Users/denis_adidas/CLionProjects/lab10/time.txt");
    char** stdlib_lib = readToMas("/Users/denis_adidas/CLionProjects/lab10/stdlib.txt");
    char** stdio_lib = readToMas("/Users/denis_adidas/CLionProjects/lab10/stdio.txt");
    char** string_lib = readToMas("/Users/denis_adidas/CLionProjects/lab10/string.txt");
    FILE* f_header;
    f_header = fopen("/Users/denis_adidas/CLionProjects/lab10/code_h.txt", "r+");
    char** src_head = readToMas("/Users/denis_adidas/CLionProjects/lab10/code_h.txt");
    int flag_time = 0;
    int flag_stdlib = 0;
    int flag_stdio = 0;
    int flag_string = 0;

    int flag_time2 = 0;
    int flag_stdlib2 = 0;
    int flag_stdio2 = 0;
    int flag_string2 = 0;
    int i = 0;


//убрать лишние и добавить новые

    while (main_code[i] != NULL) {
        for (int j = 0; j < mas_len(time_lib); j++) {
            if (strcmp(main_code[i], time_lib[j]) == 0) flag_time = 1;
        }
        for (int j = 0; j < mas_len(stdlib_lib); j++) {
            if (strcmp(main_code[i], stdlib_lib[j]) == 0) flag_stdlib = 1;
        }
        for (int j = 0; j < mas_len(stdio_lib); j++) {
            if (strcmp(main_code[i], stdio_lib[j]) == 0) flag_stdio = 1;
        }
        for (int j = 0; j < mas_len(string_lib); j++) {
            if (strcmp(main_code[i], string_lib[j]) == 0) flag_string = 1;
        }
        i++;
    }
    i = 0;
    while (src_head[i] != NULL) {
        for (int j = 0; j < mas_len(time_lib); j++) {
            if (strcmp(src_head[i], time_lib[j]) == 0) flag_time2 = 1;
        }
        for (int j = 0; j < mas_len(stdlib_lib); j++) {
            if (strcmp(src_head[i], stdlib_lib[j]) == 0) flag_stdlib2 = 1;
        }
        for (int j = 0; j < mas_len(stdio_lib); j++) {
            if (strcmp(src_head[i], stdio_lib[j]) == 0) flag_stdio2 = 1;
        }
        for (int j = 0; j < mas_len(string_lib); j++) {
            if (strcmp(src_head[i], string_lib[j]) == 0) flag_string2 = 1;
        }
        i++;
    }

    fprintf(f_header, "#ifndef CODE_H\n"
                      "#define CODE_H\n");
    if (flag_time == 1) {
        fprintf(f_header, "#include <time.h> \n");
    }
    else if (flag_time2 == 1) {
        fprintf(f_header, "#include <time.h> //This library is never used\n");
    }

    if (flag_stdlib == 1) {
        fprintf(f_header, "#include <stdlib.h> \n");
    }
    else if (flag_stdlib2 == 1) {
        fprintf(f_header, "#include <stdlib.h> //This library is never used\n");
    }

    if (flag_stdio == 1) {
        fprintf(f_header, "#include <stdio.h> \n");
    }
    else if (flag_stdio2 == 1) {
        fprintf(f_header, "#include <stdio.h> //This library is never used\n");
    }

    if (flag_string == 1) {
        fprintf(f_header, "#include <string.h> \n");
    }
    else if (flag_string2 == 1) {
        fprintf(f_header, "#include <string.h> //This library is never used\n");
    }
    fprintf(f_header, "#endif ");

    return 0;
}
