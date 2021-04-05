#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <assert.h>
#include <stdbool.h>

// /* For Normal LinkedList*/
PtrTohashSC
InitializeTableSC(int TableSize)
{
    //printf("Entered Initialize region\n");
    PtrTohashSC H;

    // Check for minimal Table size
    // if(TableSize<MinTableSize)
    // {
    //     Error("Table size too small");
    //     return NULL;
    // }
    /*Allocating table*/

    //printf("Entered Malloc region for HSC\n");
    H = (PtrTohashSC)malloc(sizeof(hashSC));
    if (H == NULL)
    {
        puts("Out of Space");
        return NULL;
    }

    //printf("Entered Allocate Table size region\n");
    //H->TableSize = nextPrime(TableSize);
    H->TableSize = TableSize;
    /*allocate array of lists*/
    //printf("Entered +allocate array of lists region\n");
    H->TheLists = (List *)malloc(sizeof(List) * (H->TableSize));
    if (H->TheLists == NULL)
    {
        puts("Out of Space");
        return NULL;
    }
    /*Allocate List headers*/
    for (int i = 0; i < H->TableSize; i++)
    {
        H->TheLists[i] = (List)malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL)
        {
            puts("Out of Space");
            return NULL;
        }
        else
        {
            //Start Buffer
            H->TheLists[i]->Next = (List)malloc(sizeof(struct ListNode));
            if (H->TheLists[i]->Next == NULL)
            {
                puts("Out of Space");
                return NULL;
            }
            H->TheLists[i]->Last = H->TheLists[i]->Next;
            H->TheLists[i]->Prev = NULL;
            //End Buffer
            H->TheLists[i]->Last->Next = NULL;
            H->TheLists[i]->Last->Last = H->TheLists[i]->Last;
            H->TheLists[i]->Last->Prev = H->TheLists[i];
        }
    }
    return H;
}
List SearchInLinkedListofHSC(ElementType x, int key, PtrTohashSC Hsc, int *posFromStart)
{
    //printf("Entered Search HSC region\n");
    List L;
    List P;

    int posCount=0;

    L = Hsc->TheLists[key];
    P = L->Next;

    //printf("Entering While Loop region\n");
    while (P!= P->Last && P->Element!=x)
    {
        //printf("Entered While Loop region %d times \n",(posCount+1));
        /* code */
        posCount++;
        //printf("Updated Counter, Now attempting P change\n");
        P=P->Next;
        //printf("P Changed , exiting or iterating\n");
    }
    //printf("Exited While region\n");

    if( P!=P->Last && P->Element==x )
    {
        *posFromStart = posCount;
        return P;
    }
    else
    {
        return NULL;
    }
    
}
void InsertIntoHSC(ElementType x, int key, PtrTohashSC Hsc)
{
    //printf("Entered InsertHsc region\n");
    List Pos, NewCell;
    List L;
    int garbage=-1;
    Pos = SearchInLinkedListofHSC(x, key, Hsc, &garbage);
    if (Pos == NULL)
    {
        NewCell = (List)malloc(sizeof(ListNode));
        if (NewCell == NULL)
        {
            puts("Out of Space");
            return;
        }
        else
        {
            L = Hsc->TheLists[key]->Last->Prev;
            NewCell->Next = L->Next;
            NewCell->Last = L->Last;
            NewCell->Prev = L;
            NewCell->Element=x;
            L->Last->Prev = NewCell;
            L->Next=NewCell;
        }
    }
}
// /*For Seperate Chaining*/
// PtrTohashSCD
// InitializeTableSCD(int TableSize)
// {
//     PtrTohashSCD H;

//     // Check for minimal Table size
//     // if(TableSize<MinTableSize)
//     // {
//     //     Error("Table size too small");
//     //     return NULL;
//     // }
//     /*Allocating table*/

//     H = (PtrTohashSCD)malloc(sizeof(hashSCD));
//     if (H == NULL)
//     {
//         puts("Out of Space");
//         return NULL;
//     }

//     H->TableSize = nextPrime(TableSize);
//     /*allocate array of lists*/
//     H->TheLists = (PtrToDeque *)malloc(sizeof(PtrToDeque) * (H->TableSize));
//     if (H->TheLists == NULL)
//     {
//         puts("Out of Space");
//         return NULL;
//     }
//     /*Allocate List headers*/
//     for (int i = 0; i < H->TableSize; i++)
//     {
//         CreateEmptyDeque(&(H->TheLists[i]));
//         if (H->TheLists[i] == NULL)
//         {
//             puts("Out of Space");
//             return NULL;
//         }
//     }
//     return H;
// }

// void InsertToHashSCD(int key, int x, PtrTohashSCD H)
// {
//     inject(&(H->TheLists[key]), x);
// }

// int LocationOfXinSCD(int key, int x, PtrTohashSCD H)
// {
//     return FindInDeque(x, H->TheLists[key]);
// }

