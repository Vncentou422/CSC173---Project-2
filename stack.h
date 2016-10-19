#include <stdio.h>

#define MAX 100

struct stack{
  int x[MAX];
  int size = 0;
};
typedef struct Stack Stack;
int peek(stack *y);
void push(stack *y, int input);
int pop(stack *y);
