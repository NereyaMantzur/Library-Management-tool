#ifndef AUTHOR_H
#define AUTHOR_H

// Forward declaration
struct BookManager;

typedef struct {
    char* name;
    char* contact;
    struct BookManager* writtenBy;  // Use forward declaration here
} Author;

#endif

