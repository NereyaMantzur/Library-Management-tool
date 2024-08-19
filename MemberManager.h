#ifndef MEMBER_H
#define MEMBER_H
#include <stdio.h>

#include "General.h"

#define MAX_BOOKS 5


typedef struct {
    char* name;
    int memberID;
    char phoneNumber[11];
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
int printMember(const Member* member);
void swapMembers(Member* memberA, Member* memberB);
char* initPhoneNumber();
int freeMember(Member* member);
char* initPhoneNumber();
int isValidPhone(char* phone);
int freeMember(Member* member);

int writeMemberManagerToText(FILE* file, MemberManager* manager);
int readMemberManagerFromText(const char* fName, MemberManager* manager);

int writeMemberManagerToBinary(char* fName, MemberManager* manager);
int readMemberManagerFromBinary(char* fName, MemberManager* manager);


#endif // !MEMBER_H


