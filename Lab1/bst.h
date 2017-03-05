#ifndef bst_included
#define bst_included

//bst.h

typedef struct bstNode{
  struct bstNode *left;
  struct bstNode *right;
  char *str;
}
  bstNode;

typedef struct{
  bstNode *root;
}
  bstTree;

//Assign memory
bstTree *bstTreeAlloc();
//Make free space
void bstTreeFree(bstTree *tp);
//Add names to tree
void bstTreePut(bstTree *tp, bstNode *np, char *s);
//Just an Empty tree
void bstTreeMakeEmpty(bstNode *tp);
//Names to be printed alphabetically
void bstTreePrint(bstNode *np);
//To remove a node from tree
void bstTreeRemove(bstTree *tp, bstNode *npP, bstNode *np, char *s);
//Write the tree names to file
void writeTreeToFile(bstNode *np, FILE *fp);


//Prints the instructions for the main menu
void printHomeStateInstructions();
//Retrive the user input
int gets_n(char *s, int limit);
//Its runs the add state
void addState(char *buf, bstTree *tp);
//It runs the remove state
void removeState(char *buf, bstTree *tp);
//It runs the list state
void listState(bstTree *tp);

#endif
