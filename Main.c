#include <stdio.h>

#include "Library.h"

void PrintMenu();

//program start here
int main()
{
Library library;
initLibrary(*library);

	printf("welcome to the library manager  V1.0");

int choice;
do{
 PrintMenu();
 scanf("%d",&choice);
 
}

void PrintMenu(){
 printf("1.  add new book/n");
 printf("2.  remove book/n");
 printf("3.  add new member/n");
 printf("4.  remove member/n");
 printf("5.  add new loan/n");
 printf("6.  return book loan/n");
 printf("7.  search a book/n");
 printf("8.  search a member/n");
 printf("9.  print all books avaiable/n");
 printf("10. print all loaned books/n");
 printf("11. print all members/n");
 printf("12. print popular books/n");
 printf("13. Exit program/n");
 printf("Please enter your choice: ");
}