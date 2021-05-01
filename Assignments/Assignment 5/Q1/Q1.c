#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//#include Sirs codes
#include "./../Boilers/queue.h"
#include "./../Boilers/Graph.h"
typedef long long ll;



enum WWTElemStates {Uninitiated, Initiated};

typedef struct Q1_WaterWayTableElement
{
    enum WWTElemStates state;
    ll yi;
    /* data */
}WWTE;

typedef WWTE * WWT;



int main()
{
    //Taking Input
    ll N,X,Y,ai,bi,si,xi,yi,output=0;

    scanf("%lld %lld %lld",&N,&X,&Y);

    //Initializing Containers for "Graphs"
        //Airways

        //Waterways
            /*//Explaination
                //Destinations    2  3  4 ...  n
                    //Root = 1 [ y2 y3 y4 ... yn ] // works for only 1 waterway from 1 to 2
                    (However, Our Waterway might have multiple edges from 1 to a node.)
                    hence we keep an "Unitialized" vs "Initialized" flag and update the least
                    value of distance and update the output instantly if there is a shorter waterway.
                    */
                    WWT Q1Waterways=(WWT)calloc(N+1,sizeof(WWTE));
            
            

    for (ll i = 0; i < X; i++)
    {
        scanf("%lld %lld %lld",&ai,&bi,&si);


    }

    // Dealing with input of Waterways.
    for(ll i = 0; i < Y; i++)
    {
        scanf("%lld %lld",&xi,&yi);
        //Preprocessing Inputs
            //xi = Node , yi= Dist from Node 1
            if(Q1Waterways[xi].state==Uninitiated)
            {
                Q1Waterways[xi].yi=yi; // Updating yi, it didn't exist before.
                Q1Waterways[xi].state=Initiated;
            }
            else // Corner Case of multiple waterways from 1 to a node is covered.
            {
                ll temp = min_ll(Q1Waterways[xi].yi,yi);
                Q1Waterways[xi].yi=temp;
                output++;
            }
    }
    
    
    
    //Processing



    //Printing Output;
    printf("%lld",output);

    return 0;
}


