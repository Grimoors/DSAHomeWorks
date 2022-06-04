#ifndef __HASH_C
#define __HASH_C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode *List;
typedef long int ElementType;
typedef struct ListNode
{
    ElementType Element;
    List Next;
    List Prev;
    List Last;
} ListNode;

typedef ListNode *List;

typedef struct hashSC
{
    long int TableSize;
    List *TheLists;
} hashSC;

typedef hashSC *PtrTohashSC;

PtrTohashSC
InitializeTableSC(long int TableSize);

List SearchInLinkedListofHSC(ElementType x, long int key, PtrTohashSC Hsc, long int *posFromStart);

void InsertIntoHSC(ElementType x, long int key, PtrTohashSC Hsc);

// typedef struct Deque Deque;
// typedef Deque* PtrToDeque;

// struct Deque{

//     long int x;
//      Deque* NextElement;
//     // Deque* PreviousElement;
//     // Deque* FirstElement;
//     Deque* LastElement;
// };

// typedef struct hashSCD
// {
//     long int TableSize;
//     PtrToDeque *TheLists;
// } hashSCD;

// typedef hashSCD* PtrTohashSCD;

// PtrTohashSCD InitializeTableSCD(long int TableSize);
// void InsertToHashSCD(long int key, long int x, PtrTohashSCD H);
// long int LocationOfXinSCD(long int key,long int x, PtrTohashSCD H);

// PtrToDeque MakeNode(long int x);
// void CreateEmptyDeque(PtrToDeque * S);

// void push(PtrToDeque* S, long int x);
// void pop(PtrToDeque* S ,int*x);
// void eject(PtrToDeque* S, int*x);
// void exitFunc(PtrToDeque S);
// void PrintDeque(PtrToDeque S);
// void inject(PtrToDeque* S, long int x);
// long int FindInDeque(long int x, PtrToDeque S);

/*For Open Addressing*/
enum KindOfEntryInHashOA
{
    Legit,
    Empty,
    Deleted
};

typedef struct hashOAEntry
{
    long int x;
    enum KindOfEntryInHashOA info;
} cell;

typedef struct hashOA
{
    long int TableSize;
    cell *TheCells;
} hashOA;

typedef hashOA *PtrTohashOA;

PtrTohashOA InitializeTableOA(long int TableSize);

long int IdentityHashFunction(long int x, long int N);
PtrTohashOA RehashOA(PtrTohashOA H);

long int FindInOA(long int x, PtrTohashOA H, bool HashModeQuad);
void InsertIntoOA(long int x, long int index, PtrTohashOA H);

bool isPrime(long int n);
long int nextPrime(long int N);

typedef struct ListNodeD *ListD;
typedef char *ElementTypeD;
typedef struct ListNodeD
{
    ElementTypeD Element;
    ListD Next;
    ListD Prev;
    ListD Last;
} ListNodeD;

typedef ListNodeD *ListD;

typedef struct hashSCD
{
    long int TableSize;
    ListD *TheLists;
} hashSCD;

typedef hashSCD *PtrTohashSCD;

PtrTohashSCD
InitializeTableSCD(long int TableSize);

ListD SearchInLinkedListofHSCD(ElementTypeD x, long int key, PtrTohashSCD Hsc, long int *posFromStart);

void InsertIntoHSCD(ElementTypeD x, long int key, PtrTohashSCD Hsc);
#endif