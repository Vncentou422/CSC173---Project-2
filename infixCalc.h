#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(int* stack  , int* top ,int item);
int pop(int* stack , int* top);
int calc(int* numberStack , int* topNumber, int* operatorStack , int* topOperator);
int calculate(char *str);