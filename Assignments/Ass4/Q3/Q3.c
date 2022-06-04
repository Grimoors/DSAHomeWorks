#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool GoRight(short *Moving, long int *freqTab, short *A, int *curri, int *currj, int k, int N);
void UpdateOutput(short *Moving, long int *freqTab, double *Output, long int *CumulativeFreqTab, int *curri, int *currj, int k);
bool GoDown(short *Moving, long int *freqTab, short *A, int *curri, int *currj, int k, int N);
bool GoLeft(short *Moving, long int *freqTab, short *A, int *curri, int *currj, int k, int N);

int main()
{

    //Taking Input
    //Declarations
    int N, k;
    short *A;

    int i, j;
    //Taking Input
    //TestIn
//    puts("Input N, K in format\nN k\n");
    //

    scanf("%d%d", &N, &k);

    A = (short *)calloc(N * N, sizeof(short));

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            //TestIn
 //           printf("Input A[%d][%d] = ", i, j);
            //

            scanf("%hd", &A[(i * N) + j]);

            //TestIn
 //           printf("\n");
            //
        }
    }

    //Processing Input

 //   printf("Creating the 'moving window'\n");

    short *Moving = (short *)calloc(k * k, sizeof(short));
  //  printf("Creating the 'Moving Frequency Table'\n");
    long int *freqTab = (long int *)calloc(21, sizeof(long int));
 //  printf("Creating the 'Cumulative Frequency Table'\n");
    long int *CumulativeFreqTab = (long int *)calloc(21, sizeof(long int ));
   // puts("Creating items for median calculation");
    int index = 0;
    double CurrMedian;
    int evenInd=0;

    //puts("Creating Output Array");
    double *Output = (double *)calloc((k * k), sizeof(double));

    //puts("Initialising Moving Window and freq table");
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            //puts("attacking Moving");
            Moving[(i * k) + j] = A[(i * N) + j];
           // printf("i = %d th and j= %d th pos of Moving table = %d\n",i,j,Moving[(i * k) + j]);
            //puts("attacking freq Tab");
            freqTab[Moving[i * k + j]]++;
        }
    }
   // puts("Creating Cumulative freq table, finding median index, finding median value, saving to output");
    for (int i = 1; i < 21; i++)
    {
        CumulativeFreqTab[i] = CumulativeFreqTab[i - 1] + freqTab[i];
    }

    //     for(int i=0;i<21;i++)
    // {
    //     printf("%d th pos of freq table = %ld\n",i,freqTab[i]);
    // }
    
    //     for(int i=0;i<21;i++)
    // {
    //     printf("%d th pos of Cumulative freq table = %ld\n",i,CumulativeFreqTab[i]);
    // }
   // puts("dbug1");
    
    if (k % 2 == 0)
    {
        index = (k*k) / 2;
        evenInd=index+1;

    }
    else
    {
        index =((k*k)+1)/2;
    }



    int val = 0;
    while (1)
    {
     //   puts("dbug2");
        if (CumulativeFreqTab[val] < index)
        {
            val++;
        }
        else
        {

            break;
        }
    }
   // puts("dbug3");
//     if (k % 2 == 0)
//     {

