//CSC 173 Project 2

#include <stdio.h>

#define MAX 100
#define EMPTY 0

int size = EMPTY;
char x[MAX];
/*
struct stack{
  char x[MAX];
  int size;
};
typedef struct stack stack;
*/

/*
char peek(stack *y){
  if (y->size == 0){
    printf("error stack empty\n");
  }
  return y->x[y->size-1];
}
*/
char peek(){
  if (size != EMPTY)
    return x[size-1];
}


/*
void push(stack *y, char input){
  if(y->size < MAX){
    y->size++;
    y->x[(y->size)-1] = input;
  }
  else
    printf("error stack full\n");
}
*/

void push(char input){
  if(size < MAX){
    size++;
    x[size] = input;
  }
  else
    printf("error stack full\n");
}

/*
char pop(stack *y){
  char output;
  if (y->size == 0)
    printf("error stack empty\n");
  else{
    output = y->x[(y->size)-1];
    y->size--;
  }
  return output;
}
*/

char pop(){
  char output;
  if(size == EMPTY)
    printf("error stack empty\n");
  else{
    output = x[size-1];
    size--;
  }
  return output;
}
