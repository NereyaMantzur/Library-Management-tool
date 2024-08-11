#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "BookManager.h"


BookManager* initBookManager( )
{
	BookManager* manager = (BookManager*)malloc(sizeof(BookManager));
	if (!manager)
	{
		return NULL;
	}
	manager->BookPtrArr = NULL;
	manager->count = 0;
	int choice;
	do
	{
		printf("[1] - Add new book\n");
		printf("[2] - Exit book initialization \n");
		printf("Please enter your choice: ");
		scanf_s("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:
			addNewBook(manager);
			break;
		case 2: 
			printf("Exiting books initialization\n");
			break;
		default:
			printf("Invalid choice!\n");
			break;
		}
	} while (choice != 2);
	return manager;
}

Book* initBook()
{
	Book* newBook = (Book*)malloc(sizeof(Book));
	if (!newBook)
	{
		return NULL;
	}
	printf("Please enter book name: ");
	newBook->name = getStr();
	printf("Please enter book genre: ");
	scanf_s("%d", &newBook->genre);
	getchar();
	printf("Please enter number of copies: ");
	scanf_s("%d", &newBook->copiesAvailable);
	getchar();
	newBook->publisher = initPublisher();
	newBook->author = initAuthor();
	
	return newBook;
}

int addNewBook(BookManager* manager)
{
	manager->BookPtrArr = (Book**)realloc(manager->BookPtrArr, sizeof(Book*) * (manager->count + 1));
	if (!manager->BookPtrArr)
	{
		return 0;
	}
	Book* add = initBook();
	for (size_t i = 0; i < manager->count; i++)
	{
		if (compareBookByName(add->name, manager->BookPtrArr[i]->name) == 0)
		{
			printf("book already exists! \n");
			return 0;
		}
	}
	manager->BookPtrArr[manager->count] = add;
	manager->count++;
	printf("Book added suuccesfully!\n");
	return 1;
}

int removeBook(BookManager* manager)
{
	if (!manager->BookPtrArr )
	{

	}
	printBookArr(manager->BookPtrArr, manager->count);
	printf("Please enter name of the book you want to remove: ");
	char* bookName = getStr();
	for (int i = 0; i < manager->count; i++)
	{
		if (strcmp(bookName,manager->BookPtrArr[i]->name) == 0)
		{
			swap(manager->BookPtrArr[i], manager->BookPtrArr[manager->count - 1]);
			freeBook(manager->BookPtrArr[manager->count - 1]);
			manager->count--;
			return 1;
		}
	}
	return 0;
}

void printBookArr(const Book** bookPtrArr, int count)
{
	if (count == 0)
	{
		printf("No books in the system!\n");
	}
	for (int i = 0; i < count; i++)
	{
		printBook(bookPtrArr[i]);
	}
}

void printBook(const Book* book)
{
	printf("%s \n", book->name);
}

int freeBook(Book* book)
{
	free(book);
	return 1;
}

void swap(Book* bookA,Book* bookB)
{
	Book* temp = bookA;
	bookA = bookB;
	bookB = temp;
}

int compareBookByName(void* bookA, void* bookB)
{
	Book* a = (Book*)bookA;
	Book* b = (Book*)bookB;
	return strcmp(a->name, b->name);
}