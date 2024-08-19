#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H
#include <stdio.h>

#include "Author.h"
#include "General.h"

// Forward declaration
typedef struct Loan Loan;
typedef struct LoanManager LoanManager;
typedef enum Genre
{
SCIENCE_FICTION,MYSTERY,FANTASY,ROMANCE,HISTORICAL_FICTION
}Genre;

struct Book
{
	char* name;
	Genre genre;
	int copiesAvailable;
	Author* author;
};

struct BookManager
{
	Book** BookPtrArr;
	int count;
};

//functions

BookManager* initBookManager();
Book* initBook(BookManager* manager);
int addNewBook(BookManager* manager);
int removeBook(BookManager* manager, LoanManager* loanManager);
int printBookArr(const Book** bookPtrArr, int count);
void printBook(const Book*);
int freeBook(Book* title);


void swap(Book* bookA, Book* bookB);
void sortBooks(BookManager* manager);
Book* searchBook(BookManager* manager);
int compareBookByName(const void* a, const void* b);
int compareBookByGenre(const void* a, const void* b);
int compareBookByAuthor(const void* a, const void* b);

int writeBookManagerToText(FILE* file, BookManager* manager);
int readBookManagerFromText(const char* fName, BookManager* manager);
int writeBookManagerToBinary(char* fName, BookManager* manager);
int readBookManagerFromBinary(char* fName, BookManager* manager);
#endif // !BOOKMANAGER_H
