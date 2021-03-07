#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char Name[50000] ;
};

typedef struct student student;
typedef struct student* studnt;

int main()
{
    int N;
    printf("Input number of Students\n");
    scanf("%ld", &N);
    student LIST[N];
    for (long int i = 0; i < N; i++)
    {
        printf("\nInput %ld 'th Student Name without spaces (Use '_' instead of space)\n",i+1);
        scanf("%s",&LIST[i].Name);
    }

    printf("\nstudents whose name begins with 'a' is = \n");
    for(int i=0;i<N;i++)
    {
        if(LIST[i].Name[0]=='a'||LIST[i].Name[0]=='A')
        printf("\nName = %s, \n",LIST[i].Name);
    }
}