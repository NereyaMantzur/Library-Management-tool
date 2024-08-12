#include <stdio.h>

#include "Library.h"
#include "General.h"


void headMessage();
void PrintMenu();

//program starts here
int main()
{
	headMessage();
	Library* library = initLibrary();

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
			removeBook(library->bookManager);
			break;
		case 3:
			printf("not implemented yet \n");
			break;
		case 4:
			printf("not implemented yet \n");
			break;
		case 5:
			printf("not implemented yet \n");
			break;
		case 6:
			printf("not implemented yet \n");
			break;
		case 7:
			printf("not implemented yet \n");
			break;
		case 8:
			printf("not implemented yet \n");
			break;
		case 9:
			sortBooks(library->bookManager);
			break;
		case 10:			
			printf("\n=============================== books available ===========================\n\n");
			printBookArr(library->bookManager->BookPtrArr, library->bookManager->count);
			break;
		case 11:
			printf("not implemented yet \n");
			break;
		case 12:
			printf("not implemented yet \n");
			break;
		case 13:
			printf("closing program!\n");
		break; 
		case 14:
			printf("closing program!\n");
			break;
		default:
			handleError("Not valid Choice!");
			break;
		}
		
		printf("\n");
	} while (choice != 14);
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

}

void PrintMenu()
{
	printf("================================ Main menu ================================\n\n");
	printf("   [1]  - Add New Book\n");
	printf("   [2]  - Remove Book\n");
	printf("   [3]  - Add New Member\n");
	printf("   [4]  - Remove Member\n");
	printf("   [5]  - Add New Loan\n");
	printf("   [6]  - Return Book Loan\n");
	printf("   [7]  - Sort books\n");
	printf("   [8]  - Search a Book\n");
	printf("   [9]  - Search a Member\n");
	printf("   [10] - Print All Available Books\n");
	printf("   [11] - Print All Loaned Books\n");
	printf("   [12] - Print All Members\n");
	printf("   [13] - Print Popular Books\n");
	printf("   [14] - Exit Program\n");
	printf(" Please enter your choice:");
}
