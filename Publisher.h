#ifndef PUBLISHER_H
#define PUBLISHER_H


 struct BookManager;
 struct Book;

typedef struct {
    char* name;
    char* email;
    struct BookManager* booksPublished;
} Publisher;

Publisher* initPublisher();
void printPublisher(Publisher* publisher);
void freePublisher(Publisher* publisher);

#endif
