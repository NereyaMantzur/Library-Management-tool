#include <stdio.h>
#include <stdlib.h>
#include "BookManager.h"
#include "General.h"


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
	return 1;
}