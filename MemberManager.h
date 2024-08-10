#ifndef MEMBER_H
#define MEMBER_H

// Forward declaration
struct Loan;

typedef struct {
    char* name;
    int memberID;
    char* phoneNumber;
    struct Loan* loanArr[5];  // Use forward declaration here
} Member;

typedef struct {
    Member* listOfMembers;
    int count;
} MemberManager;

int initMemberManager(MemberManager* manager);

#endif


