#include "Library.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "General.h"

#define LIBRARY_TEXT "libraryText.txt"
#define LIBRARY_BIN "libraryBin.bin"

void headMessage();
void PrintMenu();
void loadFile(const char* textFile, const char* binFile, Library* library);

//program starts here
int main()
{
	Library* library = initLibrary();
	headMessage();
	loadFile(LIBRARY_TEXT ,LIBRARY_BIN ,library);
	int choice;
	do {
		PrintMenu();
		scanf_s("%d", &choice);
		getchar();
		switch (choice) {
		case 1:
			addNewBook(library->bookManager);
			break;
		case 2:
			addNewMember(library->memberManager);
			break;
		case 3:
			addNewLoan(library->bookManager, library->loanManager, library->memberManager);
			break;
		case 4:
			removeBook(library->bookManager ,library->loanManager);
			break;
		case 5:
			removeMember(library->memberManager);
			break;
		case 6:
			returnBook(library->bookManager, library->loanManager, library->memberManager);
			break;
		case 7:
			sortBooks(library->bookManager);
			break;
		case 8:
			searchBook(library->bookManager);
			break;
		case 9:			
			printf("\n========================================== books available ======================================\n\n");
			printBookArr(library->bookManager->BookPtrArr, library->bookManager->count);
			break;
		case 10:
			printf("\n=========================================== Members list ========================================\n\n");
			printMemberArr(library->memberManager->memberArr,library->memberManager->count);
			break;
		case 11:
			printf("\n========================================== active loan list =====================================\n\n");
			printLoanList(library->loanManager);
			break;
		case 12:
			printf("not implemented yet \n");
			break;
		case 13:
			printf("not implemented yet \n");
			break;
		case 14:
			printf("closing program!\n");
			break;
		default:
			handleError("Not valid Choice!");
			break;
		}
		refreshLibraryLoans(library->loanManager);
		printf("\n");
	} while (choice != 14);
	writeLibraryToTextFile(LIBRARY_TEXT, library);
}

void headMessage()
{
	printf("###########################################################################\n");
	printf("############                                                   ############\n");
	printf("############          Library management System   V1.0         ############\n");
	printf("############                                                   ############\n");
	printf("############          Developed by:                            ############\n");
	printf("############          Nereya Mantzur & Simon Farber            ############\n");
	printf("############                                                   ############\n");
	printf("###########################################################################\n\n");
	printf("Press any key to continue...\n");
	_getch();
	system("cls");
}

void PrintMenu()
{
	printf("=========================================== Main menu ===========================================\n\n");
	printf("[1]  - Add New Book\n");             //DONE
	printf("[2]  - Add New Member\n");           //DONE
	printf("[3]  - Add New Loan\n");             //DONE
	printf("[4]  - Remove Book\n");              //DONE
	printf("[5]  - Remove Member\n");            //DONE
	printf("[6]  - Return a Book\n");            //DONE
	printf("[7]  - Sort books\n");               //DONE
	printf("[8]  - Search a Book\n");            //DONE
	printf("[9]  - Print All Available Books\n");//DONE
	printf("[10] - Print All Members\n");        //DONE
	printf("[11] - Print All Loaned Books\n");   //DONE
	printf("[12] - Print Popular Books\n");
	printf("[13] - Print books of a specific author\n");
	printf("[14] - Exit Program\n");
	printf("Please enter your choice: ");
}

void loadFile(const char* textFile,const char* binFile ,Library* library)
{
	int choice;
	do
	{
		printf("=========================================== Load menu ===========================================\n\n");
		printf("[1]  - Load system from a file\n");
		printf("[2]  - Exit\n");
		printf("Please enter your choice: ");
		scanf_s("%d", &choice);
		getchar();
		printf("=================================================================================================\n\n");
		switch (choice)
		{
		case 1:
			loadLibraryFromFile(textFile, binFile, library);
			break;
		case 2:
			return;
		default:
			handleError("Not valid choice! Try again!\n\n");
			break;
		}

	} while (1 && choice == 2);
}
