#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#define MAX 100


void push(int* stack  , int* top ,int item){
   
    stack[*top] = item;
    (*top)++;
}

int pop(int* stack , int* top){
    int temp;
    (*top)--;
    temp = stack[*top];
    return temp;
}

void calc(int* numstack , int* numtop, int* opstack , int* optop){
    int num1;
	int num2;
	int answer;
    char sign;

    num2 = pop(numstack,numtop);
    num1 = pop(numstack,numtop);

    switch(pop(opstack,optop)){
        case '+' : answer = num1 + num2; sign = '+' ; break;
        case '-' : answer = num1 - num2; sign = '-' ; break;
        case '*' : answer = num1 * num2; sign = '*' ; break;
        case '/' : answer = num1 / num2; sign = '/' ; break;
    }
   
    push(numstack,numtop,answer);
    while(getchar()!='\n'){} 
}

void calculate(char[] str){
    int optop = 0;
	int numtop = 0;
	int i=0;
	int numstack[100];
	int opstack[100];
	char c;
    
    while(str[i]!='\n'){ i++; }
    str[i] = '\0';
   

    i = 0;
    
    while( (c=str[i]) !='\0'){
    if(c=='(') // skip over any ( 
	{ 
		i++; 
		continue; 
	}
    else if(c=='+'||c=='-'||c=='*'||c=='/') 
		push(opstack, &optop, c);
	
    else if(c>=48 && c <=57) 
		push(numstack, &numtop, (c-48));
	
    else if(c==')') 
		calc(numstack , &numtop, opstack , &optop);
    
    i++;
    }
	
    printf("\n Evaluation of the tree = %d",pop(numstack,&numtop));
    
}