//         if (CumulativeFreqTab[val] >= index + 1)
//         {
//             CurrMedian = val;
//         }
//         else
//         {
//             //find val2, CurrMedian = val2+val /2;
//             int val2 = val;
//             while(CumulativeFreqTab[val2] < index + 1)
//             {
//                 val2++;
//             }
//             CurrMedian = (val + val2) / 2;
//         }
//    //     puts("dbug4");
//     }
//     else
//     {
//         if (CumulativeFreqTab[val] >= index + 1)
//         {
//             CurrMedian = val;
//      //       puts("dbug5");
//         }
//         else
//         {
//             //find val2 || CumulativeFreqTab[val2]<index+1
//             int val2 = val;
//             while(CumulativeFreqTab[val2] < index + 1)
//             {
//                 val2++;
//             }
//             CurrMedian = val2;
//        //     puts("dbug6");
//         }
//     }
    CurrMedian = val;
    Output[0] = CurrMedian;
    //printf("\n\n%0.0lf\n\n",Output[0]);
   // puts("dbug7");

  //  puts("Starting window movements");
    //  Starting Conditions
    bool CanGoDown = true;
    bool CanGoRight = true;
    bool CanGoLeft = true;

    //puts("Movement loop");
    int curri = 0, currj = 0;
    while (CanGoDown||CanGoRight)
    {
       // puts("Looping,");

 //       puts("Checking right");
        while (CanGoRight)
        {
   //         puts("Going right");
            CanGoRight = GoRight(Moving, freqTab, A, &curri, &currj, k, N);

     //       puts("Updating output");
            UpdateOutput(Moving, freqTab, Output, CumulativeFreqTab, &curri, &currj, k);

       //     puts("Checking Right");
        }
//        puts("Checking Down");
        if (CanGoDown)
        {
  //          puts("Going Down");
            CanGoDown = GoDown(Moving, freqTab, A, &curri, &currj, k, N);
    //        puts("Updating Output");
            UpdateOutput(Moving, freqTab, Output, CumulativeFreqTab, &curri, &currj, k);

      //      puts("Cheking left");

            if(!CanGoRight)
            {
                CanGoLeft=true;
            }

            while (CanGoLeft)
            {
        //        puts("Going Left");
                CanGoLeft = GoLeft(Moving, freqTab, A, &curri, &currj, k, N);
          //      puts("Updating Output");
                UpdateOutput(Moving, freqTab, Output, CumulativeFreqTab, &curri, &currj, k);
            //    puts("Checking Left");
            }

            //puts("Checking Down");
            if (CanGoDown)
            {
//                puts("Going Down");
                CanGoDown = GoDown(Moving, freqTab, A, &curri, &currj, k, N);
  //              puts("Updating output");
                UpdateOutput(Moving, freqTab, Output, CumulativeFreqTab, &curri, &currj, k);
            }
            if(!CanGoLeft)
            {
                CanGoRight=true;
            }
        }
    }

    //Printing output

    // //TestIn
    // //printf("Input of N = %d, k = %d \n", N, k);
    // printf("Our input array = \n");
    // for (i = 0; i < N; i++)
    // {
    //     for (j = 0; j < N; j++)
    //     {
    //         printf("%d\t", A[(i * N) + j]);
    //     }
    //     printf("\n");
    // }
    // //

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            printf("%0.0lf ", Output[i * k + j]);
        }
        printf("\n");
    }

    return 0;
}

