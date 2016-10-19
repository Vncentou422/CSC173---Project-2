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
TREE tempN, tempR;
int next;


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
//do all of the tree making
TREE* Pls(){

  curr = *input;
  // switch(next){
  //   case 1://expression
  //   break;
  //   case 2://number
  //   break;
  // }
  switch(curr) {
    case '(':
      if(!matchTerminal('(')) return NULL;
      TREE* y2 = Pls();
      if(y2==NULL) return NULL;
      if(!matchTerminal('(')) return NULL;
      TREE* y4 = Pls();
      if(y4==NULL) return NULL;
      return
      parseTree = makeNode3('E', makeNode0('('), Pls(), makeNode0(')'));
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
      if(tempL == NULL){
        if(peekNext() == '0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'){
          input++;
          tempL = (makeNode1('E', makeNode2('N', makeNode1('N', makeNode1('D', curr)), makeNode1('D', ahead))));
        }
        else{
          tempL = (makeNode1('E', makeNode1('N', makeNode1('D', curr)));
        }
      }
      else{
        if(peekNext() == '0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'){
          input++;
          return (makeNode1('E', makeNode2('N', makeNode1('N', makeNode1('D', curr)), makeNode1('D', ahead))));
        }
        else{
          return (makeNode1('E', makeNode1('N', makeNode1('D', curr)));
        }
      }
      input++;
      pls();
    break;

    case '+':
    case '-':
    case '/':
    case '*':
      tempR = Pls();
      parseTree = makeNode3('E', tempN, makeNode0(curr), tempR);//need to get the left and right part of this equation in somehow.
      break;
    default :
    statement(s);
  }
}


