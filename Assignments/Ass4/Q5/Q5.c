#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int main()
{
    

    
    //Taking input
        //Declarations
        int N,k;
        int* A;
        int X;
        int output =0;

        //loop counter
        int i;

        //Running the Scans
        scanf("%d%d",&N,&k);

            //Mallocing the Variable size array
            A= (int*)malloc(sizeof(int)*N);

        for(i=0;i<N;i++)
        {   

            scanf("%d",&A[i]);

        }

    
        scanf("%d",&X);



    //Process

    int * SubmatrixHack= (int*)calloc(N,sizeof(N));

    for(int i=0;i<N-k;i++)
    {
        for(int j=0;j<k;j++)
        SubmatrixHack[i]+=A[i+j];
    }

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(X==(k*(SubmatrixHack[i]+SubmatrixHack[j])))
            {
                output++;
            }
        }
    }


    //Output
    
    //Giving output
    printf("%d\n",output);



    return 0;
}