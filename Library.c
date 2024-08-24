#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "Library.h"


Library* initLibrary()
{
	Library* library = (Library*)malloc(sizeof(Library));
	if (!library)
	{
		printf("problem occured during system initialization\n");
		return NULL;
	}
	printf("initializing Library system\n");

	library->bookManager = initBookManager();
	library->loanManager = initLoanManager();
	library->memberManager = initMemberManager();

	return library;
}

void refreshLibraryLoans(LoanManager* manager)
{
	ListNode* head = (manager->loanList).head->next;
	if (!head)
	{
		return;
	}
	while (!head)
	{
		if (isOverdue(&((Loan*)head->data)->dateOfReturn))
		{
			((Loan*)head->data)->status = OVERDUE;
		}
	}
}

void loadLibraryFromFile(const char* textFile, const char* binFile, Library* library)
{
	int choice;
	do
	{
		printf("=========================================== Load menu 2 =========================================\n\n");
		printf("[1]  - Load system from a text file\n");
		printf("[2]  - Load system from a binary file\n");
		printf("Please enter your choice: ");
		scanf("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1:
			readLibraryFromTextFile(textFile, library);
			printf("=================================================================================================\n\n");
			return;
		case 2:
			readLibraryFromBinFile(binFile, library);
			printf("=================================================================================================\n\n");
			return;
		case 3:
			printf("Exit\n");
			break;
		default:
			handleError("Not valid choice! Try again!\n\n");
			break;
		}
	} while (1);
}

int writeLibraryToTextFile(const char* textFile, Library* library)
{
	FILE* file = fopen(textFile, "w");
	if (!file)
	{
		return 0;
	}
	int books, members, loans;
	books = writeBookManagerToText(file, library->bookManager);
	members = writeMemberManagerToText(file, library->memberManager);
	loans = writeLoanManagerToText(file, library->loanManager);

	if (!books || !loans || !loans)
	{
		handleError("Problem occured during system writing the system\n");
		fclose(file);
		return 0;
	}
	return 1;
}

int readLibraryFromTextFile(const char* textFile, Library* library)
{
	FILE* file = fopen(textFile, "r");
	if (!file)
	{
		return 0;
	}
	int books, members, loans;
	books = readBookManagerFromText(file, library->bookManager);
	members = readMemberManagerFromText(file, library->memberManager);
	loans = readLoanManagerFromText(file, library->loanManager, library->bookManager, library->memberManager);

	if (!books || !members || !loans)
	{
		handleError("problem occured during system loading the system\n");
		return 0;
	}
	getMemberLoanArr(library->loanManager, library->memberManager);
	printf("Loading sucsessfull!\n");
	return 1;
}

int writeLibraryToBinFile(const char* binFile, Library* library)
{
	FILE* file = fopen(binFile, "wb");
	if (!file)
	{
		return 0;
	}
	int books, members, loans;
	books = writeBookManagerToBinary(file, library->bookManager);
	members = writeMemberManagerToBinary(file, library->memberManager);
	loans = writeLoanManagerToBinary(file, library->loanManager);

	if (!books || !loans || !loans)
	{
		handleError("Problem occured during system writing the system\n");
		fclose(file);
		return 0;
	}
	return 1;
}

int readLibraryFromBinFile(const char* binFile, Library* library)
{
	FILE* file = fopen(binFile, "rb");
	if (!file)
	{
		return 0;
	}
	int books, members, loans;
	books = readBookManagerFromBinary(file, library->bookManager);
	members = readMemberManagerFromBinary(file, library->memberManager);
	loans = readLoanManagerFromBinary(file, library->loanManager, library->bookManager, library->memberManager);

	if (!books || !loans || !loans)
	{
		handleError("problem occured during system loading the system\n");
		return 0;
	}
	printf("Loading sucsessfull!\n");
	return 1;
}


