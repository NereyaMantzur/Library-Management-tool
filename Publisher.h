#ifndef PUBLISHER_H
#define PUBLISHER_H


typedef struct BookManager BookManager;

typedef struct {
    char* name;
    char* email;
    struct BookManager* booksPublished;
} Publisher;

int initPublisher(Publisher* publisher);
void printPublisher(Publisher* publisher);
void freePublisher(Publisher* publisher);

#endif
