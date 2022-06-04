#ifndef __my_stack_h__
#define __my_stack_h__

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;
typedef Stack* PtrToStack;

struct Stack{

    double x;
    double y;
    Stack* NextElement; 

};

 

PtrToStack MakeNode(double x, double y);
void CreateEmptyStack(PtrToStack * S);
void push(PtrToStack* S, double x, double y);
void pop(PtrToStack* S ,double *x, double *y);
void exitFunc(PtrToStack S);
void PrintStack(PtrToStack S);


#endif