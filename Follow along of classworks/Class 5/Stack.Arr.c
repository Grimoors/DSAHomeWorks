#include "Stack.h"

Stack InitStack(long int num_elems)
{
    Stack S;
    S= (Stack) malloc(sizeof(struct StackInfo));

    S->MaxNumElems - num_elems;
    S->StackItems = (ElementType)malloc(num_elems*sizeof(ElementType));

    S->TopId= -1;
}
int IsFull(Stack S)
{
    if(S->TopId==S->MaxNumElems-1)
    return 1;
    else
    return 0;
}
void Push(Stack S, ElementType E)
{
    if(S->TopId < S->MaxNumElems) //call an !IsFull(S);
    {
        ++S->TopId;
        S->StackItem[S->TopId]= E;// write a CopyItem(E);
    }
}

int IsEmpty(Stack S)
{
    if(S->TopId==-1)
    return 1;
    else
    return 0;
}

ElementType Top(const Stack S)
{
    if(!IsEmpty(S))
    return S->StackItem[S->TopId];
}

void Pop(Stack S)
{
    if(!IsEmpty(S))
        --S->TopId;
}