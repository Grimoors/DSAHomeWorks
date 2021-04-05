#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <assert.h>
#include <stdbool.h>

int main()
{
    char mode[20];
    int N, Q;
    bool HashModeQuad;
    int countfilled;

    scanf("%s", mode);
    while ((getchar()) != '\n')
        ;
    //fflush(stdin);
    scanf("%d", &N);
    while ((getchar()) != '\n')
        ;
    //fflush(stdin);
    scanf("%d", &Q);
    while ((getchar()) != '\n')
        ;
    //fflush(stdin);

    //printf("%d\n", N);
    //printf("%d\n", Q);

    int RehashNo = N / 2;

    if ((mode[0] == 's') || (mode[0] == 'S'))
    {
        ////printf("Entered SC region\n");
        PtrTohashSC Hsc = InitializeTableSC(N);

        ////printf("Entering For Loop region\n");
        for (int i = 0; i < Q; i++)
        {
            //printf("Entered For Loop region %d times\n",i+1);
            char s;
            int x;

            scanf("%c %d", &s, &x);
            while (1)
            {
                char check = getchar();
                if(check==EOF||check=='\n')
                break;
            }
                

        Retry_adding:;

            //puts(mode);
            //printf("%c\n", s);
            //printf("%d\n", x);
            //fflush(stdin);
            int key = IdentityHashFunction(x, Hsc->TableSize);

            //printf("Entered IF region\n");
            if (s == '+')
            {
                //printf("Entered + region\n");
                /* code */
                InsertIntoHSC(x, key, Hsc);
                //printf("Exited + region\n");
            }
            else
            {
                /* code */
                if (/* condition */ s == '?')
                {
                    //printf("Entered ? region\n");
                    /* code */
                    int posFromStart=-1;
                    List ElemPosPoint = SearchInLinkedListofHSC(x, key, Hsc, &posFromStart);
                    printf("%d\n", posFromStart);
                    //printf("Exited ? region\n");
                }
                else
                {
                    printf("Please Give input again!!\n");
                    scanf("%c %d", &s, &x);
                    while ((getchar()) != '\n')
                        ;
                    goto Retry_adding;
                    /* code */
                }
            }
            //printf("Exited IF region\n");
            //printf("i updated, exiting or iterating in region\n");
        }
        //printf("Exited FOR region\n");
        //printf("Exiting SC region\n");
        for (int i = 0; i < Hsc->TableSize; i++)
            free(Hsc->TheLists[i]);
        free(Hsc);
    }
    // switch (s)
    // {
    //     case '+':
    //         {
    //             InsertToHashSCD(key, x, H);
    //         }
    //     break;
    //     case '?':
    //         {
    //             printf("%d\n", LocationOfXinSCD(key, x, H));
    //             //fflush(stdout);
    //         }
    //     break;
    //     }
    // }
    else
    {
        if (/* condition */ (mode[0] == 'L') || (mode[0] == 'l'))
        {
            /* code */
        }
        else
        {
            /* code */
            if (/* condition */ (mode[0] == 'Q') || (mode[0] == 'q'))
            {
                /* code */
            }
            else
            {
                printf("Incorrect mode entered, please Try again!!");
                scanf("%s", mode);
                while ((getchar()) != '\n')
                    ;
            }
        }
    }

    return 0;
}
//     switch (mode[0])
//     {
//         case 'l':
//         case 'L':
//         {
//             countfilled = 0;
//             HashModeQuad = false;
//             PtrTohashOA H = InitializeTableOA(N);
//             for (int i = 0; i < Q; i++)
//             {

//                 char s;
//                 int x;

//                 scanf("%c %d", &s, &x);
//                 while ((getchar()) != '\n');
//                 ////fflush(stdin);

//                 switch (s)
//                 {
//                     case '+':

//                         {
//                             int index = FindInOA(x, H, HashModeQuad);
//                             InsertIntoOA(x, index, H);
//                             countfilled++;
//                         }
//                     break;

//                     case '?':

//                         {
//                             int index = FindInOA(x, H, HashModeQuad);
//                             printf("%d\n", index);
//                         }
//                     ////fflush(stdout);
//                     break;

//                     default:
//                         {
//                             printf("Invalid Input, please retry\n");
//                             //fflush(stdout);}
//                             i--;
//                         }
//                     break;
//                     // if (i == RehashNo)
//                     // {
//                     //     H= RehashOA(H);
//                     //     RehashNo *= 2;
//                     // }
//                 }

//             }
//             for (int i=0;i<H->TableSize;i++)
//             free(H->TheCells);
//             free(H);
//         }
//         break;
//         case 'q':
//         case 'Q':
//         {
//             countfilled = 0;
//             HashModeQuad = true;
//             PtrTohashOA H = InitializeTableOA(N);
//             for (int i = 0; i < Q; i++)
//             {

//                 char s;
//                 int x;

//                 scanf("%c %d", &s, &x);
//                 while ((getchar()) != '\n');
//                 //fflush(stdin);

//                 switch (s)
//                 {
//                     case '+':
//                         {
//                             int index = FindInOA(x, H, HashModeQuad);
//                             InsertIntoOA(x, index, H);
//                             countfilled++;
//                         }
//                     break;
//                     case '?':
//                         {
//                             int index = FindInOA(x, H, HashModeQuad);
//                             printf("%d\n", index);
//                             //fflush(stdout);
//                         }
//                     break;

//                     default:
//                         {
//                             printf("Invalid Input, please retry\n");
//                             //fflush(stdout);
//                             i--;
//                         }
//                     break;
//                 }

//                 // if (countfilled == RehashNo)
//                 // {
//                 //     H = RehashOA(H);
//                 //     RehashNo *= 2;
//                 // }
//             }

//         }
//         break;
//         case 's':
//         case 'S':
//         {
//             PtrTohashSCD H = InitializeTableSCD(N);
//             for (int i = 0; i < Q; i++)
//             {
//                 InputRetake:;

//                 char s=' ';
//                 int x=0;

//                 scanf("%c %d",&s ,&x);
//                 while ((getchar()) != '\n');

//                 puts(mode);
//                 printf("%c\n", s);
//                 printf("%d\n", x);
//                 //fflush(stdin);
//                 int key = IdentityHashFunction(x, N);
//                 switch (s)
//                 {
//                     case '+':
//                         {
//                             InsertToHashSCD(key, x, H);
//                         }
//                     break;
//                     case '?':
//                         {
//                             printf("%d\n", LocationOfXinSCD(key, x, H));
//                             //fflush(stdout);
//                         }
//                     break;
//                     default:
//                         {
//                                 printf("Invalid Input, please retry\n");
//                                 //fflush(stdout);
//                                 goto InputRetake;
//                         }
//                         break;
//                 }
//             }

//         }
//         break;
//     }
// }
