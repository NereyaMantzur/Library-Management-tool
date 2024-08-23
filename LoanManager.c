#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "LoanManager.h"

LoanManager* initLoanManager()
{
	LoanManager* manager = (LoanManager*)malloc(sizeof(LoanManager));
	if (!manager)
	{
		return NULL;
	}
	manager->loanList = *initList();
	return manager;
}

Loan* initLoan()
{
	Loan* newLoan = (Loan*)malloc(sizeof(Loan));
	if (!newLoan)
	{
		return NULL;
	}
	newLoan->title = NULL;
	newLoan->member = NULL;
	newLoan->status = ACTIVE;
	newLoan->dateOfReturn = *initDate();
	return newLoan;
}

void addNewLoan(BookManager* bookManager, LoanManager* loanManager, MemberManager* memberManager)
{
	printf("\n========================================== Loan adding ==========================================\n\n");
	if (!printMemberArr(memberManager->memberArr, memberManager->count))
		return;	
	printf("To which member add a new loan (#number): ");
	int choice;
	scanf("%d", &choice);
	getchar();
	Book* title = searchBook(bookManager);
	if (title && !isLoanedByMember(memberManager->memberArr[choice - 1].loanArr , title))
		loanBook(bookManager, loanManager, title, &memberManager->memberArr[choice - 1]);
}

int loanBook(BookManager* bookManager, LoanManager* loanManager, Book* title, Member* member)
{
	Loan* newLoan = initLoan();
	if (!newLoan)
	{
		return 0;
	}
	newLoan->title = title;
	(Member*)newLoan->member = member;
	newLoan->status = ACTIVE;
	for (int i = 0; i < bookManager->count; i++)
	{
		if (!strcmp(title->name, bookManager->BookPtrArr[i]->name))
		{
			if (bookManager->BookPtrArr[i]->copiesAvailable > 0)
			{
				insertFirst(&loanManager->loanList, newLoan);
				bookManager->BookPtrArr[i]->copiesAvailable--;
				addLoanToLoanArr(member, newLoan);
				member->loanCount++;
				add30DaysToCurrentTime(&newLoan->dateOfReturn);
				printf("\n==================================== Book loaned succesfully! ===================================\n\n");

				return 1;
			}
		}
	}
	printf("\n======================================= No available books ======================================\n\n");
	free(newLoan);
	return 0;
}

void returnBook(BookManager* bookManager, LoanManager* loanManager, MemberManager* memberManager)
{
	printf("\n========================================= Book returning ========================================\n\n");
	int memberNumber;
	int bookNumber;
	printMemberArr(memberManager->memberArr , memberManager->count);
	printf("Which member want to return a book (#): ");
	scanf("%d", &memberNumber);
	getchar();
	printLoanArrOfMember(memberManager, memberNumber);
	printf("Which book is returned (#): ");
	scanf("%d", &bookNumber);
	getchar();
	removeLoanFromMember( loanManager,bookManager->BookPtrArr[bookNumber - 1], &memberManager->memberArr[memberNumber -1]);
}

int removeLoanFromMember( LoanManager* loanManager,Book* title, Member* member)
{
	ListNode* head = loanManager->loanList.head->next;
	while (head)
	{
		if (!strcmp(((Loan*)head->data)->title->name,title->name ))
		{
			deleteNode(&loanManager->loanList, head);
			for (int i = 0; i < MAX_BOOKS; i++)
			{
				if (!strcmp(member->loanArr[i]->title->name,title->name))
				{
					member->loanCount--;
					//removeLoanFromLoanArr(member, (Loan*)head->data);
					title->copiesAvailable++;
					printf("\n======================================== Book returned! ========================================\n\n");
					return 1;
				}
			}
		}
		head = head->next;
	}
	printf("\n====================================== Failed to return book ====================================\n\n");
	return 0;
}

int addLoanToLoanArr(Member* member, Loan* loan)
{
	for (size_t i = 0; i < MAX_BOOKS; i++)
	{
		if (!member->loanArr[i])
		{
			member->loanArr[i] = loan;
			return 1;
		}
	}
	handleError("Maximum books allowed already reached!");
	return 0;
}


