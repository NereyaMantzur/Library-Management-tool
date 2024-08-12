#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H


#include "Publisher.h"
#include "Author.h"
#include "General.h"


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
	Publisher* publisher;
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
int removeBook(BookManager* manager);
void printBookArr(const Book** bookPtrArr, int count);
void printBook(const Book*);
int freeBook(Book* book);


void swap(Book* bookA, Book* bookB);
void sortBooks(BookManager* manager);
int compareBookByName(const void* a, const void* b);
int compareBookByGenre(const void* a, const void* b);
int compareBookByAuthor(const void* a, const void* b);

#endif // !BOOKMANAGER_H
