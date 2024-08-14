#define _CRT_SECURE_NO_WARNINGS
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
	newBook->author = initAuthor();
	
	return newBook;
}

int addNewBook(BookManager* manager)
{
	printf("\n========================================== Book adding ==========================================\n\n");

	manager->BookPtrArr = (Book**)realloc(manager->BookPtrArr, sizeof(Book*) * (manager->count + 1));
	if (!manager->BookPtrArr)
	{
		return 0;
	}
	Book* add = initBook();
	for (size_t i = 0; i < manager->count; i++)
	{
		if (compareBookByName(&add, &manager->BookPtrArr[i]) == 0)
		{
			handleError("Book already exists! \n\n");
			return 0;
		}
	}
	manager->BookPtrArr[manager->count] = add;
	manager->count++;
	printf("\n===================================== Book added succesfully! ===================================\n\n");
	return 1;
}

// what about the book that loand!!!
int removeBook(BookManager* manager)
{
	printf("\n========================================== Book removing ========================================\n\n");
	if (!printBookArr(manager->BookPtrArr, manager->count))
		return 0;
	printf("Please enter name of the book you want to remove: ");
	char* bookName = getStr();
	for (int i = 0; i < manager->count; i++)
	{
		if (strcmp(bookName,manager->BookPtrArr[i]->name) == 0)
		{
			swap(manager->BookPtrArr[i], manager->BookPtrArr[manager->count - 1]);
			freeBook(manager->BookPtrArr[manager->count - 1]);
			manager->count--;
			manager->BookPtrArr = (Book**)realloc(manager->BookPtrArr, manager->count * sizeof(Book*));
			printf("\n========================================= Book removed! =========================================\n\n");
			return 1;
		}
	}
	printf("\n====================================== Failed to remove book ====================================\n\n");
	return 0;
}

int printBookArr(const Book** bookPtrArr, int count)
{
	if (count == 0)
	{
		handleError("No books in the system!\n");
		return 0;
	}

	printf("#  |Book name           |Genre               |Author              |Available\n");
	for (int i = 0; i < count; i++)
	{
		printf("%-2d |", i + 1);
		printBook(bookPtrArr[i]);
	}
	return 1;
}

void printBook(const Book* book)
{
	if (!book)
	{
		return;
	}
	printf("%-20s|%-20d|%-20s|%d\n", book->name , book->genre , book->author->name,book->copiesAvailable );
}

void swap(Book* bookA, Book* bookB) {
	Book temp = *bookA;
	*bookA = *bookB;
	*bookB = temp;
}

void sortBooks(BookManager* manager) {
	int choice;
	printf("\n[1] - Sort books by name\n");
	printf("[2] - Sort books by genre\n");
	printf("[3] - Sort books by author\n");
	printf("Please enter your choice: ");
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		qsort(manager->BookPtrArr, manager->count, sizeof(Book*), compareBookByName);
		break;
	case 2:
		qsort(manager->BookPtrArr, manager->count, sizeof(Book*), compareBookByGenre);
		break;
	case 3:
		qsort(manager->BookPtrArr, manager->count, sizeof(Book*), compareBookByAuthor);
		break;
	default:
		handleError("Invalid choice!");
		break;
	}
		printBookArr(manager->BookPtrArr, manager->count);
}

Book* searchBook(BookManager* manager)
{
	Book* temp  = (Book*)malloc(sizeof(Book));
	int choice;
	Book** res = NULL;
	printf("\n[1] - search book by name\n");
	printf("[2] - search book by genre\n");
	printf("[3] - search book by author\n");
	printf("Please enter your choice: ");
	scanf_s("%d", &choice);
	getchar();
	switch (choice) {
	case 1:
		printf("Please enter the name of the book: ");
		temp->name =getStr();
		res = (Book**)bsearch(&temp,manager->BookPtrArr,manager->count,sizeof(Book*),compareBookByName);
		break;
	case 2:
		printf("Please enter the genre of the book: ");
		scanf_s("%d", &temp->genre);
		getchar();
		res = (Book**)bsearch(&temp, manager->BookPtrArr, manager->count, sizeof(Book*), compareBookByGenre);
		break;
	case 3:
		printf("Please enter the author of the book: ");
		strcpy(temp->author->name ,getStr());
		res = (Book**)bsearch(&temp, manager->BookPtrArr, manager->count, sizeof(Book*), compareBookByAuthor);
		break;
	default:
		handleError("Invalid choice!");
		break;
	}
	if (res)
	{
		printf("\nBook found!\n");
		printf("Book name           |Genre               |Author              |Available\n");
		printBook(*res);
		return *res;
	}
	handleError("Book not found!");
	return NULL;
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


int freeBook(Book* book)
{
	free(book);
	return 1;
}
