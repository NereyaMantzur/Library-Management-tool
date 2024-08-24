#ifndef AUTHOR_H
#define AUTHOR_H

// Forward declaration
typedef struct BookManager BookManager;
typedef struct  Book Book;


typedef struct AuthorBook {
	char* title;
	struct AuthorBook* next;
	struct AuthorBook* prev;
}AuthorBook;

typedef struct Author {
	char* name;
	AuthorBook* headBook;
} Author;


Author* initAuthor(BookManager* bookManager);
AuthorBook* initAuthorBook(Book* book);
void insert(Author* author, AuthorBook* title);
void printAuthor(Author* author);
void freeAuthor(Author* author);

#endif // !AUTHOR_H

