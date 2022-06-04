#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "./../hash.h"

int main()
{
    char Current_Word[33];
    long int N, M;

    //fflush(stdin);
    scanf("%ld", &N);
    while ((getchar()) != '\n')
        ;
    PtrTohashSCD Hscd = InitializeTableSCD(3380);
    //Building Dictionary
    for (long int i = 0; i < N; i++)
    {
        ////printf("Entered SC region\n");

        scanf("%s", Current_Word);
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

            int key = 1;

            int length = strlen(p);
            if (length >= 3)
            {
                key *= (int)(Current_Word[0] - 'a' + 1);
                key *= (int)(Current_Word[1] - 'a' + 1);
                key *= (int)(Current_Word[2] - 'a' + 1);
            }
            else
            {
                if (length = 2)
                {
                    key *= (int)(Current_Word[0] - 'a' + 1);
                    key *= (int)(Current_Word[1] - 'a' + 1);
                }
                else
                {
                    if (length = 1)
                    {
                        key *= (int)(Current_Word[0] - 'a' + 1);
                    }
                }
            }
            // while (*p != '\0')
            // {
            //     key *= (int)(*p - 'a' + 1);
            //     p++;
            // }
            key = key % Hscd->TableSize;

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
    long int Count_Fails = 0;
    ListD FailList = (ListD)malloc(sizeof(struct ListNodeD));
    FailList->Next = (ListD)malloc(sizeof(struct ListNodeD));
    FailList->Last = FailList->Next;
    FailList->Prev = NULL;
    //End Buffer
    FailList->Last->Next = NULL;
    FailList->Last->Last = FailList->Last;
    FailList->Last->Prev = FailList;

    for (long int i = 0; i < M; i++)
    {
        scanf("%s", Current_Word);
        while ((getchar()) == ' ')
            ;

        char *p = Current_Word;

        int key = 1;
        while (*p != '\0')
        {
            key *= (int)(*p - 'a' + 1);
            p++;
        }
        key = key % Hscd->TableSize;

        long int posFromStart = -1;
        SearchInLinkedListofHSCD(Current_Word, key, Hscd, &posFromStart);

        if (posFromStart == -1)
        {
            ListD NewCell= (ListD)malloc(sizeof(ListNodeD));
            ListD L = FailList->Last->Prev;
            NewCell->Next = L->Next;
            NewCell->Last = L->Last;
            NewCell->Prev = L;
            //NewCell->Element=x;//Changes to be made.

            int k = strlen(Current_Word);
            NewCell->Element = malloc(sizeof(char) * (k + 1));
            NewCell->Element = strcpy(NewCell->Element, Current_Word);

            L->Last->Prev = NewCell;
            L->Next = NewCell;

            Count_Fails++;
        }
    }

    //Printing
    printf("%ld", Count_Fails);
    ListD P = FailList->Next;
    while (P != P->Last)
    {
        printf("%s\n",P->Element);
        P=P->Next;
    }

    return 0;
}