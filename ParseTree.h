#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FAILED NULL
#define MAX 100

typedef struct NODE *Tree;
typedef struct {
  char label;
  Tree leftmostChild, rightSibling;
}NODE;

typedef struct{
  Tree x[MAX];
  int size;
}treeStack;

// Tree parseTree; /* holds the result of the parse */
// char *input; /* current position in input string */
// char prev;
// char curr;
// char ahead;
// int parens;
// int next;
// // treeStack *nodeS;
// extern void main(int argc, char **argv);
extern Tree makeNode0(char x);
extern Tree makeNode1(char x, Tree t);
extern Tree makeNode2(char x, Tree t1, Tree t2);
extern Tree makeNode3(char x, Tree t1, Tree t2, Tree t3);
extern int lookahead(char c);
extern int matchTerminal(char c);
extern char peekNext();
extern Tree Pls();

extern Tree peek(treeStack *y);
extern void push(treeStack *y, Tree input);
extern Tree pop(treeStack *y);
