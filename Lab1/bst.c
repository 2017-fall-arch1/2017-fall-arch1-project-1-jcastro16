#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "bst.h"

//bst.c file

//assign memory for tree
bstTree *bstTreeAlloc(){
  bstTree *tp = (bstTree *)malloc(sizeof(bstTree));
  tp -> root = 0;
  return tp;
}
  
  void bstTreeFree(bstTree *tp){
    free(tp);
  }
  
  //Make binary search tree empty
  void bstTreeMakeEmpty(bstNode *tp){
    bstNode *current = tp;

    if(current == 0){
      return;
    }
    else{
      bstNode *nextLeft = current -> left;
      bstNode *nextRight = current -> right;
      bstTreeMakeEmpty(nextLeft);
      bstTreeMakeEmpty(nextRight);
      free(current -> str);
      free(current);
    }
  }
  //return a copy of s
  char *makeStringCopy(char *s){
    char *scopy;
    int len;
    for(len = 0; s[len]; len++);
      scopy = (char *)malloc(len+1);
      for(len = 0; s[len]; len++)
	scopy[len] = s[len];
      scopy[len] = 0;
      return scopy;
  }

    //Initialize node to string
    void initNode(bstNode *np, char *s){
      np -> str = s;
      np -> left = 0;
      np -> right = 0;
    }

      int isLeaf(bstNode *np){
      if(np -> left == 0 && np -> right == 0){
	return 1;
    }
    else{
      return 0;
    }
    }
    //find smallest value name starting from npo(node pointer original)
    void bstTreeFindSmallest(bstNode *npo, bstNode *npP, bstNode *np){
      if(isLeaf(np)){
         npo -> str = np -> str;
         if(npP -> left == np){
	npP -> left = 0;
      }
      else{
	npP -> right = 0;
      }
    }else if(np -> left == 0 && np -> right != 0){
	//Only has the right one, so its the smallest
	npo -> str = np -> str;
	if(npP -> left == np){
	   bstNode temp = *(np -> right);
	   *(npP -> left) = temp;
	   }
	else{
	  bstNode temp = *(np -> right);
	  *(npP -> right) = temp;
	}
      }
      else{
	//If it has left, it keeps going left
	bstTreeFindSmallest(npo, np, np -> left);
      }
    }

    //Concatinates, then add name to file
    void addNameToFile(char *s, FILE *fp){
      char *tmp;
      tmp = malloc(strlen(s)+3);
      strcat(tmp, s);
      strcat(tmp, "\n");
      fputs(tmp, fp);
      free(tmp);
    }

    //write names in file
    void writeTreeToFile(bstNode *np, FILE *fp){
      if(np == 0){
	return;
      }
      //Add name to child
      if(isLeaf(np)){
	addNameToFile(np -> str, fp);
      }
      //If it has left, add name and go left
      else if(np -> left != 0 && np -> right == 0){
	addNameToFile(np  -> str, fp);
	writeTreeToFile(np -> left, fp);
      }
      else if(np -> left == 0 && np -> right != 0){
	addNameToFile(np -> str, fp);
	writeTreeToFile(np -> right, fp);
      }
      else{
	addNameToFile(np -> str, fp);
	writeTreeToFile(np -> left, fp);
	writeTreeToFile(np -> right, fp);
      }
    }

    //Add name to the tree
    void bstTreePut(bstTree *tp, bstNode *np, char *s){
      char *scopy = makeStringCopy(s);
      bstNode *i;
      if(np == 0){
	//If tree is empty, add a name
	i = (bstNode *)malloc(sizeof(bstNode));
	initNode(i, scopy);
	tp -> root = i;
      }
      else{
	//BSTree not empty, add untill space is available
	char *nstr = np -> str;
	int cmpstr = strncmp(s, nstr, 100);
	
	//if input name is <= to current one
	if(cmpstr <= 0){
	  //Left empty, so add it on the left
	  if(np -> left == 0){
	    i = (bstNode *)malloc(sizeof(bstNode));
	    initNode(i, scopy);
	    np -> left = i;
	  }
	  else{
	    //Left not empty, keep going left
	    bstTreePut(tp, np -> left, s);
	  }
	}
	//Input name is > than the current one
	else{
	  //Rifht empty, so add it right
	  if(np->right == 0){
	    i = (bstNode *)malloc(sizeof(bstNode));
	    initNode(i, scopy);
	    np -> right = i;
	  }
	  //Right not empty, go right
	  else{
	    bstTreePut(tp, np -> right, s);
	  }
	}
      }
    }

    //Prints the name on the list alphabetically
    void bstTreePrint(bstNode *np){
      if(np == 0){
	return;
      }
      else{
	bstTreePrint(np -> left);
	printf("\t%s\n", np -> str);
	bstTreePrint(np -> right);
      }
    }

    //Removes the name for the binary search tree
    void bstTreeRemove(bstTree *tp, bstNode *npP, bstNode *np, char *s){
      if(np == 0){
	printf("Name isn't on the list.\n");
      }
      else{
	char *nstr = np -> str;
	int cmpstr = strncmp(s, nstr, 100);

	if(cmpstr == 0){
	  //Node has been found
	  if(tp -> root == np && isLeaf(np)){
	    tp -> root = 0;
	  }
	  else if(tp -> root == np && np -> left != 0 && np -> right == 0){
	    //Node has left, therefore root
	    bstNode temp = *(np -> left);
	    *(tp -> root) = temp;
	  }
	  else if(tp -> root == np && np -> left == 0 && np -> right != 0){
	    //Node is root, has right
	    bstNode temp = *(np -> right);
	    *(tp -> root) = temp;
	  }
	  //Node is leaf, not root
	  else if(isLeaf(np)){
	    if(npP -> left == np){
	      npP -> left = 0;
	    }
	    else{
	      npP -> right = 0;
	    }
	  }
	  else if (np -> left != 0 && np -> right == 0){
	      //Node has a left
	      bstNode temp = *(np -> left);
	      *np = temp;
	    }
	    else if(np -> left == 0 && np -> right != 0){
	      //Node has a right
	      bstNode temp = *(np -> right);
	      *np = temp;
	    }
	    else {
	      //Node has two children
	      bstTreeFindSmallest(np, np, np -> right);
	    }
	    printf("The employee selected has been removed!\n");
	    }else if(cmpstr < 0){
	      //Node not found, so go left
	      bstTreeRemove(tp, np, np -> left, s);
	    }
	    else{
	      //Node not found, so go right
	      bstTreeRemove(tp, np, np -> right, s);
	    }
	}
      }
