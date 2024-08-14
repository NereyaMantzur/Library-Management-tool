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


