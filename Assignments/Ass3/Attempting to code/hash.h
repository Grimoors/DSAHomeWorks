#ifndef __HASH_C
#define __HASH_C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




// typedef int ElementType;
// typedef struct ListNode
// {
//     ElementType Element;
//     ListNode *Next;
// } ListNode;

// typedef ListNode *List;

// typedef struct hashSC
// {
//     int TableSize;
//     List *TheLists;
// } hashSC;

// typedef hashSC* PtrTohashSC;


typedef struct Deque Deque;
typedef Deque* PtrToDeque;

struct Deque{

    int x;
     Deque* NextElement; 
    // Deque* PreviousElement;
    // Deque* FirstElement;
    Deque* LastElement;
};

typedef struct hashSCD
{
    int TableSize;
    PtrToDeque *TheLists;
} hashSCD;

typedef hashSCD* PtrTohashSCD;

PtrTohashSCD InitializeTableSCD(int TableSize);
void InsertToHashSCD(int key, int x, PtrTohashSCD H);
int LocationOfXinSCD(int key,int x, PtrTohashSCD H);


PtrToDeque MakeNode(int x);
void CreateEmptyDeque(PtrToDeque * S);

void push(PtrToDeque* S, int x);
void pop(PtrToDeque* S ,int*x);
void eject(PtrToDeque* S, int*x);
void exitFunc(PtrToDeque S);
void PrintDeque(PtrToDeque S);
void inject(PtrToDeque* S, int x);
int FindInDeque(int x, PtrToDeque S);



/*For Open Addressing*/
enum KindOfEntryInHashOA {Legit, Empty, Deleted};

typedef struct hashOAEntry
{
    int x;
    enum KindOfEntryInHashOA info;
}cell;

typedef struct hashOA
{
    int TableSize;
    cell* TheCells;
}hashOA;

typedef hashOA* PtrTohashOA;

PtrTohashOA InitializeTableOA(int TableSize);


int IdentityHashFunction(int x, int N);
PtrTohashOA RehashOA(PtrTohashOA H);

int FindInOA(int x, PtrTohashOA H, bool HashModeQuad);
void InsertIntoOA(int x,int index,PtrTohashOA H);

bool isPrime(int n);
int nextPrime(int N);

#endif
