#include<stdio.h>
#include<stdlib.h>








int main()
{
    //Taking input
        //Declarations
        int N,k=0;
        int* A;
        int X;
        int output =0;

        //loop counter
        int i;

        //Running the Scans

        //
        //
        //debuginput
            printf("Input values of N and K in form\nN\n");
        //
        //
        scanf("%d%d",&N);

            //Mallocing the Variable size array
            A= (int*)malloc(sizeof(int)*N);
        
        //
        //
        //debuginput
            printf("Input value of the N inputs for A\n");
        //
        //
        for(i=0;i<N;i++)
        {   
            //
            //
            //debuginput
                printf("A[%d]= ",i);
            //
            //
            scanf("%d",&A[i]);
            //
            //
            //debuginput
                printf("\n");
            //
            //
        }

        //
        //
        //debuginput
            printf("Input the Value for X\n");
        //
        //
        scanf("%d",&X);
    //processing Data


    //Giving output
    printf("%d",output);
    //
    //
    //debuginput
        printf("Inputted value of N= %d,k= %d,X= %d \n",N,k,X);
        printf("Inputted value of matrix A is \n");
        for(i=0;i<N;i++)
        {
            printf("A[%d]= %d \t",i,A[i]); 
        }
    //
    //


}

