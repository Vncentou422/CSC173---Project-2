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

void calc(int* numberStack , int* topNumber, int* operatorStack , int* topOperator){
    int num1;
	int num2;
	int answer;
    char sign;

    num2 = pop(numberStack,topNumber);
    num1 = pop(numberStack,topNumber);

    switch(pop(operatorStack,topOperator)){
        case '+' : answer = num1 + num2; 
			sign = '+'; 
			break;
        case '-' : answer = num1 - num2; 
			sign = '-'  
			break;
        case '*' : answer = num1 * num2; 
			sign = '*'; 
			break;
        case '/' : answer = num1 / num2; 
			sign = '/'; 
			break;
    }
   
    push(numberStack,topNumber,answer);
    while(getchar()!='\n'){} 
}

void calculate(char[] str){
    int topOperator = 0;
	int topNumber = 0;
	int i =0 ;
	int numberStack[100];
	int operatorStack[100];
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
		push(operatorStack, &topOperator, c);
	
    else if(c>=48 && c <=57) 
		push(numberStack, &topNumber, (c-48));
	
    else if(c==')') 
		calc(numberStack , &topNumber, operatorStack , &topOperator);
    
    i++;
    }
	
    printf("\n Evaluation of the tree = %d",pop(numberStack,&topNumber));
    
}
