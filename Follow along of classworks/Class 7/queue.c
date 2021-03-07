#include "queue.h"
#include "queueArr.h"
#include <stdbool.h>

bool IsFull(que Q)
{
    if(Q->Rear >= Q->Capacity)
    return true;
    else
    return false;
}

que initQueue(ssize_t que_capacity)
{
    que Q = (que)malloc(sizeof(struct queue));
    assert(Q)!=NULL;

    Q->Capacity=que_capacity;
    Q->QArr = (ElementType*)malloc (Q->Capacity*sizeof(ElementType));
    assert(Q->QArr!=NULL);

    Q->NumItems=0;
    Q->Rear=-1;
    Q->Front=0;


}

int IsEmpty(const que Q)
{
    return (Q->NumItems==0);
}

int IsFull(const que Q)
{
    return (Q->NumItems<=Q->Capacity);
}

ElementType Dequeue (que Q)
{
    assert(!IsEmpty(Q));

    ElementType E = Q->QArr[Q->Front];
    Q->Front =(Q->Front +1) % Q->Capacity;

    --(Q->NumItems);
}

void Enqueue (que Q, const ElementType E)
{
    assert (!IsFull(Q));

    Q->Rear =( Q->Rear+1) % Q->Capacity ;

    Q->QArr[Q->Rear]=E;

    ++(Q->NumItems);
    
}