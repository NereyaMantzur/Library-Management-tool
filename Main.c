#include <stdio.h>

#include "Library.h"

void PrintMenu();

//program start here
int main()
{
  Library library;
  initLibrary(*library);

	 printf("welcome to the library manager           V1.0");

  int choice;
  do{
    PrintMenu();
    scanf("%d",&choice);
    switch (choice)
       case 1:
         printf("not implemented yet /n");
         break;
       case 2:
         printf("not implemented yet /n");
         break;
       case 3:
         printf("not implemented yet /n");
         break;
       case 4:
         printf("not implemented yet /n");
         break;
       case 5:
         printf("not implemented yet /n");
         break;
       case 6:
         printf("not implemented yet /n");
         break;
       case 7:
         printf("not implemented yet /n");
         break;
       case 8:
         printf("not implemented yet /n");
         break;
       case 9:
         printf("not implemented yet /n");
         break;
       case 10:
         printf("not implemented yet /n");
         break;
       case 11:
         printf("not implemented yet /n");
         break;
       case 12:
         printf("not implemented yet /n");
         break;
       case 13:
         printf("closing program!/n");
         break;
  while(chioce != 1)
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