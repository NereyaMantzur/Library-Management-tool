#ifndef LOAN_H
#define LOAN_H

#include "MemberManager.h"
#include "BookManager.h"
#include "Date.h"
#include "List.h"

typedef enum {
   OVERDUE,ACTIVE
} Status;

struct Loan{
    Book* book;
    Member* member;
    Date dateOfReturn;
    Status status;
};

typedef struct {
    List loanList;
    int count;
} LoanManager;


LoanManager* initLoanManager();
Loan* initLoan();
void addNewLoan(BookManager* bookManager, LoanManager* loanManager, MemberManager* memberManager);
int loanBook(BookManager* bookManager, LoanManager* loanManager, Book* book, Member* member);
void returnBook(BookManager* bookManager, LoanManager* loanManager, MemberManager* memberManager);
Date* loan_30_Days();
int addLoanToLoanArr(Member* member, Loan* loan);
int removeLoanFromLoanArr(Member* member, Loan* loan);
void printLoan(Loan* loan);
void printLoanList(LoanManager* manager);



#endif // !LOAN_H



