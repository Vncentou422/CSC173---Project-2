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

TREE makeNode0(char x);
TREE makeNode1(char x, TREE t);
TREE makeNode2(char x, TREE t1, TREE t2);
TREE makeNode3(char x, TREE t1, TREE t2, TREE t3);

TREE parseTree; /* holds the result of the parse */
char *input; /* current position in input string */
char prev;
char curr;
char ahead;
int parens;
TREE tempL, tempR;


void main(){
  input = "()()"; /* in practice, a string of terminals would be read from input */
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
//do all of the tree making
TREE Pls(){

  curr = input;
  input++;
  if(curr != NULL){
    ahead = curr;
  }
  switch(curr) {
    case '(':
      parens++;
      parseTree = makeNode3('E', makeNode0('('), Pls(), makeNode0(')'));
    break; /* optional */
    case ')'://need to add additional cases
      if(parens>0){
        parens--;
      }
      else{
        //throw some kind of error
      }
    break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      if(ahead == 0||1||2||3||4||5||6||7||8||9){
        input++;
        return (makeNode1('E', makeNode2('N', makeNode1('N', makeNode1('D', curr)), makeNode1('D', ahead))));
      }
      else{
        return (makeNode1('E', makeNode1('N', makeNode1('D', curr)));
      }
    break; /* optional */

    case '+':
    case '-':
    case '/':
    case '*':
      parseTree = makeNode3('E', pls(), makeNode0(curr), pls());//need to get the left and right part of this equation in somehow.
      break;
    default : /* Optional */
    statement(s);
  }
}


