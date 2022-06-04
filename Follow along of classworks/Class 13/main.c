#include "sorts.h"
int main()
{
    ElementType A[] = {6,1,3,4,2,7,8};
    int numElems = sizeof(A)/sizeof(ElementType);

    InsertionSort_2(A,numELems,asc_order);

    for(i=0;i<numElems;i++)
    {
        printf("%d ",A[i]);
    }
    puts(" ");

    return 0;
}




// struct Student Record
// {
//     double weight;
//     double height;
//     char* studentName;
// }

// sort_by_weight();

// sort_by_height();

