#ifndef BOOK_H
#define BOOK_H

#include "Author.h"
#include "Publisher.h"

typedef enum {
    FICTION,
    NONFICTION,
    SCIENCE,
    FANTASY
} Genre;

typedef struct {
    char* name;
    Genre genre;
    int copiesAvailable;
    Author* author;
    Publisher* publisher;
} Book;

typedef struct {
    Book* booklist;
    int count;
} BookManager;

#endif


