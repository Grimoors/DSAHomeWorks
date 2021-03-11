#ifndef __my_stack_c__
#define __my_stack_c__
#include "my_stack.h"
#include <assert.h>

PtrToStack MakeNode(double x, double y)
{
        PtrToStack P = (PtrToStack)malloc(sizeof(Stack));
    assert(P != NULL);

    P->x = x;
    P->y = y;
    P->NextElement=NULL;

    return P;
}
void CreateEmptyStack(PtrToStack * S)
{
    PtrToStack SS=MakeNode(0.0,0.0);
    *S=SS;
}
void push(PtrToStack* S, double x, double y)
{
       PtrToStack PNew = MakeNode(x,y);

    PtrToStack L = *S;

    PNew->NextElement = L->NextElement;
    L->NextElement = PNew;
}
void pop(PtrToStack* S, double *x, double *y)
{

    PtrToStack Temp2 = *S;
    *S=(*S)->NextElement;
    free(Temp2);
}
void exitFunc(PtrToStack S)
{
    PtrToStack temp2 = S;
    while (S->NextElement!=NULL)
    {
        PtrToStack temp = S->NextElement;
        S=S->NextElement;
        free(temp);
    }
    free(temp2);
       
}
void PrintStack(PtrToStack S)
{
    printf("\nThe Current Stack is:-\n");

    while (S->NextElement!=NULL)
    {
        printf(" {%lf + %lf i} ",S->NextElement->x,S->NextElement->y);

        S=S->NextElement;
        /* code */
    }
    puts(" ");
    
}


#endif