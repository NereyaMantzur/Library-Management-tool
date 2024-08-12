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
			printf("\nExiting books initialization\n");
			break;
		default:
			printf("\nInvalid choice!\n");
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
	printf("\n=============================== Book adding ===============================\n\n");

	manager->BookPtrArr = (Book**)realloc(manager->BookPtrArr, sizeof(Book*) * (manager->count + 1));
	if (!manager->BookPtrArr)
	{
		return 0;
	}
	Book* add = initBook();
	for (size_t i = 0; i < manager->count; i++)
	{
		if (compareBookByName(add, manager->BookPtrArr[i]) == 0)
		{
			printf("Book already exists! \n\n");
			return 0;
		}
	}
	manager->BookPtrArr[manager->count] = add;
	manager->count++;
	printf("\n========================== Book added suuccesfully! =======================\n\n");
	return 1;
}

// what about the book that loand!!!
int removeBook(BookManager* manager)
{
	printf("\n=============================== Book removing =============================\n\n");
	if (!manager->BookPtrArr )
	{

	}
	printf("\n- Books in the system:\n\n");
	printBookArr(manager->BookPtrArr, manager->count);
	printf("Please enter name of the book you want to remove: ");
	char* bookName = getStr();
	for (int i = 0; i < manager->count - 1; i++)
	{
		if (strcmp(bookName,manager->BookPtrArr[i]->name) == 0)
		{
			swap(manager->BookPtrArr[i], manager->BookPtrArr[manager->count - 1]);
			freeBook(manager->BookPtrArr[manager->count - 1]);
			manager->count--;
			printf("\n================================ Book removed! ==============================\n\n");
			return 1;
		}
	}
	printf("\n============================ Failed to remove book ==========================\n\n");
	return 0;
}

void sortBooks(BookManager* manager) {
	int choice;
	printf("[1] Sort books by name\n");
	printf("[2] Sort books by genre\n");
	printf("[3] Sort books by author\n");
	printf("Please enter your choice: ");
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		qsort(manager->BookPtrArr, manager->count, sizeof(Book*), compareBookByName);
		printBookArr(manager->BookPtrArr, manager->count);
		break;
	case 2:
		qsort(manager->BookPtrArr, manager->count, sizeof(Book*), compareBookByGenre);
		printBookArr(manager->BookPtrArr, manager->count);
		break;
	case 3:
		qsort(manager->BookPtrArr, manager->count, sizeof(Book*), compareBookByAuthor);
		printBookArr(manager->BookPtrArr, manager->count);
		break;
	default:
		handleError("Invalid choice!");
		break;
	}
}


int compareBookByName(const void* a, const void* b) {
	Book* bookA = *(Book**)a;
	Book* bookB = *(Book**)b;
	return strcmp(bookA->name, bookB->name);
}

int compareBookByGenre(const void* a, const void* b) {
	Book* bookA = *(Book**)a;
	Book* bookB = *(Book**)b;
	return bookA->genre - bookB->genre;
}

int compareBookByAuthor(const void* a, const void* b) {
	Book* bookA = *(Book**)a;
	Book* bookB = *(Book**)b;
	return strcmp(bookA->author->name, bookB->author->name);
}



void printBookArr(const Book** bookPtrArr, int count)
{
	if (count == 0)
	{
		printf("No books in the system!\n");
		return;
	}

	printf("#  |Book name      |Genre          |Author         |Publisher      |Available\n");
	for (int i = 0; i < count; i++)
	{
		printf("%-2d |", i + 1);
		printBook(bookPtrArr[i]);
	}
}

void printBook(const Book* book)
{
	printf("%-15s|%-15d|%-15s|%-15s|%d\n", book->name , book->genre , book->author->name,book->publisher->name,book->copiesAvailable );
}

int freeBook(Book* book)
{
	free(book);
	return 1;
}

void swap(Book* bookA, Book* bookB) {
	Book temp = *bookA;
	*bookA = *bookB;
	*bookB = temp;
}