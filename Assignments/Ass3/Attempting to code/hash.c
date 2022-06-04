#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <assert.h>
#include <stdbool.h>

// /* For Normal LinkedList*/
// PtrTohashSC
// InitializeTable(int TableSize)
// {
//     PtrTohashSC H;

//     // Check for minimal Table size
//     // if(TableSize<MinTableSize)
//     // {
//     //     Error("Table size too small");
//     //     return NULL;
//     // }
//     /*Allocating table*/

//     H = (PtrTohashSC)malloc(sizeof(hashSC));
//     if (H == NULL)
//     {
//         FatalError("Out of Space");
//     }

//     H->TableSize = nextPrime(TableSize);
//     /*allocate array of lists*/
//     H->TheLists = (List *)malloc(sizeof(List) * (H->TableSize));
//     if (H->TheLists == NULL)
//     {
//         FatalError("Out of Space!!!");
//     }
//     /*Allocate List headers*/
//     for (int i = 0; i < H->TableSize; i++)
//     {
//         H->TheLists[i] = (List)malloc(sizeof(struct ListNode));
//         if (H->TheLists[i] == NULL)
//             FatalError("Out of Space");
//         else
//             H->TheLists[i]->Next = NULL;
//     }
//     return H;
// }

/*For Seperate Chaining*/
PtrTohashSCD
InitializeTableSCD(int TableSize)
{
    PtrTohashSCD H;

    // Check for minimal Table size
    // if(TableSize<MinTableSize)
    // {
    //     Error("Table size too small");
    //     return NULL;
    // }
    /*Allocating table*/

    H = (PtrTohashSCD)malloc(sizeof(hashSCD));
    if (H == NULL)
    {
        puts("Out of Space");
        return NULL;
    }

    H->TableSize = nextPrime(TableSize);
    /*allocate array of lists*/
    H->TheLists = (PtrToDeque *)malloc(sizeof(PtrToDeque) * (H->TableSize));
    if (H->TheLists == NULL)
    {
        puts("Out of Space");
        return NULL;
    }
    /*Allocate List headers*/
    for (int i = 0; i < H->TableSize; i++)
    {
        CreateEmptyDeque(&(H->TheLists[i]));
        if (H->TheLists[i] == NULL)
        {
            puts("Out of Space");
            return NULL;
        }
    }
    return H;
}

void InsertToHashSCD(int key, int x, PtrTohashSCD H)
{
    inject(&(H->TheLists[key]), x);
}

int LocationOfXinSCD(int key, int x, PtrTohashSCD H)
{
    return FindInDeque(x, H->TheLists[key]);
}

/*For Dequeues*/
PtrToDeque MakeNode(int x)
{
    PtrToDeque P = (PtrToDeque)malloc(sizeof(Deque));
    assert(P != NULL);

    P->x = x;
    P->NextElement = NULL;

    return P;
}
void CreateEmptyDeque(PtrToDeque *S)
{
    PtrToDeque SS = MakeNode(0);
    *S = SS;
    (*S)->NextElement = MakeNode(0);
    //(*S)->FirstElement = (*S);
    (*S)->LastElement = (*S)->NextElement;
    //(*S)->NextElement->PreviousElement = (*S);
    //(*S)->PreviousElement = NULL;
}

// void push(PtrToDeque *S, int x)
// {
//     PtrToDeque PNew = MakeNode(x);

//     PtrToDeque L = *S;
//     PNew->x = x;

//     PNew->NextElement = L->FirstElement->NextElement;
//     PNew->PreviousElement = L->FirstElement;
//     PNew->FirstElement = L->FirstElement;
//     PNew->LastElement = L->LastElement;
//     L->FirstElement->NextElement->PreviousElement = PNew;
//     L->FirstElement->NextElement = PNew;
// }
void inject(PtrToDeque *S, int x)
{
    PtrToDeque PNew = MakeNode(x);

    PtrToDeque L = *S;
    PNew->x = x;

    PNew->NextElement = L->LastElement;
    //PNew->PreviousElement = L->LastElement->PreviousElement;
    //PNew->FirstElement = L->FirstElement;
    PNew->LastElement = L->LastElement;
    //L->LastElement->PreviousElement->NextElement = PNew;
    //L->LastElement->PreviousElement = PNew;
}
//void pop(PtrToDeque *S, int *x)
// {
//     *x = (*S)->FirstElement->NextElement->x;

