#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


//bstdemo.c

int gets_n(char *s, int limit){
  char *p = s;
  char c;
  if(fgets(s, limit, stdin)){
    while((c = *p) && c != '\n'){
      p++;
    }
    if(c == '\n'){
      *p = 0;
    }
  }
  return (p-s);
}

//Create the tree using the provided file
void populateTreeFromFile(bstTree *tp){
  FILE *fp;
  char buf[100];

  fp = fopen("names.txt", "a+");
  //while names exist
  while(fgets(buf, 100, (FILE*)fp)){
    int len;
    for(len = 0; buf[len]; len++);
    //Delete the '\n'
    buf[len-1] = 0;
    bstTreePut(tp, tp -> root, buf);
  }
  fclose(fp);
}

//Saves the name from the binary search tree
void saveNamesToFile(bstTree *tp){
  FILE *fp;
  fp = fopen("names.txt","w+");
  //Write names
  writeTreeToFile(tp -> root, fp);
  fclose(fp);
}

int main(){
  char buf[100];
  bstTree *tp = bstTreeAlloc();

  populateTreeFromFile(tp);
  //Prints the Main Menu Interface
  printHomeStateInstructions();

  while(gets_n(buf, 100)){
    int cmplist;
    int cmpadd;
    int cmpremove;
    int cmpquit;
    char *list = "list";
    char *add = "add";
    char *remove = "remove";
    char *quit = "quit";

    cmplist = strncmp(buf, list, 2);
    cmpadd = strncmp(buf, add, 3);
    cmpremove = strncmp(buf, remove, 2);
    cmpquit = strncmp(buf, quit, 3);

    //Upon user input, the correct instruction is executed
    if(cmplist == 0){
      listState(tp);
    }
    else if(cmpadd == 0){
      addState(buf, tp);
    }
    else if(cmpremove == 0){
      removeState(buf, tp);
    }
    else if(cmpquit == 0){
      break;
    }
    else{
      printf("Inavlid Input. Please try again");
    }
  }
  saveNamesToFile(tp);
  bstTreeMakeEmpty(tp -> root);
  bstTreeFree(tp);
  printf("Adios...\n");
  return 0;
}