// /*For Dequeues*/
// PtrToDeque MakeNode(int x)
// {
//     PtrToDeque P = (PtrToDeque)malloc(sizeof(Deque));
//     assert(P != NULL);

//     P->x = x;
//     P->NextElement = NULL;

//     return P;
// }
// void CreateEmptyDeque(PtrToDeque *S)
// {
//     PtrToDeque SS = MakeNode(0);
//     *S = SS;
//     (*S)->NextElement = MakeNode(0);
//     //(*S)->FirstElement = (*S);
//     (*S)->LastElement = (*S)->NextElement;
//     //(*S)->NextElement->PreviousElement = (*S);
//     //(*S)->PreviousElement = NULL;
// }

// // void push(PtrToDeque *S, int x)
// // {
// //     PtrToDeque PNew = MakeNode(x);

// //     PtrToDeque L = *S;
// //     PNew->x = x;

// //     PNew->NextElement = L->FirstElement->NextElement;
// //     PNew->PreviousElement = L->FirstElement;
// //     PNew->FirstElement = L->FirstElement;
// //     PNew->LastElement = L->LastElement;
// //     L->FirstElement->NextElement->PreviousElement = PNew;
// //     L->FirstElement->NextElement = PNew;
// // }
// void inject(PtrToDeque *S, int x)
// {
//     PtrToDeque PNew = MakeNode(x);

//     PtrToDeque L = *S;
//     PNew->x = x;

//     PNew->NextElement = L->LastElement;
//     //PNew->PreviousElement = L->LastElement->PreviousElement;
//     //PNew->FirstElement = L->FirstElement;
//     PNew->LastElement = L->LastElement;
//     //L->LastElement->PreviousElement->NextElement = PNew;
//     //L->LastElement->PreviousElement = PNew;
// }
// //void pop(PtrToDeque *S, int *x)
// // {
// //     *x = (*S)->FirstElement->NextElement->x;

// //     PtrToDeque Temp2 = (*S)->FirstElement->NextElement;
// //     (*S)->FirstElement->NextElement = (*S)->FirstElement->NextElement->NextElement;
// //     (*S)->FirstElement->NextElement->PreviousElement = (*S);
// //     free(Temp2);
// // }
// // void eject(PtrToDeque *S, int *x)
// // {
// //     *x = (*S)->LastElement->PreviousElement->x;

// //     PtrToDeque Temp2 = (*S)->LastElement->PreviousElement;
// //     (*S)->LastElement->PreviousElement = (*S)->LastElement->PreviousElement->PreviousElement;
// //     (*S)->LastElement->PreviousElement->NextElement = (*S);
// //     free(Temp2);
// // }
// void exitFunc(PtrToDeque S)
// {
//     PtrToDeque temp2 = S;
//     while (S->NextElement != NULL)
//     {
//         PtrToDeque temp = S->NextElement;
//         S = S->NextElement;
//         free(temp);
//     }
//     free(temp2);
// }
// // void PrintDeque(PtrToDeque S)
// // {
// //     printf("\nThe Current Deque is:-\n");

// //     while (S != S->LastElement->PreviousElement)
// //     {
// //         printf(" {%lf } ", S->NextElement->x);

// //         S = S->NextElement;
// //         /* code */
// //     }
// //     puts(" ");
// // }
// int FindInDeque(int x, PtrToDeque S)
// {
//     int pos = 0;
//     //while (S != S->LastElement->PreviousElement)
//     while (S->NextElement!= NULL)
//     {
//         if (x == S->x)
//         {
//             return pos;
//         }

//         S = S->NextElement;
//         pos++;
//         /* code */
//     }
//     return -1;
// }

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
        while (H->TheCells[CurrentPos].info != Empty && H->TheCells[CurrentPos].x != x)
        {
            CurrentPos += 2 * ++CollisionNum - 1;
            while (CurrentPos >= H->TableSize)
            {
                CurrentPos -= H->TableSize;
            }
        }
        return CurrentPos;
    }
    else
    {
        while (H->TheCells[CurrentPos].info != Empty && H->TheCells[CurrentPos].x != x)
        {
            CurrentPos += ++CollisionNum;
            while (CurrentPos >= H->TableSize)
            {
                CurrentPos -= H->TableSize;
            }
        }
        return CurrentPos;
    }
}
void InsertIntoOA(int x, int index, PtrTohashOA H)
{
    H->TheCells[index].x = x;
    H->TheCells[index].info = Legit;
}
/* Hash Functions */
int IdentityHashFunction(int x, int N)
{
    return x % N;
}

PtrTohashOA RehashOA(PtrTohashOA H)
{
    int i, OldSize;
    cell *OldCells;

    OldCells = H->TheCells;
    OldSize = H->TableSize;
    H = InitializeTableOA(2 * OldSize);

    for (i = 0; i < OldSize; i++)
    {
        if (OldCells[i].info == Legit)
        {
            InsertIntoOA(OldCells[i].x, i, H);
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