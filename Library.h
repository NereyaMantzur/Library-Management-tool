#ifndef LIBRARY_H
#define LIBRARY_H

#include "BookManager.h"
#include "MemberManager.h"
#include "LoanManager.h"

typedef struct {
    BookManager* bookManager;
    LoanManager* loanManager;
    MemberManager* memberManager;
} Library;

int initLibrary(Library* library);
#endif

