#include <stdio.h>

#define MAX 100
#define EMPTY 0

//int size;
//char x[MAX];

struct stack{
  char x[MAX];
  int size = 0;
};
typedef struct stack stack;
char peek(stack *y);
void push(stack *y, int input);
char pop(stack *y);

/*
char peek();
void push(char input);
char pop();
*/
