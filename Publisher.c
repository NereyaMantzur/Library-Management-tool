#include <stdio.h>
#include <stdlib.h>

#include "Publisher.h"
#include "General.h"



Publisher* initPublisher()
{
	Publisher* newPublisher = (Publisher*)malloc(sizeof(Publisher));
	if (!newPublisher)
	{
		return NULL;
	}
	printf("Please enter publisher name: \n");
	newPublisher->name = getStr();

	printf("Please enter publisher Email: \n");
	newPublisher->email = getStr();

	newPublisher->booksPublished = NULL;

	return newPublisher;
}

void printPublisher(Publisher* publisher)
{
	printf("%s\n", publisher->name);
} 

void freePublisher(Publisher* publisher)
{
	free(publisher);
}