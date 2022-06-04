#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "./../hash.h"
#include <assert.h>
#include <stdbool.h>

long int main()
{
    char mode[20];
    long int N, Q;
    bool HashModeQuad;
    long int countfilled;

    scanf("%s", mode);
    while ((getchar()) != '\n')
        ;
    //fflush(stdin);
    scanf("%ld", &N);
    while ((getchar()) != '\n')
        ;
    //fflush(stdin);
    scanf("%ld", &Q);
    while ((getchar()) != '\n')
        ;
    //fflush(stdin);

    //printf("%ld\n", N);
    //printf("%ld\n", Q);

    long int RehashNo = N / 2;

    if ((mode[0] == 's') || (mode[0] == 'S'))
    {
        ////printf("Entered SC region\n");
        PtrTohashSC Hsc = InitializeTableSC(N);

        ////printf("Entering For Loop region\n");
        for (long int i = 0; i < Q; i++)
        {
            //printf("Entered For Loop region %ld times\n",i+1);
            char s;
            long int x;

            scanf("%c %ld", &s, &x);
            while (1)
            {
                char check = getchar();
                if (check == EOF || check == '\n')
                    break;
            }

        Retry_adding:;

            //puts(mode);
            //printf("%c\n", s);
            //printf("%ld\n", x);
            //fflush(stdin);
            long int key = IdentityHashFunction(x, Hsc->TableSize);

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
                    long int posFromStart = -1;
                    SearchInLinkedListofHSC(x, key, Hsc, &posFromStart);
                    printf("%ld\n", posFromStart);
                    //printf("Exited ? region\n");
                }
                else
                {
                    printf("Please Give input again!!\n");
                    scanf("%c %ld", &s, &x);
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
        for (long int i = 0; i < Hsc->TableSize; i++)
            free(Hsc->TheLists[i]);
        free(Hsc);
    }

    else
    {
        if (/* condition */ (mode[0] == 'L') || (mode[0] == 'l'))
        {
            PtrTohashOA Hoa = InitializeTableOA(N);

            ////printf("Entering For Loop region\n");
            for (long int i = 0; i < Q; i++)
            {
                //printf("Entered For Loop region %ld times\n",i+1);
                char s;
                long int x;

                scanf("%c %ld", &s, &x);
                while (1)
                {
                    char check = getchar();
                    if (check == EOF || check == '\n')
                        break;
                }
            Retry_addingOAL:;

                //puts(mode);
                //printf("%c\n", s);
                //printf("%ld\n", x);
                //fflush(stdin);
                long int index = FindInOA(x, Hoa, false);

                //printf("Entered IF region\n");
                if (s == '+')
                {
                    //printf("Entered + region\n");
                    /* code */
                    InsertIntoOA(x, index, Hoa);
                    //printf("Exited + region\n");
                }
                else
                {
                    /* code */
                    if (/* condition */ s == '?')
                    {
                        //printf("Entered ? region\n");
                        /* code */
                        //long int posFromStart = -1;
                        //SearchInLinkedListofHSC(x, key, Hsc, &posFromStart);
                        if (i < Q - 1)
                        {
                            if (Hoa->TheCells[index].info == Legit)
                                printf("%ld\n", index);
                            else
                                printf("-1\n");
                        }
                        else{
                            if (Hoa->TheCells[index].info == Legit)
                                printf("%ld", index);
                            else
                                printf("-1");
                        }
                        //printf("Exited ? region\n");
                    }
                    else
                    {
                        printf("Please Give input again!!\n");
                        scanf("%c %ld", &s, &x);
                        while ((getchar()) != '\n')
                            ;
                        goto Retry_addingOAL;
                        /* code */
                    }
                }
            }
        }
        else
        {
            /* code */
            if (/* condition */ (mode[0] == 'Q') || (mode[0] == 'q'))
            {
                PtrTohashOA Hoa = InitializeTableOA(N);

                ////printf("Entering For Loop region\n");
                for (long int i = 0; i < Q; i++)
                {
                    //printf("Entered For Loop region %ld times\n",i+1);
                    char s;
                    long int x;

                    scanf("%c %ld", &s, &x);
                    while (1)
                    {
                        char check = getchar();
                        if (check == EOF || check == '\n')
                            break;
                    }
                Retry_addingOAQ:;

                    //puts(mode);
                    //printf("%c\n", s);
                    //printf("%ld\n", x);
                    //fflush(stdin);
                    long int index = FindInOA(x, Hoa, true);

                    //printf("Entered IF region\n");
                    if (s == '+')
                    {
                        //printf("Entered + region\n");
                        /* code */
                        InsertIntoOA(x, index, Hoa);
                        //printf("Exited + region\n");
                    }
                    else
                    {
                        /* code */
                        if (/* condition */ s == '?')
                        {
                            //printf("Entered ? region\n");
                            /* code */
                            //long int posFromStart = -1;
                            //SearchInLinkedListofHSC(x, key, Hsc, &posFromStart);
                            if (Hoa->TheCells[index].info == Legit)
                                printf("%ld\n", index);
                            else
                                printf("-1\n");
                            //printf("Exited ? region\n");
                        }
                        else
                        {
                            printf("Please Give input again!!\n");
                            scanf("%c %ld", &s, &x);
                            while ((getchar()) != '\n')
                                ;
                            goto Retry_addingOAQ;
                            /* code */
                        }
                    }
                }
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
//             for (long int i = 0; i < Q; i++)
//             {

//                 char s;
//                 long int x;

//                 scanf("%c %ld", &s, &x);
//                 while ((getchar()) != '\n');
//                 ////fflush(stdin);

//                 switch (s)
//                 {
//                     case '+':

//                         {
//                             long int index = FindInOA(x, H, HashModeQuad);
//                             InsertIntoOA(x, index, H);
//                             countfilled++;
//                         }
//                     break;

//                     case '?':

//                         {
//                             long int index = FindInOA(x, H, HashModeQuad);
//                             printf("%ld\n", index);
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
//             for (long int i=0;i<H->TableSize;i++)
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
//             for (long int i = 0; i < Q; i++)
//             {

//                 char s;
//                 long int x;

//                 scanf("%c %ld", &s, &x);
//                 while ((getchar()) != '\n');
//                 //fflush(stdin);

//                 switch (s)
//                 {
//                     case '+':
//                         {
//                             long int index = FindInOA(x, H, HashModeQuad);
//                             InsertIntoOA(x, index, H);
//                             countfilled++;
//                         }
//                     break;
//                     case '?':
//                         {
//                             long int index = FindInOA(x, H, HashModeQuad);
//                             printf("%ld\n", index);
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
//             for (long int i = 0; i < Q; i++)
//             {
//                 InputRetake:;

//                 char s=' ';
//                 long int x=0;

//                 scanf("%c %ld",&s ,&x);
//                 while ((getchar()) != '\n');

//                 puts(mode);
//                 printf("%c\n", s);
//                 printf("%ld\n", x);
//                 //fflush(stdin);
//                 long int key = IdentityHashFunction(x, N);
//                 switch (s)
//                 {
//                     case '+':
//                         {
//                             InsertToHashSCD(key, x, H);
//                         }
//                     break;
//                     case '?':
//                         {
//                             printf("%ld\n", LocationOfXinSCD(key, x, H));
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
