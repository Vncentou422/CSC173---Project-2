#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FAILED NULL
typedef struct NODE *Tree;
struct NODE {
  char label;
  Tree leftmostChild, rightSibling;
};
Tree parseTree; /* holds the result of the parse */
char *input; /* current position in input string */
char prev;
char curr;
char ahead;
int parens;
Tree tempL, tempR;
Tree makeNode0(char x);
Tree makeNode1(char x, Tree t);
Tree makeNode2(char x, Tree t1, Tree t2);
Tree makeNode3(char x, Tree t1, Tree t2, Tree t3);
char lookahead();
Tree Pls();
