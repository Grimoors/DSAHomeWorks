#include "./../hash.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char mode[20];
    int N, Q;
    bool HashModeQuad;
    int countfilled;

    scanf("%s", mode);
    while ((getchar()) != '\n');
    //fflush(stdin);
    scanf("%d", &N);
    while ((getchar()) != '\n');
    //fflush(stdin);
    scanf("%d", &Q);
    while ((getchar()) != '\n');
    //fflush(stdin);

                    printf("%d\n", N);
                printf("%d\n", Q);

    int RehashNo = N / 2;

    switch (mode[0])
    {
        case 'l':
        case 'L':
        {
            countfilled = 0;
            HashModeQuad = false;
            PtrTohashOA H = InitializeTableOA(N);
            for (int i = 0; i < Q; i++)
            {

                char s;
                int x;
                
                scanf("%c %d", &s, &x);
                while ((getchar()) != '\n');
                ////fflush(stdin);

                switch (s)
                {
                    case '+':

                        {
                            int index = FindInOA(x, H, HashModeQuad);
                            InsertIntoOA(x, index, H);
                            countfilled++;
                        }
                    break;

                    case '?':

                        {
                            int index = FindInOA(x, H, HashModeQuad);
                            printf("%d\n", index);
                        }
                    ////fflush(stdout);
                    break;

                    default:
                        {
                            printf("Invalid Input, please retry\n");
                            //fflush(stdout);}
                            i--;
                        }
                    break;
                    // if (i == RehashNo)
                    // {
                    //     H= RehashOA(H);
                    //     RehashNo *= 2;
                    // }
                }
                
            }
            for (int i=0;i<H->TableSize;i++)
            free(H->TheCells);
            free(H);
        }
        break;
        case 'q':
        case 'Q':
        {
            countfilled = 0;
            HashModeQuad = true;
            PtrTohashOA H = InitializeTableOA(N);
            for (int i = 0; i < Q; i++)
            {

                char s;
                int x;
                
                scanf("%c %d", &s, &x);
                while ((getchar()) != '\n');
                //fflush(stdin);

                switch (s)
                {
                    case '+':
                        {
                            int index = FindInOA(x, H, HashModeQuad);
                            InsertIntoOA(x, index, H);
                            countfilled++;
                        }
                    break;
                    case '?':
                        {
                            int index = FindInOA(x, H, HashModeQuad);
                            printf("%d\n", index);
                            //fflush(stdout);
                        }
                    break;

                    default:
                        {
                            printf("Invalid Input, please retry\n");
                            //fflush(stdout);
                            i--;
                        }
                    break;
                }

                // if (countfilled == RehashNo)
                // {
                //     H = RehashOA(H);
                //     RehashNo *= 2;
                // }
            }
            
        }
        break;
        case 's':
        case 'S':
        {
            PtrTohashSCD H = InitializeTableSCD(N);
            for (int i = 0; i < Q; i++)
            {
                InputRetake:;

                char s=' ';
                int x=0;
                
                scanf("%c %d",&s ,&x);
                while ((getchar()) != '\n');

                puts(mode);
                printf("%c\n", s);
                printf("%d\n", x);
                //fflush(stdin);
                int key = IdentityHashFunction(x, N);
                switch (s)
                {
                    case '+':
                        {
                            InsertToHashSCD(key, x, H);
                        }
                    break;
                    case '?':
                        {
                            printf("%d\n", LocationOfXinSCD(key, x, H));
                            //fflush(stdout);
                        }
                    break;
                    default:
                        {
                                printf("Invalid Input, please retry\n");
                                //fflush(stdout);
                                goto InputRetake;
                        }
                        break;
                }
            }
        
        }
        break;
    }
}