int isLoanedByMember(Loan* loanArr[], Book* title)
{
	for (int i = 0; i < MAX_BOOKS; i++) {
		if (loanArr[i] && strcmp(loanArr[i]->title->name, title->name) == 0) {
			handleError("Already loaned by this member");
			return 1;
		}
	}
	return 0;
}

int isInLoanList(LoanManager* loanManager,char* bookName)
{
	ListNode* head = loanManager->loanList.head->next;
	while (head)
	{
		Loan* loan = (Loan*)head->data;
		if (!strcmp(loan->title->name,bookName))
		{
			return 1;
		}
		head = head->next;
	}
	return 0;
}

void printLoan(Loan* loan)
{
	if (!loan || !loan->title)
		return;
	switch (loan->status)
	{
	case OVERDUE:
		printf("%-15d|%-15s|", loan->member->memberID, loan->title->name);
		printDate(&loan->dateOfReturn);
		handleError("     |OVERDUE\n");
		break;
	case ACTIVE:
		printf("%-15d|%-15s|", loan->member->memberID, loan->title->name);
		printDate(&loan->dateOfReturn);
		printf("     |ACTIVE\n");
		break;
	default:
		break;
	}
}

void printLoanList(LoanManager* manager)
{
	ListNode* head = manager->loanList.head->next;
	int i = 1;
	if (!head)
	{
		handleError("No loans yet!\n");
		return;
	}

	printf("#  |Member ID      |Book name      |Date of return |Status\n");
	while (head)
	{
		printf("%-2d |", i );
		printLoan((Loan*)head->data);
		head = head->next;
		i++;
	}
}

void printLoanArrOfMember(MemberManager* manager, int memberNumber)
{
	if (manager->memberArr[memberNumber - 1].loanCount == 0)
	{
		printf("Member did not loaned books yet!\n");
	}
	printf("#  |Member ID      |Book name      |Date of return |Status\n");
	for (int i = 0; i < MAX_BOOKS; i++)
	{
		if (manager->memberArr[memberNumber - 1].loanArr[i])
		{
			printf("%-2d |", i + 1);
			printLoan(manager->memberArr[memberNumber - 1].loanArr[i]);
		}
	}
}

int isOverdue(Date* date)
{
	time_t t = time(NULL); // Get the current time
	struct tm currentTime = *localtime(&t); // Convert to local time structure
	int day = currentTime.tm_mday;
	int month = currentTime.tm_mon + 1;
	int year = currentTime.tm_year + 1900;

	if (year > date->year || month > date->month || year > date->day)
	{
		return 1;
	}
	return 0;
}

void freeLoan(Loan* loan) 
{
	if (loan) 
	{
		free(&loan->dateOfReturn);
		free(loan);
	}
}

int freeLoanArr(Loan* loanArr[])
{
	generalArrayFunction(loanArr, MAX_BOOKS, freeLoan);
	return 1;
}

Status getStatus(char* status)
{
	if (!strcmp(status , "ACTIVE"))
	{
		return ACTIVE;
	}
	else
	{
		return OVERDUE;
	}
}


int writeLoanManagerToText(FILE* file, LoanManager * manager)
{
	int count = 0;
	ListNode* head = manager->loanList.head->next;
	while (head)
	{
		count++;
		head = head->next;
	}
	head = manager->loanList.head->next;
	fprintf(file, "%d\n", count);
	fprintf(file, "Member ID      |Book name      |Date of return |Status\n");
	Loan* loan;
	while (head)
	{
		loan = (Loan*)head->data;
		switch (loan->status)
		{
		case OVERDUE:
			fprintf(file,"%-15d %-15s ", loan->member->memberID, loan->title->name);
			fprintf(file,"%2d %2d %4d", loan->dateOfReturn.day, loan->dateOfReturn.month, loan->dateOfReturn.year);
			fprintf(file,"      OVERDUE\n");
			break;
		case ACTIVE:
			fprintf(file,"%-15d %-15s ", loan->member->memberID, loan->title->name);
			fprintf(file, "%2d %2d %4d", loan->dateOfReturn.day, loan->dateOfReturn.month, loan->dateOfReturn.year);
			fprintf(file,"      ACTIVE\n");
			break;
		default:
			break;
		}
		head = head->next;
	}
	return 1;
}

