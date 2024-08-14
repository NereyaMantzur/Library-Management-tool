#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Date.h"

Date* initDate()
{
    Date* newDate = (Date*)malloc(sizeof(Date));
    if (!newDate)
    {
        return NULL;
    }

    newDate->day = 0;
    newDate->month = 0;
    newDate->year = 0;
    return newDate;
}

void printDate(const Date* date)
{

    printf("%2d/%2d/%4d", date->day,date->month,date->year);
}

Date* add30DaysToCurrentTime(Date* date)
{

    time_t t = time(NULL); // Get the current time
    struct tm currentTime = *localtime(&t); // Convert to local time structure

    // Add 30 days
    currentTime.tm_mday += 30;

    // Normalize the time structure (mktime will handle month/year overflow)
    mktime(&currentTime);

    date->day = currentTime.tm_mday;
    date->month = currentTime.tm_mon + 1;
    date->year = currentTime.tm_year + 1900;

    // Print the new date
    printf("Date After 30 Days: %02d/%02d/%04d\n", currentTime.tm_mday, currentTime.tm_mon + 1, currentTime.tm_year + 1900);

    return date;
}

