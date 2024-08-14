#ifndef LIBRARY_H
#define LIBRARY_H

#include "BookManager.h"
#include "MemberManager.h"
#include "LoanManager.h"

// Define Library structure
typedef struct {
    BookManager* bookManager;
    LoanManager* loanManager;
    MemberManager* memberManager;
} Library;

// Function declarations
Library* initLibrary();
void refreshLibraryLoans(LoanManager* manager);

#endif // LIBRARY_H


