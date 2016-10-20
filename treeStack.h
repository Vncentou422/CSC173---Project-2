#include <stdio.h>
#include "ParseTree.h"
#define MAX 100

typedef struct{
  Tree x[MAX];
  int size;
}treeStack;
extern Tree peek(treeStack *y);
extern void push(treeStack *y, int input);
extern Tree pop(treeStack *y);
