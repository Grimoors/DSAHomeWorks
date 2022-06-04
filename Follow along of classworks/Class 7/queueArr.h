#ifndef __Queue_Element__
#define __Queue_Element__
#include <stdlib.h>


typedef int ElementType;
typedef struct queue* que;

struct queue{
    size_t Capacity;
    long int Front;
    long int Rear;
    size_t NumItems;
    ElementType* QArr;
};


#endif