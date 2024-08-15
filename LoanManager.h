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

struct LoanManager {
    List loanList;
};


LoanManager* initLoanManager();
Loan* initLoan();
void addNewLoan(BookManager* bookManager, LoanManager* loanManager, MemberManager* memberManager);
int loanBook(BookManager* bookManager, LoanManager* loanManager, Book* book, Member* member);
void returnBook(BookManager* bookManager, LoanManager* loanManager, MemberManager* memberManager);
int isInLoanList(LoanManager* loanManager, char* bookName);
int removeLoanFromMember(LoanManager* loanManager, Book* book, Member* member);
int addLoanToLoanArr(Member* member, Loan* loan);
int isLoanedByMember(Loan* loanArr[], Book* book);
void printLoan(Loan* loan);
void printLoanList(LoanManager* manager);
void printLoanArrOfMember(MemberManager* manager, int memberNumber);
int isOverdue(Date* date);
void freeLoan(Loan* loan);
int freeLoanArr(Loan* loanArr[]);



#endif // !LOAN_H



