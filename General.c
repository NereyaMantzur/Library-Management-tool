#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME 30


char* getStr() {
	char temp[MAX_NAME];
	fgets(temp, MAX_NAME, stdin);

	temp[strcspn(temp, "\n")] = '\0';

	char* str = malloc(strlen(temp) + 1);
	strcpy_s(str, sizeof(temp), temp);

	if (*str) {
		*str = toupper(*str);
		for (char* p = str + 1; *p; ++p) {
			*p = tolower(*p);
		}
	}

	return str;
}
