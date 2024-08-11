#ifndef MEMBER_H
#define MEMBER_H

// Forward declaration
struct Loan;

typedef struct {
    char* name;
    int memberID;
    char* phoneNumber;
    struct Loan* loanArr[5];
} Member;

typedef struct {
    Member* memberArr;
    int count;
} MemberManager;

MemberManager* initMemberManager();

#endif


