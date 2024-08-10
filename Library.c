#include <stdio.h>
#include "Library.h"

int initLibrary(Library* library) {
	printf("initializing Library system\n");
	int member = initMemberManager(&library->memberManager);
	int loan = initLoanManager(&library->loanManager);
	int book = initBookManager(&library->bookManager);
	if (member && book && loan)
	{
		printf("system initialized succesfully\n");
		return 1;
	}
	printf("problem occured during system initialization\n");
	return 0;
}


