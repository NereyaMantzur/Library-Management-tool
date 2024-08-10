#include <stdio.h>
#include <stdlib.h>

#include "Publisher.h"
#include "General.h"



int initPublisher(Publisher* publisher)
{
	if (!publisher)
	{
		return 0;
	}
	printf("Please enter publisher name: \n");
	publisher->name = getStr();

	printf("Please enter publisher Email: \n");
	publisher->email = getStr();

	publisher->booksPublished = NULL;

	return 1;
}

void printPublisher(Publisher* publisher)
{
	printf("%s\n", publisher->name);
} 

void freePublisher(Publisher* publisher)
{
	free(publisher);
}