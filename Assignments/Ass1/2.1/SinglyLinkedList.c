#include "SinglyLinkedList.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

PtrToNode MakeNode(ElementType X)
{
    PtrToNode P = (PtrToNode)malloc(sizeof(ListNode));
    assert(P != NULL);

    P->Element = X;
    P->Next = NULL;

    return P;
}

List CreateEmptyList()
{
    PtrToNode P = MakeNode(0);
    return P;
}

void CreateEmptyList1(List *PP)
{
    PtrToNode P = MakeNode(0);

    *PP = P;
}

void CreateEmptyList2(List PP)
{
    PtrToNode P = (PtrToNode)malloc(sizeof(ListNode));

    /*
    * Operations alag se
    * 
    * 
    * 
    * 
    * */
    assert(P != NULL);
    P->Next = NULL;

    PP = P;
}

void InsertAtFront(List *LP, ElementType X)
{
    PtrToNode PNew = MakeNode(X);
    List L = *LP;

    PNew->Next = L->Next;
    L->Next = PNew;
}

void DeleteNode(PtrToNode P)
{
    if (!P)
        free(P);
}


//Assignment 2.1 Code Start


long int FindLast(List *_searchInThis, ElementType _searchForThis)
{
    List L = *_searchInThis;
    long int depth = -1;
    long int k = -1;
    //while enterening, I search the header, the "0"th element
    while (L->Next != NULL)
    {
        k++;                    // on first entry, k=0;
        printf("k = %ld\n", k); //
        if (L->Element == _searchForThis)
            depth = k;
        L = L->Next;
    }
    return depth;
}

void DeleteAll(List *_deleteInThis, ElementType _deleteThis)
{
    List L = *_deleteInThis;
    List temp;

    while (L->Next->Next != NULL)
    {
        if (L->Next->Element == _deleteThis)
        {
            temp = L->Next->Next;
            free(L->Next);// depth n+1 is freed, (.elements and .next is freed)
            L->Next = temp;
            continue;
        }

        L = L->Next;
    }
    if(L->Next->Element==_deleteThis)
    {
        free(L->Next);
        L->Next=NULL;
    }
}



//Assignment 2.1 code/end