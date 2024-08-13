#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LoanManager.h"

LoanManager* initLoanManager()
{
	LoanManager* manager = (LoanManager*)malloc(sizeof(LoanManager));
	if (!manager)
	{
		return NULL;
	}
	manager->loanList = *initList();
	manager->count = 0;
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
	return newLoan;
}

Date* loan_30_Days()
{
	Date* newDate = (Date*)malloc(sizeof(Date));
	newDate->day = 10;
	newDate->month = 1;
	newDate->year = 2024;
	return newDate;
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
	newLoan->dateOfReturn = *loan_30_Days();
	for (int i = 0; i < bookManager->count; i++)
	{
		if (!strcmp(book->name, bookManager->BookPtrArr[i]->name))
		{
			if (bookManager->BookPtrArr[i]->copiesAvailable > 0)
			{
				insertFirst(&loanManager->loanList, newLoan);
				loanManager->count++;
				bookManager->BookPtrArr[i]->copiesAvailable--;
				addLoanToLoanArr(member, newLoan);
				return 1;
			}
		}
	}
	free(newLoan);
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