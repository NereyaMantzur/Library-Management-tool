#ifndef MEMBER_H
#define MEMBER_H

#include "General.h"

#define MAX_BOOKS 5

// Forward declaration
typedef struct Loan Loan;

typedef struct {
    char* name;
    int memberID;
    char* phoneNumber;
    struct Loan* loanArr[MAX_BOOKS];
    int loanCount;
} Member;

typedef struct {
    Member* memberArr;
    int count;
    int nextID;
} MemberManager;

//functions
MemberManager* initMemberManager();
Member* initMember();
int addNewMember(MemberManager* manager);
int removeMember(MemberManager* manager);
int printMemberArr(const Member* memberArr, int count);
void printMember(const Member* member);
void swapMembers(Member* memberA, Member* memberB);
char* initPhoneNumber();
//int freeMember(Member* member);
char* initPhoneNumber();
int isValidPhone(char* phone);



#endif // !MEMBER_H


