#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

//stateManager.c

void printHomeStateInstructions(){
  printf("\n");
  printf("\n");
  printf("\n");
  printf("------------------------------------------\n");
  printf("Welcome to Acme Employee Management System\n");
  printf("------------------------------------------\n");
  printf("\n");
  printf("To list the employees, 'list'.\n");
  printf("To add, 'add'.\n");
  printf("To remove, 'remove'.\n");
  printf("To exit, 'quit'.\n");
}

void printAddStateInstructions(){
  printf("Type name to add employee.\n");
  printf("'back' to exit.\n");
}

void printRemoveStateInstructions(){
  printf("Enter name to remove.\n");
  printf("'back' to exit..\n");
}

void addState(char *buf, bstTree *tp){
  printAddStateInstructions();
  while(gets_n(buf,100)){
    int cmpback;
    char *back = "back";

    cmpback = strncmp(buf, back, 4);

    if(cmpback == 0){
      break;
    }
    else{
      bstTreePut(tp, tp -> root, buf);
      printf("The name has been added.\n");
    }
  }
  printHomeStateInstructions();
}

void removeState(char *buf, bstTree *tp){
  printRemoveStateInstructions();
  bstTreePrint(tp -> root);
  while(gets_n(buf,100)){
    int cmpback;
    char *back = "back";

    cmpback = strncmp(buf, back, 4);

    if(cmpback == 0){
      break;
    }
    else{
      bstTreeRemove(tp, tp -> root, tp -> root, buf);
      bstTreePrint(tp -> root);
    }
  }
  printHomeStateInstructions();
}

void listState(bstTree *tp){
  printf("\tThe list in alphabetical order....\n\n");
  bstTreePrint(tp -> root);
  printf("\n\tEnd List.\n");
  printHomeStateInstructions();
}

  

