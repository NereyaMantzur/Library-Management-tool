#ifndef PUBLISHER_H
#define PUBLISHER_H




typedef struct {
    char* name;
    char* email;
    struct BookManager* booksPublished;
} Publisher;

Publisher* initPublisher();
void printPublisher(Publisher* publisher);
void freePublisher(Publisher* publisher);

#endif
