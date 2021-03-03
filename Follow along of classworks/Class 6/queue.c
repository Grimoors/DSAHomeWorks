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

void Enqueue (que Q, const ElementType E)
{
    assert (!IsFull(Q))
    Q->Rear +1;
    Q->QArr[Q->Rear]=E;
    ++(Q->NumItems);
    
}