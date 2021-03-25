void Indirect_Sorting(ElemTypePtr A, int numElems,int comp(const ElemTypePtr a, const ElemTypePtr b))
{
    int i,j;
    ElemTypePtr *P;
    ElemType tmp;

    P=Insertion_Sort_Ptr(A,numElems,comp);

    for(i=0;i<numElems;i++)
    {
        //when i=2;
        if(P[i]!=&A[i]) // A]i] is not in its sorted position
        {
            //P[i] -> is some element of A which is in i-th sorted order
            tmp=A[i]; // tmp =A[2]
            j=i;
            while(P[j]!=&A[i])
            {
                A[j]=*P[j]; //A[2]=A[4]
                offset_j= P[j]-&A[0]; //&A[4]- &A[0]
                P[j]=&A[j];
                j=offset_j;
            }
            A[j]=tmp;
            P[j]=&A[j];

            
        }
    }
}

void MergeSort(ElemTypePtr A, int lower,int upper)
{
    int middle
    if(lower<upper)
    {
        middle = (lower+upper)/2;
        MergeSort((A,lower,middle));
        MergeSort(A,middle+1;,upper);
        Merge(A,lower,middle,upper);
    }
}

void Merge()
{

}


//Mergesort with LinkedList // Insertion Sort (linkedLists)

void MergeSort(ListPtr* Head_Ref)
{
    List *first=NULL, *second=NULL;
    List *head=*Head_Ref;

    if(head==NULL||head->next==NULL)
    {
        return;
    }

    SplitListInMiddle(head,&first,&second);
    MergeSort((&first));
    MergeSort((&second));
    *Head_Ref= SortedMerge(first,second);
    
}


void SortedMerge()
{

}

//Insertion Sort (++ in linked List, insertions are O(k)



//QuickSort

void QuickSort(ElemTypePtr A,int numElems)
{
    QuickSortDriver(A,0,numElems-1);
}
void QuickSortDriver(ElemTypePtr A,int lower,int upper)
{
    int pivotIndex;
    if(lower<upper)
    {
        pivotIndx=QPartition(A,lower,upper);
        QuickSortDriver(A,lower,pivotIndex-1);
        QuickSortDriver(A,pivotIndex+1,upper);
    }
}
int QPartition( ElemTypePtr A; int lower, int upper)
{

    pivot_value =A[upper];  
}