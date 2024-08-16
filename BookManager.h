#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H


#include "Author.h"
#include "General.h"
//#include "LoanManager.h"

// Forward declaration
typedef struct Loan Loan;
typedef struct LoanManager LoanManager;
typedef enum Genre
{
SCIENCE_FICTION,MYSTERY,FANTASY,ROMANCE,HISTORICAL_FICTION
}Genre;

typedef struct Book
{
	char* name;
	Genre genre;
	int copiesAvailable;
	Author* author;
	//Publisher* publisher;
}Book;

typedef struct BookManager
{
	Book** BookPtrArr;
	int count;
}BookManager;

//functions

BookManager* initBookManager();
Book* initBook();
int addNewBook(BookManager* manager);
int removeBook(BookManager* manager, LoanManager* loanManager);
int printBookArr(const Book** bookPtrArr, int count);
void printBook(const Book*);
int freeBook(Book* book);


void swap(Book* bookA, Book* bookB);
void sortBooks(BookManager* manager);
Book* searchBook(BookManager* manager);
int compareBookByName(const void* a, const void* b);
int compareBookByGenre(const void* a, const void* b);
int compareBookByAuthor(const void* a, const void* b);

int writeBookManagerToText(char* fName, int count, BookManager* manager);
Book** readBookManagerFromText(char* fName, BookManager* manager);
int writeBookManagerToBinary(char* fName, int count, BookManager* manager);
Book** readBookManagerFromBinary(char* fName, BookManager* manager);
#endif // !BOOKMANAGER_H
