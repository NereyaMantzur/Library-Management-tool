#include <stdio.h>
#include <stdlib.h>
#include "Library.h"

Library* initLibrary() {
	Library* library = (Library*)malloc(sizeof(Library));
	if (!library)
	{
		printf("problem occured during system initialization\n");
		return NULL;
	}
	printf("initializing Library system\n");

	BookManager* book = initBookManager();
	LoanManager* loan = initLoanManager(library->loanManager);
	MemberManager* member = initMemberManager(library->memberManager);

	library->bookManager = book;
	library->loanManager = loan;
	library->memberManager = member;

	return library;
}


