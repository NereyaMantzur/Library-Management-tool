#ifndef DATE_H
#define DATE_H

typedef unsigned int CompressedDate;

typedef struct {
	int day;
	int month;
	int year;
} Date;

Date* initDate();
void printDate(const Date* date);
Date* add30DaysToCurrentTime(Date* date);
CompressedDate compressDate(Date date);
Date decompressDate(CompressedDate compressed);
int readCompressedDateFromBinaryFile(FILE* file, CompressedDate* compressedDate);
int writeCompressedDateToBinaryFile(FILE* file, CompressedDate compressedDate);

#endif // !DATE_H

