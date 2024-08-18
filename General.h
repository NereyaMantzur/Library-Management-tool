#ifndef GENERAL_H
#define GENERAL_H

#define MAX_NAME 30

#define RED_TEXT "\033[31m"
#define RESET_COLOR "\033[0m"

char* getStr();
void handleError(const char* message);
void generalArrayFunction(void** arr, int count, void (*func)(void* element));

#endif // !GENERAL_H

