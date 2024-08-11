#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BookManager.h"


int initBookManager(BookManager* manager)
{
	manager = (BookManager*)malloc(sizeof(BookManager));
	if (!manager)
	{
		return 0;
	}
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
		default:
			break;
		}
	} while (choice != 2);
	return 1;
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
	printf("Please enter number of copies: ");
	initPublisher();
	return newBook;
}

int addNewBook(BookManager* manager)
{
	manager = (BookManager*)realloc(manager, sizeof(Book*) * (manager->count + 1));
	if (!manager)
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

int compareBookByName(void* bookA, void* bookB)
{
	Book* a = (Book*)bookA;
	Book* b = (Book*)bookB;
	return strcmp(a->name, b->name);
}