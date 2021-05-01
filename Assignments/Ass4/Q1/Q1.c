#include<stdio.h>
#include<stdlib.h>

void heapify(int arr[], int size, int i);


//Defining a Struct "Entry" to store Data Values for people.
typedef struct Entry
{
    /* data */
    long int TokenID;
    char Name[20];
}Entry;


int temp;
void mergeCS(Entry* Input, int l, int m, int r);
void mergeSortCS(Entry* Input, int l, int r);
// void heapSortCS(Entry* Input, int size);
// void heapifyCS(Entry* Input, int size, int i);
// void heapify(int arr[], int size, int i);
// void heapSort(int arr[], int size);

        

int main()
{

    //declarations
        //start
            //No. of Entries
            int N;
            //loop counters
            int i,j;
        //end
    



    //Taking Input From User/OJ
        //
        //
        //debuginput
            puts("How many peoples");
        //
        //


        //taking input For People
        scanf("%d",&N);

        //creating data struct to store data for N people
        //Entry Input[N];
        Entry* Input = (Entry*)malloc(sizeof(Entry)*N);

        for( i=0;i<N;i++)
        {   
            //
            //
            //debuginput
                printf("Please give input for %d th person in the form \nTokenId(space)Name(enter)\n",i);
            //
            //


            scanf("%ld %s",&Input[i].TokenID,Input[i].Name);  
            // scanf("%ld %s",&CurrTokenID,&CurrName);
            // Input[i].Name=malloc(sizeof(char)*strlen(name));
        }




    //Processing Data
   
        // heapSortCS(Input,N);
        mergeSortCS( Input, 0, N-1);


    //printing

        //Just Seeing if Input is ok
        //
        //
        //debuginput
            for(i=0;i<N;i++)
            {
                printf("%ld %s\n",Input[i].TokenID,Input[i].Name);
            }
        //
        //
    
}

void mergeCS(Entry* Input, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    Entry L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = Input[l + i];
    for (j = 0; j < n2; j++)
        R[j] = Input[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i].TokenID <= R[j].TokenID) {
            Input[k] = L[i];
            i++;
        }
        else {
            Input[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        Input[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        Input[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSortCS(Entry * Input, int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSortCS(Input, l, m);
        mergeSortCS(Input, m + 1, r);
 
        mergeCS(Input, l, m, r);
    }
}

// void merge(Entry** Input, int l, int m, int r)
// {
//     int i, j, k;
//     int n1 = m - l + 1;
//     int n2 = r - m;
 
//     /* create temp arrays */
//     Entry *L[n1],* R[n2];
 
//     /* Copy data to temp arrays L[] and R[] */
//     for (i = 0; i < n1; i++)
//         L[i] = Input[l + i];
//     for (j = 0; j < n2; j++)
//         R[j] = Input[m + 1 + j];
 
//     /* Merge the temp arrays back into arr[l..r]*/
//     i = 0; // Initial index of first subarray
//     j = 0; // Initial index of second subarray
//     k = l; // Initial index of merged subarray
//     while (i < n1 && j < n2) {
//         if (L[i]->TokenID <= R[j]->TokenID) {
//             Input[k] = L[i];
//             i++;
//         }
//         else {
//             Input[k] = R[j];
//             j++;
//         }
//         k++;
//     }
 
//     /* Copy the remaining elements of L[], if there
//     are any */
//     while (i < n1) {
//         Input[k] = L[i];
//         i++;
//         k++;
//     }
 
//     /* Copy the remaining elements of R[], if there
//     are any */
//     while (j < n2) {
//         Input[k] = R[j];
//         j++;
//         k++;
//     }
// }
 
// /* l is for left index and r is right index of the
// sub-array of arr to be sorted */
// void mergeSort(Entry ** Input, int l, int r)
// {
//     if (l < r) {
//         // Same as (l+r)/2, but avoids overflow for
//         // large l and h
//         int m = l + (r - l) / 2;
 
//         // Sort first and second halves
//         mergeSort(Input, l, m);
//         mergeSort(Input, m + 1, r);
 
//         merge(Input, l, m, r);
//     }
// }

// void heapSortCS(Entry* Input, int size)
// {
//     int i;
//     for (i = size / 2 - 1; i >= 0; i--)
//         heapifyCS(Input, size, i);
//     for (i = size - 1; i >= 0; i--)
//     {
//         Entry tempIN = Input[0];
//         Input[0] = Input[i];
//         Input[i] = tempIN;
//         heapifyCS(Input, i, 0);
//     }
// }

// void heapifyCS(Entry* Input, int size, int i)
// {
//     int largest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if (left < size && Input[left].TokenID > Input[largest].TokenID)
//         largest = left;

//     if (right < size && Input[right].TokenID > Input[largest].TokenID)
//         largest = right;

//     if (largest != i)
//     {
//         Entry tempIN = Input[i];
//         Input[i] = Input[largest];
//         Input[largest] = tempIN;
//         heapifyCS(Input, size, largest);
//     }
// }

// void heapify(int arr[], int size, int i)
// {
//     int largest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if (left < size && arr[left] > arr[largest])
//         largest = left;

//     if (right < size && arr[right] > arr[largest])
//         largest = right;

//     if (largest != i)
//     {
//         temp = arr[i];
//         arr[i] = arr[largest];
//         arr[largest] = temp;
//         heapify(arr, size, largest);
//     }
// }

// void heapSort(int arr[], int size)
// {
//     int i;
//     for (i = size / 2 - 1; i >= 0; i--)
//         heapify(arr, size, i);
//     for (i = size - 1; i >= 0; i--)
//     {
//         temp = arr[0];
//         arr[0] = arr[i];
//         arr[i] = temp;
//         heapify(arr, i, 0);
//     }
// }   
