#ifndef __my_Deque_h__
#define __my_Deque_h__

#include <stdio.h>
#include <stdlib.h>

typedef struct Deque Deque;
typedef Deque* PtrToDeque;

struct Deque{

    double x;
    double y;
    Deque* NextElement; 
    Deque* PreviousElement;
    Deque* FirstElement;
    Deque* LastElement;
};

 

PtrToDeque MakeNode(double x, double y);
void CreateEmptyDeque(PtrToDeque * S);
void push(PtrToDeque* S, double x, double y);
void pop(PtrToDeque* S ,double *x, double *y);
void eject(PtrToDeque* S, double *x, double *y);
void exitFunc(PtrToDeque S);
void PrintDeque(PtrToDeque S);
void inject(PtrToDeque* S, double x, double y);


#endif