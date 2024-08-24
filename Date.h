#ifndef DATE_H
#define DATE_H

typedef struct {
	int day;
	int month;
	int year;
} Date;

Date* initDate();
void printDate(const Date* date);
Date* add30DaysToCurrentTime(Date* date);

#endif // !DATE_H

