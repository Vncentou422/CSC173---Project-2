#include <stdio.h>
#include "ParseTree.h"
#define MAX 100

struct stack{
  Tree x[MAX];
  int size = 0;
};
typedef struct Stack Stack;
Tree peek(stack *y);
void push(stack *y, int input);
Tree pop(stack *y);
