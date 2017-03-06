#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

//stateManager.c

//Prints the home state instructions
void printHSInstructions(){
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

void addState(char *buf, bsTree *tp){
  printAddStateInstructions();
  while(gets_n(buf,100)){
    int cmpback;
    char *back = "back";

    cmpback = strncmp(buf, back, 4);

    if(cmpback == 0){
      break;
    }
    else{
      bsTreePut(tp, tp -> root, buf);
      printf("The name has been added.\n");
    }
  }
  printHSInstructions();
}

void removeState(char *buf, bsTree *tp){
  printRemoveStateInstructions();
  bsTreePrint(tp -> root);
  while(gets_n(buf,100)){
    int cmpback;
    char *back = "back";

    cmpback = strncmp(buf, back, 4);

    if(cmpback == 0){
      break;
    }
    else{
      bsTreeRemove(tp, tp -> root, tp -> root, buf);
      bsTreePrint(tp -> root);
    }
  }
  printHSInstructions();
}

void listState(bsTree *tp){
  printf("\tThe list in alphabetical order....\n\n");
  bsTreePrint(tp -> root);
  printf("\n\tEnd List.\n");
  printHSInstructions();
}

  

