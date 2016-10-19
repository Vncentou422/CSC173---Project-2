#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ParseReader.h"
#define FAILED NULL
typedef struct NODE *TREE;
struct NODE {
  char label;
  TREE leftmostChild, rightSibling;
};
TREE parseTree; /* holds the result of the parse */
char *input; /* current position in input string */
char prev;
char curr;
char ahead;
int parens;
TREE tempL, tempR;
TREE makeNode0(char x);
TREE makeNode1(char x, TREE t);
TREE makeNode2(char x, TREE t1, TREE t2);
TREE makeNode3(char x, TREE t1, TREE t2, TREE t3);
char lookahead();
TREE Pls();