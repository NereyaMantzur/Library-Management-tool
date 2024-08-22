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

Member* getMemberByID(MemberManager* memberManager ,int ID);

int writeMemberManagerToText(FILE* file, MemberManager* manager);
int readMemberManagerFromText(FILE* file, MemberManager* manager);

int writeMemberManagerToBinary(FILE* file, MemberManager* manager);
int readMemberManagerFromBinary(FILE* file, MemberManager* manager);


#endif // !MEMBER_H


