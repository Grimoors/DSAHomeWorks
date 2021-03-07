#include "SinglyLinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main()
{
	List L=NULL;
	PtrToNode P;

	// This doesn't work as intended !
	//CreateEmptyList2(L);
	//assert(L != NULL);

	// Use one of the following 	
	CreateEmptyList1(&L);
	// or
	//L = CreateEmptyList();

	// Insert item at front of list	
	InsertAtFront(&L,1);
	InsertAtFront(&L,2);
	InsertAtFront(&L,3);
	InsertAtFront(&L,4);// 4 3 2 1
	InsertAtFront(&L,2);
	long int test_Case= FindLast(&L,2);
	printf("The '2' was found at %ld\n Now we will run DeleteAll \n",test_Case);

	DeleteAll(&L,2);

	test_Case= FindLast(&L,2);
	printf("After Deletion The '2' was found at %ld\n",test_Case);
	printf("If the value was -1, deletion succeded\n");


	//DeleteList(&L);
	
	return 0;
}