//     PtrToDeque Temp2 = (*S)->FirstElement->NextElement;
//     (*S)->FirstElement->NextElement = (*S)->FirstElement->NextElement->NextElement;
//     (*S)->FirstElement->NextElement->PreviousElement = (*S);
//     free(Temp2);
// }
// void eject(PtrToDeque *S, int *x)
// {
//     *x = (*S)->LastElement->PreviousElement->x;

//     PtrToDeque Temp2 = (*S)->LastElement->PreviousElement;
//     (*S)->LastElement->PreviousElement = (*S)->LastElement->PreviousElement->PreviousElement;
//     (*S)->LastElement->PreviousElement->NextElement = (*S);
//     free(Temp2);
// }
void exitFunc(PtrToDeque S)
{
    PtrToDeque temp2 = S;
    while (S->NextElement != NULL)
    {
        PtrToDeque temp = S->NextElement;
        S = S->NextElement;
        free(temp);
    }
    free(temp2);
}
// void PrintDeque(PtrToDeque S)
// {
//     printf("\nThe Current Deque is:-\n");

//     while (S != S->LastElement->PreviousElement)
//     {
//         printf(" {%lf } ", S->NextElement->x);

//         S = S->NextElement;
//         /* code */
//     }
//     puts(" ");
// }
int FindInDeque(int x, PtrToDeque S)
{
    int pos = 0;
    //while (S != S->LastElement->PreviousElement)
    while (S->NextElement!= NULL)
    {
        if (x == S->x)
        {
            return pos;
        }

        S = S->NextElement;
        pos++;
        /* code */
    }
    return -1;
}

/*For Open Addressing*/

PtrTohashOA
InitializeTableOA(int TableSize)
{
    PtrTohashOA H;
    int i;

    /* Allocate Table */
    H = (PtrTohashOA)malloc(sizeof(struct hashOA));
    if (H == NULL)
    {
        puts("Out of Space");
        return NULL;
    }
    H->TableSize = nextPrime(TableSize);

    /* Allocate array of cells */
    H->TheCells = malloc(sizeof(cell) * H->TableSize);
    if (H->TheCells == NULL)
    {
        puts("Out of Space");
        return NULL;
    }
    for (i = 0; i < H->TableSize; i++)
    {
        H->TheCells[i].info = Empty;
    }
    return H;
}
int FindInOA(int x, PtrTohashOA H, bool HashModeQuad)
{
    int CurrentPos;
    int CollisionNum = 0;

    CurrentPos = IdentityHashFunction(x, H->TableSize);

    if (HashModeQuad)
    {
        while (H->TheCells[CurrentPos].info != Empty && H->TheCells[CurrentPos].x!=x)
        {
            CurrentPos+=2* ++CollisionNum -1;
            while(CurrentPos>=H->TableSize)
            {CurrentPos-=H->TableSize;}
        }
        return CurrentPos;
    }
    else
    {
        while (H->TheCells[CurrentPos].info != Empty && H->TheCells[CurrentPos].x!=x)
        {
            CurrentPos+=++CollisionNum;
            while(CurrentPos>=H->TableSize)
            {CurrentPos-=H->TableSize;}
        }
        return CurrentPos;
    }
}
void InsertIntoOA(int x,int index,PtrTohashOA H)
{
    H->TheCells[index].x=x;
    H->TheCells[index].info=Legit;
}
/* Hash Functions */
int IdentityHashFunction(int x, int N)
{
    return x % N;
}

PtrTohashOA RehashOA(PtrTohashOA H)
{
    int i,OldSize;
    cell *OldCells;

    OldCells=H->TheCells;
    OldSize= H->TableSize;
    H=InitializeTableOA(2*OldSize);

    for(i=0;i<OldSize;i++)
    {
        if(OldCells[i].info==Legit)
        {
            InsertIntoOA(OldCells[i].x,i,H);
        }
    }

    free(OldCells);

    return H;
}


/* Helper Functions */
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

// Function to return the smallest
// prime number greater than N
int nextPrime(int N)
{

    // Base case
    if (N <= 1)
        return 2;

    int prime = N;
    bool found = false;

    // Loop continuously until isPrime returns
    // true for a number greater than n
    while (!found)
    {
        prime++;

        if (isPrime(prime))
            found = true;
    }

    return prime;
}