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
  bsTree;

//Assign memory
bsTree *bsTreeAlloc();
//Make free space
void bsTreeFree(bsTree *tp);
//Add names to tree
void bsTreePut(bsTree *tp, bstNode *np, char *s);
//Just an Empty tree
void bsTreeMakeEmpty(bstNode *tp);
//Names to be printed alphabetically
void bsTreePrint(bstNode *np);
//To remove a node from tree
void bsTreeRemove(bsTree *tp, bstNode *npP, bstNode *np, char *s);
//Write the tree names to file
void writeTreeToFile(bstNode *np, FILE *fp);


//Prints the instructions for the main menu
void printHSInstructions();
//Retrive the user input
int gets_n(char *s, int limit);
//Its runs the add state
void addState(char *buf, bsTree *tp);
//It runs the remove state
void removeState(char *buf, bsTree *tp);
//It runs the list state
void listState(bsTree *tp);

#endif
