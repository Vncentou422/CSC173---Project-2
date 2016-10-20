#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FAILED NULL
typedef struct NODE *Tree;
typedef struct {
  char label;
  Tree leftmostChild, rightSibling;
}NODE;
Tree parseTree; /* holds the result of the parse */
char *input; /* current position in input string */
char prev;
char curr;
char ahead;
int parens;
Tree tempL, tempR;
extern Tree makeNode0(char x);
extern Tree makeNode1(char x, Tree t);
extern Tree makeNode2(char x, Tree t1, Tree t2);
extern Tree makeNode3(char x, Tree t1, Tree t2, Tree t3);
extern int lookahead(char c);
extern int matchTerminal(char c);
extern char peekNext();
extern Tree Pls();
