#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ParseReader.h"
//#include <stack.h>

#define MAX 100
#define EMPTY 0

typedef struct NODE *Tree;

struct NODE{
  char label;
  Tree leftmostChild, rightSibling;
};

Tree makeNode0(char x);
Tree makeNode1(char x, Tree t);
Tree makeNode2(char x, Tree t1, Tree t2);
Tree makeNode3(char x, Tree t1, Tree t2, Tree t3);
Tree parse(char input[]);



int size = EMPTY;
char x[MAX];


Tree parseTree; /* holds the result of the parse */
char *input; /* current position in input string */
char prev;
char curr;
char ahead;
int parens;
int next;
//stack stacks;
//N = Number,
char rule0[10] = {'0','1','2','3','4','5','6','7','8','9'};
char rule1[3] = "NI";
char rule2[3] = "NA";
char rule3[3] = "(E)";
char rule4[3] = "+E";
char rule5[3] = "-E";
char rule6[3] = "*E";
char rule7[3] = "/E";
char rule8[3] = '\0';
char *grammar[9] = {,"NI","ENA","E(E)","A+E","A-E","A*E","A/E","A"};


void main(){
  input = "()()";
  input = readFile(argv[1]);
  parseTree = (Tree) malloc(sizeof(struct NODE));
}

Tree makeNode0(char x){
  Tree root;
  root = (Tree) malloc(sizeof(struct NODE));
  root->label = x;
  root->leftmostChild = NULL;
  root->rightSibling = NULL;
  return root;
}
//char is the root's label, various tree are the children
Tree makeNode1(char x, Tree t){
  Tree root;
  root = makeNode0(x);
  root->leftmostChild = t;
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
  return input[1];
}

//stack functions
char peek(){
  if (size != EMPTY)
    return x[size-1];
}
void push(char input){
  if(size < MAX){
    size++;
    x[size] = input;
  }
  else
    printf("error stack full\n");
}
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
char* action(char x, char y){
  if(x == 'E' && y == 'N')
    return "ENA";
  else if(x == 'A' && y == '+')
    return "A+E";
  else if(x == 'A' && y == '-')
    return "A-E";
  else if(x == 'A' && y == '*')
    return "A*E";
  else if(x=='A' && y == '/')
    return "A/E";
  else if (x == 'A' && y == '\0')
    return "";
}
//Table Driven Parser
Tree parse(char input[]){
  push('E'); //push start symbol on stack
  int counter = 0;
  char ahead = input[counter + 1];//lookahead
    
  while(size != EMPTY){
    if(peek() != '(' || peek() != '+' || peek() != '-' || peek() != '*' || peek() != '/' || peek() != '0'|| peek() != '1' || peek() !=  '2' || peek() != '3' ||peek() != '4' ||peek() != '5' ||peek() != '6' ||peek() != '7' ||peek() != '8' ||peek() != '9') //if top of stack is not a terminal
      {
	char *nextrule;
	nextrule = action(peek(),ahead); //predicts next rule
	if(nextrule != ""){
	  pop();
	  for(int i = sizeOf(nextrule) -1; i > -1; i--)
	    push(nextrule[i]); //push rule onto stack
	}
	else
	  printf("syntax error\n");
      }
    else if(ahead == peek()){ //if terminal symbole matches input
      pop();
      counter++;
      ahead = input[counter+1];
    }
    else
      printf("syntax error\n");
  }
    	  
      /*
    char pointer = input[counter];
    char ahead = input[counter + 1];
    if(pointer == '('){
      pop();
      return makeNode3('E',makeNode0('('),makeNode1('E',parse(input[])),makeNode0(')'));
      push(')');
      push('E');
      push('(');
    }
    if (ahead == '+' || ahead == '-' || ahead == '*' || ahead == "/")
    */
}
