#ifndef __Queue__
#define __Queue__
#include "queueArr.h"
que initQueue(size_t queue_capacity);
void enqueue (que Q, const ElementType E);
ElementType dequeue(que Q);
#endif