bool GoRight(short *Moving, long int *freqTab, short *A, int *curri, int *currj, int k, int N)
{

   // puts("Starting Right Moving");
    *currj += 1;

  //  puts("//short *TempVector=(short*)calloc(k,sizeof(short));");
  //  puts("Updating Thingys");
    for (int i = 0; i < k; i++)
    {
        freqTab[Moving[((i)*k)]]--;
        Moving[((i)*k)] = A[(((*curri) + i) * N + (*currj) + k -1)];
        freqTab[Moving[((i)*k)]]++;
    }




  //  puts("//FlipColumns(Moving,curri,currj,k,N);");
    for (int j = 0; j < k - 1; j++)
    {
        for (int i = 0; i < k; i++)
        {
            Moving[(i * k) + j] += Moving[(i * k) + j + 1];
            Moving[(i * k) + j + 1] = Moving[(i * k) + j] - Moving[(i * k) + j + 1];
            Moving[(i * k) + j] -= Moving[(i * k) + j + 1];
        }
    }

    if (*currj < N - k )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GoLeft(short *Moving, long int *freqTab, short *A, int *curri, int *currj, int k, int N)
{

    *currj -= 1;

    //short *TempVector=(short*)calloc(k,sizeof(short));
    for (int i = 0; i < k; i++)
    {
        freqTab[Moving[((i)*k) + (k - 1)]]--;
        Moving[((i)*k) + (k - 1)] = A[(((*curri + i)) * N + (*currj))];
        freqTab[Moving[((i)*k) + (k - 1)]]++;
    }

    //FlipColumns(Moving,curri,currj,k,N);
    for (int j = k - 2; j >= 0; j--)
    {
        for (int i = 0; i < k; i++)
        {
            Moving[(i * k) + j] += Moving[(i * k) + j + 1];
            Moving[(i * k) + j + 1] = Moving[(i * k) + j] - Moving[(i * k) + j + 1];
            Moving[(i * k) + j] -= Moving[(i * k) + j + 1];
        }
    }

    if (*currj > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GoDown(short *Moving, long int *freqTab, short *A, int *curri, int *currj, int k, int N)
{

    *curri += 1;

    //short *TempVector=(short*)calloc(k,sizeof(short));
    for (int j = 0; j < k; j++)
    {
        freqTab[Moving[j]]--;
        Moving[j] = A[(((*curri) + k - 1) * N + (*currj+j))];
        freqTab[Moving[j]]++;
    }
    // for(int i=0;i<k;i++)
    // {
    // for(int j=0;j<k;j++)
    //  printf("i = %d th and j= %d th pos of Moving table = %d\n",i,j,Moving[(i * k) + j]);
    // }
    // for(int i=0;i<21;i++)
    // {
    //     printf("%d th pos of freq table = %ld\n",i,freqTab[i]);
    // }

    //FlipRows(Moving,curri,currj,k,N);
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = 0; j < k; j++)
        {
            Moving[(i * k) + j] += Moving[((i + 1) * k) + j];
            Moving[((i + 1) * k) + j] = Moving[(i * k) + j] - Moving[((i + 1) * k) + j];
            Moving[(i * k) + j] -= Moving[((i + 1) * k) + j];
        }
    }

    if (*curri < N - k )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void UpdateOutput(short *Moving, long int *freqTab, double *Output, long int *CumulativeFreqTab, int *curri, int *currj, int k)
{
    int index = 0;
    int evenInd=0;
    double CurrMedian;

 // puts("Creating Cumulative freq table, finding median index, finding median value, saving to output");
    for (int i = 1; i < 21; i++)
    {
        CumulativeFreqTab[i] = CumulativeFreqTab[i - 1] + freqTab[i];
    }
    
    //     for(int i=0;i<21;i++)
    // {
    //     printf("%d th pos of Cumulative freq table = %ld\n",i,CumulativeFreqTab[i]);
    // }
   // puts("dbug1");
    
    if (k % 2 == 0)
    {
        index = (k*k) / 2;
        evenInd=index+1;

    }
    else
    {
        index =((k*k)+1)/2;
    }
    
  //  printf("Index = %d",index);


    int val = 0;
    while (1)
    {
     //   puts("dbug2");
        if (CumulativeFreqTab[val] < index)
        {
            val++;
        }
        else
        {

            break;
        }
    }
   // puts("dbug3");
//     if (k % 2 == 0)
//     {

//         if (CumulativeFreqTab[val] >= index + 1)
//         {
//             CurrMedian = val;
//         }
//         else
//         {
//             //find val2, CurrMedian = val2+val /2;
//             int val2 = val;
//             while(CumulativeFreqTab[val2] < index + 1)
//             {
//                 val2++;
//             }
//             CurrMedian = (val + val2) / 2;
//         }
//    //     puts("dbug4");
//     }
//     else
//     {
//         if (CumulativeFreqTab[val] >= index + 1)
//         {
//             CurrMedian = val;
//      //       puts("dbug5");
//         }
//         else
//         {
//             //find val2 || CumulativeFreqTab[val2]<index+1
//             int val2 = val;
//             while(CumulativeFreqTab[val2] < index + 1)
//             {
//                 val2++;
//             }
//             CurrMedian = val2;
//        //     puts("dbug6");
//         }
//     }
    CurrMedian = val;
 //   printf("%lf",CurrMedian);
    Output[*curri * k + *currj] = CurrMedian;
}