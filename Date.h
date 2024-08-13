#ifndef DATE_H
#define DATE_H

typedef struct {
    int day;
    int month;
    int year;
} Date;

int printTime();
int add30DaysToCurrentTime();

#endif // !DATE_H

