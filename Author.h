#ifndef AUTHOR_H
#define AUTHOR_H

// Forward declaration
struct Book;

typedef struct {
    char* name;
    struct Book* next;
    struct Book* prev;
} Author;

int initAuthor(Author* author);
void printAuthor(Author* author);
int freeAuthor(Author* author);

#endif

