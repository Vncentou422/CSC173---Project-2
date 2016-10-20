//CSC 173 Project 2

#include <stdio.h>
#include "ParseTree.h"
#define MAX 100

struct treeStack{
  Tree x[MAX];
  int size = 0;
};
typedef struct treeStack treeStack;

Tree peek(treeStack *y){
  if (y->size == 0){
    //printf("error stack empty\n");
    return -1;
  }
  return y->x[size-1];
}

void push(treeStack *y, Tree input){
  if(y->size < MAX){
    size++;
    y->x[(y->size)-1] = d;
  }
  else
    //printf("error stack full\n");
}

Tree pop(treeStack *y){
  if (y->size == 0)
    //printf("error stack empty\n");
  else{
    int output = y->x[(y->size)-1];
    y->size--;
  }
  return output;
}
