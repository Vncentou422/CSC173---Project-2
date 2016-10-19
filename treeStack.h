#include <stdio.h>
#include "ParseTree.h"
#define MAX 100

struct stack{
  TREE x[MAX];
  int size = 0;
};
typedef struct Stack Stack;
TREE peek(stack *y);
void push(stack *y, int input);
TREE pop(stack *y);
