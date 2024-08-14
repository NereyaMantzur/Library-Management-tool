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
	newLoan->book = NULL;
	newLoan->member = NULL;
	newLoan->status = ACTIVE;
	newLoan->dateOfReturn = *initDate();
	return newLoan;
}

void addNewLoan(BookManager* bookManager, LoanManager* loanManager, MemberManager* memberManager)
{
	if (!printMemberArr(memberManager->memberArr, memberManager->count))
		return;	
	printf("To which member add a new loan: (#number)\n");
	int choice;
	scanf("%d", &choice);
	getchar();
	Book* book = searchBook(bookManager);
	if (book)
		loanBook(bookManager, loanManager, book, &memberManager->memberArr[choice - 1]);
}

int loanBook(BookManager* bookManager, LoanManager* loanManager, Book* book, Member* member)
{
	Loan* newLoan = initLoan();
	if (!newLoan)
	{
		return 0;
	}
	newLoan->book = book;
	(Member*)newLoan->member = member;
	newLoan->status = ACTIVE;
	add30DaysToCurrentTime(&newLoan->dateOfReturn);
	for (int i = 0; i < bookManager->count; i++)
	{
		if (!strcmp(book->name, bookManager->BookPtrArr[i]->name))
		{
			if (bookManager->BookPtrArr[i]->copiesAvailable > 0)
			{
				insertFirst(&loanManager->loanList, newLoan);
				bookManager->BookPtrArr[i]->copiesAvailable--;
				addLoanToLoanArr(member, newLoan);
				member->loanCount++;
				return 1;
			}
		}
	}
	free(newLoan);
	return 0;
}

void returnBook(BookManager* bookManager, LoanManager* loanManager, MemberManager* memberManager)
{
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

int removeLoanFromMember( LoanManager* loanManager,Book* book, Member* member)
{
	ListNode* head = loanManager->loanList.head->next;
	while (!head)
	{
		if (!strcmp(((Loan*)head->data)->book->name,book->name ))
		{
			deleteNode(&loanManager->loanList, head);
			for (int i = 0; i < MAX_BOOKS; i++)
			{
				if (!strcmp(member->loanArr[i]->book->name,book->name))
				{
					member->loanCount--;
					member->loanArr[i] = NULL;
					book->copiesAvailable++;
					return 1;
				}
			}
		}
		head = head->next;
	}
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

int removeLoanFromLoanArr(Member* member, Loan* loan)
{
	for (size_t i = 0; i < MAX_BOOKS; i++)
	{
		if (!strcmp(member->loanArr[i]->book->name, loan->book->name))
		{
			member->loanArr[i] = NULL;
			return 1;
		}
	}
	handleError("Maximum books allowed already reached!");
	return 0;
}

void printLoan(Loan* loan)
{
	if (!loan)
		return;
	switch (loan->status)
	{
	case OVERDUE:
		printf("%-15s|%-15s|", loan->member->name, loan->book->name);
		printDate(&loan->dateOfReturn);
		handleError("     |OVERDUE\n");
		break;
	case ACTIVE:
		printf("%-15s|%-15s|", loan->member->name, loan->book->name);
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

	printf("#  |Member name    |Book name      |Date of return |Status\n");
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
	printf("#  |Member name    |Book name      |Date of return |Status\n");
	for (int i = 0; i < MAX_BOOKS; i++)
	{
		printf("%-2d |", i + 1);
		printLoan(manager->memberArr[memberNumber - 1].loanArr[i]);
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