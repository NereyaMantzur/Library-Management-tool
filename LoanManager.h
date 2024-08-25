#ifndef LOAN_H
#define LOAN_H
#include <stdio.h>

#include "MemberManager.h"
#include "BookManager.h"
#include "Date.h"
#include "List.h"


typedef enum {
	OVERDUE, ACTIVE
} Status;

struct Loan {
	Book* title;
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
int loanBook(BookManager* bookManager, LoanManager* loanManager, Book* title, Member* member);
void returnBook(BookManager* bookManager, LoanManager* loanManager, MemberManager* memberManager);
int isInLoanList(LoanManager* loanManager, char* bookName);
int removeLoanFromMember(LoanManager* loanManager, Book* title, Member* member);
int addLoanToLoanArr(Member* member, Loan* loan);
int isLoanedByMember(Loan* loanArr[], Book* title);
void printLoan(Loan* loan);
void printLoanList(LoanManager* manager);
int printLoanArrOfMember(MemberManager* manager, int memberNumber);
int isOverdue(Date* date);
void freeLoan(Loan* loan);
int freeLoanArr(Loan* loanArr[]);
void getMemberLoanArr(LoanManager* loanManager, MemberManager* memberManager);


int writeLoanManagerToText(FILE* file, LoanManager* manager);
int readLoanManagerFromText(FILE* file, LoanManager* loanManager, BookManager* bookManager, MemberManager* memberManager);

int writeLoanManagerToBinary(FILE* file, LoanManager* manager);
int readLoanManagerFromBinary(FILE* file, LoanManager* loanManager, BookManager* bookManager, MemberManager* memberManager);



#endif // !LOAN_H



