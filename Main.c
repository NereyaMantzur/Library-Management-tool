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
			addNewMember(library->memberManager);
			break;
		case 4:
			removeMember(library->memberManager);
			break;
		case 5:
			printf("not implemented yet \n");
			break;
		case 6:
			printf("not implemented yet \n");
			break;
		case 7:
			sortBooks(library->bookManager);
			break;
		case 8:
			printf("not implemented yet \n");
			break;
		case 9:
			printf("not implemented yet \n");
			break;
		case 10:			
			printf("\n=============================== books available ===========================\n\n");
			printBookArr(library->bookManager->BookPtrArr, library->bookManager->count);
			break;
		case 11:
			printMemberArr(library->memberManager->memberArr,library->memberManager->count);
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
	printf("\t[1]  - Add New Book\n");             //DONE
	printf("\t[2]  - Remove Book\n");              //DONE
	printf("\t[3]  - Add New Member\n");           //DONE
	printf("\t[4]  - Remove Member\n");            //DONE
	printf("\t[5]  - Add New Loan\n");
	printf("\t[6]  - Return Book Loan\n");
	printf("\t[7]  - Sort books\n");
	printf("\t[8]  - Search a Book\n");
	printf("\t[9]  - Search a Member\n");
	printf("\t[10] - Print All Available Books\n");//DONE
	printf("\t[11] - Print All Members\n");        //DONE
	printf("\t[12] - Print All Loaned Books\n");
	printf("\t[13] - Print Popular Books\n");
	printf("\t[14] - Exit Program\n");
	printf("\tPlease enter your choice:");
}
