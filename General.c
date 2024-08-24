#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "General.h"


char* getStr() {
	char temp[MAX_NAME];
	fgets(temp, MAX_NAME, stdin);
	temp[strlen(temp) - 1] = '\0';

	char* str = (char*)malloc(strlen(temp));
	if (str) {
		strcpy(str, temp);
		str[0] = toupper(str[0]);
		for (int i = 1; str[i]; i++) {
			str[i] = tolower(str[i]);
		}
	}
	return str;
}


void handleError(const char* message) {
	fprintf(stderr, RED_TEXT "Error: %s\n" RESET_COLOR, message);
}

void generalArrayFunction(void** arr, int count, void (*func)(void* element))
{
	for (int i = 0; i < count; i++)
	{
		if (arr[i])
		{
			printf("%-2d |", i + 1);
		}
		func(arr[i]);
	}
}
