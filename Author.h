#ifndef AUTHOR_H
#define AUTHOR_H

// Forward declaration
 struct BookManager;
 struct Book;

 typedef struct BookNode
 {
	 char* bookName;
	 struct BookNode* next;
	 struct BookNode* prev;
 }BookNode;

 typedef struct {
     char* name;
     BookNode* head;
 } Author;

 Author* initAuthor();
 int initBookNode();
 void insert(Author* author, BookNode* bookNode);
 void printAuthor(Author* author);
 void freeAuthor(Author* author);

#endif // !AUTHOR_H

