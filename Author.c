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
	newAuthor->next = NULL;
	newAuthor->prev = NULL;
	return newAuthor;
}


void insert(Author* author , Author* book)
{
	if (!author->next)
	{
		author->next = book;
		book->prev = author;
		book->next = NULL;
		return;
	}
// FIX 
}

void printAuthor(Author* author)
{
	printf("%s", author->name);
}

void freeAuthor(Author* author)
{
	free(author);
}
