#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Author.h"
#include "General.h"
#include "BookManager.h"

Author* initAuthor(BookManager* bookManager)
{
	Author* newAuthor = (Author*)malloc(sizeof(Author));
	if (!newAuthor)
	{
		return NULL;
	}

	printf("Please enter author name: ");
	newAuthor->name = getStr();

	for (int i = 0; i < bookManager->count; i++)
	{
		if (strcmp(bookManager->bookPtrArr[i]->author->name, newAuthor->name) == 0)
		{
			insert(bookManager->bookPtrArr[i]->author, initAuthorBook(bookManager->bookPtrArr[i]));
			free(newAuthor);
			return bookManager->bookPtrArr[i]->author;
		}
	}

	newAuthor->headBook = NULL;
	return newAuthor;
}

AuthorBook* initAuthorBook(Book* book)
{
	AuthorBook* authorBook = (AuthorBook*)malloc(sizeof(AuthorBook));
	if (!book)
	{
		return NULL;
	}

	authorBook->title = book->name;
	authorBook->next = NULL;
	authorBook->prev = NULL;
	return authorBook;
}

void insert(Author* author, AuthorBook* title)
{
	if (!author->headBook)
	{
		author->headBook = title;
		title->next = NULL;
		title->prev = NULL;
		return;
	}

	title->next = author->headBook;
	title->prev = NULL;
	author->headBook->prev = title;
	author->headBook = title;
}

void printBooksOfAuthor(BookManager* manager)
{
	printf("\n========================================== author books =========================================\n\n");
	printf("\nPlease enter the name of the author: ");
	char* name = getStr();
	int isPrinted = 0;
	for (int i = 0, j = 1; i < manager->count; i++)
	{
		if (!strcmp(name, manager->bookPtrArr[i]->author->name))
		{
			printf("[%d] - ", j++);
			printAuthorBook(manager->bookPtrArr[i]->author->headBook);
			isPrinted = 1;
		}
	}
	if (!isPrinted)
	{
		handleError("Author not found");
	}
}

void printAuthorBook(AuthorBook* authorBook)
{
	printf("%s\n", authorBook->title);
}


void freeAuthor(Author* author)
{
	free(author);
}
