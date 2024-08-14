#include <stdio.h>
#include <stdlib.h>

#include "Author.h"
#include "General.h"

Author* initAuthor()
{
	Author* newAuthor = (Author*)malloc(sizeof(Author));
	if (!newAuthor)
	{
		return NULL;
	}

	printf("Please enter author name: ");
	newAuthor->name = getStr();
	newAuthor->head = NULL;
	return newAuthor;
}

int initBookNode()
{
	BookNode* bookNode = (BookNode*)malloc(sizeof(BookNode));
	if (!bookNode)
	{
		return 0;
	}
	bookNode->next = NULL;
	bookNode->prev = NULL;
	return 1;
}

void insert(Author* author, BookNode* bookNode)
{
	if (!author->head->next)
	{
		author->head->next = bookNode;
		bookNode->prev = author->head;
		bookNode->next = NULL;
		return;
	}
	BookNode* temp = author->head->next;
	author->head->next = bookNode;
	bookNode->prev = author->head;
	bookNode->next = temp;
	temp->prev = bookNode;
}

void printAuthor(Author* author)
{
	printf("%s", author->name);
}

void freeAuthor(Author* author)
{
	free(author);
}
