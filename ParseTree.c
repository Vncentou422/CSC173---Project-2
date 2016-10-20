#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "ParseReader.h"
#include "treeStack.h"

#define FAILED NULL
typedef struct NODE *Tree;

typedef struct NODE {
  char label;
  Tree leftmostChild, rightSibling;
} NODE;

Tree makeNode0(char x);
Tree makeNode1(char x, Tree t);
Tree makeNode2(char x, Tree t1, Tree t2);
Tree makeNode3(char x, Tree t1, Tree t2, Tree t3);

Tree parseTree; /* holds the result of the parse */
char *input; /* current position in input string */
char prev;
char curr;
char ahead;
int parens;
int next;
treeStack *nodeS;

// void main(){
//   input = "()()";
//   nodeS = (treeStack) malloc(sizeof(struct treeStack));
//   input = readFile(argv[1]);
//   parseTree = (Tree) malloc(sizeof(struct NODE));
// }

Tree makeNode0(char x){
  Tree root;
  root = (Tree) malloc(sizeof(struct NODE));
  root->label = x;
  root->leftmostChild = NULL;
  root->rightSibling = NULL;
  return root;
}
//char is the root's label, various tree are the children
Tree makeNode1(char x, Tree t1){
  Tree root;
  root = makeNode0(x);
  root->leftmostChild = t1;
  return root;
}
Tree makeNode2(char x, Tree t1, Tree t2){
  Tree root;
  root = makeNode1(x, t1);
  t1->rightSibling = t2;
  return root;
}
Tree makeNode3(char x, Tree t1, Tree t2, Tree t3){
  Tree root;
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
  char c = input[1];
  return c;
}
//do all of the tree making
Tree Pls(){

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
      Tree y2 = Pls();
      if(y2==NULL) return NULL;
      if(!matchTerminal(')')) return NULL;
      if(!peekNext()){
        return makeNode3('E', makeNode0('('), Pls(), makeNode0(')'));
      }
      else{
        push(nodeS, makeNode3('E', makeNode0('('), Pls(), makeNode0(')')));
      }
      return Pls();
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
      if(peek(nodeS) != NULL){
        if(peekNext() == '0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'){
          char d = peekNext();
          input++;
          push(nodeS, (makeNode1('E', makeNode2('N', makeNode1('N', makeNode1('D', makeNode0(curr))), makeNode1('D', madeNode0(d))))));
        }
        else{
          push(nodeS, (makeNode1('E', makeNode1('N', makeNode1('D', makeNode0(curr))))));
        }
      }
      else{
        if(peekNext() == '0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'){
          input++;
          return (makeNode1('E', makeNode2('N', makeNode1('N', makeNode1('D', makeNode0(curr))), makeNode1('D', makeNode0(peekNext())))));
        }
        else{
          return (makeNode1('E', makeNode1('N', makeNode1('D', makeNode0(curr)))));
        }
      }
      input++;
      return Pls();
      break;

    case '+':
    case '-':
    case '/':
    case '*':
      push(nodeS,Pls());
      Tree temp;
      temp = pop(nodeS);
      parseTree = makeNode3('E', pop(nodeS), makeNode0(curr), temp);//need to get the left and right part of this equation in somehow.
      break;
    default :
      break;
  }
}
