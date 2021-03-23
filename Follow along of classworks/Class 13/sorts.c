#include"sorts.h"
void InsertionSort(){

}
int asc_order(const ElementType a, const ElementType b)
{
    return (a<b);
}
int desc_order(const ELementType b, const ElementType b)
{
    return (1-asc_order(a,b));
}
void InsertionSort_2(ElementTypePtrA, int numElems,int comp(const ElementType a, const ElementType b)){
    int i,j;
    ElementType curr;
    assert(NumElems>1);
    for(i=1;i<numElems;i++)
    {
        curr=A[i];
        j=i-1;
        //while((j>=0)&&comp(curr<A[j]))
        while((j>=0)&&comp(curr,A[j]))
        {
            A[j+1]=A[j];
            --j;
        }
// Either j=-1; or curr>-A[j]
        A[j+1]=curr;

    }
}
