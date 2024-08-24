#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H
#include <stdio.h>

#include "Author.h"
#include "General.h"

#define SETPOPULAR 1
#define ISPOPULARBOOK(X,Y) ((X) - (Y)) >= SETPOPULAR ? 1 : 0

// Forward declaration
typedef struct Loan Loan;
typedef struct LoanManager LoanManager;

typedef enum Genre
{
	SCIENCE_FICTION, MYSTERY, FANTASY, ROMANCE, HISTORICAL_FICTION
}Genre;

struct Book
{
	char* name;
	Genre genre;
	int copiesAvailable;
	int totalCopies;
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
Genre getGenre();



void swap(Book* bookA, Book* bookB);
void sortBooks(BookManager* manager);
Book* searchBook(BookManager* manager);
int compareBookByName(const void* a, const void* b);
int compareBookByGenre(const void* a, const void* b);
int compareBookByAuthor(const void* a, const void* b);

Book* getBookByTitle(BookManager* manager, char* bookTitle);
void printPopularBooks(BookManager* manager);


int writeBookManagerToText(FILE* file, BookManager* manager);
int readBookManagerFromText(FILE* file, BookManager* manager);

int writeBookManagerToBinary(FILE* file, BookManager* manager);
int readBookManagerFromBinary(FILE* file, BookManager* manager);
#endif // !BOOKMANAGER_H
