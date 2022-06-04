#include<stdio.h>
#include<stdlib.h>

typedef long int lli;

lli preProcess(lli* mat, lli *aux,lli N);
lli NoOfKoolsFor(lli*aux,lli X, lli k, lli N);
lli sumQuery(lli* aux, lli tli, lli tlj, lli rbi,lli rbj,lli N);



int main()
{
    //Taking input
        //Declarations
        lli N,k;
        lli* A;
        lli X;
        lli output =0;

        //loop counter
        lli i;

        //Running the Scans


        scanf("%ld%ld",&N,&k);

            //Mallocing the Variable size array
            A= (lli*)malloc(sizeof(lli)*N);
        

        for(i=0;i<N;i++)
        {   

            scanf("%ld",&A[i]);

        }


        scanf("%ld",&X);
    //processing Data


        //Generate "M Matrix" Uses N*2 Storage.Takes N^2 time to calculate??

            //Initialize the Matrix M
                
                lli *M=(lli*)calloc(N*N,sizeof(lli));
            
            //Fill Values into Matrix
                for(i=0;i<N;i++)
                {
                    for(lli j =0;j<N;j++)
                    {
                        M[(i*N)+j]=A[i]+A[j];//N^2
                    }
                }
        
                preProcess(M,M,N);
            
        //For value of k, Check now many submatrices have strength "X", in log N or lesser time.
            
            //For X, and a given K
                output=NoOfKoolsFor(M,X,k,N);

    //Giving output
    printf("%ld\n",output);


return 0;
}

lli preProcess(lli *mat, lli *aux,lli N)
{
    
   // Do column wise sum
   for (lli i=1; i<N; i++)
      for (lli j=0; j<N; j++)
         aux[i*N+j] = mat[i*N+j] + aux[(i-1)*N+j];
  
   // Do row wise sum
   for (lli i=0; i<N; i++)
      for (lli j=1; j<N; j++)
         aux[i*N+j] += aux[i*N+(j-1)];
    
    return 0;
}

lli NoOfKoolsFor(lli*aux,lli X, lli k, lli N)
{
    //Kool matrix is pxp
    lli p=N-k;


    lli output =0;

    for(lli i=0;i<=p;i++)
    {
        for(lli j=0;j<=p;j++)
        {
            if(X==sumQuery(aux,i,j,i+k-1,j+k-1,N))
            {
                output++;
            }
        }
    }
    
    return output;
}

lli sumQuery(lli* aux, lli tli, lli tlj, lli rbi,lli rbj,lli N)
{
    // result is now sum of elements between (0, 0) and
    // (rbi, rbj)
    lli res = aux[rbi*N+rbj];
  
    // Remove elements between (0, 0) and (tli-1, rbj)
    if (tli > 0)
       res = res - aux[(tli-1)*N+rbj];
  
    // Remove elements between (0, 0) and (rbi, tlj-1)
    if (tlj > 0)
       res = res - aux[rbi*N+(tlj-1)];
  
    // Add aux[tli-1][tlj-1] as elements between (0, 0)
    // and (tli-1, tlj-1) are subtracted twice
    if (tli > 0 && tlj > 0)
       res = res + aux[(tli-1)*N+(tlj-1)];
  
    return res;
}