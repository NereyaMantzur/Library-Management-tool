#ifndef LIBRARY_H
#define LIBRARY_H

#include "BookManager.h"
#include "MemberManager.h"
#include "LoanManager.h"

// Define Library structure
typedef struct {
    BookManager* bookManager;
    LoanManager* loanManager;
    MemberManager* memberManager;
} Library;

// Function declarations
Library* initLibrary();
void refreshLibraryLoans(LoanManager* manager);
void loadLibraryFromFile(const char* textFile, const char* binFile, Library* library);

int writeLibraryToTextFile(const char* textFile, Library* library);
int readLibraryFromTextFile(const char* textFile, Library* library);

int writeLibraryToBinFile(const char* binFile, Library* library);
int readLibraryFromBinFile(const char* binFile, Library* library);
#endif // LIBRARY_H


