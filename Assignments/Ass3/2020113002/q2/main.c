#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <assert.h>
#include <stdbool.h>

long int main()
{
    char Current_Word[33];
    long int N, M;

    //fflush(stdin);
    scanf("%ld", &N);
    while ((getchar()) != '\n')
        ;
    PtrTohashSCD Hscd = InitializeTableSC(3380);
    //Building Dictionary
    for (long int i = 0; i < N; i++)
    {
        ////printf("Entered SC region\n");

        scanf("%s", &Current_Word);
        while ((getchar()) != '\n')
        ////printf("Entering For Loop region\n");

        {
            //printf("Entered For Loop region %ld times\n",i+1);

            scanf("%s", Current_Word);
            while (1)
            {
                char check = getchar();
                if (check == EOF || check == '\n')
                    break;
            }
            char *p = Current_Word;

            int key = 1;

            while (*p != '\0')
            {
                key *= (int)(*p - 'a' + 1);
                p++;
            }
            key=key%Hscd->TableSize;

            InsertIntoHSCD(Current_Word, key, Hscd);
            //printf("Exited + region\n");
        }
    }

    while ((getchar()) != '\n')
        ;
    scanf("%ld", &M);
    while ((getchar()) != '\n')
        ;


    //Seeing if found in the Dictionary
    int Count_Fails = 0;
    char** FailArray;
    for (long int i = 0; i < M; i++)
    {
        scanf("%s", &Current_Word);
        while ((getchar()) == ' ')
            ;

        char *p = Current_Word;

        int key = 1;
        while (*p != '\0')
        {
            key *= (int)(*p - 'a' + 1);
            p++;
        }
        key=key%Hscd->TableSize;


        int posFromStart=-1;
        SearchInLinkedListofHSCD( Current_Word,  key,  Hscd,  &posFromStart);

        if(posFromStart==-1)
        {
            FailArray[Count_Fails]=malloc(sizeof(char*));
            *FailArray[Count_Fails]=malloc(sizeof(char)*(strlen(Current_Word)+1));
            strcpy(FailArray[Count_Fails],Current_Word);
            Count_Fails++;
        }
    }

    //Printing
    puts(Count_Fails);
    for (long int i=0;i<M;i++)
    {
        printf("%s\n",FailArray[i]);
    }

    return 0;
}