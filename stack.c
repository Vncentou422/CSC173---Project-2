//CSC 173 Project 2

#include <stdio.h>

#define MAX 100

struct stack{
  int x[MAX];
  int size = 0;
};
typedef struct Stack Stack;

int peek(stack *y){
  if (y->size == 0){
    printf("error stack empty\n");
    return -1;
  }
  return y->x[size-1];
}

void push(stack *y, int input){
  if(y->size < MAX){
    size++;
    y->x[(y->size)-1] = d;
  }
  else
    printf("error stack full\n");
}

int pop(stack *y){
  if (y->size == 0)
    printf("error stack empty\n");
  else{
    int output = y->x[(y->size)-1];
    y->size--;
  }
  return output;
}
