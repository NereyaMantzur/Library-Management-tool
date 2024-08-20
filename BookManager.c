#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "BookManager.h"
#include "LoanManager.h"


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

Book* initBook(BookManager* manager)
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
	newBook->author = initAuthor(manager);
	insert(newBook->author, initAuthorBook(newBook));

	return newBook;
}

int freeBook(Book* title)
{
	free(title);
	return 1;
}

int addNewBook(BookManager* manager)
{
	printf("\n========================================== Book adding ==========================================\n\n");

	manager->BookPtrArr = (Book**)realloc(manager->BookPtrArr, sizeof(Book*) * (manager->count + 1));
	if (!manager->BookPtrArr)
	{
		return 0;
	}
	Book* add = initBook(manager);
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

int removeBook(BookManager* bookManager, LoanManager* loanManager)
{
	printf("\n========================================== Book removing ========================================\n\n");
	if (!printBookArr(bookManager->BookPtrArr, bookManager->count))
		return 0;
	printf("Please enter name of the book you want to remove: ");
	char* bookName = getStr();
	for (int i = 0; i < bookManager->count; i++)
	{
		if (isInLoanList(loanManager, bookName))
		{
			handleError("Book is loaned by one of the members");
			return 0;
		}
		if (strcmp(bookName, bookManager->BookPtrArr[i]->name) == 0)
		{
			swap(bookManager->BookPtrArr[i], bookManager->BookPtrArr[bookManager->count - 1]);
			freeBook(bookManager->BookPtrArr[bookManager->count - 1]);
			bookManager->count--;
			bookManager->BookPtrArr = (Book**)realloc(bookManager->BookPtrArr, bookManager->count * sizeof(Book*));
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
		handleError("No books in the system!");
		return 0;
	}

	printf("#  |Book name           |Genre               |Author              |Available\n");
	generalArrayFunction(bookPtrArr, count, printBook);
	return 1;
}

void printBook(const Book* title)
{
	if (!title)
	{
		return;
	}
	printf("%-20s|%-20d|%-20s|%d\n", title->name, title->genre, title->author->name, title->copiesAvailable);
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
	Book* temp = (Book*)malloc(sizeof(Book));
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
		temp->name = getStr();
		res = (Book**)bsearch(&temp, manager->BookPtrArr, manager->count, sizeof(Book*), compareBookByName);
		break;
	case 2:
		printf("Please enter the genre of the book: ");
		scanf_s("%d", &temp->genre);
		getchar();
		res = (Book**)bsearch(&temp, manager->BookPtrArr, manager->count, sizeof(Book*), compareBookByGenre);
		break;
	case 3:
		printf("Please enter the author of the book: ");
		strcpy(temp->author->name, getStr());
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

int compareBookByAuthor(const void* a, const void* b) 
{
	Book* bookA = *(Book**)a;
	Book* bookB = *(Book**)b;
	return strcmp(bookA->author->name, bookB->author->name);
}

int writeBookManagerToText(FILE* file, BookManager* manager) {
	Book** arr = manager->BookPtrArr;
	fprintf(file, "%d\n",manager->count);
	fprintf(file,"Book name           |Genre               |Author              |Available\n");
	for (size_t i = 0; i < manager->count; i++) {
		fprintf(file, "%-20s %-20d %-20s %d\n", arr[i]->name, arr[i]->genre, arr[i]->author->name, arr[i]->copiesAvailable);
		fputs("\n", file);
	}

	return 1;
}


int readBookManagerFromText(const char* fName, BookManager* manager)
{
	return 1;

}

int writeBookManagerToBinary(char* fName, BookManager* manager)
{
	return 1;


}

int readBookManagerFromBinary(char* fName, BookManager* manager)
{
	return 1;

}