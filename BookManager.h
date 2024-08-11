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
	Author author;
	Publisher publisher;
}Book;

typedef struct BookManager
{
	Book** BookPtrArr;
	int count;
}BookManager;

//functions

int initBookManager(BookManager* manager);
Book* initBook();
int addNewBook(BookManager* manager);

int compareBookByName(void* bookA, void* bookB);

#endif // !BOOKMANAGER_H
