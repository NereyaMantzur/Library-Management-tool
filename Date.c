#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>



int printTime() {
    char dateStr[11];

    time_t t = time(NULL);

    strftime(dateStr, sizeof(dateStr), "%d/%m/%Y", localtime(&t));

    printf("Current date: %s\n", dateStr);

    return 0;
}

int add30DaysToCurrentTime()
{
    char dateStr[11]; // Buffer to hold the date string

    time_t t = time(NULL); // Get the current time
    t += 30 * 24 * 60 * 60; // Add 30 days' worth of seconds to the current time

    // Format the new date as "dd/mm/yyyy" using the localtime directly
    strftime(dateStr, sizeof(dateStr), "%d/%m/%Y", localtime(&t));

    printf("Date after 30 days: %s\n", dateStr);

    return 0;
}