#include <stdio.h>
#include "Library.h"

int initLibrary(Library* library) {
	printf("initializing Library system\n");
	int book = initBookManager(&library->bookManager);
	int loan = initLoanManager(&library->loanManager);
	int member = initMemberManager(&library->memberManager);

	if (book && loan && member )
	{
		printf("system initialized succesfully\n");
		return 1;
	}
	printf("problem occured during system initialization\n");
	return 0;
}


