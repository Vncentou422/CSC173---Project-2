#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

typedef struct NODE *TREE;

struct NODE{
  char label;
  TREE leftmostChild, rightSibling;
};

TREE makeNode0(char x);
TREE makeNode1(char x, TREE t);
TREE makeNode2(char x, TREE t1, TREE t2);
TREE makeNode3(char x, TREE t1, TREE t2, TREE t3);
TREE parse(char input[]);

TREE parseTree; /* holds the result of the parse */
char *input; /* current position in input string */
char prev;
char curr;
char ahead;
int parens;
int next;
stack stacks;
//N = Number,
char rule0[10] = {'0','1','2','3','4','5','6','7','8','9'};
char rule1[3] = "NI";
char rule2[3] = "NA";
char rule3[3] = "(E)";
char rule4[3] = "+E";
char rule5[3] = "-E";
char rule6[3] = "*E";
char rule7[3] = "/E";
char rule8[3] = "";
char grammar[9] = {rule0,rule1,rule2,rule3,rule4,rule5,rule6,rule7,rule8};


void main(){
  input = "()()";
  input = readFile(argv[1]);
  parseTree = (TREE) malloc(sizeof(struct NODE));
}

TREE makeNode0(char x){
  TREE root;
  root = (TREE) malloc(sizeof(struct NODE));
  root->label = x;
  root->leftmostChild = NULL;
  root->rightSibling = NULL;
  return root;
}
//char is the root's label, various tree are the children
TREE makeNode1(char x, TREE t){
  TREE root;
  root = makeNode0(x);
  root->leftmostChild = t;
  return root;
}
TREE makeNode2(char x, TREE t1, TREE t2){
  TREE root;
  root = makeNode1(x, t1);
  t1->rightSibling = t2;
  return root;
}
TREE makeNode3(char x, TREE t1, TREE t2, TREE t3){
  TREE root;
  root = makeNode1(x, t1);
  t1->rightSibling = t2;
  t2->rightSibling = t3;
  return root;
}
int lookahead(char c){
  return input[1]==c;
}
int matchTerminal(char c){
  if(input[1] == c){
    input++;
    return 1;
  }
  else{
    return 0;
  }
}
char peekNext(){
  return input[1];
}


