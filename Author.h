#ifndef AUTHOR_H
#define AUTHOR_H

// Forward declaration
 struct BookManager;
 struct Book;



 typedef struct Author{
     char* name;
	 struct Author* next;
	 struct Author* prev;
 } Author;

 Author* initAuthor();
 int initBookNode();
 void insert(Author* author, Author* book);
	 void printAuthor(Author* author);
 void freeAuthor(Author* author);

#endif // !AUTHOR_H

