#ifndef AUTHOR_H
#define AUTHOR_H

// Forward declaration
 struct BookManager;
 struct Book;

typedef struct {
    char* name;
    struct Book* next;
    struct Book* prev;
} Author;

Author* initAuthor();
void printAuthor(Author* author);
void freeAuthor(Author* author);

#endif // !AUTHOR_H

