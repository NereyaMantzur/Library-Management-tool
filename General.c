#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "General.h"


char* getStr() {
    char temp[MAX_NAME];
    scanf_s("%s", temp, (unsigned)sizeof(temp));

    char* str = malloc(strlen(temp) + 1);
    if (str) {
        strcpy(str, temp);
        str[0] = toupper(str[0]);
        for (int i = 1; str[i]; i++)
            str[i] = tolower(str[i]);
    }

    return str;
}


void handleError(const char* message) {
    fprintf(stderr, RED_TEXT "Error: %s\n" RESET_COLOR, message);
}