int readLoanManagerFromText(FILE* file, LoanManager* loanManager, BookManager* bookManager, MemberManager* memberManager)
{
	int count;
	fscanf(file, "%d", &count);
	loanManager->loanList = *initList();
	loanManager->loanList.head = initListNode();

	char buffer[256];
	fgets(buffer, sizeof(buffer), file);
	fgets(buffer, sizeof(buffer), file);

	ListNode* head = loanManager->loanList.head;
	while (head)
	{
		head->data = initLoan();
		int memberID, day, month, year;
		char bookTitle[256], status[256];
		Loan* temp = (Loan*)head->data;
		if (!temp)
		{
			return 0;
		}

		fscanf(file, "%d", &memberID);
		fscanf(file, "%s", bookTitle);
		fscanf(file, "%d", &day);
		fscanf(file, "%d", &month);
		fscanf(file, "%d", &year);
		fscanf(file, "%s", &status);

		temp->member = getMemberByID(memberManager, memberID);
		temp->title = getBookByTitle(bookManager, bookTitle);
		temp->dateOfReturn.day = day;
		temp->dateOfReturn.month = month;
		temp->dateOfReturn.year = year;
		temp->status = getStatus(status);

		head = head->next;
		insertFirst(&loanManager->loanList, temp);
	}
	return 1;
}


int writeLoanManagerToBinary(FILE* file, LoanManager* manager)
{
	int count = 0;
	ListNode* head = manager->loanList.head->next;

	while (head)
	{
		count++;
		head = head->next;
	}

	fwrite(&count, sizeof(int), 1, file);

	head = manager->loanList.head->next;

	while (head)
	{
		Loan* temp = (Loan*)head->data;

		fwrite(&temp->member->memberID, sizeof(int), 1, file);

		int nameLength = (int)strlen(temp->title->name);
		fwrite(&nameLength, sizeof(int), 1, file);
		fwrite(temp->title->name, sizeof(char), nameLength, file);

		fwrite(&temp->dateOfReturn, sizeof(Date), 1, file);
		fwrite(&temp->status, sizeof(int), 1, file);

		head = head->next;
	}

	return 1;
}

int readLoanManagerFromBinary(FILE* file, LoanManager* loanManager, BookManager* bookManager, MemberManager* memberManager)
{
	int count = 0;

	if (fread(&count, sizeof(int), 1, file) != 1) {
		return 0;
	}

	loanManager->loanList = *initList();

	for (int i = 0; i < count; i++) {
		Loan* temp = initLoan();
		if (!temp) {
			return 0;
		}

		int memberID;
		if (fread(&memberID, sizeof(int), 1, file) != 1) {
			free(temp);
			return 0;
		}
		temp->member = getMemberByID(memberManager, memberID);
		if (!temp->member) {
			free(temp);
			return 0;
		}

		int nameLength;
		if (fread(&nameLength, sizeof(int), 1, file) != 1) {
			free(temp);
			return 0;
		}

		temp->title = (Book*)malloc(sizeof(Book));
		if (!temp->title) {
			free(temp);
			return 0;
		}

		temp->title->name = (char*)malloc(nameLength + 1);
		if (!temp->title->name) {
			free(temp->title);
			free(temp);
			return 0;
		}

		if (fread(temp->title->name, sizeof(char), nameLength, file) != (size_t)nameLength) {
			free(temp->title->name);
			free(temp->title);
			free(temp);
			return 0;
		}
		temp->title->name[nameLength] = '\0';

		temp->title = getBookByTitle(bookManager, temp->title->name);
		if (!temp->title) {
			free(temp->title->name);
			free(temp->title);
			free(temp);
			return 0;
		}

		if (fread(&temp->dateOfReturn, sizeof(Date), 1, file) != 1) {
			free(temp->title->name);
			free(temp->title);
			free(temp);
			return 0;
		}

		if (fread(&temp->status, sizeof(Status), 1, file) != 1) {
			free(temp->title->name);
			free(temp->title);
			free(temp);
			return 0;
		}

		insertFirst(&loanManager->loanList, temp);
	}

	return 1;
}
