#ifndef LOAN_H
#define LOAN_H

#include "BookManager.h"
#include "MemberManager.h"
#include "Date.h"

typedef enum {
    ONGOING,
    RETURNED,
    LATE
} Status;

typedef struct {
    Book* book;
    Member* member;
    Date dateOfReturn;
    Status status;
} Loan;

typedef struct {
    Loan* loanList;
    int count;
} LoanManager;


initLoanManager(LoanManager* manager);

#endif



