#ifndef LOAN_H
#define LOAN_H

#include "BookManager.h"
#include "MemberManager.h"
#include "Date.h"
#include "List.h"

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
    List loanList;
    int count;
} LoanManager;


int initLoanManager(LoanManager* manager);

#endif



