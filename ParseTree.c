#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "ParseReader.h"
//#include "treeStack.h"
#define MAX 100
#define FAILED NULL
typedef struct NODE *Tree;

struct NODE {
  char label;
  Tree leftmostChild, rightSibling;
} NODE;
struct treeStack{
  Tree x[MAX];
  int size;
};
typedef struct treeStack treeStack;
// Tree makeNode0(char x);
// Tree makeNode1(char x, Tree t);
// Tree makeNode2(char x, Tree t1, Tree t2);
// Tree makeNode3(char x, Tree t1, Tree t2, Tree t3);

Tree parseTree; /* holds the result of the parse */
char *input; /* current position in input string */
char prev;
char curr;
char ahead;
int parens;
int next;
treeStack *nodeS;

// int main(int argc, char **argv){
//   nodeS = malloc(sizeof(struct treeStack));
//   nodeS->size=0;
//   parseTree = (Tree) malloc(sizeof(struct NODE));
//   FILE *file = fopen(argv[1], "r");
// 	input = "";
// 	if (file == 0 )
// 	{
//
// 		printf(" File failed to open \n");
//
// 	}
// 	char in;
// 	while ((in = fgetc(file)) != -1)
// 	{
// 		// reads each character in the file one by one
// 		input += in;
// 	}
// 	fclose(file);
//   input = "1*2+3";
//   printf("%s\n", input);
//
//   //Pls();
// }

Tree * newTree(char **argv){
  nodeS = malloc(sizeof(struct treeStack));
  nodeS->size=0;
  parseTree = (Tree) malloc(sizeof(struct NODE));
  FILE *file = fopen(argv[1], "r");
  input = "";
  if (file == 0 )
  {

    printf(" File failed to open \n");

  }
  char in;
  while ((in = fgetc(file)) != -1)
  {
    // reads each character in the file one by one
    input += in;
  }
  fclose(file);
  input = "1*2+3";
  printf("%s\n", input);
}


Tree peek(treeStack *y){
  if (y->size == 0){
    return NULL;
  }
  return y->x[y->size-1];
}

void push(treeStack *y, Tree input){
  if(y->size < MAX){
    y->x[(y->size)] = input;
    y->size++;
  }
  //else
    //printf("error stack full\n");
}

Tree pop(treeStack *y){
  Tree output;
  if (y->size == 0){}
    //printf("error stack empty\n");
  else{
    Tree output = y->x[(y->size)-1];
    y->size--;
  }
  return output;
}

Tree makeNode0(char x){
  Tree root;
  root = (Tree) malloc(sizeof(struct NODE));
  root->label = x;
  printf("%c\n",root->label);
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
void printPTree(Tree t, int indent){
  printf("(");
  printf("%c ", t[0].label);
}
void printPT(){

  printPTree(parseTree,0);
}
//do all of the tree making
Tree Pls(){
  curr = *input;

  //printf("%c\n",curr);
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
      if(peekNext()!=NULL){
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
      //printf("push");
      if(peekNext() != NULL){
        if(peekNext() == '0'||peekNext() =='1'||peekNext() =='2'||peekNext() =='3'
        ||peekNext() =='4'||peekNext() =='5'||peekNext() =='6'||peekNext() =='7'
        ||peekNext() =='8'||peekNext() =='9'){
          input++;
          //printf("push");
          push(nodeS, (makeNode1('E', makeNode2('N', makeNode1('N', makeNode1('D', makeNode0(curr))), makeNode1('D', makeNode0(peekNext()))))));
        }
        else{
          //printf("push");
          push(nodeS, (makeNode1('E', makeNode1('N', makeNode1('D', makeNode0(curr))))));
        }
      }
      else{
        if(peekNext() == '0'||peekNext() =='1'||peekNext() =='2'||peekNext() =='3'
        ||peekNext() =='4'||peekNext() =='5'||peekNext() =='6'||peekNext() =='7'
        ||peekNext() =='8'||peekNext() =='9'){
          input++;
          return (makeNode1('E', makeNode2('N', makeNode1('N', makeNode1('D', makeNode0(curr))), makeNode1('D', makeNode0(peekNext())))));
        }
        else{
          return (makeNode1('E', makeNode1('N', makeNode1('D', makeNode0(curr)))));
        }
      }
      input++;
      //printf("hi");
      return Pls();
      break;

    case '+':
    case '-':
    case '/':
    case '*':
      input++;
      push(nodeS,Pls());
      input--;
      Tree temp;
      temp = pop(nodeS);
      curr = input;
      input++;
      if(peekNext() != NULL){
        push(nodeS, makeNode3('E', pop(nodeS), makeNode0(curr), temp));
      }
      else{
        return makeNode3('E', pop(nodeS), makeNode0(curr), temp);//need to get the left and right part of this equation in somehow.
      }
      //return makeNode3('E', pop(nodeS), makeNode0(curr), temp);//need to get the left and right part of this equation in somehow.
      break;
    default :
      break;
  }
}
