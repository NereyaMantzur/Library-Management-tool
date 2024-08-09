#ifndef PUBLISHER_H
#define PUBLISHER_H

// Forward declaration
struct BookManager;

typedef struct {
    char* name;
    char* address;
    char* email;
    struct BookManager* booksPublished;  // Use forward declaration here
} Publisher;

#endif
