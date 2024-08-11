#ifndef LOAN_H
#define LOAN_H

#include "Date.h"
#include "List.h"

typedef enum {
    ONGOING,
    RETURNED,
    LATE
} Status;

typedef struct {
    struct Book* book;
    struct Member* member;
    Date dateOfReturn;
    Status status;
} Loan;

typedef struct {
    List loanList;
    int count;
} LoanManager;


LoanManager* initLoanManager();

#endif



