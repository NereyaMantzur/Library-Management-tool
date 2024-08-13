#include <stdio.h>
#include <stdlib.h>

#include "Library.h"
#include "General.h"
#include "Date.h"


void headMessage();
void PrintMenu();

//program starts here
int main()
{
	printTime();
	add30DaysToCurrentTime();
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
			addNewMember(library->memberManager);
			break;
		case 4:
			removeMember(library->memberManager);
			break;
		case 5:
			addNewLoan(library->bookManager, library->loanManager, library->memberManager);
			break;
		case 6:
			printf("not implemented yet \n");
			break;
		case 7:
			sortBooks(library->bookManager);
			break;
		case 8:
			searchBook(library->bookManager);
			break;
		case 9:			
			printf("\n=============================== books available ===========================\n\n");
			printBookArr(library->bookManager->BookPtrArr, library->bookManager->count);
			break;
		case 10:
			printMemberArr(library->memberManager->memberArr,library->memberManager->count);
			break;
		case 11:
			printf("not implemented yet \n");
			break;
		case 12:
			printf("closing program!\n");
		break; 
		case 13:
			printf("closing program!\n");
			break;
		default:
			handleError("Not valid Choice!");
			break;
		}
		
		printf("\n");
	} while (choice != 13);
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
	getchar();
	system("cls");
}

void PrintMenu()
{
	printf("================================ Main menu ================================\n\n");
	printf("\t[1]  - Add New Book\n");             //DONE
	printf("\t[2]  - Remove Book\n");              //DONE
	printf("\t[3]  - Add New Member\n");           //DONE
	printf("\t[4]  - Remove Member\n");            //DONE
	printf("\t[5]  - Add New Loan\n");             //DONE
	printf("\t[6]  - Return Book Loan\n");
	printf("\t[7]  - Sort books\n");               //DONE
	printf("\t[8]  - Search a Book\n");            //DONE
	printf("\t[9] - Print All Available Books\n"); //DONE
	printf("\t[10] - Print All Members\n");        //DONE
	printf("\t[11] - Print All Loaned Books\n");
	printf("\t[12] - Print Popular Books\n");
	printf("\t[13] - Exit Program\n");
	printf("\tPlease enter your choice:");
}
